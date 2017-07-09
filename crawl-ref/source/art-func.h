/**
 * @file
 * @brief Functions non-standard unrandarts uses.
**/

/*
 * util/art-data.pl scans through this file to grab the functions
 * non-standard unrandarts use and put them into the unranddata structs
 * in art-data.h, so the function names must have the form of
 * _UNRAND_ENUM_func_name() in order to be recognised.
 */

#ifdef ART_FUNC_H
#error "art-func.h included twice!"
#endif

#ifdef ART_DATA_H
#error "art-func.h must be included before art-data.h"
#endif

#define ART_FUNC_H

#include "beam.h"          // For Lajatang of Order's silver damage
#include "cloud.h"         // For storm bow's and robe of clouds' rain
#include "english.h"       // For apostrophise
#include "exercise.h"      // For practise_evoking
#include "fight.h"
#include "food.h"          // For evokes
#include "ghost.h"         // For is_dragonkind ghost_demon datas
#include "god-conduct.h"    // did_god_conduct
#include "god-passive.h"    // passive_t::want_curses
#include "mgen-data.h"     // For Sceptre of Asmodeus evoke
#include "mon-death.h"     // For demon axe's SAME_ATTITUDE
#include "mon-place.h"     // For Sceptre of Asmodeus evoke
#include "player.h"
#include "player-stats.h"
#include "spl-cast.h"      // For evokes
#include "spl-damage.h"    // For the Singing Sword.
#include "spl-goditem.h"   // For Sceptre of Torment tormenting
#include "spl-miscast.h"   // For Staff of Wucad Mu and Scythe of Curses miscasts
#include "spl-summoning.h" // For Zonguldrok animating dead
#include "terrain.h"       // For storm bow
#include "view.h"          // For arc blade's discharge effect

// prop recording whether the singing sword has said hello yet
#define SS_WELCOME_KEY "ss_welcome"
// similarly, for the majin-bo
#define MB_WELCOME_KEY "mb_welcome"

/*******************
 * Helper functions.
 *******************/

static void _equip_mpr(bool* show_msgs, const char* msg,
                       msg_channel_type chan = MSGCH_PLAIN)
{
    bool do_show = true;
    if (show_msgs == nullptr)
        show_msgs = &do_show;

    if (*show_msgs)
        mprf(chan, "%s", msg);

    // Caller shouldn't give any more messages.
    *show_msgs = false;
}

/*******************
 * Unrand functions.
 *******************/

static bool _evoke_sceptre_of_asmodeus()
{
    if (!x_chance_in_y(you.skill(SK_EVOCATIONS, 100), 3000))
        return false;

    const monster_type mon = random_choose_weighted(
                                   3, MONS_EFREET,
                                   3, MONS_SUN_DEMON,
                                   3, MONS_BALRUG,
                                   2, MONS_HELLION,
                                   1, MONS_BRIMSTONE_FIEND);

    mgen_data mg(mon, BEH_CHARMED, you.pos(), MHITYOU,
                 MG_FORCE_BEH, you.religion);
    mg.set_summoned(&you, 0, 0);
    mg.extra_flags |= (MF_NO_REWARD | MF_HARD_RESET);

    monster *m = create_monster(mg);

    if (m)
    {
        mpr("홀이 자신의 시종 중 하나를 소환했다.");
        did_god_conduct(DID_EVIL, 3);

        m->add_ench(mon_enchant(ENCH_FAKE_ABJURATION, 6));

        if (!player_angers_monster(m))
            mpr("당신은 별로 좋은 예감이 들지 않는다...");
    }
    else
        mpr("대기가 잠시 어른거렸다.");

    return true;
}

static bool _ASMODEUS_evoke(item_def *item, bool* did_work, bool* unevokable)
{
    if (_evoke_sceptre_of_asmodeus())
    {
        make_hungry(200, false, true);
        *did_work = true;
        practise_evoking(1);
    }

    return false;
}

////////////////////////////////////////////////////
static void _CEREBOV_melee_effects(item_def* weapon, actor* attacker,
                                   actor* defender, bool mondied, int dam)
{
    if (dam)
    {
        if (defender->is_player()
            && defender->res_fire() <= 3
            && !you.duration[DUR_FIRE_VULN])
        {
            mpr("세레보브의 검이 당신의 화염 저항을 불태웠다.");
            you.increase_duration(DUR_FIRE_VULN, 3 + random2(dam), 50);
        }
        if (defender->is_monster()
            && !mondied
            && !defender->as_monster()->has_ench(ENCH_FIRE_VULN))
        {
            if (you.can_see(*attacker))
            {
                mprf("세레보브의 검이 %s의 화염 저항을 불태웠다.",
                     defender->name(DESC_ITS).c_str());
            }
            defender->as_monster()->add_ench(
                mon_enchant(ENCH_FIRE_VULN, 1, attacker,
                            (3 + random2(dam)) * BASELINE_DELAY));
        }
    }
}

////////////////////////////////////////////////////

static void _CURSES_equip(item_def *item, bool *show_msgs, bool unmeld)
{
    _equip_mpr(show_msgs, "전율이 당신의 등골을 타고 흘렀다.");
    if (!unmeld)
    {
        MiscastEffect(&you, nullptr, WIELD_MISCAST, SPTYP_NECROMANCY, random2(9),
                      random2(70), "the scythe of Curses", NH_NEVER);
    }
}

static void _CURSES_world_reacts(item_def *item)
{
    // don't spam messages for ash worshippers
    if (one_chance_in(30) && !have_passive(passive_t::want_curses))
        curse_an_item(true);
}

