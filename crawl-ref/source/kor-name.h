/**
 * @file
 * @item name in korean
**/

#include "item-prop-enum.h"
#include "potion-type.h"
#include "book-type.h"


map<int, string> Weapon_name = 
{
    {WPN_CLUB,                  "몽둥이"},
    {WPN_WHIP,                  "채찍"},
    {WPN_MACE,                  "메이스"},
    {WPN_FLAIL,                 "플레일"},
    {WPN_MORNINGSTAR,           "모닝스타"},
    {WPN_DIRE_FLAIL,            "다이어 플레일"},
    {WPN_EVENINGSTAR,           "이브닝스타"},
    {WPN_GREAT_MACE,            "대형 메이스"},

    {WPN_DAGGER,                "단도"},
    {WPN_QUICK_BLADE,           "퀵 블레이드"},
    {WPN_SHORT_SWORD,           "단검"},
    {WPN_RAPIER,                "레이피어"},

    {WPN_FALCHION,              "펄션"},
    {WPN_LONG_SWORD,            "장검"},
    {WPN_SCIMITAR,              "시미터"},
    {WPN_GREAT_SWORD,           "대검"},

    {WPN_HAND_AXE,              "손도끼"},
    {WPN_WAR_AXE,               "워 액스"},
    {WPN_BROAD_AXE,             "브로드 액스"},
    {WPN_BATTLEAXE,             "배틀 액스"},
    {WPN_EXECUTIONERS_AXE,      "처형자의 도끼"},

    {WPN_SPEAR,                 "창"},
    {WPN_TRIDENT,               "삼지창"},
    {WPN_HALBERD,               "할버드"},
    {WPN_GLAIVE,                "글레이브"},
    {WPN_BARDICHE,              "바디셰"},

    {WPN_BLOWGUN,               "바람총"},

    {WPN_HAND_CROSSBOW,         "손 쇠뇌"},
    {WPN_ARBALEST,              "아발레스트"},
    {WPN_TRIPLE_CROSSBOW,       "삼중석궁"},


    {WPN_SHORTBOW,              "단궁"},
    {WPN_LONGBOW,               "장궁"},

    {WPN_HUNTING_SLING,         "사냥용 투석구"},
    {WPN_FUSTIBALUS,            "푸스티발루스"},

    {WPN_DEMON_WHIP,            "악마의 채찍"},
    {WPN_GIANT_CLUB,            "거대 몽둥이"},
    {WPN_GIANT_SPIKED_CLUB,     "가시박힌 거대 몽둥이"},

    {WPN_DEMON_BLADE,           "악마의 칼"},
    {WPN_DOUBLE_SWORD,          "이중검"},
    {WPN_TRIPLE_SWORD,          "삼중검"},

    {WPN_DEMON_TRIDENT,         "악마의 삼지창"},
    {WPN_SCYTHE,                "낫"},

    {WPN_STAFF,                 "지팡이"},
    {WPN_QUARTERSTAFF,          "육척봉"},
    {WPN_LAJATANG,              "라자탕"},

    {WPN_EUDEMON_BLADE,         "성령의 검"},
    {WPN_SACRED_SCOURGE,        "성스러운 천벌"},
    {WPN_TRISHULA,              "트리슐라"},
};


map<int, string> Missile_name = 
{
    {MI_NEEDLE,                 "바늘"},
    {MI_ARROW,                  "화살"},
    {MI_BOLT,                   "볼트"},
    {MI_JAVELIN,                "자벨린"},
    {MI_STONE,                  "돌"},
    {MI_LARGE_ROCK,             "바위"},
    {MI_SLING_BULLET,           "투석구"},
    {MI_THROWING_NET,           "투척용 그물"},
    {MI_TOMAHAWK,               "토마호크"},
};


