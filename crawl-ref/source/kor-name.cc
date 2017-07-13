/**
 * @file
 * @words translation
**/

#include "AppHdr.h"

#include "kor-name.h"

#include <cstring>

#include "art-enum.h"
#include "book-type.h"
#include "branch-type.h"
#include "item-prop-enum.h"
#include "job-type.h"
#include "libutil.h"
#include "potion-type.h"
#include "species-type.h"
#include "spell-type.h"
#include "object-class-type.h"

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
    {MI_JAVELIN,                "투창"},
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
    {AMU_HARM,                  "상해"},
    {AMU_MANA_REGENERATION,     "마나 재생"},
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
    {POT_AGILITY,               "기민"},
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
    {RUNE_SNAKE,                "뱀무늬"}, // serpentine
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

string item_korean_name(const item_def &item)
{
    return item_korean_name(item.base_type, item.sub_type);
}

string item_korean_name(object_class_type type, int sub_type)
{
    switch (type)
    {
    case OBJ_WEAPONS:
        return lookup(Weapon_name, sub_type, "");
    case OBJ_MISSILES:
        return lookup(Missile_name, sub_type, "");
    case OBJ_ARMOUR:
        return lookup(Armour_name, sub_type, "");
    case OBJ_WANDS:
        return lookup(Wand_name, sub_type, "");
    case OBJ_FOOD:
        return lookup(Food_name, sub_type, "");
    case OBJ_SCROLLS:
        return lookup(Scroll_name, sub_type, "");
    case OBJ_JEWELLERY:
        return lookup(Jewellery_name, sub_type, "");
    case OBJ_POTIONS:
        return lookup(Potion_name, sub_type, "");
    case OBJ_BOOKS:
        return lookup(Book_name, sub_type, "");
    case OBJ_STAVES:
        return lookup(Staff_name, sub_type, "");
    case OBJ_MISCELLANY:
        return lookup(Miscellany_name, sub_type, "");
    case OBJ_RUNES:
        return lookup(Rune_name, sub_type, "");

    default:
        return "";
    }
}

