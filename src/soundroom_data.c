#include "global.h"

#include "soundroom.h"

#include "constants/songs.h"
#include "constants/msg.h"

struct SoundRoomEnt CONST_DATA gSoundRoomTable[] =
{
    {
        .bgmId = SONG_THE_VALIANT,
        .songLength = 2640,
        .displayCondFunc = NULL,
        .nameTextId = MSG_78B,
    },
    {
        .bgmId = SONG_MAIN_THEME_EXT,
        .songLength = 5880,
        .displayCondFunc = NULL,
        .nameTextId = MSG_78C,
    },
    {
        .bgmId = SONG_PROLOGUE,
        .songLength = 4140,
        .displayCondFunc = NULL,
        .nameTextId = MSG_78D,
    },
    {
        .bgmId = SONG_THE_BEGINNING,
        .songLength = 3720,
        .displayCondFunc = NULL,
        .nameTextId = MSG_78E,
    },
    {
        .bgmId = SONG_TREASURED_MEMORIES,
        .songLength = 4560,
        .displayCondFunc = NULL,
        .nameTextId = MSG_78F,
    },
    {
        .bgmId = SONG_GRIM_JOURNEY,
        .songLength = 4440,
        .displayCondFunc = NULL,
        .nameTextId = MSG_790,
    },
    {
        .bgmId = SONG_TIES_OF_FRIENDSHIP,
        .songLength = 3840,
        .displayCondFunc = NULL,
        .nameTextId = MSG_791,
    },
    {
        .bgmId = SONG_RAY_OF_HOPE,
        .songLength = 3900,
        .displayCondFunc = NULL,
        .nameTextId = MSG_792,
    },
    {
        .bgmId = SONG_DISTANT_ROADS,
        .songLength = 6420,
        .displayCondFunc = NULL,
        .nameTextId = MSG_793,
    },
    {
        .bgmId = SONG_RISE_ABOVE,
        .songLength = 5640,
        .displayCondFunc = NULL,
        .nameTextId = MSG_794,
    },
    {
        .bgmId = SONG_FOLLOW_ME,
        .songLength = 4980,
        .displayCondFunc = NULL,
        .nameTextId = MSG_795,
    },
    {
        .bgmId = SONG_DETERMINATION,
        .songLength = 4560,
        .displayCondFunc = NULL,
        .nameTextId = MSG_796,
    },
    {
        .bgmId = SONG_TRUTH_DESPAIR_AND_HOPE,
        .songLength = 5820,
        .displayCondFunc = NULL,
        .nameTextId = MSG_797,
    },
    {
        .bgmId = SONG_LAND_OF_PROMISE,
        .songLength = 4680,
        .displayCondFunc = NULL,
        .nameTextId = MSG_798,
    },
    {
        .bgmId = SONG_BINDING_VOW,
        .songLength = 3840,
        .displayCondFunc = NULL,
        .nameTextId = MSG_799,
    },
    {
        .bgmId = SONG_GRASP_AT_VICTORY,
        .songLength = 2460,
        .displayCondFunc = NULL,
        .nameTextId = MSG_79A,
    },
    {
        .bgmId = SONG_CONFRONT_THE_PAST,
        .songLength = 4980,
        .displayCondFunc = NULL,
        .nameTextId = MSG_79B,
    },
    {
        .bgmId = SONG_SHADOWS_APPROACH,
        .songLength = 5640,
        .displayCondFunc = NULL,
        .nameTextId = MSG_79C,
    },
    {
        .bgmId = SONG_SHADOW_OF_THE_ENEMY,
        .songLength = 2820,
        .displayCondFunc = NULL,
        .nameTextId = MSG_79D,
    },
    {
        .bgmId = SONG_ASSAULT,
        .songLength = 5100,
        .displayCondFunc = NULL,
        .nameTextId = MSG_79E,
    },
    {
        .bgmId = SONG_FROM_THE_DARKNESS,
        .songLength = 4380,
        .displayCondFunc = NULL,
        .nameTextId = MSG_79F,
    },
    {
        .bgmId = SONG_TWISTED_SHADOWS_A,
        .songLength = 4440,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7A0,
    },
    {
        .bgmId = SONG_TWISTED_SHADOWS_B,
        .songLength = 4440,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7A1,
    },
    {
        .bgmId = SONG_ENVOY_FROM_THE_DARK,
        .songLength = 4980,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7A2,
    },
    {
        .bgmId = SONG_ATTACK,
        .songLength = 1500,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7A3,
    },
    {
        .bgmId = SONG_DEFENSE,
        .songLength = 1680,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7A4,
    },
    {
        .bgmId = SONG_THE_BATTLE_MUST_BE_WON,
        .songLength = 1680,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7A5,
    },
    {
        .bgmId = SONG_POWERFUL_FOE,
        .songLength = 1440,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7A6,
    },
    {
        .bgmId = SONG_THE_PRINCES_DESPAIR,
        .songLength = 2040,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7A7,
    },
    {
        .bgmId = SONG_RETURN_OF_THE_DEMON_KING,
        .songLength = 3840,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7A8,
    },
    {
        .bgmId = SONG_SACRED_STRENGTH,
        .songLength = 660,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7A9,
    },
    {
        .bgmId = SONG_TETHYS,
        .songLength = 1440,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7AA,
    },
    {
        .bgmId = SONG_HEALING,
        .songLength = 840,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7AB,
    },
    {
        .bgmId = SONG_CURING,
        .songLength = 660,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7AC,
    },
    {
        .bgmId = SONG_TO_A_HIGHER_PLACE,
        .songLength = 1800,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7AD,
    },
    {
        .bgmId = SONG_ADVANCE,
        .songLength = 3180,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7AE,
    },
    {
        .bgmId = SONG_TENSION,
        .songLength = 2040,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7AF,
    },
    {
        .bgmId = SONG_RAID,
        .songLength = 2520,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7B0,
    },
    {
        .bgmId = SONG_REUNION,
        .songLength = 2700,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7B1,
    },
    {
        .bgmId = SONG_INDIGNATION,
        .songLength = 2940,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7B2,
    },
    {
        .bgmId = SONG_SORROW,
        .songLength = 3180,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7B3,
    },
    {
        .bgmId = SONG_LAUGHTER,
        .songLength = 2160,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7B4,
    },
    {
        .bgmId = SONG_LEGACY,
        .songLength = 4200,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7B5,
    },
    {
        .bgmId = SONG_LYON,
        .songLength = 2880,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7B6,
    },
    {
        .bgmId = SONG_LOST_HEART,
        .songLength = 3720,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7B7,
    },
    {
        .bgmId = SONG_LYON_ORGAN_ARRANGEMENT,
        .songLength = 3900,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7B8,
    },
    {
        .bgmId = SONG_THE_FINAL_BATTLE,
        .songLength = 2880,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7B9,
    },
    {
        .bgmId = SONG_SOLVE_THE_RIDDLE,
        .songLength = 3300,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7BA,
    },
    {
        .bgmId = SONG_LIGHTS_IN_THE_DARK,
        .songLength = 3420,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7BB,
    },
    {
        .bgmId = SONG_COMRADES,
        .songLength = 2160,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7BC,
    },
    {
        .bgmId = SONG_VICTORY,
        .songLength = 3120,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7BD,
    },
    {
        .bgmId = SONG_INTO_THE_SHADOW_OF_VICTORY,
        .songLength = 2220,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7BE,
    },
    {
        .bgmId = SONG_MAIN_THEME_REPRISE,
        .songLength = 3960,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7BF,
    },
    {
        .bgmId = SONG_COMBAT_PREPARATION,
        .songLength = 3960,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7C0,
    },
    {
        .bgmId = SONG_SHOPS,
        .songLength = 1260,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7C1,
    },
    {
        .bgmId = SONG_ARMORIES,
        .songLength = 1080,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7C2,
    },
    {
        .bgmId = SONG_BONDS,
        .songLength = 900,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7C3,
    },
    {
        .bgmId = SONG_COLOSSEUM_ENTRANCE,
        .songLength = 2520,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7C4,
    },
    {
        .bgmId = SONG_IN_THE_COLOSSEUM,
        .songLength = 1740,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7C5,
    },
    {
        .bgmId = SONG_COLOSSEUM_VICTORY,
        .songLength = 360,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7C6,
    },
    {
        .bgmId = SONG_COLOSSEUM_DEFEAT,
        .songLength = 1320,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7C7,
    },
    {
        .bgmId = SONG_VICTORY_SONG_A,
        .songLength = 420,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7C8,
    },
    {
        .bgmId = SONG_VICTORY_SONG_B,
        .songLength = 420,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7C9,
    },
    {
        .bgmId = SONG_GAME_OVER,
        .songLength = 2160,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7CA,
    },
    {
        .bgmId = SONG_IN_SORROWS_SHROUD,
        .songLength = 1620,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7CB,
    },
    {
        .bgmId = SONG_RECORDS,
        .songLength = 2760,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7CC,
    },
    {
        .bgmId = SONG_VICTORY_AND_THE_FUTURE,
        .songLength = 6240,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7CD,
    },
    {
        .bgmId = SONG_FLY_WITH_THE_BREEZE,
        .songLength = 9120,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7CE,
    },
    {
        .bgmId = SONG_EPILOGUE,
        .songLength = 9360,
        .displayCondFunc = NULL,
        .nameTextId = MSG_7CF,
    },
    {
        .bgmId = -1,
    },
};
