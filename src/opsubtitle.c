#include "global.h"

#include "hardware.h"
#include "m4a.h"
#include "soundwrapper.h"
#include "bmlib.h"
#include "spline.h"
#include "sysutil.h"

#include "constants/songs.h"

/*
The opening monologue that introduces the Sacred Stones / associated lore.
*/

struct OpSubtitleProc
{
    /* 00 */ PROC_HEADER;

    /* 29 */ s8 index;
    /* 2A */ s16 timer_2a;
    /* 2C */ s16 timer_2c;

    /* 2E */ STRUCT_PAD(0x2E, 0x4C);

    /* 4C */ s16 unk_4c;
    /* 4E */ s16 unk_4e;
};

struct OpSubtitleEnt
{
    /* 00 */ void * gfx;
    /* 04 */ void * tsa;
    /* 08 */ int timer;
};

// clang-format off

const struct OpSubtitleEnt gOpSubtitleGfxLut[] =
{
    {
        /*
        "In an age long past...
        evil flooded over the land.
        Creatures awash in the dark
        tide ran wild, pushing mankind
        to the brink of annihilation."
        */
        gGfx_OpSubtitle_00,
        gTsa_OpSubtitle_00,
        335,
    },
    {
        /*
        "In its despair, mankind
        appealed to the heavens, and
        from a blinding light came hope."
        */
        gGfx_OpSubtitle_01,
        gTsa_OpSubtitle_01,
        280,
    },
    {
        /*
        "The Sacred Stones"
        */
        gGfx_OpSubtitle_02,
        gTsa_OpSubtitle_02,
        120,
    },
    {
        /*
        "These five glorious treasures
        held the power to dispel evil."
        */
        gGfx_OpSubtitle_03,
        gTsa_OpSubtitle_03,
        280,
    },
    {
        /*
        "The hero Grado and his warriors
        used the Sacred Stones to combat
        evil's darkness. They defeated
        the Demon King and sealed his
        soul away within the stones."
        */
        gGfx_OpSubtitle_04,
        gTsa_OpSubtitle_04,
        330,
    },
    {
        /*
        "With the darkness imprisoned,
        peace returned to Magvel."
        */
        gGfx_OpSubtitle_05,
        gTsa_OpSubtitle_05,
        300,
    },
    {
        /*
        "But this peace would not last..."
        */
        gGfx_OpSubtitle_06,
        gTsa_OpSubtitle_06,
        250,
    },
};

// clang-format on

//! FE8U = 0x080C488C
void sub_80C488C(int bg)
{
    int offset = GetBackgroundTileDataOffset(bg);
    Decompress(Img_CommGameBgScreen, BG_CHR_ADDR(0x0) + offset);
    CpuFastFill(0, BG_CHR_ADDR(0x280) + offset, CHR_SIZE);
    BG_EnableSyncByMask(1 << bg);

    CpuFastFill(RGB(7, 5, 2) | RGB(7, 5, 2) << 16, PAL_BG(14), PLTT_SIZE_4BPP);
    EnablePaletteSync();

    return;
}

//! FE8U = 0x080C48F0
void sub_80C48F0(int bg)
{
    int i;

    u16 * mapBuf = BG_GetMapBuffer(bg);
    int tileref = TILEREF(0x0, 15);

    for (i = 0; i < 0x280; i++)
    {
        *mapBuf++ = tileref + i;
    }

    return;
}

//! FE8U = 0x080C4918
void OpSubtitle_HandleStartPress(ProcPtr proc)
{
    if (gKeyStatusPtr->newKeys & START_BUTTON)
    {
        Sound_FadeOutBGM(1);
        Proc_Goto(proc, 6);
    }

    return;
}

// clang-format off

u16 CONST_DATA gBgConfig_OpSubtitle[] =
{
    0x0000, 0x6000, 0,
    0x0000, 0x6800, 0,
    0x8000, 0x7000, 0,
    0x8000, 0x7800, 0,
};

// clang-format on

