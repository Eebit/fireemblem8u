#pragma once

enum song_idx {
    SONG_NONE = 0x00,
    SONG_THE_VALIANT = 0x01,
    SONG_MAIN_THEME_EXT = 0x02,
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
    SONG_GRASP_AT_VICTORY = 0x10,
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
    SONG_MAIN_THEME = 0x43,
    SONG_LYON_ORGAN_ARRANGEMENT = 0x44,
    SONG_THE_FINAL_BATTLE = 0x45,    
    SONG_EPILOGUE = 0x46,
    SONG_47 = 0x47, 
    SONG_49 = 0x49, 
    SONG_4A = 0x4A, 
    SONG_4B = 0x4B, 
    SONG_4C = 0x4C, 
    SONG_4D = 0x4D, 
    SONG_4E = 0x4E, 
    SONG_52 = 0x52, 
    SONG_53 = 0x53, 
    SONG_54 = 0x54, 
    SONG_55 = 0x55, 
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
    SONG_6D = 0x6D,
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
    SONG_7C = 0x7C,
    SONG_7D = 0x7D,
    SONG_7E = 0x7E,
    SONG_SE_POINT_UP = 0x80,
    SONG_81 = 0x81,
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
    SONG_8E = 0x8E,
    SONG_8F = 0x8F,
    SONG_90 = 0x90,
    SONG_91 = 0x91,
    SONG_95 = 0x95, 
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
    SONG_SE_MONEY = 0xB9,
    SONG_BA = 0xBA,
    SONG_BB = 0xBB,
    SONG_BC = 0xBC,
    SONG_BD = 0xBD, // chapter 14x timed map change sound A
    SONG_BE = 0xBE, // chapter 14x timed map change sound B
    SONG_BF = 0xBF,
    SONG_C4 = 0xC4,
    SONG_C6 = 0xC6,
    SONG_C8 = 0xC8, // stat screen unit slide, also miss
    SONG_C9 = 0xC9,
    SONG_CA = 0xCA,
    SONG_CB = 0xCB,
    SONG_CD = 0xCD,
    SONG_CE = 0xCE,
    SONG_CF = 0xCF,
    SONG_D1 = 0xD1,
    SONG_D2 = 0xD2,
    SONG_D3 = 0xD3,
    SONG_D4 = 0xD4,
    SONG_D5 = 0xD5,
    SONG_D6 = 0xD6,
    SONG_D7 = 0xD7,
    SONG_D8 = 0xD8, // crit?
    SONG_DC = 0xDC,
    SONG_DD = 0xDD,
    SONG_DE = 0xDE,
    SONG_E7 = 0xE7,
    SONG_EA = 0xEA,
    SONG_EB = 0xEB,
    SONG_EC = 0xEC, // no damage
    SONG_ED = 0xED,
    SONG_F1 = 0xF1,
    SONG_F6 = 0xF6,
    SONG_FD = 0xFD, // manim
    SONG_10F = 0x10F,
    SONG_117 = 0x117,
    SONG_134 = 0x134,
    SONG_135 = 0x135,
    SONG_136 = 0x136,
    SONG_13F = 0x13F,
    SONG_140 = 0x140,
    SONG_141 = 0x141,
    SONG_142 = 0x142,
    SONG_14A = 0x14A,
    SONG_154 = 0x154,
    SONG_15E = 0x15E,
    SONG_168 = 0x168,
    SONG_172 = 0x172,
    SONG_17C = 0x17C,
    SONG_186 = 0x186,
    SONG_190 = 0x190,
    SONG_192 = 0x192,
    SONG_194 = 0x194,
    SONG_1AE = 0x1AE,
    SONG_1B1 = 0x1B1,
    SONG_1B2 = 0x1B2,
    SONG_1CC = 0x1CC,
    SONG_1CE = 0x1CE,
    SONG_1D0 = 0x1D0,
    SONG_1EA = 0x1EA,
    SONG_1EC = 0x1EC,
    SONG_1EE = 0x1EE,
    SONG_208 = 0x208,
    SONG_20A = 0x20A,
    SONG_20C = 0x20C,
    SONG_226 = 0x226,
    SONG_228 = 0x228,
    SONG_22A = 0x22A,
    SONG_244 = 0x244,
    SONG_246 = 0x246,
    SONG_248 = 0x248,
    SONG_262 = 0x262,
    SONG_263 = 0x263,
    SONG_265 = 0x265,
    SONG_267 = 0x267,
    SONG_269 = 0x269,
    SONG_26A = 0x26A,
    SONG_2CD = 0x2CD,
    SONG_2CE = 0x2CE,
    SONG_2CF = 0x2CF,
    SONG_2D0 = 0x2D0,
    SONG_2D1 = 0x2D1,
    SONG_2D2 = 0x2D2,
    SONG_2D3 = 0x2D3,
    SONG_2D4 = 0x2D4,
    SONG_2D5 = 0x2D5,
    SONG_SE_SHATTER_STONE = 0x2D6,
    SONG_2D7 = 0x2D7,
    SONG_2D8 = 0x2D8,
    SONG_2D9 = 0x2D9,
    SONG_2DD = 0x2DD,
    SONG_2DE = 0x2DE,
    SONG_2DF = 0x2DF,
    SONG_2E0 = 0x2E0,
    SONG_2E4 = 0x2E4,
    SONG_2E5 = 0x2E5,
    SONG_2E6 = 0x2E6,
    SONG_2E7 = 0x2E7,
    SONG_2E8 = 0x2E8,
    SONG_2EB = 0x2EB,
    SONG_2F7 = 0x2F7,
    SONG_2F8 = 0x2F8,
    SONG_2F9 = 0x2F9,
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
    SONG_310 = 0x310,
    SONG_311 = 0x311,
    SONG_312 = 0x312,
    SONG_313 = 0x313,
    SONG_314 = 0x314,
    SONG_316 = 0x316,
    SONG_317 = 0x317,
    SONG_320 = 0x320,
    SONG_321 = 0x321,
    SONG_322 = 0x322,
    SONG_325 = 0x325,
    SONG_326 = 0x326,
    SONG_327 = 0x327,
    SONG_329 = 0x329,
    SONG_32A = 0x32A,
    SONG_32B = 0x32B,
    SONG_32C = 0x32C,
    SONG_32E = 0x32E,
    SONG_32F = 0x32F,
    SONG_330 = 0x330,
    SONG_331 = 0x331,
    SONG_332 = 0x332,
    SONG_334 = 0x334,
    SONG_336 = 0x336,
    SONG_33A = 0x33a,
    SONG_33E = 0x33e,
    SONG_338 = 0x338,
    SONG_340 = 0x340,
    SONG_342 = 0x342,
    SONG_344 = 0x344,
    SONG_348 = 0x348,
    SONG_34A = 0x34a,
    SONG_34C = 0x34c,
    SONG_34E = 0x34e,
    SONG_352 = 0x352,
    SONG_354 = 0x354,
    SONG_356 = 0x356,
    SONG_358 = 0x358,
    SONG_35C = 0x35c,
    SONG_35E = 0x35e,
    SONG_360 = 0x360,
    SONG_362 = 0x362,
    SONG_366 = 0x366,
    SONG_368 = 0x368,
    SONG_36A = 0x36a,
    SONG_36C = 0x36c,
    SONG_370 = 0x370,
    SONG_372 = 0x372,
    SONG_374 = 0x374,
    SONG_376 = 0x376,
    SONG_37A = 0x37A,
    SONG_37B = 0x37B,
    SONG_37C = 0x37C,
    SONG_37D = 0x37D,
    SONG_37F = 0x37F,
    SONG_384 = 0x384,
    SONG_3B7 = 0x3B7,
    SONG_3BA = 0x3BA,
    SONG_3BB = 0x3BB,
    SONG_3BF = 0x3BF,
    SONG_3C0 = 0x3C0,
    SONG_3C2 = 0x3C2,
    SONG_3C3 = 0x3C3,
    SONG_3C4 = 0x3C4,
    SONG_3CA = 0x3CA,
    SONG_3CF = 0x3CF,
    SONG_SILENT = 0x7fff, 
};
