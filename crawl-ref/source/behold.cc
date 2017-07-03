/**
 * @file
 * @brief player methods dealing with mesmerisation.
**/

#include "AppHdr.h"

#include "player.h"

#include "areas.h"
#include "art-enum.h"
#include "coord.h"
#include "env.h"
#include "fprop.h"
#include "losglobal.h"
#include "state.h"

// Add a monster to the list of beholders.
void player::add_beholder(const monster& mon, bool axe)
{
    if (is_sanctuary(pos()) && !axe)
    {
        if (mons_is_siren_beholder(mon))
        {
            if (can_see(mon))
            {
                mprf("%s의 마력이 공중으로 사라졌다.",
                     mon.name(DESC_THE).c_str());
            }
            else
                mpr("노래가 기묘하게 조용해졌고, 당신에게 아무런 효과도 미치지 못한다.");
        }
        else
        {
            if (can_see(mon))
                mprf("%s은(는) 더 이상 매혹적으로 보이지 않는다!", mon.name(DESC_THE).c_str());
            else
                mpr("매혹된 대상이 당신에게 갖는 관심이 줄어든 것 같다!");
        }

        return;
    }

    if (!duration[DUR_MESMERISED])
    {
        set_duration(DUR_MESMERISED, random_range(7, 15), 15);
        beholders.push_back(mon.mid);
        if (!axe)
        {
            mprf(MSGCH_WARN, "당신은 %s의 최면에 걸려있다!",
                             mon.name(DESC_THE).c_str());
        }
    }
    else
    {
        increase_duration(DUR_MESMERISED, random_range(5, 8), 15);
        if (!beheld_by(mon))
            beholders.push_back(mon.mid);
    }
}

// Whether player is mesmerised.
bool player::beheld() const
{
    ASSERT((duration[DUR_MESMERISED] > 0) == !beholders.empty());
    return duration[DUR_MESMERISED] > 0;
}

// Whether player is mesmerised by the given monster.
bool player::beheld_by(const monster &mon) const
{
    return find(begin(beholders), end(beholders), mon.mid) != end(beholders);
}

// Checks whether a beholder keeps you from moving to
// target, and returns one if it exists.
monster* player::get_beholder(const coord_def &target) const
{
    for (mid_t beh : beholders)
    {
        monster* mon = monster_by_mid(beh);
        // The monster may have died.
        if (!mon)
            continue;
        const int olddist = grid_distance(pos(), mon->pos());
        const int newdist = grid_distance(target, mon->pos());

        if (olddist < newdist)
            return mon;
    }
    return nullptr;
}

monster* player::get_any_beholder() const
{
    if (!beholders.empty())
        return monster_by_mid(beholders[0]);
    else
        return nullptr;
}

// Removes a monster from the list of beholders if present.
void player::remove_beholder(const monster& mon)
{
    for (unsigned int i = 0; i < beholders.size(); i++)
        if (beholders[i] == mon.mid)
        {
            beholders.erase(beholders.begin() + i);
            _removed_beholder();
            return;
        }
}

// Clear the list of beholders. Doesn't message.
void player::clear_beholders()
{
    beholders.clear();
    duration[DUR_MESMERISED] = 0;
    you.duration[DUR_MESMERISE_IMMUNE] = random_range(21, 40);
}

static void _removed_beholder_msg(const monster *mons)
{
    if (!mons)
        return;

    const monster &mon = *mons;
    if (!mon.alive() || !mons_is_siren_beholder(mon)
        || mon.submerged() || !you.see_cell(mon.pos()))
    {
        return;
    }

    if (is_sanctuary(you.pos()) && !mons_is_fleeing(mon))
    {
        if (mons_is_siren_beholder(mon))
        {
            if (you.can_see(mon))
            {
                mprf("%s의 노랫소리가 별안간 멈추었다.",
                     mon.name(DESC_THE).c_str());
            }
            else
                mpr("무언가의 노래가 기묘한 침묵으로 중단되었다.");
        }
        else
        {
            if (you.can_see(mon))
                mprf("%s은(는) 더 이상 매혹적으로 보이지 않는다!", mon.name(DESC_THE).c_str());
            else
                mpr("매혹된 대상이 당신에게 갖는 관심이 줄어든 것 같다!");
        }

        return;
    }

    if (you.can_see(mon))
    {
        if (silenced(you.pos()) || silenced(mon.pos()))
        {
            if (mons_is_siren_beholder(mon))
            {
                mprf("더 이상 %s의 노랫소리가 들리지 않는다!",
                     mon.name(DESC_THE).c_str());
            }
            else
                mpr("정적이 당신의 정신을 맑게 만들었다.");
            return;
        }

        if (mons_is_siren_beholder(mon))
            mprf("%s은(는) 노래를 멈추었다.", mon.name(DESC_THE).c_str());
        else
            mprf("%s의 노래는 더이상 최면 효과가 없다!", mon.name(DESC_THE).c_str());

        return;
    }

    if (mons_is_siren_beholder(mon))
        mpr("무언가가 노래하길 멈추었다.");
    else
        mpr("매혹된 대상이 당신에게 거의 관심을 갖지 않는다!");
}

// Update all beholders' status after changes.
void player::update_beholders()
{
    if (!beheld())
        return;
    bool removed = false;
    for (int i = beholders.size() - 1; i >= 0; i--)
    {
        const monster* mon = monster_by_mid(beholders[i]);
        if (!possible_beholder(mon))
        {
            beholders.erase(beholders.begin() + i);
            removed = true;

            // If that was the last one, clear the duration before
            // printing any subsequent messages, or a --more-- can
            // crash (#6547).
            _removed_beholder(true);
            _removed_beholder_msg(mon);
        }
    }
    if (removed)
        _removed_beholder();
}

// Update a single beholder.
void player::update_beholder(const monster* mon)
{
    if (possible_beholder(mon))
        return;
    for (unsigned int i = 0; i < beholders.size(); i++)
        if (beholders[i] == mon->mid)
        {
            beholders.erase(beholders.begin() + i);
            // Do this dance to clear the duration before printing messages
            // (#8844), but still print all messages in the right order.
            _removed_beholder(true);
            _removed_beholder_msg(mon);
            _removed_beholder();
            return;
        }
}

// Helper function that resets the duration and messages if the player
// is no longer mesmerised.
void player::_removed_beholder(bool quiet)
{
    if (beholders.empty())
    {
        duration[DUR_MESMERISED] = 0;
        you.duration[DUR_MESMERISE_IMMUNE] = random_range(21, 40);
        if (!quiet)
        {
            mprf(MSGCH_DURATION,
                 coinflip() ? "현혹에서 벗어나 정신을 차렸다!"
                            : "황홀한 감정이 사라졌다.");
        }
    }
}

// Helper function that checks whether the given monster is a possible
// beholder.
bool player::possible_beholder(const monster* mon) const
{
    if (crawl_state.game_is_arena())
        return false;

    return mon && mon->alive() && !mon->submerged()
        && cell_see_cell(pos(), mon->pos(), LOS_SOLID_SEE) && mon->see_cell_no_trans(pos())
        && !mon->wont_attack() && !mon->pacified()
        && ((mons_is_siren_beholder(mon->type)
             || mon->has_spell(SPELL_MESMERISE))
            && !silenced(pos())
            && !mon->is_silenced()
            && !mon->confused()
            && !mon->asleep() && !mon->cannot_move()
            && !mon->berserk_or_insane()
            && !mons_is_fleeing(*mon)
            && !is_sanctuary(pos())
          || player_equip_unrand(UNRAND_DEMON_AXE));
}
