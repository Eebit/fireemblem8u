#pragma once

#include "global.h"
#include "anime.h"
#include "proc.h"

struct ProcEkrDispUP {
    PROC_HEADER;

    /* 29 */ u8 unk29;
    /* 2A */ u8 unk2A;
    /* 2B */ u8 _pad_2B[0x32 - 0x2B];
    /* 32 */ u16 unk32;
    /* 34 */ u8 _pad_32[0x3A - 0x34];
    /* 3A */ u16 unk3A;
    /* 3C */ u8 _pad_3C[0x4C - 0x3C];
    /* 4C */ u32 unk4C;
    /* 50 */ u32 unk50;
};

extern struct ProcEkrDispUP *gpProcEkrDispUP;

struct Unknown_030053E0 {
    u16 u00;
    u16 u02;
    u16 u04;
    u16 u06;
    u16 u08;
    u16 u0a;
    u16 u0c;
    u16 u0e;
    u16 u10;
    u16 u12;
    u16 *buf;
    u8 *u18;
    u8 *u1c;
    u8 *u20;
    void (*u24)(void);
};
extern struct Unknown_030053E0 gUnknown_030053E0;

struct Unknown_030053A0 {
    /* 00 */ u8 u00;
    /* 01 */ u8 u01;
    /* 02 */ u16 u02;
    /* 04 */ u16 u04;
    /* 06 */ u16 u06;
    /* 08 */ u16 u08;
    /* 0A */ u16 u0a;
    /* 0C */ u16 u0c;
    /* 0E */ u16 u0e;
    /* 10 */ u16 u10;
    /* 14 */ struct Anim *anim1;
    /* 18 */ struct Anim *anim2;
    /* 1C */ u8 *u1c;
    /* 20 */ u8 *u20;
    /* 24 */ u8 *u24;
    /* 28 */ u8 *u28;
    /* 2C */ u8 *_u2c;
    /* 30 */ struct Unknown_030053E0 * u30;
};

extern struct Unknown_030053A0 gUnknown_030053A0;

struct Unknown_0201FADC {
    /* 00 */ u16 things[8];
    /* 10 */ u16 _pad_10;
    /* 14 */ ProcPtr p1;
    /* 18 */ ProcPtr p2;
    /* 1c */ u32 u1c;
    /* 20 */ u8 *u20;
    /* 24 */ u32 _pad_24;
};

extern struct Unknown_0201FADC gUnknown_0201FADC;

struct ProcEfxHPBar {
    PROC_HEADER;

    /* 29 */ u8 unk29;
    /* 2A */ u8 _pad_2A[0x2C - 0x2A];
    /* 2C */ s16 timer;
    /* 2E */ s16 max;
    /* 30 */ u8 _pad_30[0x48 - 0x30];
    /* 48 */ int unk48;
    /* 4C */ int unk4C;
    /* 50 */ int unk50;
    /* 54 */ int unk54;
    /* 58 */ int unk58;
    /* 5C */ struct Anim *anim5C;
    /* 60 */ struct Anim *anim60;
    /* 64 */ struct Anim *anim64;
};

void ekrDispUP_Loop(struct ProcEkrDispUP *proc);

struct EkrSpEff {
    /* 00 */ u8 type;
    /* 01 */ u8 unk01;
    /* 02 */ u16 attr;
    /* 04 */ ProcPtr proc;
    /* 08 */ u32 unk08;
    /* 0C */ struct Anim *anim;
};

extern struct EkrSpEff gEkrSpEffBuff[2];
struct EkrSpEff *GetEkrSpEff(struct Anim *anim);
u16 GetEkrSpEffAttr(struct Anim *anim);
void AddEkrSpEffAttr(struct Anim *anim, u16 attr_bitfile);
u32 GetEkrSpEffType(struct Anim *anim);
// ??? GetEkrSpEffType_(???);
// ??? SetEkrSpEffType(???);
// ??? GetEkrSpEffUnk1(???);
void SetEkrSpEffUnk1(u16 attr);

struct ProcEfxDKIntro {
    PROC_HEADER;

    /* 29 */ u8 _pad_29[0x2C - 0x29];
    /* 2C */ s16 unk2C;
    /* 2E */ s16 unk2E;
    /* 30 */ u8 _pad_30[0x5C - 0x30];
    /* 5C */ struct Anim *anim5C;
};