//! FE8U = 0x080C4944
void OpSubtitle_Init(struct OpSubtitleProc * proc)
{
    SetupBackgrounds(gBgConfig_OpSubtitle);

    gLCDControlBuffer.dispcnt.mode = DISPCNT_MODE_1;

    gLCDControlBuffer.bg0cnt.priority = 3;
    gLCDControlBuffer.bg1cnt.priority = 3;
    gLCDControlBuffer.bg2cnt.priority = 0;
    gLCDControlBuffer.bg3cnt.priority = 3;

    SetDispEnable(1, 0, 0, 0, 1);

    gLCDControlBuffer.bg2cnt.screenSize = 1;
    gLCDControlBuffer.bg2cnt.areaOverflowMode = 0;

    SetWinEnable(0, 0, 0);

    SetBlendAlpha(0, 16);
    SetBlendTargetA(0, 0, 1, 0, 0);
    SetBlendTargetB(1, 1, 0, 0, 1);

    Decompress(Img_ChapterIntro_LensFlare, BG_CHR_ADDR(0x0) + GetBackgroundTileDataOffset(BG_2));
    ApplyPalettes(Pal_ChapterIntro_LensFlare, 0, 3);

    BG_Fill(gBG2TilemapBuffer, 0);
    BG_EnableSyncByMask(BG2_SYNC_BIT);

    StartBgm(SONG_PROLOGUE, NULL);

    proc->index = 0;
    proc->timer_2a = 60;

    return;
}

//! FE8U = 0x080C4A3C
void Subtitle_LightFlareFx_Init(struct OpSubtitleProc * proc)
{
    proc->unk_4c = 0;
    proc->unk_4e = 0;

    sub_800154C(gBG2TilemapBuffer, Tsa_08B18D68, 0, 5);

    BG_EnableSyncByMask(BG2_SYNC_BIT);

    SetDispEnable(1, 0, 1, 0, 0);

    return;
}

//! FE8U = 0x080C4A88
void Subtitle_LightFlareFx_Loop(struct OpSubtitleProc * proc)
{
    int scale;
    int alpha;
    int xOffset;
    int yOffset;

    if (proc->unk_4c < 30)
    {
        scale = Interpolate(INTERPOLATE_RCUBIC, 4, 50, proc->unk_4c, 30);
        alpha = Interpolate(INTERPOLATE_RSQUARE, 0, 16, proc->unk_4c, 30);
    }
    else
    {
        scale = Interpolate(INTERPOLATE_LINEAR, 50, 100, proc->unk_4c - 30, 30);
        alpha = Interpolate(INTERPOLATE_LINEAR, 16, 0, proc->unk_4c - 30, 30);
    }

    if (scale > 49)
    {
        scale = 100 - scale;
    }

    xOffset = Interpolate(INTERPOLATE_LINEAR, 0, 214, proc->unk_4c, 60);
    yOffset = Interpolate(INTERPOLATE_LINEAR, 16, 128, proc->unk_4c, 60);

    BgAffinRotScaling(BG_2, proc->unk_4e, 0, 0, scale * 5 + 128, scale * 5 + 128);
    BgAffinScaling(BG_2, 0x100, 0x100);
    BgAffinAnchoring(BG_2, xOffset, yOffset, 80, 72);

    proc->unk_4e -= 64;

    SetBlendAlpha(alpha, 16);

    proc->unk_4c++;

    if (proc->unk_4c > 59)
    {
        Proc_Break(proc);
    }

    return;
}

//! FE8U = 0x080C4BA0
void Subtitle_LightFlareFx_End(void)
{
    gLCDControlBuffer.dispcnt.bg2_on = 0;
    return;
}

// clang-format off

struct ProcCmd CONST_DATA gProcScr_OpSubtitle_LightFlareFx[] =
{
    PROC_SLEEP(1),

    PROC_CALL(Subtitle_LightFlareFx_Init),
    PROC_REPEAT(Subtitle_LightFlareFx_Loop),

    PROC_SLEEP(1),

    PROC_CALL(Subtitle_LightFlareFx_End),

    PROC_END,
};

// clang-format on