static void _CURSES_melee_effects(item_def* weapon, actor* attacker,
                                  actor* defender, bool mondied, int dam)
{
    if (attacker->is_player())
        did_god_conduct(DID_EVIL, 3);
    if (!mondied && defender->holiness() == MH_NATURAL)
    {
        MiscastEffect(defender, attacker, MELEE_MISCAST, SPTYP_NECROMANCY,
                      random2(9), random2(70), "the scythe of Curses",
                      NH_NEVER);
    }
}

/////////////////////////////////////////////////////

static bool _DISPATER_evoke(item_def *item, bool* did_work, bool* unevokable)
{
    if (!enough_hp(14, true))
    {
        mpr("이 아이템을 사용하기엔 당신이 죽음에 너무 가깝다.");
        *unevokable = true;
        return true;
    }

    if (!enough_mp(4, false))
    {
        *unevokable = true;
        return true;
    }

    *did_work = true;
    int power = you.skill(SK_EVOCATIONS, 8);

    if (your_spells(SPELL_HURL_DAMNATION, power, false) == SPRET_ABORT)
    {
        *unevokable = true;
        return false;
    }

    mpr("지팡이가 당신의 에너지를 빨아들였다!");
    dec_hp(14, false);
    dec_mp(4);
    make_hungry(100, false, true);
    practise_evoking(random_range(1, 2));

    return false;
}

////////////////////////////////////////////////////

// XXX: Staff giving a boost to poison spells is hardcoded in
// player_spec_poison()

static void _OLGREB_equip(item_def *item, bool *show_msgs, bool unmeld)
{
    if (you.can_smell())
        _equip_mpr(show_msgs, "당신은 염소 냄새를 맡았다.");
    else
        _equip_mpr(show_msgs, "지팡이가 병든 녹색으로 빛난다.");
}

static void _OLGREB_unequip(item_def *item, bool *show_msgs)
{
    if (you.can_smell())
        _equip_mpr(show_msgs, "염소 냄새가 사라졌다.");
    else
        _equip_mpr(show_msgs, "지팡이의 병든 녹색빛이 사라졌다.");
}

static bool _OLGREB_evoke(item_def *item, bool* did_work, bool* unevokable)
{
    if (!enough_mp(4, false))
    {
        *unevokable = true;
        return true;
    }

    if (!x_chance_in_y(you.skill(SK_EVOCATIONS, 100) + 100, 600))
        return false;

    *did_work = true;

    int power = div_rand_round(20 + you.skill(SK_EVOCATIONS, 20), 4);

    // Allow aborting (for example if friendlies are nearby).
    if (your_spells(SPELL_OLGREBS_TOXIC_RADIANCE, power, false) == SPRET_ABORT)
    {
        *unevokable = true;
        return false;
    }

    if (x_chance_in_y(you.skill(SK_EVOCATIONS, 100) + 100, 2000))
        your_spells(SPELL_VENOM_BOLT, power, false);

    dec_mp(4);
    make_hungry(50, false, true);
    practise_evoking(1);

    return false;
}

static void _OLGREB_melee_effects(item_def* weapon, actor* attacker,
                                  actor* defender, bool mondied, int dam)
{
    if (defender->alive())
        defender->poison(attacker, 2);
}

////////////////////////////////////////////////////

static void _power_pluses(item_def *item)
{
    item->plus = min(you.hp / 10, 27);
}

static void _POWER_equip(item_def *item, bool *show_msgs, bool unmeld)
{
    _equip_mpr(show_msgs, "당신은 엄청난 힘의 기운을 느꼈다.");
    _power_pluses(item);
}

static void _POWER_world_reacts(item_def *item)
{
    _power_pluses(item);
}

////////////////////////////////////////////////////

static void _SINGING_SWORD_equip(item_def *item, bool *show_msgs, bool unmeld)
{
    bool def_show = true;

    if (show_msgs == nullptr)
        show_msgs = &def_show;

    if (!*show_msgs)
        return;

    if (!item->props.exists(SS_WELCOME_KEY))
    {
        mprf(MSGCH_TALK, "검이 말했다, \"안녕! 나는 노래하는 검이야!\"");
        item->props[SS_WELCOME_KEY].get_bool() = true;
    }
    else
        mprf(MSGCH_TALK, "노래하는 검의 칼날이 기쁨으로 웅웅 떨었다!");

    *show_msgs = false;
}

static void _SINGING_SWORD_unequip(item_def *item, bool *show_msgs)
{
    set_artefact_name(*item, "Singing Sword");
    _equip_mpr(show_msgs, "노래하는 검이 한숨을 쉬었다.", MSGCH_TALK);
}

static void _SINGING_SWORD_world_reacts(item_def *item)
{
    int tension = get_tension(GOD_NO_GOD);
    int tier = (tension <= 0) ? 1 : (tension < 40) ? 2 : 3;
    bool silent = silenced(you.pos());

    string old_name = get_artefact_name(*item);
    string new_name;
    if (silent)
        new_name = "Sulking Sword";
    else if (tier < 2)
        new_name = "Singing Sword";
    else
        new_name = "Screaming Sword";
    if (old_name != new_name)
    {
        set_artefact_name(*item, new_name);
        you.wield_change = true;
    }

    // not as spammy at low tension
    if (!x_chance_in_y(7, (tier == 1) ? 1000 : (tier == 2) ? 100 : 10))
        return;

    // it will still struggle more with higher tension
    if (silent)
        tier = 0;

    if (tier == 3 && one_chance_in(10))
        tier++; // SCREAM -- double damage

    const char *tenname[] =  {"silenced", "no_tension", "low_tension",
                              "high_tension", "SCREAM"};
    const string key = tenname[tier];
    string msg = getSpeakString("singing sword " + key);

    const int loudness[] = {0, 0, 15, 25, 35};
    item_noise(*item, msg, loudness[tier]);

    if (tier < 3)
        return; // no damage on low tiers

    sonic_damage(tier == 4);
}

