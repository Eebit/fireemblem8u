#pragma once

#include "global.h"
#include "proc.h"

#define ApplyPalettesOpAnim(aSrc, aPalId, aPalCount) CopyToPalOpAnim((aSrc), 0x20 * (aPalId), 0x20 * (aPalCount))
#define ApplyPaletteOpAnim(aSrc, aPalId) ApplyPalettesOpAnim((aSrc), (aPalId), 1)

struct TitleScreenProc {
    /* 00 */ PROC_HEADER;

    /* 29 */ s8 unk_29; // maybe a flag for whether we are coming from the intro sequence?
    /* 2A */ u16 timer;
    /* 2C */ int unk_2c;
    /* 30 */ int unk_30;

    /* 34 */ u8 _pad[0x4C-0x34];

    /* 4C */ s16 unk_4c;
    /* 4E */ s16 unk_4e; // unused/pad?
    /* 50 */ s16 unk_50; // unused/pad?
    /* 52 */ u16 unk_52;
};

extern struct BgAffineDstData gOpAnimBgAffineDstData;

struct OpAnimSt {
    /* 00 */ s16 unk00;
    /* 02 */ s16 unk02;
    /* 04 */ u16 unk04;
    /* 06 */ u16 unk06;
    /* 08 */ s16 unk08;
    /* 0A */ s16 unk0A;
    /* 0C */ u16 unk0C;
};

extern struct OpAnimSt gOpAnimSt;

struct ProcOpAnim {
    PROC_HEADER;

    /* 2A */ u16 timer;
    /* 2C */ s16 unk2C;
    /* 2E */ s16 unk2E;
    /* 30 */ s16 unk30;
    /* 32 */ s16 unk32;
    /* 34 */ s16 unk34;
    /* 36 */ s16 unk36;
    /* 38 */ s16 unk38;
    /* 3A */ s16 unk3A;
    /* 3C */ s16 unk3C;
    /* 3E */ s16 unk3E;
    /* 40 */ STRUCT_PAD(0x40, 0x46);
    /* 46 */ u8 unk46;
};

struct ProcOpAnimFadeIn {
    PROC_HEADER;

    /* 29 */ STRUCT_PAD(0x29, 0x4C);
    /* 4C */ s16 cur;
    /* 4E */ STRUCT_PAD(0x4E, 0x64);
    /* 64 */ s16 max;
};

struct ProcOpAnimBLDALPHA {
    PROC_HEADER;

    /* 2A */ u16 timer;
};

struct Proc08AA7034 {
    PROC_HEADER;

    /* 29 */ STRUCT_PAD(0x29, 0x4C);
    /* 4C */ s16 timer;
};

extern CONST_DATA u16 Obj_08AA6BFA[];
extern CONST_DATA u16 Obj_08AA6C0E[];
extern CONST_DATA u16 Obj_08AA6C22[];
extern CONST_DATA u16 Obj_08AA6C36[];
extern CONST_DATA u16 Obj_08AA6C4A[];
extern CONST_DATA u16 Obj_08AA6C58[];
extern CONST_DATA u16 Obj_08AA6C58[];
extern CONST_DATA u16 Obj_08AA6C58[];
extern CONST_DATA u16 Obj_08AA6C66[];
extern CONST_DATA u16 Obj_08AA6C74[];
extern CONST_DATA u16 Obj_08AA6C82[];
extern CONST_DATA u16 Obj_08AA6C8A[];
extern CONST_DATA u16 Obj_08AA6C92[];
extern CONST_DATA u16 Obj_08AA6C9A[];
extern CONST_DATA struct ProcCmd ProcScr_OpAnimfxTerminator[];
extern CONST_DATA struct ProcCmd ProcScr_OpAnimFadeIn[];
extern CONST_DATA struct ProcCmd ProcScr_OpAnimBLDALPHA[];
extern CONST_DATA struct ProcCmd ProcScr_08AA6D04[];
extern CONST_DATA u8 * imgs_08AA6D14[100];
extern CONST_DATA u16 * tsas_08AA6EA4[100];
extern CONST_DATA struct ProcCmd ProcScr_08AA7034[];
// extern ??? gUnknown_08AA705C
// extern ??? gUnknown_08AA707C
// extern ??? gUnknown_08AA709C
// extern ??? gUnknown_08AA70BC
// extern ??? gUnknown_08AA70DC
// extern ??? gUnknown_08AA70EA
// extern ??? gUnknown_08AA7116
// extern ??? gUnknown_08AA712A
// extern ??? gUnknown_08AA715C
// extern ??? gUnknown_08AA7194