//! FE8U = 0x080C4BB4
void sub_80C4BB4(u16 * src, u16 * dst, int count, int coeff)
{
    u16 * srcIt;
    u16 * dstIt;
    int i;

    if (count <= 0)
    {
        return;
    }

    dstIt = dst;
    srcIt = src;
    for (i = count; i != 0; i--)
    {
        int color = (*srcIt);

        s16 r = DivArm(0x1000, RED_VALUE(color) * coeff);
        s16 g = DivArm(0x1000, GREEN_VALUE(color) * coeff);
        s16 b = DivArm(0x1000, BLUE_VALUE(color) * coeff);

        *dstIt++ = (u32)r + ((u32)g << 5) + ((u32)b << 10);
        do srcIt++; while (0);
    }
}

//! FE8U = 0x080C4C3C
void OpSubtitle_AwaitTimer2a(struct OpSubtitleProc * proc)
{
    proc->timer_2a--;

    if (proc->timer_2a < 1)
    {
        Proc_Break(proc);
    }

    OpSubtitle_HandleStartPress(proc);

    return;
}

//! FE8U = 0x080C4C60
void sub_80C4C60(struct OpSubtitleProc * proc)
{
    Decompress(gOpSubtitleGfxLut[proc->index].gfx, BG_CHR_ADDR(0x80));
    Decompress(gOpSubtitleGfxLut[proc->index].tsa, gGenericBuffer);

    CallARM_FillTileRect(gBG0TilemapBuffer, gGenericBuffer, TILEREF(0x80, 3));

    gLCDControlBuffer.dispcnt.bg0_on = 1;

    BG_EnableSyncByMask(BG0_SYNC_BIT);

    proc->timer_2c = 0;

    return;
}

//! FE8U = 0x080C4CD0
void sub_80C4CD0(struct OpSubtitleProc * proc)
{
    Decompress(gOpSubtitleGfxLut[proc->index].gfx, BG_CHR_ADDR(0x80));

    Decompress(gOpSubtitleGfxLut[proc->index].tsa, gGenericBuffer);
    CallARM_FillTileRect(gBG0TilemapBuffer, gGenericBuffer, TILEREF(0x80, 3));
    CallARM_FillTileRect(gBG1TilemapBuffer, gGenericBuffer, TILEREF(0x80, 14));

    gLCDControlBuffer.dispcnt.bg0_on = 1;

    BG_EnableSyncByMask(BG0_SYNC_BIT | BG1_SYNC_BIT);

    proc->timer_2c = 0;

    return;
}

//! FE8U = 0x080C4D54
void sub_80C4D54(int index)
{
    Decompress(gOpSubtitleGfxLut[index].gfx, BG_CHR_ADDR(0x280));

    Decompress(gOpSubtitleGfxLut[index].tsa, gGenericBuffer);
    CallARM_FillTileRect(gBG0TilemapBuffer, gGenericBuffer, TILEREF(0x280, 3));

    BG_EnableSyncByMask(BG0_SYNC_BIT);

    return;
}

//! FE8U = 0x080C4DA0
void sub_80C4DA0(struct OpSubtitleProc * proc)
{
    proc->timer_2c++;

    if (proc->timer_2c < 80)
    {
        int coeff = _DivArm1(proc->timer_2c, 80, 0);
        sub_80C4BB4(gPal_OpSubtitle, PAL_BG(3), 16, coeff);
    }
    else
    {
        ApplyPalette(gPal_OpSubtitle, 3);

        Proc_Break(proc);

        proc->timer_2a = gOpSubtitleGfxLut[proc->index].timer;
        proc->timer_2c = 0;
    }

    EnablePaletteSync();

    OpSubtitle_HandleStartPress(proc);

    return;
}

//! FE8U = 0x080C4E18
void sub_80C4E18(struct OpSubtitleProc * proc)
{
    proc->timer_2c++;

    if (proc->timer_2c < 80)
    {
        int coeff = 0x1000 - _DivArm1(proc->timer_2c, 80, 0);
        sub_80C4BB4(gPal_OpSubtitle, PAL_BG(3), 16, coeff);
    }
    else
    {
        CpuFastFill(RGB_BLACK, PAL_BG(3), PLTT_SIZE_4BPP);

        proc->timer_2c = 0;

        proc->index++;

        if (proc->index < 2)
        {
            proc->timer_2a = 80;
            Proc_Break(proc);
        }
        else
        {
            SetDispEnable(0, 0, 0, 0, 0);
            Proc_Goto(proc, 1);
        }
    }

    EnablePaletteSync();

    OpSubtitle_HandleStartPress(proc);

    return;
}