////////////////////////////////////////////////////

static void _PRUNE_equip(item_def *item, bool *show_msgs, bool unmeld)
{
    _equip_mpr(show_msgs, "자두가 된 기분이 들었다.");
}

static void _PRUNE_world_reacts(item_def *item)
{
    if (one_chance_in(10))
        did_god_conduct(DID_CHAOS, 1);
}

////////////////////////////////////////////////////

static void _TORMENT_equip(item_def *item, bool *show_msgs, bool unmeld)
{
    _equip_mpr(show_msgs, "타오르는 듯한 끔찍한 고통이 당신의 팔을 타고 올라왔다!");
}

static void _TORMENT_melee_effects(item_def* weapon, actor* attacker,
                                   actor* defender, bool mondied, int dam)
{
    if (coinflip())
        torment(attacker, TORMENT_SCEPTRE, attacker->pos());
}

/////////////////////////////////////////////////////

static void _TROG_equip(item_def *item, bool *show_msgs, bool unmeld)
{
    _equip_mpr(show_msgs, "피에 대한 갈증이 끓어올랐다!");
}

static void _TROG_unequip(item_def *item, bool *show_msgs)
{
    _equip_mpr(show_msgs, "당신은 덜 폭력적으로 변했다.");
}

////////////////////////////////////////////////////

static void _wucad_backfire()
{
    switch (random2(7))
    {
    case 0:
    case 1:
        switch (random2(4))
        {
        case 0:
            mpr("이상한 모습이 당신의 머릿속을 스쳐지나갔다.");
            break;
        case 1:
            mpr("당신의 머리가 아파온다.");
            break;
        case 2:
            mpr("당신은 온몸을 휩싸는 기묘한 에너지를 느꼈다.");
            break;
        case 3:
            mpr("당신은 불편한 기분이 들었다.");
            break;
        }
        break;
    case 2:
    case 3:
        confuse_player(2 + random2(4));
        break;
    case 4:
    case 5:
        dec_mp(5 + random2(20));
        break;
    case 6:
        lose_stat(STAT_INT, 1 + random2avg(5, 2));
        break;
    }
}

static bool _WUCAD_MU_evoke(item_def *item, bool* did_work, bool* unevokable)
{
    if (you.magic_points == you.max_magic_points)
    {
        mpr("당신의 마력 용량이 가득 찼다.");
        *unevokable = true;
        return true;
    }

    if (!x_chance_in_y(you.skill(SK_EVOCATIONS, 100) + 100, 2500))
        return false;

    if (one_chance_in(4))
    {
        _wucad_backfire();
        did_god_conduct(DID_CHANNEL, 10, true);
        return false;
    }

    mpr("마법 에너지가 당신의 내면 속으로 흘러들어왔다!");

    inc_mp(3 + random2(5) + you.skill_rdiv(SK_EVOCATIONS, 1, 3));
    make_hungry(50, false, true);

    *did_work = true;
    practise_evoking(1);
    did_god_conduct(DID_CHANNEL, 10, true);

    return false;
}

///////////////////////////////////////////////////

// XXX: Always getting maximal vampiric drain is hardcoded in
// attack::apply_damage_brand()

static void _VAMPIRES_TOOTH_equip(item_def *item, bool *show_msgs, bool unmeld)
{
    if (you.undead_state() == US_ALIVE && !you_foodless())
    {
        _equip_mpr(show_msgs,
                   "공중에 피냄새가 퍼지며, 기이한 갈증이 느껴진다...");
    }
    else if (you.species != SP_VAMPIRE)
        _equip_mpr(show_msgs, "당신은 기이한 공허함을 느꼈다.");
    // else let player-equip.cc handle message
}

///////////////////////////////////////////////////

// XXX: Pluses at creation time are hardcoded in make_item_unrandart()

static void _VARIABILITY_world_reacts(item_def *item)
{
    if (x_chance_in_y(2, 5))
        item->plus += random_choose(+1, -1);

    if (item->plus < -4)
        item->plus = -4;
    else if (item->plus > 16)
        item->plus = 16;
}

///////////////////////////////////////////////////

static void _ZONGULDROK_equip(item_def *item, bool *show_msgs, bool unmeld)
{
    _equip_mpr(show_msgs, "당신은 엄청나게 불경한 기운을 느꼈다.");
}

static void _ZONGULDROK_melee_effects(item_def* weapon, actor* attacker,
                                      actor* defender, bool mondied, int dam)
{
    if (attacker->is_player())
    {
        did_god_conduct(DID_EVIL, 3);
        did_god_conduct(DID_CORPSE_VIOLATION, 3);
    }
}

///////////////////////////////////////////////////

static void _STORM_BOW_world_reacts(item_def *item)
{
    if (!one_chance_in(300))
        return;

    for (radius_iterator ri(you.pos(), 2, C_SQUARE, LOS_SOLID); ri; ++ri)
        if (!cell_is_solid(*ri) && !cloud_at(*ri) && one_chance_in(5))
            place_cloud(CLOUD_RAIN, *ri, random2(20), &you, 3);
}

///////////////////////////////////////////////////

