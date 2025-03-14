#pragma once

enum song_idx {
    SONG_THE_VALIANT = 0x01,
    SONG_MAIN_THEME = 0x02,
    SONG_PROLOGUE = 0x03,
    SONG_THE_BEGINNING = 0x004,
    SONG_TREASURED_MEMORIES = 0x005,
    SONG_GRIM_JOURNEY = 0x006,
    SONG_TIES_OF_FRIENDSHIP = 0x007,
    SONG_RAY_OF_HOPE = 0x008,
    SONG_DISTANT_ROADS = 0x09,
    SONG_RISE_ABOVE = 0x0A,
    SONG_FOLLOW_ME = 0x0B,
    SONG_DETERMINATION = 0x0C,
    SONG_TRUTH_DESPAIR_AND_HOPE = 0x0D,
    SONG_LAND_OF_PROMISE = 0x0E,
    SONG_BINDING_VOW = 0x0F,
    SONG_GRASP_AT_VICTORY = 0x010,
    SONG_SHADOWS_APPROACH = 0x11,
    SONG_CONFRONT_THE_PAST = 0x12,
    SONG_SHADOW_OF_THE_ENEMY = 0x13,
    SONG_ASSAULT = 0x14,
    SONG_FROM_THE_DARKNESS = 0x15,
    SONG_TWISTED_SHADOWS_A = 0x16,
    SONG_TWISTED_SHADOWS_B = 0x17,
    SONG_ENVOY_FROM_THE_DARK = 0x18,
    SONG_ATTACK	= 0x19,
    SONG_DEFENSE = 0x1A,
    SONG_THE_BATTLE_MUST_BE_WON	= 0x1B,
    SONG_POWERFUL_FOE =	0x1C,
    SONG_THE_PRINCES_DESPAIR =	0x1D,
    SONG_RETURN_OF_THE_DEMON_KING =	0x1E,
    SONG_SACRED_STRENGTH =	0x1F,
    SONG_TETHYS	=	0x20,
    SONG_HEALING =	0x21,
    SONG_CURING = 0x22,
    SONG_TO_A_HIGHER_PLACE = 0x23,
    SONG_ADVANCE = 0x24,
    SONG_TENSION = 0x25,
    SONG_RAID = 0x26,
    SONG_REUNION = 0x27,
    SONG_INDIGNATION = 0x28,
    SONG_SORROW = 0x29,
    SONG_LAUGHTER = 0x2A,
    SONG_LEGACY = 0x2B,
    SONG_LYON = 0x2C,
    SONG_LOST_HEART = 0x2D,
    SONG_SOLVE_THE_RIDDLE = 0x2E,
    SONG_LIGHTS_IN_THE_DARK = 0x2F,
    SONG_COMRADES = 0x30,
    SONG_VICTORY = 0x31,
    SONG_INTO_THE_SHADOW_OF_VICTORY = 0x32,
    SONG_MAIN_THEME_REPRISE = 0x33,
    SONG_COMBAT_PREPARATION = 0x34,
    SONG_SHOPS = 0x35,
    SONG_ARMORIES = 0x36,
    SONG_BONDS = 0x37,
    SONG_COLOSSEUM_ENTRANCE = 0x38,
    SONG_IN_THE_COLOSSEUM = 0x39,
    SONG_COLOSSEUM_VICTORY = 0x3A, 
    SONG_COLOSSEUM_DEFEAT = 0x3B,
    SONG_VICTORY_SONG_A = 0x3C,
    SONG_VICTORY_SONG_B = 0x3D,
    SONG_GAME_OVER = 0x3E,
    SONG_IN_SORROWS_SHROUD = 0x3F,
    SONG_RECORDS = 0x40,
    SONG_VICTORY_AND_THE_FUTURE = 0x41,
    SONG_FLY_WITH_THE_BREEZE = 0x42,
    SONG_43 = 0x43,
    SONG_LYON_ORGAN_ARRANGEMENT = 0x44,
    SONG_THE_FINAL_BATTLE = 0x45,
    