//! FE8U = 0x080C4EC4
void sub_80C4EC4(struct OpSubtitleProc * proc)
{
    proc->timer_2c++;

    if (proc->timer_2c < 80)
    {
        int coeff = 0x1000 - _DivArm1(proc->timer_2c, 80, 0);
        sub_80C4BB4(gPal_OpSubtitle, PAL_BG(3), 16, coeff);
    }
    else
    {
        CpuFastFill(RGB_BLACK, PAL_BG(3), PLTT_SIZE_4BPP);

        proc->timer_2c = 0;
        proc->index++;
        proc->timer_2a = 90;

        SetDispEnable(0, 0, 1, 0, 0);

        Proc_Break(proc);
    }

    EnablePaletteSync();

    OpSubtitle_HandleStartPress(proc);

    return;
}

//! FE8U = 0x080C4F60
void sub_80C4F60(struct OpSubtitleProc * proc)
{
    proc->timer_2c++;

    if (proc->timer_2c < 80)
    {
        int coeff = _DivArm1(proc->timer_2c, 80, 0);
        s16 var = DivArm(0x1000, coeff << 4);

        SetBlendAlpha(16 - var, var);
    }
    else
    {
        SetBlendAlpha(0, 16);

        if (proc->index < 5)
        {
            Proc_Break(proc);
            proc->timer_2a = gOpSubtitleGfxLut[proc->index].timer;
            proc->timer_2c = 0;
        }
        else
        {
            proc->timer_2a = gOpSubtitleGfxLut[proc->index].timer;
            proc->index++;

            Proc_Goto(proc, 4);
        }
    }

    EnablePaletteSync();

    OpSubtitle_HandleStartPress(proc);

    return;
}

//! FE8U = 0x080C501C
void sub_80C501C(struct OpSubtitleProc * proc)
{
    proc->timer_2c++;

    if (proc->timer_2c < 80)
    {
        int coeff = _DivArm1(proc->timer_2c, 80, 0);
        s16 var = DivArm(0x1000, (0x1000 - coeff) << 4);

        SetBlendAlpha(16 - var, var);
    }
    else
    {
        SetBlendAlpha(16, 0);

        proc->timer_2c = 0;
        proc->index++;
        proc->timer_2a = 80;

        Proc_Break(proc);

        OpSubtitle_HandleStartPress(proc);
    }

    EnablePaletteSync();

    OpSubtitle_HandleStartPress(proc);

    return;
}

//! FE8U = 0x080C50A0
void sub_80C50A0(struct OpSubtitleProc * proc)
{
    sub_80C488C(BG_1);

    CpuFastFill(RGB_BLACK, PAL_BG(15), PLTT_SIZE_4BPP);

    sub_80C48F0(BG_1);

    BG_EnableSyncByMask(BG1_SYNC_BIT);

    CpuFastFill(0, BG_CHR_ADDR(0x280), 0x1000);
    BG_Fill(gBG0TilemapBuffer, 0x280);
    BG_EnableSyncByMask(BG0_SYNC_BIT);

    proc->timer_2a = 22;
    proc->timer_2c = 0;

    return;
}

//! FE8U = 0x080C5104
void sub_80C5104(struct OpSubtitleProc * proc)
{
    if (proc->timer_2c == 0)
    {
        SetDispEnable(1, 1, 1, 0, 0);
    }

    proc->timer_2c++;

    if (proc->timer_2c < 46)
    {
        int coeff = _DivArm1(proc->timer_2c, 46, 0);
        sub_80C4BB4(Pal_08B1756C, PAL_BG(15), 16, coeff);
    }
    else
    {
        ApplyPalette(Pal_08B1756C, 15);

        Proc_Break(proc);

        proc->timer_2a = gOpSubtitleGfxLut[proc->index].timer;
        proc->timer_2c = 0;
    }

    EnablePaletteSync();

    OpSubtitle_HandleStartPress(proc);

    return;
}