map<int, string> Unrand_name =
{
    {UNRAND_SINGING_SWORD,      "노래부르는 검"}, // Singing Sword
    {UNRAND_TROG,               "트로그의 분노"}, // Wrath of Trog
    {UNRAND_VARIABILITY,        "변덕의 메이스"}, // mace of Variability
    {UNRAND_PRUNE,              "자두의 글레이브"}, // glaive of Prune
    {UNRAND_POWER,              "힘의 검"}, // sword of Power
    {UNRAND_OLGREB,             "올그레브의 지팡이"}, // staff of Olgreb
    {UNRAND_WUCAD_MU,           "우카드 무의 지팡이"}, // staff of Wucad Mu
    {UNRAND_VAMPIRES_TOOTH,     "뱀파이어의 송곳니"}, // Vampire's Tooth
    {UNRAND_CURSES,             "저주의 낫"}, // scythe of Curses
    {UNRAND_TORMENT,            "고문의 셉터"}, // sceptre of Torment
    {UNRAND_ZONGULDROK,         "종굴드로크의 검"}, // sword of Zonguldrok
    {UNRAND_CEREBOV,            "세레보브의 검"}, // sword of Cerebov
    {UNRAND_DISPATER,           "디스파테르의 지팡이"}, // staff of Dispater
    {UNRAND_ASMODEUS,           "아스모데우스의 셉터"}, // sceptre of Asmodeus
    {UNRAND_FAERIE,             "요정 용 비늘"}, // faerie dragon scales
    {UNRAND_BLOODBANE,          "악마의 칼 \"핓빛 파멸\""}, // demon blade "Bloodbane"
    {UNRAND_FLAMING_DEATH,      "불타오르는 죽음의 시미터"}, // scimitar of Flaming Death
    {UNRAND_BRILLIANCE,         "이브닝스타 \"광채\""}, // eveningstar "Brilliance"
    {UNRAND_LEECH,              "악마의 칼 \"거머리\""}, // demon blade "Leech"
    {UNRAND_CHILLY_DEATH,       "싸늘한 죽음의 단도"}, // dagger of Chilly Death
    {UNRAND_MORG,               "단도 \"모르그\""}, // dagger "Morg"
    {UNRAND_FINISHER,           "낫 \"처형자\""}, // scythe "Finisher"
    {UNRAND_PUNK,               "투석구 \"펑크\""},  // sling "Punk"
    {UNRAND_ZEPHYR,             "장궁 \"산들바람\""}, // longbow "Zephyr"
    {UNRAND_SKULLCRUSHER,       "거대 몽둥이 \"두개골분쇄자\""}, // giant club "Skullcrusher"
    {UNRAND_GUARD,              "수호의 글레이브"}, // glaive of the Guard
    {UNRAND_ZEALOT_SWORD,       "광신도의 검"}, // zealot's sword
    {UNRAND_DAMNATION,          "아발레스트 \"업화\""}, // arbalest "Damnation"
    {UNRAND_DOOM_KNIGHT,        "파멸의 기사의 대검"}, // sword of the Doom Knight
    {UNRAND_EOS,                "모닝스타 \"에오스\""}, // morningstar "Eos"
    {UNRAND_BOTONO,             "보토노의 창"}, // spear of the Botono
    {UNRAND_OCTOPUS_KING,       "문어왕의 삼지창"}, // trident of the Octopus King
    {UNRAND_ARGA,               "미스릴 도끼 \"아르가\""}, // mithril axe "Arga"
    {UNRAND_ELEMENTAL_STAFF,    "원소의 지팡이"}, // Elemental Staff
    {UNRAND_SNIPER,             "중석궁 \"저격수\""}, // heavy crossbow "Sniper"
    {UNRAND_PIERCER,            "장궁 \"꽤뚫는 자\""}, // longbow "Piercer"
    {UNRAND_BLOWGUN_ASSASSIN,   "암살자의 바람총"}, // blowgun of the Assassin
    {UNRAND_WYRMBANE,           "창 \"용의 파멸\""}, // lance "Wyrmbane"
    {UNRAND_SPRIGGANS_KNIFE,    "스프리건의 나이프"}, // Spriggan's Knife
    {UNRAND_PLUTONIUM_SWORD,    "플루토늄 검"}, // plutonium sword
    {UNRAND_UNDEADHUNTER,       "대형 메이스 \"언데드 사냥꾼\""}, // great mace "Undeadhunter"
    {UNRAND_SNAKEBITE,          "채찍 \"사교상\""}, // whip "Snakebite"
    {UNRAND_ACCURACY,           "명중의 나이프"}, // knife of Accuracy
    {UNRAND_CRYSTAL_SPEAR,      "레후딥의 수정창"}, // Lehudib's crystal spear
    {UNRAND_CAPTAIN,            "두목의 커틀라스"}, // captain's cutlass
    {UNRAND_STORM_BOW,          "폭풍의 활"}, // storm bow
    {UNRAND_IGNORANCE,          "무지의 방패"}, // large shield of Ignorance
    {UNRAND_AUGMENTATION,       "증강의 로브"}, // robe of Augmentation
    {UNRAND_THIEF,              "도둑의 망토"}, // cloak of the Thief
    {UNRAND_BULLSEYE,           "대형 방패 \"황소눈\""}, // large shield "Bullseye"
    {UNRAND_DYROVEPREVA,        "다이로베프러버의 왕관"}, // crown of Dyrovepreva
    {UNRAND_BEAR_SPIRIT,        "곰 영혼의 모자"}, // hat of the Bear Spirit
    {UNRAND_MISFORTUNE,         "불운의 로브"}, // robe of Misfortune
    {UNRAND_FLASH,              "섬광의 망토"}, // cloak of Flash
    {UNRAND_BOOTS_ASSASSIN,     "암살자의 신발"}, // boots of the Assassin
    {UNRAND_LEAR,               "리어왕의 사슬갑옷"}, // Lear's hauberk
    {UNRAND_ZHOR,               "즈홀의 가죽"}, // skin of Zhor
    {UNRAND_SALAMANDER,         "살라맨더 가죽갑옷"}, // salamander hide armour
    {UNRAND_WAR,                "전쟁의 건틀릿"}, // gauntlets of War
    {UNRAND_RESISTANCE,         "저항의 방패"}, // shield of Resistance
    {UNRAND_FOLLY,              "우둔의 로브"}, // robe of Folly
    {UNRAND_MAXWELL,            "맥스웰의 특허 갑옷"}, // Maxwell's patent armour
    {UNRAND_DRAGONMASK,         "용의 가면"}, // mask of the Dragon
    {UNRAND_NIGHT,              "밤의 로브"}, // robe of Night
    {UNRAND_DRAGON_KING,        "용왕의 비늘"}, // scales of the Dragon King
    {UNRAND_ALCHEMIST,          "연금술사의 모자"}, // hat of the Alchemist
    {UNRAND_FENCERS,            "펜싱선수의 장갑"}, // fencer's gloves
    {UNRAND_STARLIGHT,          "별빛의 망토"}, // cloak of Starlight
    {UNRAND_RATSKIN_CLOAK,      "쥐가죽의 망토"}, // ratskin cloak
    {UNRAND_GONG,               "징 방패"}, // shield of the Gong
    {UNRAND_AIR,                "대기의 부적"}, // amulet of the Air
    {UNRAND_SHADOWS,            "그림자의 반지"}, // ring of Shadows
    {UNRAND_CEKUGOB,            "세쿠고브의 부적"}, // amulet of Cekugob
    {UNRAND_FOUR_WINDS,         "사방위 바람의 부적"}, // amulet of the Four Winds
    {UNRAND_BLOODLUST,          "피에 굶주린 목걸이"}, // necklace of Bloodlust
    {UNRAND_PHASING,            "위상의 반지"}, // ring of Phasing
    {UNRAND_ROBUSTNESS,         "강건의 반지"}, // ring of Robustness
    {UNRAND_MAGE,               "마도사의 반지"}, // ring of the Mage
    {UNRAND_SHIELDING,          "수호의 브로치"}, // brooch of Shielding
    {UNRAND_RCLOUDS,            "구름의 로브"}, // robe of Clouds
    {UNRAND_PONDERING,          "심사숙고의 모자"}, // hat of Pondering
    {UNRAND_DEMON_AXE,          "흑요석 도끼"}, // obsidian axe
    {UNRAND_LIGHTNING_SCALES,   "번개 비늘"}, // lightning scales
    {UNRAND_BLACK_KNIGHT_HORSE, "흑기사의 마갑"}, // Black Knight's horse barding
    {UNRAND_VITALITY,           "활력의 목걸이"}, // amulet of Vitality
    {UNRAND_AUTUMN_KATANA,      "가을의 카타나"}, // autumn katana
    {UNRAND_DEVASTATOR,         "슐레라 \"파괴자\""}, // shillelagh "Devastator"
    {UNRAND_DRAGONSKIN,         "용가죽 망토"}, // dragonskin cloak
    {UNRAND_OCTOPUS_KING_RING,  "문어왕의 반지"}, // ring of the Octopus King
    {UNRAND_WOE,                "비통의 도끼"}, // Axe of Woe
    {UNRAND_MOON_TROLL_LEATHER_ARMOUR, "문 트롤 가죽갑옷"}, // moon troll leather armour
    {UNRAND_FINGER_AMULET,      "섬뜩한 손가락 목걸이"}, // macabre finger necklace
    {UNRAND_SPIDER,             "거미의 신발"}, // boots of the spider
    {UNRAND_DARK_MAUL,          "다크 마울"}, // dark maul
    {UNRAND_HIGH_COUNCIL,       "최고의원회의 모자"}, // hat of the High Council
    {UNRAND_ARC_BLADE,          "아크 블레이드"}, // arc blade
    {UNRAND_SPELLBINDER,        "악마의 채찍 \"주문봉쇄자\""}, // demon whip "Spellbinder"
    {UNRAND_ORDER,              "질서의 라자탕"}, // lajatang of Order
    {UNRAND_FIRESTARTER,        "대형 메이스 \"방화범\""}, // great mace "Firestarter"
    {UNRAND_ORANGE_CRYSTAL_PLATE_ARMOUR, "오렌지색 수정 판금갑옷"}, // orange crystal plate armour
    {UNRAND_MAJIN,              "마인 보오"}, // Majin-Bo
    {UNRAND_GYRE,               "한 쌍의 퀵 블레이드 \"기르\" 와 \"김블\""}, // pair of quick blades "Gyre" and "Gimble"
    {UNRAND_ETHERIC_CAGE,       "맥스웰의 에테르 감옥"}, // Maxwell's etheric cage
    {UNRAND_ETERNAL_TORMENT,    "영원한 고통의 왕관"}, // crown of Eternal Torment
    {UNRAND_VINES,              "덩굴 로브"}, // robe of Vines
    {UNRAND_KRYIAS,             "크리야의 사슬 코트"}, // Kryia's mail coat
    {UNRAND_FROSTBITE,          "얼어붙은 도끼 \"동상\""}, // frozen axe "Frostbite"
    {UNRAND_TALOS,              "탈로스의 갑옷"}, // armour of Talos
    {UNRAND_WARLOCK_MIRROR,     "워락의 거울"}, // warlock's mirror
    {UNRAND_INVISIBILITY,       "투명의 목걸이"}, // amulet of invisibility
    {UNRAND_THERMIC_ENGINE,     "맥스웰의 열 엔진"}, // Maxwell's thermic engine
};

