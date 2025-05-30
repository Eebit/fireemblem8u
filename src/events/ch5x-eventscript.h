#pragma once

#include "global.h"
#include "event.h"
#include "eventinfo.h"
#include "eventcall.h"
#include "eventscript.h"
#include "EAstdlib.h"
#include "constants/worldmap.h"
#include "constants/characters.h"
#include "constants/backgrounds.h"
#include "constants/songs.h"
#include "constants/chapters.h"

void HandleCh5xUnits_Start(void)
{
    int i;
    for (i = FACTION_BLUE + 1; i < FACTION_GREEN; i++) {
        struct Unit * unit = GetUnit(i);

        if (!UNIT_IS_VALID(unit))
            continue;

        switch (unit->pCharacterData->number) {
            case CHARACTER_EPHRAIM:
            case CHARACTER_FORDE:
            case CHARACTER_KYLE:
            case CHARACTER_ORSON_CH5X:
                continue;
        }
        if (US_BIT16 & unit->state)
            unit->state |= US_BIT26;

        unit->state |= US_BIT16 | US_HIDDEN;
    }
}

CONST_DATA EventListScr EventScr_Ch5x_BeginningScene[] = {
    ASMC(HandleCh5xUnits_Start)
    MUSC(SONG_SOLVE_THE_RIDDLE)
    SVAL(EVT_SLOT_B, 0x4000a)
    LOMA(CHAPTER_L_7)
    FADU(16)
    BROWNBOXTEXT(0x657, 8, 8)
    CUMO_AT(9, 4)
    STAL(60)
    CURE
    FADI(16)
    SVAL(EVT_SLOT_B, 0x4000b)
    LOMA(CHAPTER_L_8)
    LOAD1(0x1, UnitDef_088B5DAC)
    ENUN
    FADU(16)
    SPAWN_ENEMY(CHARACTER_VALTER, 10, 10)
    MOVE(0x10, CHARACTER_VALTER, 10, 4)
    ENUN
    MOVE(0x10, CHARACTER_TIRADO, 9, 3)
    ENUN
    MOVE(0x10, CHARACTER_VALTER, 10, 2)
    ENUN
    MOVE(0x10, CHARACTER_TIRADO, 10, 3)
    ENUN
    CUMO_CHAR(CHARACTER_TIRADO)
    STAL(60)
    CURE
    TEXTSTART
    TEXTSHOW(0x9d7)
    TEXTEND
    REMA
    FADI(16)
    MUSCMID(SONG_SILENT)
    CLEA
    CLEE
    CLEN
    SVAL(EVT_SLOT_B, 0xc0014)
    LOMA(CHAPTER_L_6)
    LOAD2(0x1, UnitDef_088B5DFC)
    ENUN
    FADU(16)
    CUMO_CHAR(CHARACTER_EPHRAIM)
    STAL(60)
    CURE
    SetBackground(BG_TREES)
    MUSC(SONG_TENSION)
    TEXTSHOW(0x9d8)
    TEXTEND
    REMA
    FADI(16)
    CLEA
    CLEE
    CLEN
    SVAL(EVT_SLOT_B, 0x70009)
    LOMA(CHAPTER_L_7)
    FADU(16)
    LOAD2(0x1, UnitDef_088B5E94)
    ENUN
    CUMO_CHAR(CHARACTER_EPHRAIM)
    STAL(60)
    CURE
    Text_BG(BG_STREAM, 0x9d9)
    MOVE(0x0, CHARACTER_EPHRAIM, 9, 4)
    STAL2(8)
    MOVE(0x0, CHARACTER_FORDE, 9, 5)
    MOVE(0x0, CHARACTER_KYLE, 8, 5)
    MOVE(0x0, CHARACTER_ORSON_CH5X, 8, 6)
    STAL2(8)
    FADI(16)
    ENUN
    CLEA
    CLEE
    CLEN
    SVAL(EVT_SLOT_B, 0x7000e)
    LOMA(CHAPTER_L_5X)
    LOAD1(0x1, UnitDef_088B5AC8)
    ENUN
    FADU(16)
    CUMO_CHAR(CHARACTER_ZONTA)
    STAL(60)
    CURE
    TEXTSHOW(0x9da)
    TEXTEND
    REMA
    CAMERA(0, 18)
    LOAD1(0x1, UnitDef_Event_Ch5xAlly)
    ENUN
    CUMO_CHAR(CHARACTER_EPHRAIM)
    STAL(60)
    CURE
    SetBackground(BG_CASTLE_BRIGHT)
    TEXTSHOW(0x9db)
    TEXTEND
    REMA
    MUSCFAST(SONG_SILENT)
    ENDA
};

void HandleCh5xUnits_End(void)
{
    int i;
    for (i = FACTION_BLUE + 1; i < FACTION_GREEN; i++) {
        struct Unit * unit = GetUnit(i);

        if (!UNIT_IS_VALID(unit))
            continue;

        switch (unit->pCharacterData->number) {
            case CHARACTER_EPHRAIM:
            case CHARACTER_FORDE:
            case CHARACTER_KYLE:
                unit->state &= ~US_DEAD;
                unit->state |= US_HIDDEN | US_BIT16;
                continue;

            case CHARACTER_ORSON_CH5X:
                ClearUnit(unit);
                continue;
        }

        if (0 == (unit->state & US_BIT26))
            unit->state &= ~(US_BIT16 | US_HIDDEN);

    }
}

CONST_DATA EventListScr EventScr_Ch5x_EndingScene[] = {
    ASMC(HandleCh5xUnits_End)
    MUSC(SONG_VICTORY)
    SetBackground(BG_CASTLE_BRIGHT)
    TEXTSHOW(0x9e1)
    TEXTEND
    REMA
    FADI(16)
    MUSCMID(SONG_SILENT)
    CLEA
    CLEE
    CLEN
    CLEAN
    CAMERA2(13, 9)
    EvtSetLoadUnitNoREDA // ENOSUPP in EAstdlib
    LOAD2(0x1, UnitDef_088B5D48)
    ENUN
    FADU(16)
    LOAD1(0x1, UnitDef_088B5D48)
    ENUN
    CUMO_CHAR(CHARACTER_FORDE)
    STAL(60)
    CURE
    TEXTSTART
    TEXTSHOW(0x9e2)
    TEXTEND
    REMA
    FADI(16)
    CLEA
    CLEE
    CLEN
    SVAL(EVT_SLOT_B, 0x4000a)
    LOMA(CHAPTER_L_7)
    LOAD1(0x1, UnitDef_088B5FCC)
    ENUN
    FADU(16)
    EVBIT_T(9)
    LOAD2(0x1, UnitDef_088B5F7C)
    ENUN
    EVBIT_F(9)
    MUSC(SONG_RAID)
    LOAD1(0x1, UnitDef_088B60A8)
    ENUN
    LOAD1(0x1, UnitDef_088B6120)
    ENUN
    CUMO_CHAR(CHARACTER_VALTER)
    STAL(60)
    CURE
    SetBackground(BG_STREAM)
    TEXTSHOW(0x9e3)
    TEXTEND
    REMA
    FADI(16)
    MUSCMID(SONG_SILENT)

    WmEvtSetUnitOnNode(WM_MU_0, WM_NODE_Serafew) // ENOSUPP in EAstdlib

    MNCH(0x7)
    ENDA
};