map<int, string> Armour_name = 
{
    {ARM_ROBE,                  "로브"},
    {ARM_LEATHER_ARMOUR,        "가죽 갑옷"},
    {ARM_RING_MAIL,             "고리 갑옷"},
    {ARM_SCALE_MAIL,            "미늘 갑옷"},
    {ARM_CHAIN_MAIL,            "사슬 갑옷"},
    {ARM_PLATE_ARMOUR,          "판금 갑옷"},
    {ARM_CRYSTAL_PLATE_ARMOUR,  "수정 판금 갑옷"},
    {ARM_CLOAK,                 "망토"},
    {ARM_SCARF,                 "스카프"},
    {ARM_HAT,                   "모자"},
    {ARM_HELMET,                "투구"},
    {ARM_GLOVES,                "장갑"},
    {ARM_BOOTS,                 "신발"},

    {ARM_BUCKLER,               "버클러"},
    {ARM_SHIELD,                "방패"},
    {ARM_LARGE_SHIELD,          "대형 방패"},

    {ARM_ANIMAL_SKIN,           "동물 가죽"},
    {ARM_TROLL_LEATHER_ARMOUR,  "트롤 가죽 갑옷"},

    {ARM_FIRE_DRAGON_ARMOUR,    "화염 용 비늘"},
    {ARM_ICE_DRAGON_ARMOUR,     "얼음 용 비늘"},
    {ARM_STEAM_DRAGON_ARMOUR,   "증기 용 비늘"},
    {ARM_ACID_DRAGON_ARMOUR,    "산성 용 비늘"},
    {ARM_STORM_DRAGON_ARMOUR,   "천둥 용 비늘"},
    {ARM_GOLD_DRAGON_ARMOUR,    "황금 용 비늘"},
    {ARM_SWAMP_DRAGON_ARMOUR,   "늪지 용 비늘"},
    {ARM_PEARL_DRAGON_ARMOUR,   "진주 용 비늘"},
    {ARM_SHADOW_DRAGON_ARMOUR,  "그림자 용 비늘"},
    {ARM_QUICKSILVER_DRAGON_ARMOUR, "수은 용 비늘"},

    {ARM_CENTAUR_BARDING,       "센타우르 마갑"},
    {ARM_NAGA_BARDING,          "나가 꼬리갑옷"},
};

map<int, string> Wand_name = 
{
    {WAND_FLAME,                "불꽃"},
    {WAND_PARALYSIS,            "마비"},
    {WAND_CONFUSION,            "혼란"},
    {WAND_DIGGING,              "굴착"},
    {WAND_ICEBLAST,             "얼음 폭발"},
    {WAND_LIGHTNING,            "번개"},
    {WAND_POLYMORPH,            "변이"},
    {WAND_ENSLAVEMENT,          "노예화"},
    {WAND_ACID,                 "산성"},
    {WAND_RANDOM_EFFECTS,       "무작위 효과"},
    {WAND_DISINTEGRATION,       "분해"},
    {WAND_CLOUDS,               "구름"},
    {WAND_SCATTERSHOT,          "산탄"},
};

// might be useless
static map<int, string> Food_name =
{
    {FOOD_MEAT_RATION,          "고기 식량"},
    {FOOD_BREAD_RATION,         "빵 식량"},
    {FOOD_ROYAL_JELLY,          "로얄 젤리"},
    {FOOD_FRUIT,                "과일"},
    {FOOD_CHUNK,                "고깃덩이"},
};


 map<int, string> Scroll_name =
{
    {SCR_IDENTIFY,              "식별"},
    {SCR_TELEPORTATION,         "공간이동"},
    {SCR_FEAR,                  "공포"},
    {SCR_NOISE,                 "소음"},
    {SCR_REMOVE_CURSE,          "저주 해제"},
    {SCR_SUMMONING,             "소환"},
    {SCR_ENCHANT_WEAPON,        "무기 강화"},
    {SCR_ENCHANT_ARMOUR,        "방어구 강화"},
    {SCR_TORMENT,               "고문"},
    {SCR_RANDOM_USELESSNESS,    "쓸모없는 무작위"},
    {SCR_IMMOLATION,            "발화"},
    {SCR_BLINKING,              "순간이동"},
    {SCR_MAGIC_MAPPING,         "마법적 탐색"},
    {SCR_FOG,                   "안개"},
    {SCR_ACQUIREMENT,           "획득"},
    {SCR_BRAND_WEAPON,          "무기 속성 부여"},
    {SCR_RECHARGING,            "충전"},
    {SCR_HOLY_WORD,             "신성한 언어"},
    {SCR_VULNERABILITY,         "취약"},
    {SCR_SILENCE,               "침묵"},
    {SCR_AMNESIA,               "망각"},
};

