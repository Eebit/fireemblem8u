#ifndef GUARD_EVENT_H
#define GUARD_EVENT_H

#include "global.h"

struct EventEngineProc {
    PROC_HEADER;

    /* 2C */ void (*pCallback)(struct EventEngineProc*);

    /* 30 */ const u16* pEventStart;
    /* 34 */ const u16* pEventIdk;
    /* 38 */ const u16* pEventCurrent;

    /* 3C */ u16 evStateBits;
    /* 3E */ u16 evStallTimer;

    /* 40 */ s8 overwrittenTextSpeed;
    /* 41 */ u8 execType;
    /* 42 */ u8 activeTextType;
    /* 43 */ u8 chapterIndex;

    /* 44 */ u16 mapSpritePalIdOverride;

    /* 46 */ // pad

    /* 48 */ const void* pUnitLoadData;
    /* 4C */ s16 unitLoadCount;

    /* 4E */ u8  idk4E;

    /* 4F */ u8 _pad_4F[0x54 - 0x4F];
    /* 54 */ struct Unit *unit;
};

enum EventExecType {
    EV_EXEC_WORLDMAP  = 0, // for world map events
    EV_EXEC_CUTSCENE  = 1, // for overall chapter cutscene events?
    EV_EXEC_GAMEPLAY  = 2, // for gameplay-triggered events? (battle quotes, villages tile changes, chests, game over)
    EV_EXEC_QUIET     = 3, // for events that should just execute events? (no fade, no clearing stuff, etc)
    EV_EXEC_UNK4      = 4, // not used?
    EV_EXEC_UNK5      = 5  // not used?
};

enum EventStateFlags {
    EV_STATE_NONE      = 0,

    EV_STATE_ABORT     = (1 << 0x0), // queued event engine calls will wait
    EV_STATE_0002      = (1 << 0x1), // prevents "ENDA events" to play. Needs further investigation
    EV_STATE_SKIPPING  = (1 << 0x2), // currently skipping events (trigger with start)
    EV_STATE_0008      = (1 << 0x3), // ??? seems to be dialogue related
    EV_STATE_NOSKIP    = (1 << 0x4), // prevents skipping with start, set by EVBIT_MODIFY
    EV_STATE_0020      = (1 << 0x5), // set by EVBIT_MODIFY
    EV_STATE_0040      = (1 << 0x6), // set by EVBIT_MODIFY
    EV_STATE_NOFADE    = (1 << 0x7), // don't fade at end of events
    EV_STATE_FADEDIN   = (1 << 0x8), // faded into white/back
    EV_STATE_UNITCAM   = (1 << 0x9), // camera follows unit movement
    EV_STATE_CHANGECH  = (1 << 0xA), // moving to another chapter (?)
    EV_STATE_CHANGEGM  = (1 << 0xB), // changing "game mode" (GAMECTRL field 0x29 was changed?)
    EV_STATE_GFXLOCKED = (1 << 0xC)  // set when the game graphics have been locked through events (codes 0x23/0x24)

    // I don't think there's more, but I could be wrong
};

enum EventExecRet {
    EV_RET_DEFAULT = 0,
    EV_RET_1,
    EV_RET_2,
    EV_RET_3,
    EV_RET_4,
    EV_RET_BREAK,
    EV_RET_ERR,
};

// This will probably be used in evtcmd_gmap/evtscr for defining the event code handler arrays or something
typedef u8(*EventFuncType)(struct EventEngineProc*);

/**
 * event slot values
 * 
 * Null (0)
 * Vars (1-A)
 * Position (B)
 * Check (C)
 * QP (D)
 */
#define EVENT_SLOT_COUNT 0xE
extern unsigned gEventSlots[EVENT_SLOT_COUNT];

struct EnqueuedEventCall {
    const u16* events;
    u8 execType;
    s8 isUsed;
};

extern struct EnqueuedEventCall gEventCallQueue[];

struct Struct03000570 {
    const u16 * evt1;
    const u16 * evt2;
};

extern struct Struct03000570 gUnknown_03000570[];

enum EventCmdIndex {
    EV_CMD_NOP = 0,
    EV_CMD_END,
    EV_CMD_EVSET,
    EV_CMD_EVCHECK,
    EV_CMD_RANDOMNUMBER,
    EV_CMD_SVAL,
    EV_CMD_SLOT_OPS,
    EV_CMD_QUEUE_OPS,
    EV_CMD_LABEL,
    EV_CMD_GOTO,
    EV_CMD_CALL,
    EV_CMD_0B,
    EV_CMD_BRANCH,
    EV_CMD_ASMC,
};

