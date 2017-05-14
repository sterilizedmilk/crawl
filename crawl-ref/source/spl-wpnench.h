#pragma once

#include "item-prop-enum.h"
#include "spl-cast.h"

#define ORIGINAL_BRAND_KEY "orig brand"

class dist;

brand_type affined_brand();

string _get_brand_msg(brand_type which_brand, bool is_range_weapon);

void end_weapon_brand(item_def &weapon, bool verbose = false);
int _get_brand_duration(brand_type which_brand);

spret_type brand_weapon(brand_type which_brand, int power, bool fail);
spret_type cast_confusing_touch(int power, bool fail);
