#include "gbafe.h"

CONST_DATA EventListScr EventScr_Ch14a_BeginningScene[] = {
    REMOVEPORTRAITS
    BACG(BG_BLANK)
    FADU(128)
    FAWI(2)
    BACG(BG_GARDEN_FLASHBACK)
    EvtBgmFadeIn(SONG_LYON, 8) // ENOSUPP in EAstdlib
    FAWU(2)
    BROWNBOXTEXT(0x210, 8, 8)
    TEXTSHOW(0xa81)
    TEXTEND
    EvtBgmFadeIn(SONG_SILENT, 8) // ENOSUPP in EAstdlib
    FAWI(2)
    REMA
    SVAL(EVT_SLOT_B, 0x4000e)
    LOMA(CHAPTER_E_15)
    MUSC(SONG_4E)
    FAWU(2)
    LOAD2(0x1, UnitDef_088BC350)
    ENUN
    CUMO_CHAR(CHARACTER_SETH)
    STAL(60)
    CURE
    SetBackground(BG_DESERT)
    TEXTSHOW(0xa82)
    TEXTEND
    MUSC(SONG_TENSION)
    TEXTCONT
    TEXTEND
    REMA
    CALL(EventScr_TextShowWithFadeIn)
    MOVE(0x10, CHARACTER_EIRIKA, 9, 4)
    MOVE(0x10, CHARACTER_SETH, 9, 4)
    MOVE(0x10, CHARACTER_INNES, 9, 4)
    MOVE(0x10, CHARACTER_LARACHEL, 9, 4)
    STAL2(20)
    FADI(16)
    ENUN
    CLEA
    CLEE
    CLEN
    SVAL(EVT_SLOT_B, 0x7000a)
    LOMA(CHAPTER_E_14)
    LOAD1(0x1, UnitDef_088BBCAC)
    ENUN
    MOVE(0xffff, CHARACTER_CARLYLE, 9, 7)
    LOAD1(0x1, UnitDef_088BC10C)
    ENUN
    FADU(16)
    MOVE_1STEP(0x10, CHARACTER_CARLYLE, FACING_UP)
    ENUN
    CUMO_CHAR(CHARACTER_CARLYLE)
    STAL(60)
    CURE
    MUSC(SONG_RAID)
    TEXTSTART
    TEXTSHOW(0xa83)
    TEXTEND
    REMA
    FADI(16)
    MOVE(0xffff, CHARACTER_CARLYLE, 8, 7)
    CALL(EventScr_08591FD8)
    MUSC(SONG_ASSAULT)
    CAMERA_CAHR(CHARACTER_RENNAC)
    FADU(16)
    CUMO_CHAR(CHARACTER_RENNAC)
    STAL(60)
    CURE
    MUSI
    Text_BG(BG_PASSAGE, 0xa84)
    ENUT(12)
    ENUT(14)
    EVBIT_T(7)
    ENDA
};

CONST_DATA EventListScr EventScr_089F5CC4[] = {
    CAMERA2(9, 7)
    LOAD1(0x1, UnitDef_088BC134)
    ENUN
    CUMO_CHAR(CHARACTER_CAELLACH)
    STAL(60)
    CURE
    MUSC(SONG_RAID)
    TEXTSTART
    TEXTSHOW(0xa85)
    TEXTEND
    REMA
    MOVEONTO(0x0, CHARACTER_CAELLACH, CHARACTER_ISMAIRE)
    ENUN
    MOVE_1STEP(0x8, CHARACTER_ISMAIRE, FACING_DOWN)
    MOVE_1STEP(0x0, CHARACTER_CARLYLE, FACING_RIGHT)
    ENUN
    CUMO_CHAR(CHARACTER_CAELLACH)
    STAL(60)
    CURE
    TEXTSTART
    TEXTSHOW(0xa86)
    TEXTEND
    REMA
    MOVE_1STEP(0x0, CHARACTER_CARLYLE, FACING_LEFT)
    ENUN
    MOVEONTO(0x0, CHARACTER_CAELLACH, CHARACTER_ISMAIRE)
    ENUN
    DISA(CHARACTER_ISMAIRE)
    STAL(16)
    MOVE(0x0, CHARACTER_CAELLACH, 9, 8)
    ENUN
    CUMO_CHAR(CHARACTER_CAELLACH)
    STAL(60)
    CURE
    TEXTSTART
    TEXTSHOW(0xa87)
    TEXTEND
    REMA
    MOVEONTO(0x0, CHARACTER_CAELLACH, CHARACTER_LYON)
    ENUN
    DISA(CHARACTER_LYON)
    MOVE(0x0, CHARACTER_CAELLACH, 17, 11)
    ENUN
    DISA(CHARACTER_CAELLACH)
    CAMERA2(9, 6)
    MOVE(0x0, CHARACTER_CARLYLE, 9, 5)
    LOAD1(0x1, UnitDef_088BC170)
    ENUN
    EVBIT_T(7)
    ENDA
};