#define EVT_SUB_CMD(scr) (*((const u8 *)(scr)) & 0xF)
#define EVT_SUB_CMD_LO(scr) (*((const u16 *)(scr)) & 0x7)
#define EVT_SUB_CMD_HI(scr) ((*((const u16 *)(scr)) & 0xF) >> 0x3)

#define EVT_CMD_LEN(scr) ((*((const u16 *)(scr)) >> 0x4) & 0xF)
#define EVT_CMD_ARGV(scr) ((const s16 *)(scr) + 1)
#define EVT_CMD_ARG32_BE(scr) ((u16)EVT_CMD_ARGV(scr)[1] | ((u16)EVT_CMD_ARGV(scr)[2] << 0x10))
#define EVT_CMD_ARG32_LE(scr) (*((u32 *)(EVT_CMD_ARGV(scr) + 1)))

enum EventCmdSubIndex {

    /* EV_CMD_END */
    EVSUBCMD_ENDA = 0,
    EVSUBCMD_ENDB = 1,

    /* EV_CMD_EVSET */
    EVSUBCMD_EVBIT_F = 0,
    EVSUBCMD_EVBIT_T = 8,
    EVSUBCMD_ENUF = 1,
    EVSUBCMD_ENUT = 9,

    /* EV_CMD_EVCHECK */
    EVSUBCMD_CHECK_EVBIT = 0,
    EVSUBCMD_CHECK_EVENTID = 1,

    /* EV_CMD_SLOT_OPS */
    EVSUBCMD_SADD = 0,
    EVSUBCMD_SSUB = 1,
    EVSUBCMD_SMUL = 2,
    EVSUBCMD_SDIV = 3,
    EVSUBCMD_SMOD = 4,
    EVSUBCMD_SAND = 5,
    EVSUBCMD_SORR = 6,
    EVSUBCMD_SXOR = 7,
    EVSUBCMD_SLSL = 8,
    EVSUBCMD_SLSR = 9,

    /* EV_CMD_QUEUE_OPS */
    EVSUBCMD_SENQUEUE = 0,
    EVSUBCMD_SDEQUEUE_S1 = 1,
    EVSUBCMD_SDEQUEUE = 2,

    /* EV_CMD_BRANCH */
    EVSUBCMD_BEQ = 0,
    EVSUBCMD_BNE = 1,
    EVSUBCMD_BGE = 2,
    EVSUBCMD_BGT = 3,
    EVSUBCMD_BLE = 4,
    EVSUBCMD_BLT = 5,
};

// extern ??? gUnknown_03000428
// extern ??? gUnknown_03000430
// extern ??? gUnknown_03000434
// extern ??? gUnknown_030004E4
// extern ??? gUnknown_030004E6
// extern ??? gUnknown_030004E8
extern unsigned gEventSlotQueue[]; // event slot queue (just an array)
extern unsigned gEventSlotCounter;
extern struct ProcCmd gGenericProc[4];

extern const struct ProcCmd gProc_StdEventEngine[]; // map event engine proc
extern const struct ProcCmd gProc_BattleEventEngine[]; // battle (?) event engine proc
extern const EventFuncType gEventLoCmdTable[]; // regular event functions
extern const EventFuncType gEventHiCmdTable[]; // gmap event functions
extern const struct ProcCmd gUnknown_08591DD8[]; // map event engine "witness lock" (alive while map event engine is)

// extern ??? gUnknown_08591DE8
// extern ??? gUnknown_08591E00
// extern ??? gUnknown_08591E58
// extern ??? gUnknown_08591EB0
// extern ??? gUnknown_08591F08
// extern ??? gUnknown_08591F18
// extern ??? gUnknown_08591F28
// extern ??? gEvent_DisplayBattleQuote
// extern ??? gEvent_TriggerQueuedTileChanges
// extern ??? gEvent_OpenChest
// extern ??? gEvent_MapSupportConversation
// extern ??? gEvent_SupportViewerConversation
// extern ??? gEvent_SkirmishRetreat
// extern ??? gEvent_SuspendPrompt
// extern ??? gEvent_GameOver
extern u16 gEvent_08592114[];
// extern ??? gUnknown_085921AC