map<int, string> Unrand_unid_name =
{
    {UNRAND_CEREBOV,            "구불구불한 대검"}, // great serpentine sword
    {UNRAND_DISPATER,           "황금 지팡이"}, // golden staff
    {UNRAND_ASMODEUS,           "루비 셉터"}, // ruby sceptre
    {UNRAND_DRAGONSKIN,         "유백색 비늘망토"}, // opalescent scaly cloak
};

string get_unrand_korean(int type, bool unid)
{
    string name;
    if (unid)
    {
        name = lookup(Unrand_unid_name, type, "");
        if (name != "")
            return name;
    }

    name = lookup(Unrand_name, type, "오류");
    return name;
}

map<int, const char*> Job_name =
{
    {JOB_FIGHTER,               "전사"},
    {JOB_WIZARD,                "마법사"},
    {JOB_GLADIATOR,             "검투사"},
    {JOB_NECROMANCER,           "강령술사"},
    {JOB_ASSASSIN,              "암살자"},
    {JOB_BERSERKER,             "광전사"},
    {JOB_HUNTER,                "사냥꾼"},
    {JOB_CONJURER,              "파괴술사"},
    {JOB_ENCHANTER,             "주술사"},
    {JOB_FIRE_ELEMENTALIST,     "화염술사"},
    {JOB_ICE_ELEMENTALIST,      "냉기술사"},
    {JOB_SUMMONER,              "소환사"},
    {JOB_AIR_ELEMENTALIST,      "대기술사"},
    {JOB_EARTH_ELEMENTALIST,    "대지술사"},
    {JOB_SKALD,                 "음유시인"},
    {JOB_VENOM_MAGE,            "독술사"},
    {JOB_CHAOS_KNIGHT,          "혼돈의 기사"},
    {JOB_TRANSMUTER,            "변이술사"},
    {JOB_MONK,                  "수도사"},
    {JOB_WARPER,                "전이술사"},
    {JOB_WANDERER,              "방랑자"},
    {JOB_ARTIFICER,             "발동술사"},
    {JOB_ARCANE_MARKSMAN,       "마법궁수"},
    {JOB_ABYSSAL_KNIGHT,        "심연의 기사"},
};

const char* job_korean_name(int type)
{
    return lookup(Job_name, type, "무직");
}