    SONG_EPILOGUE = 0x46,
    SONG_BGM_ED_STAFF_2 = 0x56,
    SONG_5A = 0x5A,
    SONG_5B = 0x5B,
    SONG_5C = 0x5C,
    SONG_60 = 0x60, // save success
    SONG_61 = 0x61,
    SONG_65 = 0x65,
    SONG_SE_SYS_CURSOR_UD1 = 0x66,
    SONG_SE_SYS_CURSOR_LR1 = 0x67, // change selection in menu/help box
    SONG_68 = 0x68,
    SONG_69 = 0x69,
    SONG_SE_SYS_WINDOW_SELECT1 = 0x6A,
    SONG_SE_SYS_WINDOW_CANSEL1 = 0x6B,
    SONG_6C = 0x6C,
    SONG_6E = 0x6E,
    SONG_6F = 0x6F, // stat screen page slide
    SONG_70 = 0x70, // help box open
    SONG_71 = 0x71, // help box close
    SONG_73 = 0x73,
    SONG_74 = 0x74, // exp bar thingy
    SONG_75 = 0x75,
    SONG_76 = 0x76,
    SONG_77 = 0x77,
    SONG_78 = 0x78, // open minimap
    SONG_79 = 0x79, // close minimap
    SONG_7A = 0x7A,
    SONG_7B = 0x7B, // sioerror
    SONG_82 = 0x82, // manim
    SONG_83 = 0x83, // manim
    SONG_84 = 0x84, // manim
    SONG_85 = 0x85, // manim
    SONG_86 = 0x86,
    SONG_87 = 0x87,
    SONG_88 = 0x88, // manim
    SONG_89 = 0x89,
    SONG_8A = 0x8A, // manim
    SONG_8B = 0x8B, // manim
    SONG_8C = 0x8C,
    SONG_8D = 0x8D, // manim (unlock?)
    SONG_90 = 0x90,
    SONG_91 = 0x91,
    SONG_96 = 0x96,
    SONG_97 = 0x97,
    SONG_9A = 0x9A,
    SONG_9B = 0x9B,
    SONG_9C = 0x9C,
    SONG_SE_BMP_MOVE_BIRD1A_T1 = 0xA0, // also map anim steal
    SONG_A4 = 0xA4,
    SONG_A5 = 0xA5,
    SONG_A6 = 0xA6,
    SONG_A8 = 0xA8, // dance sfx
    SONG_A9 = 0xA9, // play (bard) sfx
    SONG_AA = 0xAA,
    SONG_AB = 0xAB,
    SONG_AC = 0xAC,
    SONG_AF = 0xAF, // obstacle destroy (end)
    SONG_B0 = 0xB0, // obstacle destroy (mid)
    SONG_B1 = 0xB1,
    SONG_B3 = 0xB3,
    SONG_B4 = 0xB4, // manim
    SONG_B5 = 0xB5, // manim
    SONG_B6 = 0xB6,
    SONG_B7 = 0xB7, // manim poison
    SONG_BA = 0xBA,
    SONG_BB = 0xBB,
    SONG_BC = 0xBC,
    SONG_BD = 0xBD, // chapter 14x timed map change sound A
    SONG_BE = 0xBE, // chapter 14x timed map change sound B
    SONG_BF = 0xBF,
    SONG_C4 = 0xC4,
    SONG_C6 = 0xC6,
    SONG_C8 = 0xC8, // stat screen unit slide, also miss
    SONG_D2 = 0xD2,
    SONG_D5 = 0xD5,
    SONG_D6 = 0xD6,
    SONG_D8 = 0xD8, // crit?
    SONG_EC = 0xEC, // no damage
    SONG_FD = 0xFD, // manim
    SONG_10F = 0x10F,
    SONG_13F = 0x13F,
    SONG_140 = 0x140,
    SONG_141 = 0x141,
    SONG_269 = 0x269,
    SONG_26A = 0x26A,
    SONG_2E0 = 0x2E0,
    SONG_302 = 0x302,
    SONG_303 = 0x303,
    SONG_304 = 0x304,
    SONG_305 = 0x305,
    SONG_306 = 0x306,
    SONG_307 = 0x307,
    SONG_308 = 0x308,
    SONG_309 = 0x309,
    SONG_30A = 0x30A,
    SONG_30B = 0x30B,
    SONG_30C = 0x30C,
    SONG_30D = 0x30D,
    SONG_30E = 0x30E,
    SONG_30F = 0x30F,
    SONG_3BB = 0x3BB,
    SONG_3BF = 0x3BF,
};