extern CONST_DATA u16 * pal_08AF47F0[];
extern CONST_DATA u8 img_gameintro1[];
extern CONST_DATA u8 img_gameintro2[];
extern CONST_DATA u8 img_gameintro3[];
extern CONST_DATA u8 img_gameintro4[];
extern CONST_DATA u8 img_gameintro5[];
extern CONST_DATA u8 img_gameintro6[];
extern CONST_DATA u8 img_gameintro7[];
extern CONST_DATA u8 img_gameintro8[];
extern CONST_DATA u8 img_gameintro9[];
extern CONST_DATA u8 img_gameintro10[];
extern CONST_DATA u8 img_gameintro11[];
extern CONST_DATA u8 img_gameintro12[];
extern CONST_DATA u8 img_gameintro13[];
extern CONST_DATA u8 img_gameintro14[];
extern CONST_DATA u8 img_gameintro15[];
extern CONST_DATA u8 img_gameintro16[];
extern CONST_DATA u8 img_gameintro17[];
extern CONST_DATA u8 img_gameintro18[];
extern CONST_DATA u8 img_gameintro19[];
extern CONST_DATA u8 img_gameintro20[];
extern CONST_DATA u8 img_gameintro21[];
extern CONST_DATA u8 img_gameintro22[];
extern CONST_DATA u8 img_gameintro23[];
extern CONST_DATA u8 img_gameintro24[];
extern CONST_DATA u8 img_gameintro25[];
extern CONST_DATA u8 img_gameintro26[];
extern CONST_DATA u8 img_gameintro27[];
extern CONST_DATA u8 img_gameintro28[];
extern CONST_DATA u8 img_gameintro29[];
extern CONST_DATA u8 img_gameintro30[];
extern CONST_DATA u8 img_gameintro31[];
extern CONST_DATA u8 img_gameintro32[];
extern CONST_DATA u8 img_gameintro33[];
extern CONST_DATA u8 img_gameintro34[];
extern CONST_DATA u8 img_gameintro35[];
extern CONST_DATA u8 img_gameintro36[];
extern CONST_DATA u8 img_gameintro37[];
extern CONST_DATA u8 img_gameintro38[];
extern CONST_DATA u8 img_gameintro39[];
extern CONST_DATA u8 img_gameintro40[];
extern CONST_DATA u8 img_gameintro41[];
extern CONST_DATA u8 img_gameintro42[];
extern CONST_DATA u8 img_gameintro43[];
extern CONST_DATA u8 img_gameintro44[];
extern CONST_DATA u8 img_gameintro45[];
extern CONST_DATA u8 img_gameintro46[];
extern CONST_DATA u8 img_gameintro47[];
extern CONST_DATA u8 img_gameintro48[];
extern CONST_DATA u8 img_gameintro49[];
extern CONST_DATA u8 img_gameintro50[];
extern CONST_DATA u8 img_gameintro51[];
extern CONST_DATA u8 img_gameintro52[];
extern CONST_DATA u8 img_gameintro53[];
extern CONST_DATA u8 img_gameintro54[];
extern CONST_DATA u8 img_gameintro55[];
extern CONST_DATA u8 img_gameintro56[];
extern CONST_DATA u8 img_gameintro57[];
extern CONST_DATA u8 img_gameintro58[];
extern CONST_DATA u8 img_gameintro59[];
extern CONST_DATA u8 img_gameintro60[];
extern CONST_DATA u8 img_gameintro61[];
extern CONST_DATA u8 img_gameintro62[];
extern CONST_DATA u8 img_gameintro63[];
extern CONST_DATA u8 img_gameintro64[];
extern CONST_DATA u8 img_gameintro65[];
extern CONST_DATA u8 img_gameintro66[];
extern CONST_DATA u8 img_gameintro67[];
extern CONST_DATA u8 img_gameintro68[];
extern CONST_DATA u8 img_gameintro69[];
extern CONST_DATA u8 img_gameintro70[];
extern CONST_DATA u8 img_gameintro71[];
extern CONST_DATA u8 img_gameintro72[];
extern CONST_DATA u8 img_gameintro73[];
extern CONST_DATA u8 img_gameintro74[];
extern CONST_DATA u8 img_gameintro75[];
extern CONST_DATA u8 img_gameintro76[];
extern CONST_DATA u8 img_gameintro77[];
extern CONST_DATA u8 img_gameintro78[];
extern CONST_DATA u8 img_gameintro79[];
extern CONST_DATA u8 img_gameintro80[];
extern CONST_DATA u8 img_gameintro81[];
extern CONST_DATA u8 img_gameintro82[];
extern CONST_DATA u8 img_gameintro83[];
extern CONST_DATA u8 img_gameintro84[];
extern CONST_DATA u8 img_gameintro85[];
extern CONST_DATA u8 img_gameintro86[];
extern CONST_DATA u8 img_gameintro87[];
extern CONST_DATA u8 img_gameintro88[];
extern CONST_DATA u8 img_gameintro89[];
extern CONST_DATA u8 img_gameintro90[];
extern CONST_DATA u8 img_gameintro91[];
extern CONST_DATA u8 img_gameintro92[];
extern CONST_DATA u8 img_gameintro93[];
extern CONST_DATA u8 img_gameintro94[];
extern CONST_DATA u8 img_gameintro95[];
extern CONST_DATA u8 img_gameintro96[];
extern CONST_DATA u8 img_gameintro97[];
extern CONST_DATA u8 img_gameintro98[];
extern CONST_DATA u8 img_gameintro99[];
extern CONST_DATA u8 img_gameintro100[];
extern CONST_DATA u16 tsa_gameintro1[];
extern CONST_DATA u16 tsa_gameintro2[];
extern CONST_DATA u16 tsa_gameintro3[];
extern CONST_DATA u16 tsa_gameintro4[];
extern CONST_DATA u16 tsa_gameintro5[];
extern CONST_DATA u16 tsa_gameintro6[];
extern CONST_DATA u16 tsa_gameintro7[];
extern CONST_DATA u16 tsa_gameintro8[];
extern CONST_DATA u16 tsa_gameintro9[];
extern CONST_DATA u16 tsa_gameintro10[];
extern CONST_DATA u16 tsa_gameintro11[];
extern CONST_DATA u16 tsa_gameintro12[];
extern CONST_DATA u16 tsa_gameintro13[];
extern CONST_DATA u16 tsa_gameintro14[];
extern CONST_DATA u16 tsa_gameintro15[];
extern CONST_DATA u16 tsa_gameintro16[];
extern CONST_DATA u16 tsa_gameintro17[];
extern CONST_DATA u16 tsa_gameintro18[];
extern CONST_DATA u16 tsa_gameintro19[];
extern CONST_DATA u16 tsa_gameintro20[];
extern CONST_DATA u16 tsa_gameintro21[];
extern CONST_DATA u16 tsa_gameintro22[];
extern CONST_DATA u16 tsa_gameintro23[];
extern CONST_DATA u16 tsa_gameintro24[];
extern CONST_DATA u16 tsa_gameintro25[];
extern CONST_DATA u16 tsa_gameintro26[];
extern CONST_DATA u16 tsa_gameintro27[];
extern CONST_DATA u16 tsa_gameintro28[];
extern CONST_DATA u16 tsa_gameintro29[];
extern CONST_DATA u16 tsa_gameintro30[];
extern CONST_DATA u16 tsa_gameintro31[];
extern CONST_DATA u16 tsa_gameintro32[];
extern CONST_DATA u16 tsa_gameintro33[];
extern CONST_DATA u16 tsa_gameintro34[];
extern CONST_DATA u16 tsa_gameintro35[];
extern CONST_DATA u16 tsa_gameintro36[];
extern CONST_DATA u16 tsa_gameintro37[];
extern CONST_DATA u16 tsa_gameintro38[];
extern CONST_DATA u16 tsa_gameintro39[];
extern CONST_DATA u16 tsa_gameintro40[];
extern CONST_DATA u16 tsa_gameintro41[];
extern CONST_DATA u16 tsa_gameintro42[];
extern CONST_DATA u16 tsa_gameintro43[];
extern CONST_DATA u16 tsa_gameintro44[];
extern CONST_DATA u16 tsa_gameintro45[];
extern CONST_DATA u16 tsa_gameintro46[];
extern CONST_DATA u16 tsa_gameintro47[];
extern CONST_DATA u16 tsa_gameintro48[];
extern CONST_DATA u16 tsa_gameintro49[];
extern CONST_DATA u16 tsa_gameintro50[];
extern CONST_DATA u16 tsa_gameintro51[];
extern CONST_DATA u16 tsa_gameintro52[];
extern CONST_DATA u16 tsa_gameintro53[];
extern CONST_DATA u16 tsa_gameintro54[];
extern CONST_DATA u16 tsa_gameintro55[];
extern CONST_DATA u16 tsa_gameintro56[];
extern CONST_DATA u16 tsa_gameintro57[];
extern CONST_DATA u16 tsa_gameintro58[];
extern CONST_DATA u16 tsa_gameintro59[];
extern CONST_DATA u16 tsa_gameintro60[];
extern CONST_DATA u16 tsa_gameintro61[];
extern CONST_DATA u16 tsa_gameintro62[];
extern CONST_DATA u16 tsa_gameintro63[];
extern CONST_DATA u16 tsa_gameintro64[];
extern CONST_DATA u16 tsa_gameintro65[];
extern CONST_DATA u16 tsa_gameintro66[];
extern CONST_DATA u16 tsa_gameintro67[];
extern CONST_DATA u16 tsa_gameintro68[];
extern CONST_DATA u16 tsa_gameintro69[];
extern CONST_DATA u16 tsa_gameintro70[];
extern CONST_DATA u16 tsa_gameintro71[];
extern CONST_DATA u16 tsa_gameintro72[];
extern CONST_DATA u16 tsa_gameintro73[];
extern CONST_DATA u16 tsa_gameintro74[];
extern CONST_DATA u16 tsa_gameintro75[];
extern CONST_DATA u16 tsa_gameintro76[];
extern CONST_DATA u16 tsa_gameintro77[];
extern CONST_DATA u16 tsa_gameintro78[];
extern CONST_DATA u16 tsa_gameintro79[];
extern CONST_DATA u16 tsa_gameintro80[];
extern CONST_DATA u16 tsa_gameintro81[];
extern CONST_DATA u16 tsa_gameintro82[];
extern CONST_DATA u16 tsa_gameintro83[];
extern CONST_DATA u16 tsa_gameintro84[];
extern CONST_DATA u16 tsa_gameintro85[];
extern CONST_DATA u16 tsa_gameintro86[];
extern CONST_DATA u16 tsa_gameintro87[];
extern CONST_DATA u16 tsa_gameintro88[];
extern CONST_DATA u16 tsa_gameintro89[];
extern CONST_DATA u16 tsa_gameintro90[];
extern CONST_DATA u16 tsa_gameintro91[];
extern CONST_DATA u16 tsa_gameintro92[];
extern CONST_DATA u16 tsa_gameintro93[];
extern CONST_DATA u16 tsa_gameintro94[];
extern CONST_DATA u16 tsa_gameintro95[];
extern CONST_DATA u16 tsa_gameintro96[];
extern CONST_DATA u16 tsa_gameintro97[];
extern CONST_DATA u16 tsa_gameintro98[];
extern CONST_DATA u16 tsa_gameintro99[];
extern CONST_DATA u16 tsa_gameintro100[];
extern u16 pal_08B103D8[];