map<int, string> Jewellery_name =
{
    {RING_PROTECTION,           "보호"},
    {RING_PROTECTION_FROM_FIRE, "화염 저항"},
    {RING_POISON_RESISTANCE,    "독 저항"},
    {RING_PROTECTION_FROM_COLD, "냉기 저항"},
    {RING_STRENGTH,             "힘"},
    {RING_SLAYING,              "살육"},
    {RING_SEE_INVISIBLE,        "투명 보기"},
    {RING_RESIST_CORROSION,     "산성 저항"},
    {RING_LOUDNESS,             "소음"},
    {RING_TELEPORTATION,        "공간이동"},
    {RING_EVASION,              "회피"},
    {RING_STEALTH,              "은신"},
    {RING_DEXTERITY,            "민첩"},
    {RING_INTELLIGENCE,         "지능"},
    {RING_WIZARDRY,             "마법사"},
    {RING_MAGICAL_POWER,        "마력"},
    {RING_FLIGHT,               "비행"},
    {RING_LIFE_PROTECTION,      "양 에너지"},
    {RING_PROTECTION_FROM_MAGIC, "마법 저항"},
    {RING_FIRE,                 "화염"},
    {RING_ICE,                  "얼음"},
	{RING_WILD,                 "야생"},

    {AMU_RAGE,                  "격노"},
    {AMU_HARM,                  "아픔"},
    {AMU_MANA_REGENERATION,     "마법 재생"},
    {AMU_THE_GOURMAND,          "대식가"},
    {AMU_INACCURACY,            "부정확"},
    {AMU_NOTHING,               "공백"},
    {AMU_GUARDIAN_SPIRIT,       "수호령"},
    {AMU_FAITH,                 "신앙"},
    {AMU_REFLECTION,            "반사"},
    {AMU_REGENERATION,          "재생"},
};


map<int, string> Potion_name =
{
    {POT_CURING,                "치료"},
    {POT_HEAL_WOUNDS,           "상처 치유"},
    {POT_HASTE,                 "가속"},
    {POT_MIGHT,                 "힘"},
    {POT_BRILLIANCE,            "총명함"},
    {POT_AGILITY,               "날쌤"},
    {POT_FLIGHT,                "비행"},
    {POT_CANCELLATION,          "취소"},
    {POT_AMBROSIA,              "암브로시아"},
    {POT_INVISIBILITY,          "투명"},
    {POT_DEGENERATION,          "약화"},
    {POT_EXPERIENCE,            "경험"},
    {POT_MAGIC,                 "마력"},
    {POT_BERSERK_RAGE,          "광폭화"},
    {POT_MUTATION,              "변이"},
    {POT_RESISTANCE,            "저항"},
    {POT_BLOOD,                 "피"},
    {POT_LIGNIFY,               "수목화"},
};