map<int, string> Branch_long_name =
{
    {BRANCH_DUNGEON,            "던전"},
    {BRANCH_TEMPLE,             "만신전"},
    {BRANCH_ORC,                "오크 광산"},
    {BRANCH_ELF,                "엘프의 방"},
    {BRANCH_LAIR,               "짐승굴"},
    {BRANCH_SWAMP,              "늪지"},
    {BRANCH_SHOALS,             "해안가"},
    {BRANCH_SNAKE,              "뱀 구덩이"},
    {BRANCH_SPIDER,             "거미의 둥지"},
    {BRANCH_SLIME,              "점액질 구덩이"},
    {BRANCH_VAULTS,             "금고"},
    {BRANCH_CRYPT,              "지하 묘지"},
    {BRANCH_TOMB,               "무덤"},
    {BRANCH_DEPTHS,             "심층부"},
    {BRANCH_VESTIBULE,          "지옥의 현관"},
    {BRANCH_DIS,                "디스의 강철도시"},
    {BRANCH_GEHENNA,            "게헨나"},
    {BRANCH_COCYTUS,            "코퀴투스"},
    {BRANCH_TARTARUS,           "타르타로스"},
    {BRANCH_ZOT,                "조트의 영역"},
    {BRANCH_ABYSS,              "어비스"},
    {BRANCH_PANDEMONIUM,        "판데모니움"},
    {BRANCH_ZIGGURAT,           "지구라트"},
    {BRANCH_LABYRINTH,          "미궁"},
    {BRANCH_BAZAAR,             "벼룩시장"},
    {BRANCH_TROVE,              "보물 창고"},
    {BRANCH_SEWER,              "하수구"},
    {BRANCH_OSSUARY,            "납골당"},
    {BRANCH_BAILEY,             "성채"},
    {BRANCH_ICE_CAVE,           "얼음 동굴"},
    {BRANCH_VOLCANO,            "화산"},
    {BRANCH_WIZLAB,             "마법사의 연구소"},
    {BRANCH_DESOLATION,         "소금의 황무지"},
};

map<int, string> Branch_short_name =
{
    {BRANCH_DUNGEON,            "던전"},
    {BRANCH_TEMPLE,             "만신전"},
    {BRANCH_ORC,                "오크"},
    {BRANCH_ELF,                "엘프"},
    {BRANCH_LAIR,               "짐승굴"},
    {BRANCH_SWAMP,              "늪지"},
    {BRANCH_SHOALS,             "해안가"},
    {BRANCH_SNAKE,              "뱀"},
    {BRANCH_SPIDER,             "거미"},
    {BRANCH_SLIME,              "슬라임"},
    {BRANCH_VAULTS,             "금고"},
    {BRANCH_CRYPT,              "지하 묘지"},
    {BRANCH_TOMB,               "무덤"},
    {BRANCH_DEPTHS,             "심층부"},
    {BRANCH_VESTIBULE,          "지옥"},
    {BRANCH_DIS,                "디스"},
    {BRANCH_GEHENNA,            "게헨나"},
    {BRANCH_COCYTUS,            "코퀴투스"},
    {BRANCH_TARTARUS,           "타르타로스"},
    {BRANCH_ZOT,                "조트"},
    {BRANCH_ABYSS,              "어비스"},
    {BRANCH_PANDEMONIUM,        "판데모니움"},
    {BRANCH_ZIGGURAT,           "지구라트"},
    {BRANCH_LABYRINTH,          "미궁"},
    {BRANCH_BAZAAR,             "벼룩시장"},
    {BRANCH_TROVE,              "보물 창고"},
    {BRANCH_SEWER,              "하수구"},
    {BRANCH_OSSUARY,            "납골당"},
    {BRANCH_BAILEY,             "성채"},
    {BRANCH_ICE_CAVE,           "얼음"},
    {BRANCH_VOLCANO,            "화산"},
    {BRANCH_WIZLAB,             "연구소"},
    {BRANCH_DESOLATION,         "황무지"},
};

string branch_korean_name(int type, bool long_name)
{
    if (long_name)
        return lookup(Branch_long_name, type, "");
    else
        return lookup(Branch_short_name, type, "");
}

map<int, string> Species_name =
{
    {SP_HUMAN,                  "인간"},
    {SP_DEEP_ELF,               "딥 엘프"},
    {SP_HALFLING,               "하플링"},
    {SP_HILL_ORC,               "언덕 오크"},
    {SP_KOBOLD,                 "코볼트"},
    {SP_MUMMY,                  "머미"},
    {SP_NAGA,                   "나가"},
    {SP_OGRE,                   "오거"},
    {SP_TROLL,                  "트롤"},

    {SP_RED_DRACONIAN,          "붉은 드라코니언"},
    {SP_WHITE_DRACONIAN,        "흰 드라코니언"},
    {SP_GREEN_DRACONIAN,        "녹색 드라코니언"},
    {SP_YELLOW_DRACONIAN,       "노란 드라코니언"},
    {SP_GREY_DRACONIAN,         "회색 드라코니언"},
    {SP_BLACK_DRACONIAN,        "검은 드라코니언"},
    {SP_PURPLE_DRACONIAN,       "보라색 드라코니언"},
    {SP_PALE_DRACONIAN,         "창백한 드라코니언"},
    {SP_BASE_DRACONIAN,         "드라코니언"},

    {SP_CENTAUR,                "센타우르"},
    {SP_DEMIGOD,                "반신"},
    {SP_SPRIGGAN,               "스프리건"},
    {SP_MINOTAUR,               "미노타우르스"},
    {SP_DEMONSPAWN,             "데몬스폰"},
    {SP_GHOUL,                  "구울"},
    {SP_TENGU,                  "텐구"},
    {SP_MERFOLK,                "머포크"},
    {SP_VAMPIRE,                "뱀파이어"},
    {SP_DEEP_DWARF,             "딥 드워프"},
    {SP_FELID,                  "펠리드"},
    {SP_OCTOPODE,               "옥토포드"},
    {SP_GARGOYLE,               "가고일"},
    {SP_FORMICID,               "포미시드"},
    {SP_VINE_STALKER,           "바인 스토커"},
    {SP_BARACHI,                "바라치"},
    {SP_GNOLL,                  "놀"},
};