// ??? NewEkrTogiInitPROC(???);
// ??? sub_805B104(???);
// ??? sub_805B18C(???);
// ??? sub_805B200(???);
// ??? sub_805B264(???);
// ??? NewEkrTogiEndPROC(???);
// ??? sub_805B290(???);
// ??? sub_805B2BC(???);
// ??? sub_805B320(???);
// ??? NewEkrTogiColor(???);
// ??? EndEkrTogiColor(???);
// ??? sub_805B394(???);
// ??? StartSpellAnimation(???);
// ??? sub_805B3FC(???);
// ??? sub_805B400(???);
// ??? sub_805B444(???);
// ??? EfxResetRSTMain(???);
// ??? sub_805B4E8(???);
// ??? EfxTwoBaiRSTMain(???);
// ??? sub_805B554(???);
// ??? sub_805B584(???);
// ??? DummvRSTMain(???);
// ??? sub_805B5E0(???);
// ??? EfxRestWINMain(???);
// ??? sub_805B724(???);
// ??? sub_805B750(???);
// ??? sub_805B77C(???);
// ??? sub_805B7BC(???);
// ??? sub_805B7FC(???);
// ??? sub_805B828(???);
// ??? sub_805B93C(???);
// ??? sub_805B94C(???);
// ??? sub_805B958(???);
// ??? sub_805BA1C(???);
// ??? sub_805BA64(???);
// ??? sub_805BB24(???);
// ??? sub_805BB84(???);
// ??? StartSpellThing_MagicQuake(???);
// ??? Loop6C_efxMagicQUAKE(???);
// ??? StartSpellAnimDummy(???);
// ??? Loop6C_efxDummymagic(???);
// ??? StartSpellAnimHandAxe(???);
// ??? sub_805BF40(???);
// ??? sub_805BFDC(???);
// ??? sub_805C080(???);
// ??? sub_805C0DC(???);
// ??? sub_805C104(???);
// ??? sub_805C188(???);
// ??? sub_805C1C8(???);
// ??? sub_805C20C(???);
// ??? sub_805C21C(???);
// ??? StartSpellAnimArrow(???);
// ??? sub_805C29C(???);
// ??? sub_805C358(???);
// ??? sub_805C3C0(???);
// ??? StartSpellAnimJavelin(???);
// ??? sub_805C44C(???);
// ??? sub_805C4A8(???);
// ??? sub_805C504(???);
// ??? sub_805C560(???);
// ??? sub_805C5BC(???);
// ??? sub_805C618(???);
// ??? sub_805C674(???);
// ??? sub_805C6D0(???);
// ??? sub_805C72C(???);
// ??? sub_805C788(???);
// ??? sub_805C7E4(???);
// ??? sub_805C88C(???);
// ??? sub_805C904(???);
// ??? StartSpellAnimSong(???);
// ??? sub_805C96C(???);
// ??? sub_805CA64(???);
// ??? sub_805CAC4(???);
// ??? sub_805CB40(???);
// ??? sub_805CBA8(???);
// ??? StartSpellAnimDance(???);
// ??? sub_805CC14(???);
// ??? sub_805CD0C(???);
// ??? sub_805CD5C(???);
// ??? sub_805CE1C(???);
// ??? sub_805CE94(???);
// ??? nullsub_42(???);
// ??? sub_805CEC8(???);
// ??? sub_805CF04(???);
// ??? sub_805CFC0(???);
// ??? sub_805D030(???);
// ??? StartSpellAnimFireBreath(???);
// ??? sub_805D09C(???);
// ??? sub_805D14C(???);
// ??? sub_805D1FC(???);
// ??? sub_805D260(???);
// ??? sub_805D2B4(???);
// ??? sub_805D2EC(???);
// ??? sub_805D328(???);
// ??? StartSpellAnimIceBreath(???);
// ??? sub_805D3C4(???);
// ??? sub_805D444(???);
// ??? sub_805D4B8(???);
// ??? StartSpellAnimDarkBreath(???);
// ??? Loop6C_efxDarkbreath(???);
// ??? sub_805D59C(???);
// ??? sub_805D5EC(???);
// ??? sub_805D644(???);
// ??? sub_805D680(???);
// ??? sub_805D6CC(???);
// ??? sub_805D774(???);
// ??? StartSpellAnimThunder(???);
// ??? Loop6C_efxThunder(???);
// ??? sub_805D8B4(???);
// ??? sub_805D938(???);
// ??? sub_805D9BC(???);
// ??? sub_805D9F8(???);
// ??? sub_805DA44(???);
// ??? sub_805DAA4(???);
// ??? StartSpellAnimFire(???);
// ??? StartSpellAnimElfire(???);
// ??? Loop6C_efxFire(???);
// ??? sub_805DC64(???);
// ??? Loop6C_efxFireBG(???);
// ??? sub_805DD1C(???);
// ??? sub_805DDA8(???);
// ??? StartSubSpell_efxFireHITBG(???);
// ??? sub_805DE74(???);
// ??? StartSubSpell_efxElfireBG(???);
// ??? sub_805DF70(???);
// ??? StartSubSpell_efxElfireBGCOL(???);
// ??? sub_805DFE8(???);
// ??? StartSubSpell_efxElfireOBJ(???);
// ??? sub_805E0B4(???);
// ??? StartSpellAnimFimbulvetr(???);
// ??? sub_805E120(???);
// ??? sub_805E230(???);
// ??? sub_805E2B4(???);
// ??? sub_805E318(???);
// ??? sub_805E39C(???);
// ??? sub_805E430(???);
// ??? sub_805E494(???);
// ??? sub_805E4C4(???);
// ??? sub_805E510(???);
// ??? sub_805E53C(???);
// ??? sub_805E694(???);
// ??? sub_805E754(???);
// ??? sub_805E790(???);
// ??? sub_805E850(???);
// ??? sub_805E8A4(???);
// ??? sub_805E900(???);
// ??? sub_805E924(???);
// ??? sub_805E968(???);
// ??? sub_805E98C(???);
// ??? sub_805E9B0(???);
// ??? sub_805E9E4(???);
// ??? sub_805EA4C(???);
// ??? sub_805EAAC(???);
// ??? sub_805EAF0(???);
// ??? sub_805EB54(???);
// ??? sub_805EB98(???);
// ??? sub_805EBD4(???);
// ??? sub_805ECD4(???);
// ??? sub_805ED44(???);
// ??? sub_805ED98(???);
// ??? sub_805EDDC(???);
// ??? sub_805EE24(???);
// ??? sub_805EEAC(???);
// ??? sub_805EED8(???);
// ??? sub_805EF14(???);
// ??? sub_805F004(???);
// ??? sub_805F0B0(???);
// ??? sub_805F140(???);
// ??? sub_805F1A4(???);
// ??? sub_805F1E8(???);
// ??? sub_805F234(???);
// ??? sub_805F24C(???);
// ??? sub_805F288(???);
// ??? sub_805F2C4(???);
// ??? sub_805F300(???);
// ??? sub_805F32C(???);
// ??? StartSpellAnimNosferatu(???);
// ??? Loop6C_efxResire(???);
// ??? sub_805F4B0(???);
// ??? sub_805F53C(???);
// ??? sub_805F5DC(???);
// ??? sub_805F660(???);
// ??? sub_805F6FC(???);
// ??? sub_805F76C(???);
// ??? sub_805F7D4(???);
// ??? sub_805F838(???);
// ??? sub_805F868(???);
// ??? sub_805F8B4(???);
// ??? sub_805F8F0(???);
// ??? sub_805F9A8(???);
// ??? sub_805FA28(???);
// ??? StartSpellAnimPurge(???);
// ??? sub_805FB24(???);
// ??? sub_805FB60(???);
// ??? sub_805FC90(???);
// ??? sub_805FCE0(???);
// ??? sub_805FD5C(???);
// ??? sub_805FD90(???);
// ??? sub_805FDFC(???);
// ??? sub_805FE68(???);
// ??? nullsub_41(???);
// ??? StartSpellAnimDivine(???);
// ??? DivineSfxLoop(???);
// ??? sub_805FFB0(???);
// ??? sub_8060034(???);
// ??? sub_80600B8(???);
// ??? sub_806013C(???);
// ??? sub_80601E0(???);
// ??? sub_8060254(???);
// ??? sub_8060284(???);
// ??? nullsub_40(???);
// ??? sub_806028C(???);
// ??? sub_80602C8(???);
// ??? sub_8060440(???);
// ??? sub_80604B0(???);
// ??? sub_8060514(???);
// ??? sub_806056C(???);
// ??? sub_80605E8(???);
// ??? sub_8060664(???);
// ??? sub_806067C(???);
// ??? sub_80606D8(???);
// ??? sub_8060734(???);
// ??? sub_8060790(???);
// ??? sub_80607D8(???);
// ??? sub_8060838(???);
// ??? sub_806088C(???);
// ??? StartSpellAnimFenrir(???);
// ??? sub_80608E0(???);
// ??? sub_8060A9C(???);
// ??? sub_8060B2C(???);
// ??? sub_8060B48(???);
// ??? sub_8060B7C(???);
// ??? sub_8060BC4(???);
// ??? sub_8060BD4(???);
// ??? sub_8060C18(???);
// ??? sub_8060C78(???);
// ??? sub_8060CAC(???);
// ??? sub_8060D3C(???);
// ??? sub_8060DC4(???);
// ??? sub_8060E90(???);
// ??? sub_8060ED8(???);
// ??? sub_8060F24(???);
// ??? sub_8060FA4(???);
// ??? StartSpellAnimHeal(???);
// ??? sub_806104C(???);
// ??? StartSpellAnimMend(???);
// ??? sub_8061180(???);
// ??? StartSpellAnimRecover(???);
// ??? sub_80612E4(???);
// ??? sub_8061420(???);
// ??? sub_8061448(???);
// ??? sub_8061594(???);
// ??? sub_8061650(???);
// ??? sub_8061704(???);
// ??? sub_8061774(???);
// ??? sub_80617E4(???);
// ??? sub_8061854(???);
// ??? sub_806189C(???);
// ??? sub_80618D8(???);
// ??? sub_80618F4(???);
// ??? sub_806196C(???);
// ??? sub_80619CC(???);
// ??? sub_8061A30(???);
// ??? sub_8061A64(???);
// ??? sub_8061A98(???);
// ??? sub_8061ACC(???);
// ??? sub_8061B14(???);
// ??? sub_8061BE4(???);
// ??? sub_8061C18(???);
// ??? sub_8061C48(???);
// ??? sub_8061C78(???);
// ??? sub_8061D28(???);
// ??? sub_8061D78(???);
// ??? sub_8061DF8(???);
// ??? sub_8061E44(???);
// ??? sub_8061E8C(???);
// ??? sub_8061F78(???);
// ??? sub_8062058(???);
// ??? sub_80620A4(???);
// ??? sub_80620EC(???);
// ??? sub_8062128(???);
// ??? sub_80622A0(???);
// ??? sub_80622F4(???);
// ??? sub_8062358(???);
// ??? sub_80623D0(???);
// ??? StartSpellAnimSilence(???);
// ??? sub_806241C(???);
// ??? sub_8062524(???);
// ??? sub_80625B0(???);
// ??? sub_8062608(???);
// ??? sub_8062660(???);
// ??? StartSpellAnimSleep(???);
// ??? sub_80626B4(???);
// ??? sub_80627B4(???);
// ??? sub_8062840(???);
// ??? sub_8062898(???);
// ??? sub_80628F0(???);
// ??? sub_8062934(???);
// ??? sub_8062944(???);
// ??? sub_8062968(???);
// ??? sub_8062988(???);
// ??? StartSpellAnimHammerne(???);
// ??? sub_80629D4(???);
// ??? sub_8062AF4(???);
// ??? sub_8062B48(???);
// ??? sub_8062BAC(???);
// ??? sub_8062C04(???);
// ??? StartSpellAnimBerserk(???);
// ??? sub_8062C50(???);
// ??? sub_8062D30(???);
// ??? sub_8062E44(???);
// ??? sub_8062EAC(???);
// ??? sub_8062ED8(???);
// ??? sub_8062F3C(???);
// ??? sub_8062F4C(???);
// ??? sub_8062FA4(???);
// ??? sub_8062FBC(???);
// ??? sub_8062FF8(???);
// ??? sub_8063034(???);
// ??? sub_8063070(???);
// ??? sub_80630AC(???);
// ??? sub_80630E8(???);
// ??? sub_8063124(???);
// ??? sub_8063160(???);
// ??? sub_806319C(???);
// ??? sub_80631D8(???);
// ??? sub_8063214(???);
// ??? sub_8063250(???);
// ??? sub_806331C(???);
// ??? sub_8063378(???);
// ??? sub_80633D0(???);
// ??? sub_8063428(???);
// ??? sub_8063468(???);
// ??? StartSpellAnimShine(???);
// ??? sub_80634BC(???);
// ??? sub_8063590(???);
// ??? sub_80635E8(???);
// ??? sub_806364C(???);
// ??? sub_80636D8(???);
// ??? sub_806376C(???);
// ??? sub_80637B0(???);
// ??? sub_80637F8(???);
// ??? sub_8063840(???);
// ??? sub_80638F0(???);
// ??? sub_8063948(???);
// ??? StartSpellAnimLuna(???);
// ??? sub_80639B0(???);
// ??? sub_8063B6C(???);
// ??? sub_8063BC8(???);
// ??? sub_8063C20(???);
// ??? sub_8063C40(???);
// ??? sub_8063CFC(???);
// ??? sub_8063D1C(???);
// ??? sub_8063D64(???);
// ??? sub_8063E58(???);
// ??? sub_8063E74(???);
// ??? sub_8063EA0(???);
// ??? sub_8063EE8(???);
// ??? sub_8063EF8(???);
// ??? sub_8063F3C(???);
// ??? sub_8063FC0(???);
// ??? sub_8064024(???);
// ??? sub_8064060(???);
// ??? sub_80640D0(???);
// ??? sub_806416C(???);
// ??? sub_80641F0(???);
// ??? sub_806428C(???);
// ??? sub_80642BC(???);
// ??? sub_8064308(???);
// ??? sub_8064344(???);
// ??? sub_80644E0(???);
// ??? sub_806454C(???);
// ??? sub_8064568(???);
// ??? sub_80645FC(???);
// ??? sub_806464C(???);
// ??? sub_806466C(???);
// ??? sub_80646B0(???);
// ??? sub_80646C0(???);
// ??? sub_80646FC(???);
// ??? sub_8064720(???);
// ??? sub_80647D0(???);
// ??? sub_80647F0(???);
// ??? sub_8064838(???);
// ??? sub_806491C(???);
// ??? sub_8064938(???);
// ??? sub_8064958(???);
// ??? sub_806499C(???);
// ??? sub_80649E4(???);
// ??? sub_8064AC8(???);
// ??? sub_8064AE4(???);
// ??? sub_8064B04(???);
// ??? sub_8064B48(???);
// ??? sub_8064B90(???);
// ??? sub_8064BFC(???);
// ??? sub_8064C28(???);
// ??? sub_8064C80(???);
// ??? nullsub_51(???);
// ??? sub_8064D00(???);
// ??? sub_8064DA8(???);
// ??? sub_8064DC4(???);
// ??? sub_8064DE4(???);
// ??? sub_8064E2C(???);
// ??? StartSpellAnimAura(???);
// ??? sub_8064EB0(???);
// ??? sub_8065008(???);
// ??? sub_806509C(???);
// ??? sub_8065130(???);
// ??? sub_80651C4(???);
// ??? sub_806521C(???);
// ??? sub_8065300(???);
// ??? sub_806531C(???);
// ??? sub_806533C(???);
// ??? sub_8065384(???);
// ??? sub_80653CC(???);
// ??? sub_806542C(???);
// ??? sub_8065490(???);
// ??? nullsub_53(???);
// ??? sub_8065498(???);
// ??? sub_80654F8(???);
// ??? sub_80655C4(???);
// ??? sub_8065624(???);
// ??? sub_8065634(???);
// ??? sub_8065670(???);
// ??? sub_80656AC(???);
// ??? sub_80656E8(???);
// ??? sub_8065724(???);
// ??? StartSpellAnimIvaldi(???);
// ??? Loop6C_efxIvaldi(???);
// ??? StartSpellBG_IvaldiBG1(???);
// ??? Loop6C_efxIvaldiBG1(???);
// ??? StartSpellBG_IvaldiBG2(???);
// ??? Loop6C_efxIvaldiBG2(???);
// ??? StartSpellBG_IvaldiBG3(???);
// ??? Loop6C_efxIvaldiBG3(???);
// ??? StartSpellBG_IvaldiBG4(???);
// ??? sub_8065CA0(???);
// ??? PrepareSomeIvaldiParticleGraphics(???);
// ??? StartSpellOBJ_IvaldiFall(???);
// ??? sub_8065DF8(???);
// ??? StartSpellOBJ_IvaldiSideWash(???);
// ??? Loop6C_efxIvaldiOBJSideWash(???);
// ??? sub_8066060(???);
// ??? sub_80660B4(???);
// ??? sub_8066258(???);
// ??? sub_806635C(???);
// ??? sub_8066390(???);
// ??? sub_8066434(???);
// ??? sub_8066470(???);
// ??? sub_80664A8(???);
// ??? sub_8066514(???);
// ??? sub_8066550(???);
// ??? sub_80666D0(???);
// ??? sub_8066758(???);
// ??? sub_80667E0(???);
// ??? sub_806683C(???);
// ??? sub_80668DC(???);
// ??? sub_8066914(???);
// ??? sub_806699C(???);
// ??? sub_8066A0C(???);
// ??? sub_8066A94(???);
// ??? sub_8066B14(???);
// ??? sub_8066B40(???);
// ??? sub_8066BBC(???);
// ??? sub_8066BD4(???);
// ??? sub_8066C1C(???);
// ??? sub_8066C74(???);
// ??? sub_8066C98(???);
// ??? sub_8066CB8(???);
// ??? sub_8066D7C(???);
// ??? sub_8066DB0(???);
// ??? sub_8066E74(???);
// ??? sub_8066EA8(???);
// ??? sub_8066EC8(???);
// ??? sub_8066F90(???);
// ??? sub_8066FC4(???);
// ??? sub_80670A8(???);
// ??? sub_80670DC(???);
// ??? sub_80671C0(???);
// ??? sub_80671F4(???);
// ??? sub_8067244(???);
// ??? sub_8067400(???);
// ??? sub_80674A0(???);
// ??? StartSpellAnimStone(???);
// ??? sub_8067510(???);
// ??? sub_80675D4(???);
// ??? sub_8067660(???);
// ??? sub_80676E4(???);
// ??? sub_8067764(???);
// ??? StartSpellAnimEvilEye(???);
// ??? sub_80677D4(???);
// ??? sub_806788C(???);
// ??? sub_8067914(???);
// ??? sub_8067984(???);
// ??? sub_8067A30(???);
// ??? sub_8067AA0(???);
// ??? sub_8067B48(???);
// ??? StartSpellAnimNaglfar(???);
// ??? Loop6C_efxNaglfar(???);
// ??? sub_8067DC4(???);
// ??? Loop6C_efxNaglfarBG(???);
// ??? sub_8067E98(???);
// ??? Loop6C_efxNaglfarBG2(???);
// ??? sub_8067F64(???);
// ??? sub_8067FB8(???);
// ??? sub_8068028(???);
// ??? sub_806807C(???);
// ??? sub_80680EC(???);
// ??? sub_8068208(???);
// ??? sub_806823C(???);
// ??? sub_80682E0(???);
// ??? sub_8068314(???);
// ??? sub_8068348(???);
// ??? sub_8068614(???);
// ??? sub_8068638(???);
// ??? sub_8068680(???);
// ??? sub_8068738(???);
// ??? sub_80687D0(???);
// ??? sub_80687E4(???);
// ??? sub_806881C(???);
// ??? sub_80688C0(???);
// ??? sub_8068970(???);
// ??? sub_80689D4(???);
// ??? sub_8068A28(???);
// ??? sub_8068A60(???);
// ??? sub_8068A9C(???);
// ??? sub_8068AFC(???);
// ??? sub_8068B80(???);
// ??? sub_8068BB8(???);
// ??? sub_8068D20(???);
// ??? sub_8068D78(???);
// ??? sub_8068D9C(???);
// ??? sub_8068DD8(???);
// ??? sub_8068E14(???);
// ??? sub_8068E50(???);
// ??? sub_8068E8C(???);
// ??? sub_8068EC8(???);
// ??? sub_8068F04(???);
// ??? sub_8068F40(???);
// ??? sub_8068F7C(???);
// ??? sub_8068FB8(???);
// ??? sub_8068FF4(???);
// ??? sub_8069030(???);
// ??? sub_806906C(???);
// ??? sub_80690A8(???);
// ??? sub_80690E4(???);
// ??? sub_8069100(???);
// ??? sub_80692B0(???);
// ??? sub_806935C(???);
// ??? sub_80693CC(???);
// ??? sub_8069400(???);
// ??? sub_8069488(???);
// ??? sub_8069528(???);
// ??? sub_8069530(???);
// ??? sub_80696F0(???);
// ??? sub_8069704(???);
// ??? sub_806977C(???);
// ??? sub_80697F4(???);
// ??? sub_8069878(???);
// ??? sub_80699A8(???);
// ??? sub_8069AC4(???);
// ??? sub_8069AFC(???);
// ??? sub_8069B68(???);
// ??? sub_8069C18(???);
// ??? sub_8069CDC(???);
// ??? sub_8069E88(???);
// ??? StartSpellAnimCrimsonEye(???);
// ??? sub_8069F00(???);
// ??? sub_806A008(???);
// ??? sub_806A068(???);
// ??? sub_806A0CC(???);
// ??? sub_806A138(???);
// ??? sub_806A1EC(???);
// ??? sub_806A3CC(???);
// ??? sub_806A3F4(???);
// ??? sub_806A47C(???);
// ??? sub_806A4CC(???);
// ??? sub_806A560(???);
// ??? sub_806A578(???);
// ??? sub_806A590(???);
// ??? sub_806A634(???);
// ??? sub_806A64C(???);
// ??? sub_806A664(???);
// ??? sub_806A6C4(???);
// ??? sub_806A6FC(???);
// ??? sub_806A7C4(???);
// ??? sub_806A8E8(???);
// ??? sub_806A9C4(???);
// ??? sub_806AAA0(???);
// ??? sub_806ABCC(???);
// ??? sub_806AEF4(???);
// ??? sub_806AF30(???);
// ??? sub_806B088(???);
// ??? sub_806B0AC(???);
// ??? sub_806B11C(???);
// ??? sub_806B134(???);
// ??? sub_806B194(???);
// ??? sub_806B1E8(???);
// ??? sub_806B24C(???);
// ??? sub_806B2C0(???);
// ??? sub_806B33C(???);
// ??? sub_806B344(???);
// ??? sub_806B4E4(???);
// ??? sub_806B4F8(???);
// ??? sub_806B534(???);
// ??? sub_806B64C(???);
// ??? sub_806B664(???);
// ??? sub_806B680(???);
// ??? sub_806B73C(???);
// ??? sub_806B7A8(???);
// ??? sub_806B830(???);
// ??? sub_806B89C(???);
// ??? sub_806B938(???);
// ??? sub_806B940(???);
// ??? sub_806BACC(???);
// ??? sub_806BBDC(???);
// ??? sub_806BBF0(???);
// ??? sub_806BC98(???);
// ??? sub_806BD94(???);
// ??? sub_806BEEC(???);
// ??? sub_806C050(???);
// ??? sub_806C0B8(???);
// ??? sub_806C14C(???);
// ??? sub_806C154(???);
// ??? sub_806C1B8(???);
// ??? sub_806C2D4(???);
// ??? sub_806C464(???);
// ??? sub_806C478(???);
// ??? sub_806C608(???);
void NewEfxDamageMojiEffect(struct Anim *anim, int r1);
// ??? efxDamageMojiEffectMain(???);
// ??? sub_806C67C(???);
// ??? efxDamageMojiEffectOBJMain(???);
// ??? sub_806C71C(???);
// ??? efxCriricalEffectMain(???);
// ??? sub_806C798(???);
// ??? efxCriricalEffectBGMain(???);
// ??? sub_806C810(???);
// ??? efxCriricalEffectBGCOLMain(???);
// ??? sub_806C87C(???);
// ??? efxNormalEffectMain(???);
// ??? sub_806C904(???);
// ??? efxNormalEffectBGMain(???);
// ??? sub_806C9E8(???);
// ??? efxPierceCriticalEffectMain(???);
// ??? sub_806CA38(???);
// ??? efxPierceCriticalEffectBGMain(???);
// ??? sub_806CAB0(???);
// ??? efxPierceCriticalEffectBGCOLMain(???);
// ??? sub_806CB1C(???);
// ??? efxPierceNormalEffectMain(???);
// ??? sub_806CB7C(???);
// ??? efxPierceNormalEffectBGMain(???);
// ??? sub_806CC60(???);
// ??? EfxYushaSpinShieldMain(???);
// ??? sub_806CC94(???);
// ??? efxYushaSpinShieldOBJ_806CD14(???);
// ??? efxYushaSpinShieldOBJ_806CD7C(???);
// ??? efxYushaSpinShieldOBJ_806CDA4(???);
// ??? efxYushaSpinShieldOBJ_806CE08(???);
// ??? sub_806CE30(???);
// ??? EfxHurtmutEff00Main(???);
// ??? sub_806CE80(???);
// ??? efxHurtmutEff00OBJ_806CEC4(???);
// ??? efxHurtmutEff00OBJ_806CF10(???);
// ??? efxHurtmutEff00OBJ_806CF5C(???);
// ??? sub_806CF80(???);
// ??? efxHurtmutEff01OBJ_806CFC4(???);
// ??? efxHurtmutEff01OBJ_806D010(???);
// ??? efxHurtmutEff01OBJ_806D05C(???);
// ??? sub_806D080(???);
// ??? EfxMagfcastMain(???);
// ??? sub_806D1B4(???);
// ??? EfxMagfcastBGMain(???);
// ??? sub_806D320(???);
// ??? sub_806D350(???);
// ??? sub_806D35C(???);
// ??? sub_806D540(???);
// ??? sub_806D570(???);
// ??? sub_806D59C(???);
// ??? sub_806D5A8(???);
// ??? sub_806D62C(???);
// ??? sub_806D65C(???);
// ??? sub_806D678(???);
// ??? sub_806D6E8(???);
// ??? sub_806D704(???);
// ??? sub_806D764(???);
// ??? sub_806D7D8(???);
// ??? sub_806D828(???);
// ??? sub_806D89C(???);
// ??? sub_806D8D0(???);
// ??? sub_806D980(???);
// ??? sub_806D98C(???);
// ??? sub_806D9AC(???);
// ??? sub_806DA1C(???);
// ??? sub_806DA68(???);
// ??? sub_806DA90(???);
// ??? sub_806DAB0(???);
// ??? sub_806DB34(???);
// ??? sub_806DB54(???);
// ??? sub_806DB9C(???);
// ??? sub_806DBBC(???);
// ??? sub_806DC08(???);
// ??? sub_806DCA4(???);
// ??? sub_806DD34(???);
// ??? sub_806DFA4(???);
// ??? sub_806DFD0(???);
// ??? sub_806E014(???);
// ??? sub_806E034(???);
// ??? sub_806E078(???);
// ??? sub_806E0D0(???);
// ??? sub_806E128(???);
// ??? sub_806E158(???);
// ??? sub_806E1F0(???);
// ??? sub_806E290(???);
// ??? nullsub_17(???);
// ??? sub_806E310(???);
// ??? sub_806E444(???);
// ??? sub_806E58C(???);
// ??? sub_806E610(???);
// ??? sub_806E638(???);
// ??? sub_806E6E0(???);
// ??? sub_806E79C(???);
// ??? sub_806E868(???);
// ??? sub_806E8A4(???);
void sub_806E8F0(void);
void sub_806E904(void);
void sub_806E920(void);
// ??? sub_806E93C(???);
// ??? sub_806E948(???);
// ??? sub_806E954(???);
// ??? sub_806E95C(???);
// ??? sub_806E9B4(???);
// ??? sub_806E9E4(???);
// ??? sub_806EA38(???);
// ??? sub_806EAA4(???);
// ??? sub_806EAD4(???);
// ??? sub_806EAFC(???);
// ??? sub_806EB2C(???);
// ??? sub_806EB54(???);
// ??? nullsub_73(???);
// ??? sub_806EB7C(???);
// ??? sub_806EB9C(???);
// ??? sub_806EBBC(???);
// ??? sub_806EC1C(???);
// ??? sub_806EC68(???);
// ??? sub_806ECE8(???);
// ??? sub_806ED0C(???);
// ??? sub_806ED2C(???);
// ??? sub_806ED54(???);
// ??? sub_806EDB0(???);
// ??? sub_806EE34(???);
// ??? sub_806EE68(???);
// ??? sub_806EEA8(???);
// ??? sub_806EF24(???);
// ??? sub_806EF48(???);
// ??? sub_806EF64(???);
// ??? sub_806EFB8(???);
// ??? sub_806F00C(???);
// ??? sub_806F058(???);
// ??? sub_806F08C(???);
// ??? sub_806F0CC(???);
// ??? sub_806F0FC(???);
// ??? sub_806F118(???);
// ??? sub_806F184(???);
// ??? sub_806F1E8(???);
// ??? sub_806F210(???);
// ??? sub_806F230(???);
// ??? sub_806F248(???);
// ??? sub_806F2A0(???);
// ??? sub_806F304(???);
// ??? sub_806F38C(???);
// ??? sub_806F3F8(???);
// ??? sub_806F450(???);
// ??? sub_806F47C(???);
// ??? sub_806F4B4(???);
// ??? sub_806F4C0(???);
// ??? sub_806F4F8(???);
// ??? sub_806F530(???);
// ??? sub_806F568(???);
// ??? sub_806F594(???);
// ??? sub_806F5BC(???);
// ??? sub_806F5E0(???);
// ??? sub_806F648(???);
// ??? sub_806F668(???);
// ??? sub_806F6B4(???);
// ??? sub_806F6D4(???);
// ??? sub_806F6EC(???);
// ??? sub_806F704(???);
// ??? sub_806F75C(???);
// ??? sub_806F7C0(???);
// ??? sub_806F820(???);
// ??? sub_806F844(???);
// ??? sub_806F864(???);
// ??? sub_806F87C(???);
// ??? sub_806F894(???);
// ??? sub_806F8F0(???);
// ??? sub_806F968(???);
// ??? sub_806F9D8(???);
// ??? sub_806F9FC(???);
u32 sub_806FAB0(void);
// ??? sub_806FAD8(???);
void sub_806FB2C(int, int);
void sub_806FBB8(void);
bool CheckEkrSpecialClassIntroAnimDone(struct Anim *anim);
bool sub_806FC14(struct Anim *anim);
// ??? sub_806FC30(???);
// ??? sub_806FC50(???);
// ??? EfxDracoZombiePrepareTSA(???);
// ??? EfxDracoZombiePrepareImg(???);
// ??? sub_806FD74(???);
// ??? sub_806FEA4(???);
// ??? sub_806FED4(???);
// ??? sub_806FF00(???);
// ??? sub_806FF48(???);
// ??? sub_80700CC(???);
// ??? sub_80701A0(???);
void EfxDoDracoZombieIntroAnim(struct Anim *anim);
void sub_80701E8(struct Anim *anim);
// ??? sub_80701F4(???);
// ??? sub_8070204(???);
bool sub_8070214(struct Anim *anim);
// ??? sub_8070234(???);
void sub_8070254(void);
// ??? sub_807027C(???);
// ??? sub_80702D0(???);
// ??? sub_80702FC(???);
// ??? sub_807032C(???);
// ??? sub_807035C(???);
// ??? sub_8070380(???);
// ??? sub_807038C(???);
// ??? sub_80703C4(???);
// ??? sub_8070568(???);
// ??? sub_80705A8(???);
// ??? sub_8070618(???);
// ??? sub_8070670(???);
// ??? sub_80706E0(???);
// ??? sub_8070710(???);
// ??? sub_80707C0(???);
// ??? sub_80707FC(???);
// ??? sub_8070874(???);
// ??? sub_80708A0(???);
void EfxDoMyrrhIntroAnim(struct Anim *anim);