map<int, string> Book_name =
{
    {BOOK_MINOR_MAGIC,          "하급 마법"},
    {BOOK_CONJURATIONS,         "파괴술"},
    {BOOK_FLAMES,               "불꽃"},
    {BOOK_FROST,                "서리"},
    {BOOK_SUMMONINGS,           "소환술"},
    {BOOK_FIRE,                 "화염"},
    {BOOK_ICE,                  "얼음"},
    {BOOK_SPATIAL_TRANSLOCATIONS, "공간 전이"},
    {BOOK_ENCHANTMENTS,         "주술"},
    {BOOK_YOUNG_POISONERS,      "초보 독술사 입문서"},
    {BOOK_TEMPESTS,             "폭풍"},
    {BOOK_DEATH,                "죽음"},
    {BOOK_MISFORTUNE,           "불운"},
    {BOOK_CHANGES,              "변화"},
    {BOOK_TRANSFIGURATIONS,     "변신"},
    {BOOK_FEN,                  "펜 폴리오"},
    {BOOK_BATTLE,               "전투"},
    {BOOK_CLOUDS,               "구름"},
    {BOOK_NECROMANCY,           "강령술"},
    {BOOK_CALLINGS,             "부름"},
    {BOOK_MALEDICT,             "저주"},
    {BOOK_AIR,                  "대기"},
    {BOOK_SKY,                  "하늘"},
    {BOOK_WARP,                 "왜곡"},
    {BOOK_UNLIFE,               "불생"},
    {BOOK_GEOMANCY,             "흙점술"},
    {BOOK_EARTH,                "대지"},
    {BOOK_POWER,                "힘"},
    {BOOK_CANTRIPS,             "장난"},
    {BOOK_PARTY_TRICKS,         "파티용 마술"},
    {BOOK_DEBILITATION,         "약화"},
    {BOOK_DRAGON,               "용"},
    {BOOK_BURGLARY,             "도둑질"},
    {BOOK_DREAMS,               "꿈"},
    {BOOK_ALCHEMY,              "연금술"},
    {BOOK_BEASTS,               "짐승"},
    {BOOK_ANNIHILATIONS,        "섬멸"},
    {BOOK_GRAND_GRIMOIRE,       "대 마도서"},
    {BOOK_NECRONOMICON,         "네크로노미콘"},
    {BOOK_MANUAL,               "설명서"}
};

map<int, string> Staff_name =
{
    {STAFF_WIZARDRY,            "마법사"},
    {STAFF_POWER,               "힘"},
    {STAFF_FIRE,                "화염"},
    {STAFF_COLD,                "냉기"},
    {STAFF_POISON,              "독"},
    {STAFF_ENERGY,              "에너지"},
    {STAFF_DEATH,               "죽음"},
    {STAFF_CONJURATION,         "파괴"},
    {STAFF_SUMMONING,           "소환"},
    {STAFF_AIR,                 "대기"},
    {STAFF_EARTH,               "대지"},
};

map<int, string> Miscellany_name = 
{
    {MISC_FAN_OF_GALES,         "질풍의 부채"},
    {MISC_LAMP_OF_FIRE,         "화염의 램프"},
    {MISC_HORN_OF_GERYON,       "게리욘의 뿔"},
    {MISC_BOX_OF_BEASTS,        "짐승상자"},
    {MISC_CRYSTAL_BALL_OF_ENERGY, "에너지 수정구"},
    {MISC_LIGHTNING_ROD,        "번개 마법막대"},

    {MISC_DECK_OF_ESCAPE,       "탈출"},
    {MISC_DECK_OF_DESTRUCTION,  "파괴"},
    {MISC_DECK_OF_SUMMONING,    "소환"},
    {MISC_DECK_OF_PUNISHMENT,   "징벌"},

    {MISC_QUAD_DAMAGE,          "대미지 4배"},

    {MISC_PHIAL_OF_FLOODS,      "홍수의 물병"},
    {MISC_SACK_OF_SPIDERS,      "거미 주머니"},
    {MISC_ZIGGURAT,             "지구라트 모형"},

    {MISC_PHANTOM_MIRROR,       "환영 거울"},
};

map<int, string> Rune_name =
{
    {RUNE_SWAMP,                "부패"},
    {RUNE_SNAKE,                "뱀무늬"}, // serpentine은 사문석 인듯
    {RUNE_SHOALS,               "따개비"},
    {RUNE_SLIME,                "끈적끈적한"},
    {RUNE_ELF,                  "엘프"},
    {RUNE_VAULTS,               "은"},
    {RUNE_TOMB,                 "황금"},
    {RUNE_DIS,                  "강철"},
    {RUNE_GEHENNA,              "흑요석"},
    {RUNE_COCYTUS,              "차가운"},
    {RUNE_TARTARUS,             "뼈"},
    {RUNE_ABYSSAL,              "심연"},
    {RUNE_DEMONIC,              "악마"},
    {RUNE_MNOLEG,               "빛나는"},
    {RUNE_LOM_LOBON,            "마법의"},
    {RUNE_CEREBOV,              "이글거리는"},
    {RUNE_GLOORX_VLOQ,          "어둠의"},
    {RUNE_SPIDER,               "거미줄"},
    {RUNE_FOREST,               "숲"},
};