static void _GONG_melee_effects(item_def* item, actor* wearer,
                                actor* attacker, bool dummy, int dam)
{
    if (silenced(wearer->pos()))
        return;

    string msg = getSpeakString("shield of the gong");
    if (msg.empty())
        msg = "You hear a strange loud sound.";
    mprf(MSGCH_SOUND, "%s", msg.c_str());

    noisy(40, wearer->pos());
}

///////////////////////////////////////////////////

static void _RCLOUDS_world_reacts(item_def *item)
{
    cloud_type cloud;
    if (one_chance_in(4))
        cloud = CLOUD_RAIN;
    else
        cloud = CLOUD_MIST;

    for (radius_iterator ri(you.pos(), 2, C_SQUARE, LOS_SOLID); ri; ++ri)
        if (!cell_is_solid(*ri) && !cloud_at(*ri) && one_chance_in(20))
            place_cloud(cloud, *ri, random2(10), &you, 1);
}

static void _RCLOUDS_equip(item_def *item, bool *show_msgs, bool unmeld)
{
    _equip_mpr(show_msgs, "옅은 안개가 당신의 주위에 서린다!");
}

///////////////////////////////////////////////////

static void _DEMON_AXE_melee_effects(item_def* item, actor* attacker,
                                     actor* defender, bool mondied, int dam)
{
    if (one_chance_in(10))
    {
        if (monster* mons = attacker->as_monster())
        {
            create_monster(
                mgen_data(summon_any_demon(RANDOM_DEMON_COMMON),
                          SAME_ATTITUDE(mons), mons->pos(), mons->foe)
                .set_summoned(mons, 6, SPELL_SUMMON_DEMON));
        }
        else
            cast_summon_demon(50+random2(100));
    }
}

static monster* _find_nearest_possible_beholder()
{
    for (distance_iterator di(you.pos(), true, true, LOS_RADIUS); di; ++di)
    {
        monster *mon = monster_at(*di);
        if (mon && you.can_see(*mon)
            && you.possible_beholder(mon)
            && mons_is_threatening(*mon))
        {
            return mon;
        }
    }

    return nullptr;
}

static void _DEMON_AXE_world_reacts(item_def *item)
{

    monster* mon = _find_nearest_possible_beholder();

    if (!mon)
        return;

    monster& closest = *mon;

    if (!you.beheld_by(closest))
    {
        mprf("%s 살육하는 환상이 당신의 머리속으로 넘쳐흘렀다.",
             closest.name("을").c_str());

        // The monsters (if any) currently mesmerising the player do not include
        // this monster. To avoid trapping the player, all other beholders
        // are removed.

        you.clear_beholders();
    }

    if (you.confused())
    {
        mpr("피에 대한 갈증이 타오름에 따라 당신의 혼란함이 사라진다.");
        you.duration[DUR_CONF] = 0;
    }

    you.add_beholder(closest, true);
}

static void _DEMON_AXE_unequip(item_def *item, bool *show_msgs)
{
    if (you.beheld())
    {
        // This shouldn't clear sirens and merfolk avatars, but we lack the
        // information why they behold us -- usually, it's due to the axe.
        // Since unwielding it costs scrolls of rem curse, we might say getting
        // the demon away is enough of a shock to get you back to senses.
        you.clear_beholders();
        mpr("피에 대한 갈증이 사라졌다.");
    }
}

///////////////////////////////////////////////////

static void _WYRMBANE_equip(item_def *item, bool *show_msgs, bool unmeld)
{
    _equip_mpr(show_msgs,
               species_is_draconian(you.species)
                || you.form == transformation::dragon
                   ? "자살하고픈 압도적인 욕망이 들끓는다."
                   : "당신은 용을 살해하고픈 압도적인 욕망을 느꼈다!");
}

static bool is_dragonkind(const actor *act)
{
    if (mons_genus(act->mons_species()) == MONS_DRAGON
        || mons_genus(act->mons_species()) == MONS_DRAKE
        || mons_genus(act->mons_species()) == MONS_DRACONIAN)
    {
        return true;
    }

    if (act->is_player())
        return you.form == transformation::dragon;

    // Else the actor is a monster.
    const monster* mon = act->as_monster();

    if (mons_is_zombified(*mon)
        && (mons_genus(mon->base_monster) == MONS_DRAGON
            || mons_genus(mon->base_monster) == MONS_DRAKE
            || mons_genus(mon->base_monster) == MONS_DRACONIAN))
    {
        return true;
    }

    if (mons_is_ghost_demon(mon->type)
        && species_is_draconian(mon->ghost->species))
    {
        return true;
    }

    return false;
}

static void _WYRMBANE_melee_effects(item_def* weapon, actor* attacker,
                                    actor* defender, bool mondied, int dam)
{
    if (!defender || !is_dragonkind(defender))
        return;

    // Since the target will become a DEAD MONSTER if it dies due to the extra
    // damage to dragons, we need to grab this information now.
    int hd = min(defender->get_experience_level(), 18);
    string name = defender->name(DESC_THE);

    if (!mondied)
    {
        mprf("%s이(가) %s!",
            defender->name(DESC_PLAIN).c_str(),
            defender->conj_verb("경련했다").c_str());

        defender->hurt(attacker, 1 + random2(3*dam/2));

        // Allow the lance to charge when killing dragonform felid players.
        mondied = defender->is_player() ? defender->as_player()->pending_revival
                                        : !defender->alive();
    }

    if (!mondied || defender->is_summoned()
        || (defender->is_monster()
            && testbits(defender->as_monster()->flags, MF_NO_REWARD)))
    {
        return;
    }

    // The cap can be reached by:
    // * iron dragon, golden dragon, pearl dragon (18)
    // * Xtahua (19)
    // * bone dragon, Serpent of Hell (20)
    // * Tiamat (22)
    // * pghosts (up to 27)
    dprf("Killed a drac with hd %d.", hd);

    if (weapon->plus < hd)
    {
        weapon->plus++;

        // Including you, if you were a dragonform felid with lives left.
        if (weapon->plus == 18)
        {
            mprf("<white>%s을(를) 꿰뚫는 순간 창이 밝게 빛났다. "
                 "당신은 이 무기의 힘이 최고조에 달했음을 깨달았다.</white>",
                 name.c_str());
        }
        else
        {
            mprf("<green>%s을(를) 꿰뚫자 창이 빛났다.</green>",
                 name.c_str());
        }

        you.wield_change = true;
    }
}