// ??? _MarkSomethingInMenu(???);
// ??? EventEngine_OnUpdate(???);
// ??? EventEngine_OnEnd(???);
// ??? EnqueueEventCall(???);
// ??? CallNextQueuedEvent(???);
void CallEvent(const u16* events, u8 execType);
struct EventEngineProc* EventEngine_Create(const u16* events, u8 idk);
void EventEngine_CreateBattle(const u16* events);
s8 EventEngineExists(void);
int BattleEventEngineExists(void);
void DeleteEventEngines(void);
// ??? sub_800D1E4(???);
void SetEventSlotC(unsigned value);
// ??? sub_800D204(???);
int sub_800D208(void);
// ??? CallBattleQuoteEvent(???);
void CallBattleQuoteEventInBattle(u16 textIndex);
void CallTileChangeEvent(u16 tileChangeIndex);
void CallChestOpeningEvent(u16 tileChangeIndex, u16 idr);
void CallMapSupportEvent(u16 musicIndex, u16 textIndex);
void CallSupportViewerEvent(u16);
void CallRetreatPromptEvent(void);
void CallSuspendPromptEvent(void);
void CallGameOverEvent(void);
void sub_800D3E4(void);
void EventEngine_StartSkip(struct EventEngineProc * proc);
void sub_800D488(struct EventEngineProc * unused);
void SetEventTriggerState(u16 triggerId, bool8 value);
s8 GetEventTriggerState(u16 triggerId);
ProcPtr MergeGenericProc(ProcPtr parent, ProcFunc init, ProcFunc loop, ProcFunc dest);
void sub_800D524(void);
void SlotQueuePush(unsigned value);
unsigned SlotQueuePop(void);
void SetEventSlotCounter(unsigned value);
unsigned GetEventSlotCounter(void);