CONST_DATA EventListScr EventScr_Ch14a_EndingScene[] = {
    FADI(16)
    SVAL(EVT_SLOT_2, 0x1c)
    CALL(EventScr_9EE5BC)
    MUSC(SONG_RAID)
    CLEA
    CLEE
    CLEN
    SVAL(EVT_SLOT_B, 0x0)
    LOMA(CHAPTER_4A)
    FADU(16)
    LOAD1(0x1, UnitDef_088BC45C)
    ENUN
    CUMO_CHAR(CHARACTER_CAELLACH)
    STAL(60)
    CURE
    Text_BG(BG_THRONE_NORMAL, 0xa8b)
    MOVE_1STEP(0x10, CHARACTER_CAELLACH, FACING_UP)
    ENUN

    StartBattle
    NormalDamage(DEFENDER, 0)
    FIGHT_MAP(CHARACTER_CAELLACH, CHARACTER_ISMAIRE, 0, 0)

    DISA(CHARACHER_FRELIAN)
    CUMO_CHAR(CHARACTER_CAELLACH)
    STAL(60)
    CURE
    TEXTSTART
    TEXTSHOW(0xa8c)
    TEXTEND
    REMA
    SVAL(EVT_SLOT_2, 0x53)
    CALL(EventScr_CallBreakStone)
    MOVE(0x30, CHARACTER_LYON, 6, 3)
    ENUN
    CUMO_CHAR(CHARACTER_CAELLACH)
    STAL(60)
    CURE
    SetBackground(BG_THRONE_NORMAL)
    TEXTSHOW(0xa8d)
    TEXTEND
    REMA
    MUSCMID(SONG_SILENT)
    FADI(16)
    SVAL(EVT_SLOT_B, 0x7000a)
    LOMA(CHAPTER_E_14)
    CLEA
    CLEE
    CLEN
    EvtSetLoadUnitNoREDA // ENOSUPP in EAstdlib
    LOAD2(0x1, UnitDef_088BC1FC)
    ENUN
    FADU(16)
    CUMO_CHAR(CHARACTER_EIRIKA)
    STAL(60)
    CURE
    TEXTSTART
    TEXTSHOW(0xa8e)
    TEXTEND
    REMA
    LOAD2(0x1, UnitDef_088BC1FC)
    ENUN
    SPAWN_ENEMY(CHARACTER_LYON, 0, 0)
    SVAL(EVT_SLOT_2, 0x40)
    MOVE_CLOSEST(0xffff, CHAR_EVT_SLOT2, 9, 8)
    CALL(EventScr_UnitWarpIN)
    STAL(15)
    MOVE_1STEP(0x0, CHARACTER_LYON, FACING_DOWN)
    ENUN
    CUMO_CHAR(CHARACTER_LYON)
    STAL(60)
    CURE
    MUSC(SONG_LYON)
    TEXTSTART
    TEXTSHOW(0xa8f)
    TEXTEND
    REMA
    SVAL(EVT_SLOT_2, 0x40)
    CALL(EventScr_UnitWarpOUT)
    DISA(CHARACTER_LYON)
    MUSCMID(SONG_SILENT)
    LOAD2(0x1, UnitDef_088BC24C)
    ENUN
    CUMO_CHAR(CHARACTER_LARACHEL)
    STAL(60)
    CURE
    TEXTSTART
    TEXTSHOW(0xa90)
    TEXTEND
    REMA
    LOAD2(0x1, UnitDef_088BC274)
    STAL2(30)
    FADI(16)
    ENUN
    SetBackground(BG_THRONE_NORMAL)
    CHECK_ALIVE(CHARACTER_JOSHUA)
    BEQ(0x0, EVT_SLOT_C, EVT_SLOT_0)
    TEXTSHOW(0xa91)
    TEXTEND
    MUSCSLOW(SONG_SORROW)
    TEXTCONT
    TEXTEND
    REMA
    CALL(EventScr_RemoveBGIfNeeded)
    SVAL(EVT_SLOT_3, 0x91)
    GIVEITEMTO(CHARACTER_JOSHUA)
    CALL(EventScr_RemoveBGIfNeeded)
    SVAL(EVT_SLOT_3, 0x3e)
    GIVEITEMTO(CHARACTER_JOSHUA)
    GOTO(0x1)
LABEL(0x0)
    TEXTSHOW(0xa94)
    TEXTEND
    MUSCSLOW(SONG_SORROW)
    TEXTCONT
    TEXTEND
    REMA
    CALL(EventScr_RemoveBGIfNeeded)
    SVAL(EVT_SLOT_3, 0x91)
    GIVEITEMTO(CHARACTER_EIRIKA)
    CALL(EventScr_RemoveBGIfNeeded)
    SVAL(EVT_SLOT_3, 0x3e)
    GIVEITEMTO(CHARACTER_EIRIKA)
LABEL(0x1)
    MUSCSLOW(SONG_SILENT)
    FADI(16)
    TILECHANGE(0x2)
    CLEAN
    CAMERA(24, 0)
    EvtSetLoadUnitNoREDA // ENOSUPP in EAstdlib
    LOAD2(0x1, UnitDef_088BC2B0)
    ENUN
    DISA(0xcd)
    CHECK_ALIVE(CHARACTER_JOSHUA)
    BEQ(0x2, EVT_SLOT_C, EVT_SLOT_0)
    FADU(16)
    CUMO_CHAR(CHARACTER_JOSHUA)
    STAL(60)
    CURE
    SetBackground(BG_PASSAGE)
    MUSC(SONG_INTO_THE_SHADOW_OF_VICTORY)
    TEXTSHOW(0xa92)
    TEXTEND
    REMA
    FADI(16)
    CLEAN
LABEL(0x2)
    FADU(16)
    STAL(15)
    LOAD2(0x1, UnitDef_088BC2B0)
    ENUN
    CUMO_CHAR(0xcd)
    STAL(60)
    CURE
    SetBackground(BG_PASSAGE)
    CHECK_ALIVE(CHARACTER_JOSHUA)
    BEQ(0xa, EVT_SLOT_C, EVT_SLOT_0)
    MUSC(SONG_RAID)
    TEXTSHOW(0xa93)
    TEXTEND
    GOTO(0xb)
LABEL(0xa)
    MUSC(SONG_RAID)
    TEXTSHOW(0xa95)
    TEXTEND
LABEL(0xb)
    EvtBgTransion(0x2b, 1, 4) // ENOSUPP in EAstdlib
    REMOVEPORTRAITS
    TEXTCONT
    TEXTEND
    REMA
    FADI(16)
    CLEA
    CLEE
    CLEN
    SVAL(EVT_SLOT_B, 0x4000e)
    LOMA(CHAPTER_E_15)
    FADU(16)
    LOAD2(0x1, UnitDef_088BC4D4)
    ENUN
    CUMO_CHAR(CHARACTER_EIRIKA)
    STAL(60)
    CURE
    SetBackground(BG_DESERT)
    TEXTSHOW(0xa96)
    TEXTEND
    FADI(16)
    REMA
    ENUT(118)
    MNCH(0xf)
    ENDA
};