///////////////////////////////////////////////////

static void _UNDEADHUNTER_melee_effects(item_def* item, actor* attacker,
                                        actor* defender, bool mondied, int dam)
{
    if (defender->holiness() & MH_UNDEAD && !one_chance_in(3)
        && !mondied && dam)
    {
        mprf("%s은(는) 붕괴 에너지에 폭파당했다!",
              defender->name(DESC_PLAIN).c_str());
        defender->hurt(attacker, random2avg((1 + (dam * 3)), 3));
    }
}

///////////////////////////////////////////////////
static void _EOS_equip(item_def *item, bool *show_msgs, bool unmeld)
{
    invalidate_agrid(true);
}

static void _EOS_unequip(item_def *item, bool *show_msgs)
{
    invalidate_agrid(true);
}

///////////////////////////////////////////////////
static void _SHADOWS_equip(item_def *item, bool *show_msgs, bool unmeld)
{
    invalidate_agrid(true);
}

static void _SHADOWS_unequip(item_def *item, bool *show_msgs)
{
    invalidate_agrid(true);
}

///////////////////////////////////////////////////
static void _DEVASTATOR_equip(item_def *item, bool *show_msgs, bool unmeld)
{
    _equip_mpr(show_msgs, "거추장스런 법칙들을 내려놓을 시간이다.");
}

static void _DEVASTATOR_melee_effects(item_def* item, actor* attacker,
                                      actor* defender, bool mondied, int dam)
{
    if (dam)
        shillelagh(attacker, defender->pos(), dam);
}

///////////////////////////////////////////////////
static void _DRAGONSKIN_equip(item_def *item, bool *show_msgs, bool unmeld)
{
    _equip_mpr(show_msgs, "당신은 원소로부터 불안정하게 보호받음을 느꼈다.");
}

static void _DRAGONSKIN_unequip(item_def *item, bool *show_msgs)
{
    _equip_mpr(show_msgs, "원소로부터 보호받던 느낌이 사라졌다.");
}

///////////////////////////////////////////////////
static void _BLACK_KNIGHT_HORSE_world_reacts(item_def *item)
{
    if (one_chance_in(10))
        did_god_conduct(DID_EVIL, 1);
}

///////////////////////////////////////////////////
static void _NIGHT_equip(item_def *item, bool *show_msgs, bool unmeld)
{
    update_vision_range();
    _equip_mpr(show_msgs, "당신의 주위에서 빛이 사라졌다.");
}

static void _NIGHT_unequip(item_def *item, bool *show_msgs)
{
    update_vision_range();
    _equip_mpr(show_msgs, "당신의 주위에 빛이 돌아온다.");
}

///////////////////////////////////////////////////

static void _PLUTONIUM_SWORD_melee_effects(item_def* weapon, actor* attacker,
                                           actor* defender, bool mondied,
                                           int dam)
{
    if (!mondied && one_chance_in(5)
        && (!defender->is_monster()
             || !mons_immune_magic(*defender->as_monster())))
    {
        mpr("기묘한 에너지가 플루토늄 검을 타고 흘러들어왔다!");
        MiscastEffect(defender, attacker, MELEE_MISCAST, SPTYP_TRANSMUTATION,
                      random2(9), random2(70), "the plutonium sword", NH_NEVER);

        if (attacker->is_player())
            did_god_conduct(DID_CHAOS, 3);
    }
}

///////////////////////////////////////////////////

static void _SNAKEBITE_melee_effects(item_def* weapon, actor* attacker,
                                     actor* defender, bool mondied, int dam)
{
    if (!mondied && x_chance_in_y(2, 5))
    {
        curare_actor(attacker, defender, 2, "curare",
                     attacker->name(DESC_PLAIN));
    }
}

///////////////////////////////////////////////////

static void _WOE_melee_effects(item_def* weapon, actor* attacker,
                               actor* defender, bool mondied, int dam)
{
    const char *verb = "bugger", *adv = "";
    switch (random2(8))
    {
    case 0: verb = "cleave", adv = " in twain"; break;
    case 1: verb = "pulverise", adv = " into a thin bloody mist"; break;
    case 2: verb = "hew", adv = " savagely"; break;
    case 3: verb = "fatally mangle", adv = ""; break;
    case 4: verb = "dissect", adv = " like a pig carcass"; break;
    case 5: verb = "chop", adv = " into pieces"; break;
    case 6: verb = "butcher", adv = " messily"; break;
    case 7: verb = "slaughter", adv = " joyfully"; break;
    }
    if (you.see_cell(attacker->pos()) || you.see_cell(defender->pos()))
    {
        mprf("%s %s %s%s.", attacker->name(DESC_THE).c_str(),
             attacker->conj_verb(verb).c_str(),
             (attacker == defender ? defender->pronoun(PRONOUN_REFLEXIVE)
                                   : defender->name(DESC_THE)).c_str(),
             adv);
    }

    if (!mondied)
        defender->hurt(attacker, defender->stat_hp());
}

