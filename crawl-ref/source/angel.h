
#pragma once

#include "mutation-type.h"

enum talent_type
{
    TAL_HP,
    TAL_MP,
    TAL_STR,
    TAL_INT,
    TAL_DEX,
    TAL_MR,
    TAL_APT,
    TAL_WINGS,
    TAL_HALO,
    TAL_RN,
    TAL_RMUT,
    TAL_REGEN,
    NUM_TALENT
};

struct angel_trait
{
    talent_type talent;
    const char* name;
    mutation_type mut_type;
    int cap;
};

const angel_trait angel_data[] =
{
    { TAL_HP, "Hit point", MUT_NO_LEVELUP_BONUS, 9 },
    { TAL_MP, "Magic point", MUT_NO_LEVELUP_BONUS, 6 },
    { TAL_STR, "Strength", MUT_NO_LEVELUP_BONUS, 4 },
    { TAL_INT, "Intelligence", MUT_NO_LEVELUP_BONUS, 4 },
    { TAL_DEX, "Dexterity", MUT_NO_LEVELUP_BONUS, 4 },
    { TAL_MR, "Magic resistance", MUT_NO_LEVELUP_BONUS, 3 },
    { TAL_APT, "Aptitude", MUT_NO_LEVELUP_BONUS, 2 },
    { TAL_WINGS, "Wings", MUT_BIG_WINGS, 1 },
    { TAL_HALO, "Halo", MUT_HALO, 2 },
    { TAL_RN, "Positive energy", MUT_NEGATIVE_ENERGY_RESISTANCE, 3 },
    { TAL_RMUT, "Mutation resistance", MUT_MUTATION_RESISTANCE, 3 },
    { TAL_REGEN, "Regeneration", MUT_REGENERATION, 3 },
};