CONST_DATA EventListScr EventScr_089F619C[] = {
    MUSS(0x30)
    STAL(33)
    TEXTSTART
    TEXTSHOW(0xa97)
    TEXTEND
    REMA
    MURE(0x2)
    CUSA(CHARACTER_RENNAC)
    EVBIT_T(7)
    ENDA
};

CONST_DATA EventListScr EventScr_089F61C4[] = {
    SVAL(EVT_SLOT_2, 0x9)
    SVAL(EVT_SLOT_3, 0x1c)
    SVAL(EVT_SLOT_4, 0x26fc)
    SVAL(EVT_SLOT_D, 0x0)
    SVAL(EVT_SLOT_1, 0xa98)
    SENQUEUE1
    SVAL(EVT_SLOT_1, 0xa99)
    SENQUEUE1
    SVAL(EVT_SLOT_1, 0xa9b)
    SENQUEUE1
    SVAL(EVT_SLOT_1, 0xa9c)
    SENQUEUE1
    SVAL(EVT_SLOT_1, 0xa9d)
    SENQUEUE1
    SVAL(EVT_SLOT_1, 0xa9a)
    SENQUEUE1
    CALL(EventScr_9EEAAC)
    ENDA
};

CONST_DATA EventListScr EventScr_089F6238[] = {
    SVAL(EVT_SLOT_2, UnitDef_088BC008)
    CALL(EventScr_LoadReinforce)
    EVBIT_T(7)
    ENDA
};