///////////////////////////////////////////////////

static setup_missile_type _DAMNATION_launch(item_def* item, bolt* beam,
                                           string* ammo_name, bool* returning)
{
    ASSERT(beam->item
           && beam->item->base_type == OBJ_MISSILES
           && !is_artefact(*(beam->item)));
    beam->item->special = SPMSL_EXPLODING; // so that it mulches
    beam->item->props[DAMNATION_BOLT_KEY].get_bool() = true;

    beam->name    = "damnation bolt";
    *ammo_name    = "a damnation bolt";
    beam->colour  = LIGHTRED;
    beam->glyph   = DCHAR_FIRED_ZAP;

    bolt *expl   = new bolt(*beam);
    expl->flavour = BEAM_DAMNATION;
    expl->is_explosion = true;
    expl->damage = dice_def(3, 14);
    expl->name   = "damnation";

    beam->special_explosion = expl;
    return SM_FINISHED;
}

///////////////////////////////////////////////////

/**
 * Calculate the bonus damage that the Elemental Staff does with an attack of
 * the given flavour.
 *
 * @param flavour   The elemental flavour of attack; may be BEAM_NONE for earth
 *                  (physical) attacks.
 * @param defender  The victim of the attack. (Not const because checking res
 *                  may end up IDing items on monsters... )
 * @return          The amount of damage that the defender will receive.
 */
static int _calc_elemental_staff_damage(beam_type flavour,
                                        actor* defender)
{
    const int base_bonus_dam = 10 + random2(15);

    if (flavour == BEAM_NONE) // earth
        return defender->apply_ac(base_bonus_dam);

    return resist_adjust_damage(defender, flavour, base_bonus_dam);
}

static void _ELEMENTAL_STAFF_melee_effects(item_def*, actor* attacker,
                                           actor* defender, bool mondied,
                                           int)
{
    const int evoc = attacker->skill(SK_EVOCATIONS, 27);
    if (mondied || !(x_chance_in_y(evoc, 27*27) || x_chance_in_y(evoc, 27*27)))
        return;

    const char *verb = nullptr;
    beam_type flavour = BEAM_NONE;

    switch (random2(4))
    {
    case 0:
        verb = "burn";
        flavour = BEAM_FIRE;
        break;
    case 1:
        verb = "freeze";
        flavour = BEAM_COLD;
        break;
    case 2:
        verb = "electrocute";
        flavour = BEAM_ELECTRICITY;
        break;
    default:
        dprf("Bad damage type for elemental staff; defaulting to earth");
        // fallthrough to earth
    case 3:
        verb = "crush";
        break;
    }

    const int bonus_dam = _calc_elemental_staff_damage(flavour, defender);

    if (bonus_dam <= 0)
        return;

    mprf("%s %s %s.",
         attacker->name(DESC_THE).c_str(),
         attacker->conj_verb(verb).c_str(),
         (attacker == defender ? defender->pronoun(PRONOUN_REFLEXIVE)
                               : defender->name(DESC_THE)).c_str());

    defender->hurt(attacker, bonus_dam, flavour);

    if (defender->alive() && flavour != BEAM_NONE)
        defender->expose_to_element(flavour, 2);
}

///////////////////////////////////////////////////

static void _ARC_BLADE_equip(item_def *item, bool *show_msgs, bool unmeld)
{
    _equip_mpr(show_msgs, "전하의 칼날이 살아있는 것처럼 불꽃을 튀겼다.");
}

static void _ARC_BLADE_unequip(item_def *item, bool *show_msgs)
{
    _equip_mpr(show_msgs, "전하의 칼날에서 불꽃이 사라졌다.");
}

static void _ARC_BLADE_melee_effects(item_def* weapon, actor* attacker,
                                     actor* defender, bool mondied,
                                     int dam)
{
    if (!mondied && one_chance_in(3))
    {
        const int pow = 75 + random2avg(75, 2);
        const int num_targs = 1 + random2(random_range(1, 3) + pow / 20);
        int dam_dealt = 0;
        for (int i = 0; defender->alive() && i < num_targs; i++)
            dam_dealt += discharge_monsters(defender->pos(), pow, attacker);
        if (dam_dealt > 0)
            scaled_delay(100);
        else
        {
            if (you.can_see(*attacker))
                mpr("전하의 칼날에서 불꽃이 튀었다.");
            else
                mpr("당신은 전기 불꽃이 튀는 소리를 들었다.");
        }
    }
}

///////////////////////////////////////////////////

static void _SPELLBINDER_melee_effects(item_def* weapon, actor* attacker,
                                       actor* defender, bool mondied,
                                       int dam)
{
    // Only cause miscasts if the target has magic to disrupt.
    if (defender->antimagic_susceptible()
        && !mondied)
    {
        MiscastEffect(defender, attacker, MELEE_MISCAST, SPTYP_RANDOM,
                      random2(9), random2(70),
                      "the demon whip \"Spellbinder\"", NH_NEVER);
    }
}

///////////////////////////////////////////////////

static void _ORDER_melee_effects(item_def* item, actor* attacker,
                                         actor* defender, bool mondied, int dam)
{
    if (!mondied)
    {
        string msg = "";
        int silver_dam = silver_damages_victim(defender, dam, msg);
        if (silver_dam)
        {
            if (you.can_see(*defender))
                mpr(msg);
            defender->hurt(attacker, silver_dam);
        }
    }
}

///////////////////////////////////////////////////