//! FE8U = 0x080C51A8
void sub_80C51A8(void)
{
    sub_80C4D54(2);

    ApplyPalette(gPal_OpSubtitle, 3);
    EnablePaletteSync();

    return;
}

// clang-format off

struct ProcCmd CONST_DATA gProcScr_08AA2184[] =
{
    PROC_YIELD,
    PROC_SLEEP(36),
    PROC_CALL(sub_80C51A8),

    PROC_END,
};

u16 CONST_DATA gUnknown_08AA21A4[] =
{
    0x0000, 0x6000, 0,
    0x0000, 0x6800, 0,
    0x0000, 0x7000, 0,
    0x8000, 0x7800, 0,
};

// clang-format on

//! FE8U = 0x080C51C8
void OpSubtitle_SetupBackgrounds(void)
{
    int bg;
    u16 * bgConfig;

    memset(&gLCDControlBuffer.bg0cnt, 0, 2);
    memset(&gLCDControlBuffer.bg1cnt, 0, 2);
    memset(&gLCDControlBuffer.bg2cnt, 0, 2);
    memset(&gLCDControlBuffer.bg3cnt, 0, 2);

    bgConfig = gUnknown_08AA21A4;

    for (bg = 0; bg < 4; bg++)
    {
        SetBackgroundTileDataOffset(bg, *bgConfig++);
        SetBackgroundMapDataOffset(bg, *bgConfig++);
        SetBackgroundScreenSize(bg, *bgConfig++);

        BG_SetPosition(bg, 0, 0);
    }

    return;
}

//! FE8U = 0x080C5218
void sub_80C5218(struct OpSubtitleProc * proc)
{
    OpSubtitle_SetupBackgrounds();

    gLCDControlBuffer.dispcnt.mode = DISPCNT_MODE_0;

    gLCDControlBuffer.bg0cnt.priority = 1;
    gLCDControlBuffer.bg1cnt.priority = 2;
    gLCDControlBuffer.bg2cnt.priority = 3;
    gLCDControlBuffer.bg3cnt.priority = 0;

    SetBlendAlpha(0, 16);

    SetBlendTargetA(0, 0, 0, 1, 0);
    SetBlendTargetB(1, 1, 0, 0, 0);

    SetBlendBackdropA(0);
    SetBlendBackdropB(0);

    BG_SetPosition(BG_0, 0, 0);
    BG_SetPosition(BG_1, -3, -3);
    BG_SetPosition(BG_2, 0, 0);
    BG_SetPosition(BG_3, 0, 0);

    sub_80C488C(BG_3);
    sub_80C48F0(BG_3);

    BG_Fill(gBG1TilemapBuffer, 0);
    BG_Fill(gBG2TilemapBuffer, 0);

    BG_EnableSyncByMask(BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);

    sub_80C4D54(2);

    SetDispEnable(1, 0, 0, 1, 0);

    proc->index = 2;
    proc->timer_2a = 120;

    return;
}

//! FE8U = 0x080C5328
void sub_80C5328(void)
{
    CpuFastFill(0, BG_CHR_ADDR(0x0), CHR_SIZE);
    BG_EnableSyncByMask(BG1_SYNC_BIT);
    SetDispEnable(1, 1, 0, 1, 0);
    return;
}

//! FE8U = 0x080C5370
void sub_80C5370(struct OpSubtitleProc * proc)
{
    proc->timer_2c = 0;
    CpuFastCopy(gPaletteBuffer, gUnk_OpSubtitle_0201CDD4, 0x200);

    return;
}

//! FE8U = 0x080C538C
void sub_80C538C(struct OpSubtitleProc * proc)
{
    proc->timer_2c++;

    if (proc->timer_2c < 60)
    {
        int coeff = 0x1000 - _DivArm1(proc->timer_2c, 60, 0);
        sub_80C4BB4(gUnk_OpSubtitle_0201CDD4, gPaletteBuffer, 0x200, coeff);
    }
    else
    {
        CpuFastFill(RGB_BLACK, gPaletteBuffer, 0x200);

        proc->timer_2c = 0;
        proc->timer_2a = 60;

        Proc_Break(proc);
    }

    EnablePaletteSync();

    OpSubtitle_HandleStartPress(proc);

    return;
}