CONST_DATA EventListScr EventScr_089F6250[] = {
    SVAL(EVT_SLOT_2, UnitDef_088BC0BC)
    CALL(EventScr_LoadReinforce)
    EVBIT_T(7)
    ENDA
};

CONST_DATA EventListScr EventScr_089F6268[] = {
    SVAL(EVT_SLOT_2, 0x0)
    CALL(EventScr_UnTriggerIfNotFaction)
    ENUF(12)
    EVBIT_T(7)
    ENDA
};

CONST_DATA EventListScr EventScr_089F6284[] = {
    SVAL(EVT_SLOT_2, UnitDef_088BC030)
    CALL(EventScr_LoadReinforce)
    EVBIT_T(7)
    ENDA
};

CONST_DATA EventListScr EventScr_089F629C[] = {
    SVAL(EVT_SLOT_2, 0x0)
    CALL(EventScr_UnTriggerIfNotFaction)
    COUNTER_SET(0x0, 2)
    ENUF(14)
    EVBIT_T(7)
    ENDA
};

CONST_DATA EventListScr EventScr_089F62BC[] = {
    SVAL(EVT_SLOT_2, UnitDef_088BC080)
    CALL(EventScr_LoadReinforce)
    COUNTER_DEC(0x0)
    ENUF(14)
    COUNTER_CHECK(0x0)
    BNE(0x0, EVT_SLOT_C, EVT_SLOT_0)
    ENUT(14)
LABEL(0x0)
    EVBIT_T(7)
    ENDA
};

CONST_DATA EventListScr EventScr_089F62F0[] = {
    SVAL(EVT_SLOT_2, 0x0)
    CALL(EventScr_UnTriggerIfNotFaction)
    SVAL(EVT_SLOT_D, 0x0)
    SVAL(EVT_SLOT_1, 0x70008)
    SENQUEUE1
    SVAL(EVT_SLOT_1, 0x70009)
    SENQUEUE1
    SVAL(EVT_SLOT_1, 0x7000a)
    SENQUEUE1
    SVAL(EVT_SLOT_2, 0x10000)
    CALL(EventScr_ChangeAIinQueue)
    EVBIT_T(7)
    ENDA
};