void OpAnimPutObjCommon(int ix, int iy, u8 a, u8 b);
void OpAnimfxTerminatorMain(struct Proc * proc);
void NewOpAnimfxTerminator(ProcPtr parent);
void EndOpAnimfxTerminator(ProcPtr parent);
void CopyToPalOpAnim(const void * src, int offset, int size);
void CopyFirstPalDirectly(const u16 * src, u16 * dst);
void SetFirstPalDirectly(u16 * src, u16 * dst, u8 pal);
void ClearFirstPalDirectly(u16 * dst);
void TsaModifyFirstPalMaybe(s16 end, s16 start, u8 unused, u16 bg, u16 * src1, u16 * src2, s8 flag);
void sub_80C689C(s16 end, s16 start, u8 unused, u16 bg, u16 * src1, u16 * src2, s8 flag);
void sub_80C69B0(u16 *, int, u16);
void Initialize6CIntroSequence(struct ProcOpAnim * proc);
void OpAnimAllBlack(struct ProcOpAnimFadeIn * proc);
void OpAnimFadeInMain(struct ProcOpAnimFadeIn * proc);
void NewProcOpAnimFadeIn(int max, ProcPtr parent);
void BgAffineSetOpAnim(int scaling_radio, int angle);
void SetupOpAnimWorldMapfx(struct ProcOpAnim * proc);
void OpAnimBldAlphaInit(struct ProcOpAnimBLDALPHA * proc);
void OpAnimBldAlphaUpdateBgPalette(struct ProcOpAnimBLDALPHA * proc);
void OpAnimBldAlphaDelay(struct ProcOpAnimBLDALPHA * proc);
void OpAnimBldAlphaMain(struct ProcOpAnimBLDALPHA * proc);
bool OpAnimBldAlphaExists(void);
void OpAnimUpdateScreen1(struct ProcOpAnim * proc);
void sub_80C6F70(struct ProcOpAnim * proc);
void sub_80C7050(struct ProcOpAnim * proc);
void Proc08AA6D04Main(void);
void NewProc08AA6D04(void);
void EndProc08AA6D04(void);
void OpAnim1_UpdateScrollOneLine(s16 index);
void OpAnim1_UpdateScroll(int new, int old);
void sub_80C72A4(u8 type);
void sub_80C73B0(struct ProcOpAnim * proc);
void Proc08AA7034_Init(struct Proc08AA7034 * proc);
void Proc08AA7034_Main(struct Proc08AA7034 * proc);
void GameIntoCharCgFlyInMaybe(int xOam1, int yOam0);
void sub_80C76C8(struct ProcOpAnim * proc);
void OpAnimHBlank1(void);
void OpAnimHBlank2(void);
void sub_80C7900(struct ProcOpAnim * proc);
// ??? sub_80C79F4(???);
// ??? sub_80C7A84(???);
// ??? sub_80C7AE8(???);
// ??? sub_80C7B80(???);
// ??? sub_80C7CF8(???);
// ??? sub_80C7F90(???);
// ??? sub_80C8100(???);
// ??? sub_80C8184(???);
// ??? sub_80C8214(???);
// ??? sub_80C8278(???);
// ??? sub_80C835C(???);
// ??? sub_80C84D8(???);
// ??? sub_80C8554(???);
// ??? sub_80C8564(???);
// ??? sub_80C8580(???);
// ??? sub_80C85B0(???);
// ??? sub_80C85FC(???);
// ??? sub_80C8608(???);
// ??? sub_80C8638(???);
// ??? sub_80C8684(???);
// ??? sub_80C8690(???);
// ??? sub_80C883C(???);
// ??? sub_80C8934(???);
// ??? sub_80C8A20(???);
// ??? sub_80C8B0C(???);
// ??? sub_80C8BF8(???);
// ??? sub_80C8CE4(???);
// ??? sub_80C8D30(???);
// ??? sub_80C8ED4(???);
// ??? sub_80C9024(???);
// ??? sub_80C9100(???);
// ??? sub_80C9218(???);
// ??? sub_80C9330(???);
// ??? sub_80C940C(???);
// ??? sub_80C955C(???);
// ??? sub_80C9638(???);
// ??? sub_80C9750(???);
// ??? sub_80C98A0(???);
// ??? sub_80C99B8(???);
// ??? sub_80C9A94(???);
// ??? sub_80C9AFC(???);
// ??? sub_80C9B6C(???);
// ??? sub_80C9C08(???);
// ??? sub_80C9C5C(???);
// ??? sub_80C9CAC(???);
// ??? sub_80C9CFC(???);
// ??? sub_80C9D4C(???);
// ??? sub_80C9DA0(???);
// ??? sub_80C9DF0(???);
// ??? sub_80C9E6C(???);
// ??? sub_80C9EE8(???);
// ??? sub_80C9F7C(???);
// ??? sub_80C9FF8(???);
// ??? sub_80CA10C(???);
// ??? sub_80CA26C(???);
// ??? sub_80CA3B8(???);
// ??? sub_80CA4A4(???);
// ??? sub_80CA4DC(???);
// ??? sub_80CA92C(???);
// ??? sub_80CA940(???);
// ??? sub_80CA9F8(???);
// ??? sub_80CAA38(???);
// ??? sub_80CABB0(???);
// ??? sub_80CAE20(???);
// ??? sub_80CAF2C(???);
// ??? sub_80CB0A0(???);
// ??? sub_80CB20C(???);
// ??? sub_80CB320(???);
// ??? sub_80CB594(???);
// ??? sub_80CB6A0(???);
// ??? sub_80CB878(???);
// ??? sub_80CBA64(???);
// ??? sub_80CBC40(???);
// ??? sub_80CBD7C(???);
// ??? sub_80CBDD8(???);
// ??? sub_80CBE0C(???);
// ??? sub_80CBEF8(???);
// ??? sub_80CBF9C(???);
// ??? sub_80CBFC0(???);
// ??? sub_80CC074(???);
// ??? sub_80CC098(???);
// ??? sub_80CC0FC(???);
// ??? sub_80CC13C(???);
// ??? sub_80CC1A0(???);
// ??? sub_80CC1E0(???);
// ??? sub_80CC1E8(???);
// ??? sub_80CC1F0(???);
// ??? PrepareHealthAndSafetyScreen(???);
// ??? sub_80CC2F4(???);
// ??? sub_80CC32C(???);
// ??? sub_80CC430(???);