static void _FIRESTARTER_equip(item_def *item, bool *show_msgs, bool unmeld)
{
    _equip_mpr(show_msgs, "당신의 내부는 화염으로 타오른다.");
}

static void _FIRESTARTER_unequip(item_def *item, bool *show_msgs)
{
    _equip_mpr(show_msgs, "당신 내부의 화염이 사라졌다.");
}

static void _FIRESTARTER_melee_effects(item_def* weapon, actor* attacker,
                                   actor* defender, bool mondied, int dam)
{
    if (dam)
    {
        if (defender->is_monster()
            && !mondied
            && !defender->as_monster()->has_ench(ENCH_INNER_FLAME))
        {
            mprf("%s은(는) 내면의 불꽃으로 가득찼다.",
                 defender->name(DESC_PLAIN).c_str());
            defender->as_monster()->add_ench(
                mon_enchant(ENCH_INNER_FLAME, 0, attacker,
                            (3 + random2(dam)) * BASELINE_DELAY));
        }
    }
}

///////////////////////////////////////////////////

static void _CHILLY_DEATH_equip(item_def *item, bool *show_msgs, bool unmeld)
{
    _equip_mpr(show_msgs, "단검이 시릴 듯한 파란 빛으로 타오른다!");
}

static void _CHILLY_DEATH_unequip(item_def *item, bool *show_msgs)
{
    _equip_mpr(show_msgs, "단검의 빛이 사라졌다.");
}

static void _CHILLY_DEATH_melee_effects(item_def* weapon, actor* attacker,
                                   actor* defender, bool mondied, int dam)
{
    if (dam)
    {
        if (defender->is_monster()
            && !mondied
            && !defender->as_monster()->has_ench(ENCH_FROZEN))
        {
            mprf("%s은(는) 급속도로 얼어붙었다.",
                 defender->name(DESC_PLAIN).c_str());
            defender->as_monster()->add_ench(
                mon_enchant(ENCH_FROZEN, 0, attacker,
                            (5 + random2(dam)) * BASELINE_DELAY));
        }
        else if (defender->is_player()
            && !you.duration[DUR_FROZEN])
        {
            mprf(MSGCH_WARN, "당신은 얼음으로 뒤덮혔다.");
            you.increase_duration(DUR_FROZEN, 5 + random2(dam));
        }
    }
}

///////////////////////////////////////////////////

static void _FLAMING_DEATH_equip(item_def *item, bool *show_msgs, bool unmeld)
{
    _equip_mpr(show_msgs, "시미터로부터 뜨거운 붉은 불길이 뿜어져 나온다!");
}

static void _FLAMING_DEATH_unequip(item_def *item, bool *show_msgs)
{
    _equip_mpr(show_msgs, "시미터로부터 나오던 불길이 사그라졌다.");
}

static void _FLAMING_DEATH_melee_effects(item_def* weapon, actor* attacker,
                                   actor* defender, bool mondied, int dam)
{
    if (!mondied && (dam > 2 && one_chance_in(3)))
    {
        if (defender->is_player())
            napalm_player(random2avg(7, 3) + 1, attacker->name(DESC_A, true));
        else
        {
            napalm_monster(
                defender->as_monster(),
                attacker,
                min(4, 1 + random2(attacker->get_hit_dice())/2));
        }
    }
}

///////////////////////////////////////////////////

static void _MAJIN_equip(item_def *item, bool *show_msgs, bool unmeld)
{
    if (!you.max_magic_points)
        return;

    const bool should_msg = !show_msgs || *show_msgs;
    _equip_mpr(show_msgs, "어둠이 당신의 마법을 뒤덮는 느낌이 들었다.");

    if (!item->props.exists(MB_WELCOME_KEY) && should_msg)
    {
        const string msg = "A voice whispers, \"" +
                           getSpeakString("majin-bo greeting") + "\"";
        mprf(MSGCH_TALK, "%s", msg.c_str());
        item->props[MB_WELCOME_KEY].get_bool() = true;
    }
}

static void _MAJIN_unequip(item_def *item, bool *show_msgs)
{
    if (you.max_magic_points)
    {
        _equip_mpr(show_msgs,
                   "어둠이 당신의 마법에서 천천히 풀려나간다.");
    }
}

///////////////////////////////////////////////////

static int _octorings_worn()
{
    int worn = 0;

    for (int i = EQ_LEFT_RING; i < NUM_EQUIP; ++i)
    {
        if (you.melded[i] || you.equip[i] == -1)
            continue;

        item_def& ring = you.inv[you.equip[i]];
        if (is_unrandom_artefact(ring, UNRAND_OCTOPUS_KING_RING))
            worn++;
    }

    return worn;
}

static void _OCTOPUS_KING_equip(item_def *item, bool *show_msgs, bool unmeld)
{
    int rings = _octorings_worn();

    if (rings == 8)
        _equip_mpr(show_msgs, "당신은 왕이 된 듯한 느낌이 들었다!");
    else if (rings)
        _equip_mpr(show_msgs, "당신은 제왕이 된 듯한 느낌이 들었다.");
    item->plus = 8 + 2 * rings;
}

static void _OCTOPUS_KING_world_reacts(item_def *item)
{
    item->plus = 8 + 2 * _octorings_worn();
}

///////////////////////////////////////////////////