//! FE8U = 0x080C5400
void sub_80C5400(void)
{
    Sound_FadeOutBGM(4);
    return;
}

//! FE8U = 0x080C540C
void sub_80C540C(void)
{
    BG_SetPosition(BG_1, 0, 0);
    return;
}

// clang-format off

struct ProcCmd CONST_DATA gProcScr_OpSubtitle[] =
{
    PROC_YIELD,

    PROC_CALL(OpSubtitle_Init),

    PROC_SLEEP(1),

    PROC_CALL_ARG(NewFadeIn, 2),
    PROC_WHILE(FadeInExists),

    PROC_REPEAT(OpSubtitle_AwaitTimer2a),

PROC_LABEL(0), // loop used for the first two "slides"
    PROC_CALL(sub_80C4C60),
    PROC_REPEAT(sub_80C4DA0),
    PROC_REPEAT(OpSubtitle_AwaitTimer2a),

    PROC_REPEAT(sub_80C4E18),
    PROC_REPEAT(OpSubtitle_AwaitTimer2a),

    PROC_GOTO(0),

PROC_LABEL(1),
    PROC_START_CHILD(gProcScr_OpSubtitle_LightFlareFx),
    PROC_START_CHILD(gProcScr_08AA2184),

    PROC_CALL(sub_80C50A0),
    PROC_REPEAT(OpSubtitle_AwaitTimer2a),

    PROC_REPEAT(sub_80C5104),
    PROC_CALL(sub_80C5218),
    PROC_REPEAT(OpSubtitle_AwaitTimer2a),

    PROC_REPEAT(sub_80C501C),
    PROC_REPEAT(OpSubtitle_AwaitTimer2a),

    PROC_CALL(sub_80C5328),

    // fallthrough

PROC_LABEL(2),
    PROC_CALL(sub_80C4CD0),
    PROC_REPEAT(sub_80C4F60),
    PROC_REPEAT(OpSubtitle_AwaitTimer2a),

    PROC_REPEAT(sub_80C501C),
    PROC_REPEAT(OpSubtitle_AwaitTimer2a),

    PROC_GOTO(2),

PROC_LABEL(4),
    PROC_REPEAT(OpSubtitle_AwaitTimer2a),

    PROC_CALL(sub_80C5370),
    PROC_REPEAT(sub_80C538C),
    PROC_REPEAT(OpSubtitle_AwaitTimer2a),

    PROC_CALL(sub_80C4C60),
    PROC_REPEAT(sub_80C4DA0),
    PROC_REPEAT(OpSubtitle_AwaitTimer2a),

    PROC_REPEAT(sub_80C4EC4),
    PROC_REPEAT(OpSubtitle_AwaitTimer2a),

    // fallthrough

PROC_LABEL(5),
    PROC_END_EACH(gProcScr_OpSubtitle_LightFlareFx),
    PROC_END_EACH(gProcScr_08AA2184),

    PROC_CALL(sub_80C5400),

    PROC_CALL(StartSlowFadeToBlack),
    PROC_REPEAT(WaitForFade),
    PROC_SLEEP(30),

    PROC_GOTO(7),

PROC_LABEL(6), // ended due to Start Button press
    PROC_END_EACH(gProcScr_OpSubtitle_LightFlareFx),
    PROC_END_EACH(gProcScr_08AA2184),

    PROC_CALL(StartFastFadeToBlack),
    PROC_REPEAT(WaitForFade),

    PROC_SLEEP(10),

    PROC_GOTO(7),

PROC_LABEL(7),
    PROC_CALL(sub_80C540C),

    PROC_SLEEP(1),

    PROC_END,
};

// clang-format on

//! FE8U = 0x080C541C
void StartIntroMonologue(ProcPtr proc)
{
    Proc_StartBlocking(gProcScr_OpSubtitle, proc);
    return;
}