// ??? sub_800B910(???);
// ??? sub_800B954(???);
// ??? sub_800B994(???);
// ??? sub_800B9B8(???);
// ??? sub_800BA04(???);
// ??? sub_800BA34(???);
// ??? SetSomeRealCamPos(???);
// ??? sub_800BAA8(???);
// ??? TriggerMapChanges(???);
// ??? sub_800BB48(???);
void sub_800BB98(void);
// ??? sub_800BBB4(???);
// ??? sub_800BBE4(???);
// ??? HideAllUnits(???);
struct Unit * GetUnitStructFromEventParameter(s8 pid);
void sub_800BCDC(int); // battle related
// ??? Event80_(???);
// ??? Event81_(???);
// ??? Event82_EndWM(???);
// ??? Event83_WM_SETCAM(???);
// ??? Event84_WM_SETCAMONLOC(???);
// ??? Event85_WM_SETCAMONSPRITE(???);
// ??? Event86_WM_MOVECAM(???);
// ??? Event87_(???);
// ??? Event88_(???);
// ??? Event89_(???);
// ??? Event8A_(???);
// ??? Event8B_(???);
// ??? Event8C_(???);
// ??? Event8D_(???);
// ??? Event8E_(???);
// ??? Event8F_(???);
// ??? Event90_WM_DRAWPATH(???);
// ??? Event91_WM_DRAWPATH_Silent(???);
// ??? Event92_REMOVEPATH(???);
// ??? Event93_(???);
// ??? Event94_(???);
// ??? Event95_(???);
// ??? Event96_(???);
// ??? Event97_(???);
// ??? Event98_(???);
// ??? Event99_(???);
// ??? Event9A_(???);
// ??? Event9B_(???);
// ??? Event9C_(???);
// ??? Event9D_(???);
// ??? Event9E_PUTSPRITE(???);
// ??? Event9F_(???);
// ??? EventA0_REMSPRITE(???);
// ??? EventA1_(???);
// ??? EventA2_(???);
// ??? EventA3_(???);
// ??? EventA4_(???);
// ??? EventA5_(???);
// ??? EventA6_(???);
// ??? EventA7_(???);
// ??? EventA8_(???);
// ??? EventA9_(???);
// ??? EventAA_(???);
// ??? EventAB_(???);
// ??? EventAC_(???);
// ??? EventAD_(???);
// ??? EventAE_(???);
// ??? EventAF_(???);
// ??? EventB0_(???);
// ??? EventB1_(???);
// ??? EventB2_(???);
// ??? EventB3_(???);
// ??? EventB4_(???);
// ??? EventB5_(???);
// ??? EventB6_(???);
// ??? EventB7_(???);
// ??? EventB8_(???);
// ??? EventB9_(???);
// ??? EventBA_(???);
// ??? EventBB_(???);
// ??? EventBC_(???);
// ??? EventBD_(???);
// ??? EventBE_(???);
// ??? EventBF_(???);
// ??? EventC0_(???);
// ??? EventC1_SKIPWM(???);
// ??? EventC2_(???);
// ??? EventC3_(???);
// ??? EventCE_(???);
// ??? EventCF_(???);
// ??? EventC4_(???);
// ??? sub_800CCE8(???);
// ??? nullsub_32(???);
// ??? EventC5_(???);
// ??? sub_800CD38(???);
// ??? nullsub_34(???);
// ??? sub_800CD40(???);
// ??? EventC6_(???);
// ??? EventC7_(???);
// ??? EventC8_(???);
// ??? EventC9_(???);
// ??? sub_800CDE8(???);
// ??? sub_800CDEC(???);
// ??? EventCA_(???);
// ??? EventCB_(???);
// ??? EventCC_(???);
// ??? EventCD_(???);
// ??? Event00_NULL(???);
// ??? Event01_End(???);
// ??? Event02_EvBitAndIdMod(???);
// ??? Event03_CheckEvBitOrId(???);
// ??? Event04_CheckRandom(???);
// ??? Event05_SetSlot(???);
// ??? Event06_SlotOperation(???);
// ??? Event07_SlotQueueOperations(???);
// ??? Event08_Label(???);
// ??? Event09_Goto(???);
// ??? Event0A_Call(???);
// ??? Event0B_(???);
// ??? Event0C_Branch(???);
// ??? Event0D_AsmCall(???);
// ??? Event0E_STAL(???);
// ??? Event0F_(???);
// ??? Event10_ModifyEvBit(???);
// ??? Event11_SetIgnoredKeys(???);
// ??? Event12_(???);
// ??? Event13_(???);
// ??? Event14_(???);
// ??? Event15_(???);
// ??? Event16_(???);
// ??? Event17_(???);
// ??? Event18_(???);
// ??? Event19_(???);
// ??? Event1A_TEXTSTART(???);
// ??? sub_800E210(???);
// ??? sub_800E290(???);
// ??? sub_800E31C(???);
// ??? Event1B_TEXTSHOW(???);
// ??? Event1C_TEXTCONT(???);
// ??? Event1D_TEXTEND(???);
// void sub_800E640(struct EventEngineProc*);
// ??? _WhileFace6CExists(???);
// ??? Event1E_(???);
// ??? Event1F_(???);
// ??? Event20_(???);
// ??? sub_800E7D0(???);
// ??? Event21_(???);
// ??? sub_800EA84(???);
// ??? sub_800EBB0(???);
// ??? sub_800EC00(???);
// ??? sub_800EC50(???);
// ??? sub_800ED50(???);
// ??? sub_800EE54(???);
// ??? sub_800EEE8(???);
// ??? sub_800EF48(???);
// ??? Event22_(???);
// ??? Event23_(???);
// ??? Event24_(???);
// ??? Event25_(???);
// ??? Event26_CameraControlMaybe(???);
// ??? Event27_MapChange(???);
// ??? Event28_ChangeWeather(???);
// ??? Event29_SetFogVision(???);
// ??? Event2A_MoveToChapter(???);
// ??? sub_800F50C(???);
// ??? ShouldUNITBeLoaded(???);
// ??? sub_800F5B8(???);
// ??? sub_800F698(???);
// ??? LoadUnit_800F704(???);
// ??? sub_800F8A8(???);
// ??? sub_800F914(???);
// ??? Event2B_(???);
// ??? Event2C_LoadUnits(???);
// ??? TryPrepareEventUnitMovement(???);
// ??? GetSomeEventEngineMoveRelatedBitfield(???);
// ??? Event2D_(???);
// ??? Event2E_CheckAt(???);
// ??? Event2F_MoveUnit(???);
// ??? Event30_ENUN(???);
// ??? Event31_DisplayEffectRange(???);
// ??? Event32_SpawnSingleUnit(???);
// ??? Event33_CheckUnitVarious(???);
// ??? Event34_MessWithUnitState(???);
// ??? Event35_UnitClassChanging(???);
// ??? Event36_CheckInArea(???);
// ??? Event37_GiveItem(???);
// ??? Event38_ChangeActiveUnit(???);
// ??? Event39_(???);
// ??? Event3A_(???);
// ??? sub_8010748(???);
// ??? Event3B_(???);
// ??? Event3C_(???);
// ??? Event3D_(???);
// ??? Event3E_PrepScreenCall(???);
// ??? sub_801098C(???);
// ??? sub_8010A28(???);
// ??? Event3F_(???);
// ??? sub_8010B48(???);
// ??? Event40_(???);
// ??? Event41_(???);
// ??? Event42_(???);
// ??? Event43_(???);
// ??? Event44_(???);
// ??? Event45_(???);

#endif // GUARD_EVENT_H