static void _CAPTAIN_melee_effects(item_def* weapon, actor* attacker,
                                actor* defender, bool mondied, int dam)
{
    // Player disarming sounds like a bad idea; monster-on-monster might
    // work but would be complicated.
    if (coinflip()
        && dam >= (3 + random2(defender->get_hit_dice()))
        && !x_chance_in_y(defender->get_hit_dice(), random2(20) + dam*4)
        && attacker->is_player()
        && defender->is_monster()
        && !mondied)
    {
        item_def *wpn = defender->as_monster()->disarm();
        if (wpn)
        {
            mprf("선장의 커틀러스가 번쩍였다! 당신은 %s의 손아귀를 찢어버렸다!!",
                defender->name(DESC_PLAIN).c_str());
            mprf("%s의 %s 바닥에 떨어졌다!",
                apostrophise(defender->name(DESC_PLAIN)).c_str(),
                wpn->name("이").c_str());
            defender->hurt(attacker, 18 + random2(18));
        }
    }
}

///////////////////////////////////////////////////

static void _FENCERS_equip(item_def *item, bool *show_msgs, bool unmeld)
{
    _equip_mpr(show_msgs, "앙 가르드!");
}

///////////////////////////////////////////////////

static void _ETHERIC_CAGE_equip(item_def *item, bool *show_msgs, bool unmeld)
{
    _equip_mpr(show_msgs, "당신은 웅장한 마력의 흐름을 느꼈다.");
}

static void _ETHERIC_CAGE_world_reacts(item_def *item)
{
    const int delay = you.time_taken;
    ASSERT(delay > 0);

    // coinflip() chance of 1 MP per turn.
    if (player_regenerates_mp())
        inc_mp(binomial(div_rand_round(delay, BASELINE_DELAY), 1, 2));
}

///////////////////////////////////////////////////

static void _ETERNAL_TORMENT_equip(item_def *item, bool *show_msgs, bool unmeld)
{
    calc_hp();
}

static void _ETERNAL_TORMENT_world_reacts(item_def *item)
{
    if (one_chance_in(10))
        did_god_conduct(DID_EVIL, 1);
}


static void _ETERNAL_TORMENT_unequip(item_def *item, bool *show_msgs)
{
    calc_hp();
}

///////////////////////////////////////////////////

static void _VINES_equip(item_def *item, bool *show_msgs, bool unmeld)
{
    _equip_mpr(show_msgs, "덩굴이 당신의 몸에 달라붙는다!");
}

static void _VINES_unequip(item_def *item, bool *show_msgs)
{
    _equip_mpr(show_msgs, "덩굴이 당신의 몸으로부터 떨어져 나갔다!");
}

///////////////////////////////////////////////////

static void _KRYIAS_equip(item_def *item, bool *show_msgs, bool unmeld)
{
    _equip_mpr(show_msgs, "당신의 몸에 대한 치료 물약의 효율이 증가했다.");
}

static void _KRYIAS_unequip(item_def *item, bool *show_msgs)
{
    _equip_mpr(show_msgs, "당신의 몸에 대한 치료 물약의 효율이 감소했다.");
}

///////////////////////////////////////////////////

static void _FROSTBITE_melee_effects(item_def* weapon, actor* attacker,
                                    actor* defender, bool mondied, int dam)
{
    coord_def spot = defender->pos();
    if (!cell_is_solid(spot)
        && !cloud_at(spot)
        && one_chance_in(5))
    {
         place_cloud(CLOUD_COLD, spot, random_range(4, 8), attacker, 0);
    }
}

///////////////////////////////////////////////////

// Vampiric effect triggers on every hit, see attack::apply_damage_brand()

static void _LEECH_equip(item_def *item, bool *show_msgs, bool unmeld)
{
    if (you.undead_state() == US_ALIVE && !you_foodless())
        _equip_mpr(show_msgs, "당신은 강렬한 굶주림을 느꼈다.");
    else if (you.species != SP_VAMPIRE)
        _equip_mpr(show_msgs, "당신은 텅 빈듯한 기분이 들었다.");
    // else let player-equip.cc handle message
}


///////////////////////////////////////////////////

static void _THERMIC_ENGINE_equip(item_def *item, bool *show_msgs, bool unmeld)
{
    _equip_mpr(show_msgs, "엔진이 살아 움직이기 시작했다!");
    item->plus = 2;
}

static void _THERMIC_ENGINE_unequip(item_def *item, bool *show_msgs)
{
    _equip_mpr(show_msgs, "엔진은 덜덜 떨리더니, 이내 멈추었다.");
    item->plus = 2;
}

static void _THERMIC_ENGINE_melee_effects(item_def* weapon, actor* attacker,
                                   actor* defender, bool mondied, int dam)
{
    if (weapon->plus < 14)
    {
        weapon->plus += 2;

        if (weapon->plus > 14)
            weapon->plus = 14;

        you.wield_change = true;
    }

    if (mondied)
        return;

    // the flaming brand has already been applied at this point
    const int bonus_dam = resist_adjust_damage(defender, BEAM_COLD,
                                               random2(dam) / 2 + 1);
    if (bonus_dam > 0)
    {
        mprf("%s은(는) %s을(를) %s.",
            attacker->name(DESC_PLAIN).c_str(),
            (attacker == defender ? defender->pronoun(PRONOUN_REFLEXIVE)
                                : defender->name(DESC_PLAIN)).c_str(),
            attacker->conj_verb("얼렸다").c_str());

        defender->hurt(attacker, bonus_dam, BEAM_COLD);
        if (defender->alive())
            defender->expose_to_element(BEAM_COLD, 2);
    }
}

static void _THERMIC_ENGINE_world_reacts(item_def *item)
{
    if (item->plus > 2)
    {
        item->plus -= div_rand_round(you.time_taken, BASELINE_DELAY);

        if (item->plus < 2)
            item->plus = 2;

        you.wield_change = true;
    }
}