string species_korean_name(int type)
{
    return lookup(Species_name, type, "");
}

map<int, const char*> Spell_name =
{
    {SPELL_TELEPORT_SELF,           "자가 공간이동"},
    {SPELL_CAUSE_FEAR,              "공포 유발"},
    {SPELL_MAGIC_DART,              "마법의 다트"},
    {SPELL_FIREBALL,                "화염구"},
    {SPELL_APPORTATION,             "수집"},
    {SPELL_CONJURE_FLAME,           "불기둥 생성"},
    {SPELL_DIG,                     "굴착"},
    {SPELL_BOLT_OF_FIRE,            "화염의 화살"},
    {SPELL_BOLT_OF_COLD,            "냉기의 화살"},
    {SPELL_LIGHTNING_BOLT,          "번개의 화살"},
    {SPELL_BOLT_OF_MAGMA,           "용암의 화살"},
    {SPELL_POLYMORPH,               "변이"},
    {SPELL_SLOW,                    "감속"},
    {SPELL_HASTE,                   "가속"},
    {SPELL_PARALYSE,                "마비"},
    {SPELL_CONFUSE,                 "혼란"},
    {SPELL_INVISIBILITY,            "투명화"},
    {SPELL_THROW_FLAME,             "화염 투척"},
    {SPELL_THROW_FROST,             "서릿발 투척"},
    {SPELL_CONTROLLED_BLINK,        "제어 순간이동"},
    {SPELL_FREEZING_CLOUD,          "냉기 구름"},
    {SPELL_MEPHITIC_CLOUD,          "악취 구름 "},
    {SPELL_RING_OF_FLAMES,          "화염의 고리"},
    {SPELL_VENOM_BOLT,              "맹독의 화살"},
    {SPELL_OLGREBS_TOXIC_RADIANCE,  "올그레브의 맹독성 휘광"},
    {SPELL_TELEPORT_OTHER,          "타인 공간이동"},
    {SPELL_MINOR_HEALING,           "하위 치유"},
    {SPELL_MAJOR_HEALING,           "고위 치유"},
    {SPELL_DEATHS_DOOR,             "죽음의 문턱"},
    {SPELL_MASS_CONFUSION,          "대규모 혼란"},
    {SPELL_SMITING,                 "강타"},
    {SPELL_SUMMON_SMALL_MAMMAL,     "소형 포유류 소환"},
    {SPELL_ABJURATION,              "송환"},
    {SPELL_BOLT_OF_DRAINING,        "흡성의 화살"},
    {SPELL_LEHUDIBS_CRYSTAL_SPEAR,  "레후딥의 수정창"},
    {SPELL_POISONOUS_CLOUD,         "독성 구름"},
    {SPELL_FIRE_STORM,              "화염 폭풍"},
    {SPELL_BLINK,                   "순간이동"},
    {SPELL_ISKENDERUNS_MYSTIC_BLAST, "이스켄데룬의 신비한 폭발"},
    {SPELL_SUMMON_HORRIBLE_THINGS,  "끔찍한 것 소환"},
    {SPELL_ENSLAVEMENT,             "예속"},
    {SPELL_ANIMATE_DEAD,            "송장 일으키기"},
    {SPELL_PAIN,                    "고통"},
    {SPELL_CONTROL_UNDEAD,          "언데드 제어"},
    {SPELL_ANIMATE_SKELETON,        "해골 일으키기"},
    {SPELL_VAMPIRIC_DRAINING,       "피의 흡수"},
    {SPELL_HAUNT,                   "유령 출몰"},
    {SPELL_BORGNJORS_REVIVIFICATION, "보르그뇨르의 소생"},
    {SPELL_FREEZE,                  "빙결"},
    {SPELL_OZOCUBUS_REFRIGERATION,  "오크조브의 냉각"},
    {SPELL_STICKY_FLAME,            "점착 화염"},
    {SPELL_SUMMON_ICE_BEAST,        "얼음 짐승 소환"},
    {SPELL_OZOCUBUS_ARMOUR,         "오조크브의 갑옷"},
    {SPELL_CALL_IMP,                "임프 소환"},
    {SPELL_REPEL_MISSILES,          "투사체 방어"},
    {SPELL_BERSERKER_RAGE,          "광전사의 분노"},
    {SPELL_DISPEL_UNDEAD,           "언데드 말살"},
    {SPELL_POISON_ARROW,            "독액의 화살"},
    {SPELL_TWISTED_RESURRECTION,    "뒤틀린 소생"},
    {SPELL_REGENERATION,            "재생"},
    {SPELL_BANISHMENT,              "추방"},
    {SPELL_STING,                   "독침"},
    {SPELL_SUBLIMATION_OF_BLOOD,    "피의 승화"},
    {SPELL_TUKIMAS_DANCE,           "투키마의 무도"},
    {SPELL_HURL_DAMNATION,          "업화 투척"},
    {SPELL_SUMMON_DEMON,            "악마 소환"},
    {SPELL_SUMMON_GREATER_DEMON,    "고위 악마 소환"},
    {SPELL_CORPSE_ROT,              "시체 부패"},
    {SPELL_IRON_SHOT,               "강철 탄환"},
    {SPELL_STONE_ARROW,             "암석의 화살"},
    {SPELL_SHOCK,                   "전격"},
    {SPELL_SWIFTNESS,               "신속"},
    {SPELL_DEBUGGING_RAY,           "디버그의 광선"},
    {SPELL_RECALL,                  "소집"},
    {SPELL_AGONY,                   "고문"},
    {SPELL_SPIDER_FORM,             "거미 변신"},
    {SPELL_DISINTEGRATE,            "해체"},
    {SPELL_BLADE_HANDS,             "칼날의 손"},
    {SPELL_STATUE_FORM,             "석상 변신"},
    {SPELL_ICE_FORM,                "얼음의 형상"},
    {SPELL_DRAGON_FORM,             "용의 형상"},
    {SPELL_HYDRA_FORM,              "히드라 변신"},
    {SPELL_IRRADIATE,               "오염"},
    {SPELL_NECROMUTATION,           "죽은 자의 형상"},
    {SPELL_DEATH_CHANNEL,           "죽음의 영매술"},
    {SPELL_SYMBOL_OF_TORMENT,       "고통의 문양"},
    {SPELL_DEFLECT_MISSILES,        "투사체 저지"},
    {SPELL_THROW_ICICLE,            "고드름 발사"},
    {SPELL_GLACIATE,                "동결"},
    {SPELL_AIRSTRIKE,               "선풍의 일격"},
    {SPELL_SHADOW_CREATURES,        "그림자 피조물"},
    {SPELL_CONFUSING_TOUCH,         "혼란의 일격"},
    {SPELL_FLAME_TONGUE,            "불꽃 줄기"},
    {SPELL_PASSWALL,                "벽 통과"},
    {SPELL_IGNITE_POISON,           "독의 연소"},
    {SPELL_STICKS_TO_SNAKES,        "막대를 뱀으로"},
    {SPELL_CALL_CANINE_FAMILIAR,    "개과 친우 소환"},
    {SPELL_SUMMON_DRAGON,           "용 소환"},
    {SPELL_HIBERNATION,             "동면"},
    {SPELL_ENGLACIATION,            "동결"},
    {SPELL_SUMMON_BUTTERFLIES,      "나비 소환"},
    {SPELL_SILENCE,                 "침묵"},
    {SPELL_SHATTER,                 "분쇄"},
    {SPELL_DISPERSAL,               "전송"},
    {SPELL_DISCHARGE,               "방전"},
    {SPELL_CORONA,                  "후광"},
    {SPELL_INTOXICATE,              "주연"},
    {SPELL_LRD,                     "리의 순간 해체술"},
    {SPELL_SANDBLAST,               "모래 폭풍"},
    {SPELL_SIMULACRUM,              "얼음의 환영"},
    {SPELL_CONJURE_BALL_LIGHTNING,  "번개의 구"},
    {SPELL_CHAIN_LIGHTNING,         "연쇄 번개"},
    {SPELL_EXCRUCIATING_WOUNDS,     "고통의 상처"},
    {SPELL_PORTAL_PROJECTILE,       "투사체 전이"},
    {SPELL_MONSTROUS_MENAGERIE,     "괴물의 서커스"},
    {SPELL_PETRIFY,                 "석화"},
    {SPELL_GOLUBRIAS_PASSAGE,       "골루브리아의 통로"},

    // Mostly monster-only spells after this point:
    {SPELL_CALL_DOWN_DAMNATION,     "업화 투하"},
    {SPELL_BRAIN_FEED,              "뇌 먹기"},
    {SPELL_STEAM_BALL,              "증기 덩어리"},
    {SPELL_SUMMON_UFETUBUS,         "우페터버스 소환"},
    {SPELL_SUMMON_HELL_BEAST,       "지옥 짐승 소환"},
    {SPELL_ENERGY_BOLT,             "에너지의 화살"},
    {SPELL_SPIT_POISON,             "독 뱉기"},
    {SPELL_SUMMON_UNDEAD,           "언데드 소환"},
    {SPELL_CANTRIP,                 "장난"},
    {SPELL_QUICKSILVER_BOLT,        "수은 화살"},
    {SPELL_METAL_SPLINTERS,         "금속 흩뿌리기"},
    {SPELL_MIASMA_BREATH,           "역병의 숨결"},
    {SPELL_SUMMON_DRAKES,           "드레이크 소환"},
    {SPELL_BLINK_OTHER,             "타인 순간이동"},
    {SPELL_SUMMON_MUSHROOMS,        "버섯 소환"},
    {SPELL_SPIT_ACID,               "산성 숨결"},
    {SPELL_ACID_SPLASH,             "산 분사"},
    {SPELL_FIRE_BREATH,             "화염 숨결"},
    {SPELL_COLD_BREATH,             "냉기 숨결"},
    {SPELL_WATER_ELEMENTALS,        "물의 정령 소환"},
    {SPELL_PORKALATOR,              "돼지 변신"},
    {SPELL_CREATE_TENTACLES,        "촉수 생성"},
    {SPELL_TOMB_OF_DOROKLOHE,       "도로클로헤의 무덤"},
    {SPELL_SUMMON_EYEBALLS,         "눈알 소환"},
    {SPELL_HASTE_OTHER,             "타인 가속"},
    {SPELL_FIRE_ELEMENTALS,         "불의 정령 소환"},
    {SPELL_EARTH_ELEMENTALS,        "땅의 정령 소환"},
    {SPELL_AIR_ELEMENTALS,          "공기의 정령 소환"},
    {SPELL_SLEEP,                   "수면"},
    {SPELL_BLINK_OTHER_CLOSE,       "타인 근접 순간이동"},
    {SPELL_BLINK_CLOSE,             "근접 순간이동"},
    {SPELL_BLINK_RANGE,             "원거리 순간이동"},
    {SPELL_BLINK_AWAY,              "탈출 순간이동"},
    {SPELL_FAKE_MARA_SUMMON,        "마라 소환"},
    {SPELL_SUMMON_ILLUSION,         "환상 소환"},
    {SPELL_PRIMAL_WAVE,             "태고의 파도"},
    {SPELL_CALL_TIDE,               "파도 부르기"},
    {SPELL_IOOD,                    "이스켄데룬의 파괴의 구체"},
    {SPELL_INK_CLOUD,               "먹물 분사"},
    {SPELL_MIGHT,                   "용력"},
    {SPELL_AWAKEN_FOREST,           "깨어난 숲"},
    {SPELL_DRUIDS_CALL,             "드루이드의 부름"},
    {SPELL_SUMMON_SPECTRAL_ORCS,    "오크 영체 소환"},
    {SPELL_SUMMON_HOLIES,           "천사 소환"},
    {SPELL_HEAL_OTHER,              "타인 치료"},
    {SPELL_HOLY_FLAMES,             "성스러운 불꽃"},
    {SPELL_HOLY_BREATH,             "신성한 숨결"},
    {SPELL_TROGS_HAND,              "트로그의 손길"},
    {SPELL_BROTHERS_IN_ARMS,        "전우"},
    {SPELL_INJURY_MIRROR,           "피해 반사"},
    {SPELL_DRAIN_LIFE,              "생명력 흡수"},
    {SPELL_MALIGN_GATEWAY,          "이계의 관문"},
    {SPELL_NOXIOUS_CLOUD,           "악취 구름"},
    {SPELL_TORNADO,                 "회오리"},
    {SPELL_STICKY_FLAME_RANGE,      "원거리 점착 화염"},
    {SPELL_LEDAS_LIQUEFACTION,      "레다의 용해술"},
    {SPELL_SUMMON_HYDRA,            "히드라 소환"},
    {SPELL_DARKNESS,                "어둠"},
    {SPELL_MESMERISE,               "매혹"},
    {SPELL_FIRE_SUMMON,             "화염 소환"},
    {SPELL_SHROUD_OF_GOLUBRIA,      "골루브리아의 장막"},
    {SPELL_INNER_FLAME,             "내면의 불꽃"},
    {SPELL_PETRIFYING_CLOUD,        "석화 구름"},
    {SPELL_AURA_OF_ABJURATION,      "송환의 오라"},
    {SPELL_BEASTLY_APPENDAGE,       "짐승적 부속지"},
    {SPELL_ENSNARE,                 "속박"},
    {SPELL_THUNDERBOLT,             "천둥번개"},
    {SPELL_SUMMON_MINOR_DEMON,      "하급 악마 소환"},
    {SPELL_DISJUNCTION,             "분리"},
    {SPELL_CHAOS_BREATH,            "혼돈의 숨결"},
    {SPELL_BATTLESPHERE,            "전투 구체"},
    {SPELL_FULMINANT_PRISM,         "폭발성 프리즘"},
    {SPELL_DAZZLING_SPRAY,          "눈부신 빛줄기"},
    {SPELL_FORCE_LANCE,             "힘의 창"},
    {SPELL_MALMUTATE,               "악성 변이"},
    {SPELL_MIGHT_OTHER,             "타인 용력"},
    {SPELL_SENTINEL_MARK,           "파수꾼의 징표"},
    {SPELL_WORD_OF_RECALL,          "소집의 언령"},
    {SPELL_INJURY_BOND,             "고통 분담"},
    {SPELL_SPECTRAL_CLOUD,          "영체 구름"},
    {SPELL_GHOSTLY_FIREBALL,        "유령 화염구"},
    {SPELL_CALL_LOST_SOUL,          "잃어버린 영혼 소환"},
    {SPELL_DIMENSION_ANCHOR,        "차원 닻"},
    {SPELL_BLINK_ALLIES_ENCIRCLE,   "아군 순간이동 포위"},
    {SPELL_AWAKEN_VINES,            "깨어난 덩굴"},
    {SPELL_THORN_VOLLEY,            "가시 사격"},
    {SPELL_WALL_OF_BRAMBLES,        "가시덤불 방벽"},
    {SPELL_WATERSTRIKE,             "물줄기 강타"},
    {SPELL_WIND_BLAST,              "바람 폭발"},
    {SPELL_STRIP_RESISTANCE,        "저항 벗기기"},
    {SPELL_INFUSION,                "주입"},
    {SPELL_SONG_OF_SLAYING,         "살육의 노래"},
    {SPELL_SPECTRAL_WEAPON,         "유령 무기"},
    {SPELL_SUMMON_VERMIN,           "해충 소환"},
    {SPELL_MALIGN_OFFERING,         "악의 제물"},
    {SPELL_SEARING_RAY,             "타오르는 광선"},
    {SPELL_DISCORD,                 "불협화음"},
    {SPELL_BLINKBOLT,               "순간이동의 화살"},
    {SPELL_INVISIBILITY_OTHER,      "타인 투명화"},
    {SPELL_VIRULENCE,               "극독"},
    {SPELL_ORB_OF_ELECTRICITY,      "전격의 구"},
    {SPELL_FLASH_FREEZE,            "순간 동결"},
    {SPELL_LEGENDARY_DESTRUCTION,   "전설적 파괴"},
    {SPELL_FORCEFUL_INVITATION,     "강제 초청"},
    {SPELL_PLANEREND,               "차원분열"},
    {SPELL_CHAIN_OF_CHAOS,          "혼돈의 사슬"},
    {SPELL_CALL_OF_CHAOS,           "혼돈의 부름"},
    {SPELL_BLACK_MARK,              "검은 표식"},
    {SPELL_SAP_MAGIC,               "마법 약화"},
    {SPELL_MAJOR_DESTRUCTION,       "대파괴"},
    {SPELL_BLINK_ALLIES_AWAY,       "아군 순간이동 후퇴"},
    {SPELL_SHADOW_SHARD,            "그림자 파편"},
    {SPELL_SHADOW_BOLT,             "그림자 화살"},
    {SPELL_CRYSTAL_BOLT,            "수정 화살"},
    {SPELL_SUMMON_FOREST,           "숲 소환"},
    {SPELL_SUMMON_LIGHTNING_SPIRE,  "번개 첨탑 소환"},
    {SPELL_SUMMON_GUARDIAN_GOLEM,   "골렘 수호자 소환"},
    {SPELL_RANDOM_BOLT,             "무작위의 화살"},
    {SPELL_CLOUD_CONE,              "구름 분사"},
    {SPELL_DRAGON_CALL,             "용의 부름"},
    {SPELL_SPELLFORGED_SERVITOR,    "주문연성 하인"},
    {SPELL_SUMMON_MANA_VIPER,       "마력독사 소환"},
    {SPELL_PHANTOM_MIRROR,          "악령 거울"},
    {SPELL_DRAIN_MAGIC,             "마법 흡수"},
    {SPELL_CORROSIVE_BOLT,          "부식성 화살"},
    {SPELL_SUMMON_EMPEROR_SCORPIONS, "황제 전갈 소환"},
    {SPELL_SPIT_LAVA,               "용암 뱉기"},
    {SPELL_ELECTRICAL_BOLT,         "전격 화살"},
    {SPELL_FLAMING_CLOUD,           "타오르는 구름"},
    {SPELL_THROW_BARBS,             "가시 투척"},
    {SPELL_BATTLECRY,               "전장의 함성"},
    {SPELL_WARNING_CRY,             "경고의 함성"},
    {SPELL_SEAL_DOORS,              "관문 봉쇄"},
    {SPELL_FLAY,                    "비행"},
    {SPELL_BERSERK_OTHER,           "타인 광폭화"},
    {SPELL_CORRUPTING_PULSE,        "타락의 파동"},
    {SPELL_SIREN_SONG,              "세이렌의 노래"},
    {SPELL_AVATAR_SONG,             "화신의 노래"},
    {SPELL_PARALYSIS_GAZE,          "마비의 응시"},
    {SPELL_CONFUSION_GAZE,          "혼란의 응시"},
    {SPELL_DRAINING_GAZE,           "흡수의 응시"},
    {SPELL_DEATH_RATTLE,            "죽음의 메아리"},
    {SPELL_SUMMON_SCARABS,          "풍뎅이 소환"},
    {SPELL_SEARING_BREATH,          "이글거리는 숨결"},
    {SPELL_CHILLING_BREATH,         "싸늘한 숨결"},
    {SPELL_SCATTERSHOT,             "산탄"},
    {SPELL_CLEANSING_FLAME,         "정화의 불꽃"},
    {SPELL_THROW_ALLY,              "아군 투척"},
    {SPELL_CIGOTUVIS_EMBRACE,       "시고투비의 포옹"},
    {SPELL_GRAVITAS,                "겔의 중력"},
    {SPELL_ENTROPIC_WEAVE,          "엔트로피 엮기"},
    {SPELL_SUMMON_EXECUTIONERS,     "처형자 소환"},
    {SPELL_VIOLENT_UNRAVELLING,     "야라의 폭력적 해제"},
    {SPELL_DOOM_HOWL,               "파멸의 울부짖음"},
    {SPELL_AWAKEN_EARTH,            "깨어난 대지"},
    {SPELL_AURA_OF_BRILLIANCE,      "총명의 오라"},
    {SPELL_ICEBLAST,                "얼음 폭발"},
    {SPELL_SLUG_DART,               "달팽이 다트"},
    {SPELL_SPRINT,                  "질주"},
    {SPELL_GREATER_SERVANT_MAKHLEB, "마크레브의 고위 종복 소환"},
    {SPELL_SERPENT_OF_HELL_GEH_BREATH, "게헨나의 마룡의 숨결"},
    {SPELL_SERPENT_OF_HELL_COC_BREATH, "코퀴토스의 마룡의 숨결"},
    {SPELL_SERPENT_OF_HELL_TAR_BREATH, "타르타로스의 마룡의 숨결"},
    {SPELL_SERPENT_OF_HELL_DIS_BREATH, "디스의 마룡의 숨결"},
    {SPELL_BIND_SOULS,              "영혼 속박"},
    {SPELL_INFESTATION,             "감염"},
    {SPELL_STILL_WINDS,             "바람 잠재우기"},
    {SPELL_RESONANCE_STRIKE,        "공명 타격"},
    {SPELL_GHOSTLY_SACRIFICE,       "섬뜩한 희생"},
    {SPELL_DREAM_DUST,              "꿈가루"},
    {SPELL_BECKONING,               "약한 부름"},
    {SPELL_UPHEAVAL,                "격변"},
    {SPELL_RANDOM_EFFECTS,          "무작위 효과"},
    {SPELL_POISONOUS_VAPOURS,       "독성 증기"},
    {SPELL_RING_OF_THUNDER,         "번개의 고리"},
    {SPELL_IGNITION,                "점화"},
};

const char* spell_korean_name(int type)
{
    return lookup(Spell_name, type, "");
}
