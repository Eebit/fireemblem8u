#include "global.h"
#include "proc.h"
#include "hardware.h"
#include "chapterdata.h"
#include "rng.h"

extern const u16* gUnknown_0859D968[];

extern const u16 gUnknown_085A3AC0[];

extern const u8 gUnknown_085A3964[];
extern const u8 gUnknown_085A3A84[];

void CopyDataWithPossibleUncomp(const void* src, void* dst);
void CopyTileGfxForObj(const void* src, void* dst, int tileWidth, int tileHeight);

extern const u8 gUnknown_085A39EC[];

extern union {
	// Buffer holding colors for vertical gradient.
	u16 lines[320];

	// Buffer holding 8 different variations of the tileset palette
	// Variations have increasing amounts of red; used for fire weather effect
	u16 fireGradient[8][0x40];
} gUnknown_02002ADC;

struct TileGfxAnim {
	u16         time;
	u16         size;
	const void* data;
};

struct TilePalAnim {
	const void* data;
	u8          time;
	u8          colorCount;
	u8          colorStart;
};

struct BMVSyncProc {
	PROC_HEADER;

	/* 2C */ const struct TileGfxAnim* tileGfxAnimStart;
	/* 30 */ const struct TileGfxAnim* tileGfxAnimCurrent;

	/* 34 */ short tileGfxAnimClock;
	/* 36 */ short tilePalAnimClock;

	/* 28 */ const struct TilePalAnim* tilePalAnimStart;
	/* 3C */ const struct TilePalAnim* tilePalAnimCurrent;
};

struct WeatherParticle {
	/* 00 */ short xPosition;
	/* 02 */ short yPosition;

	/* 04 */ short xSpeed;
	/* 06 */ short ySpeed;

	/* 08 */ u8  gfxIndex;
	/* 09 */ u8  typeId;
};

extern const struct ProcCmd gUnknown_0859D8B8[];

extern struct WeatherParticle gUnknown_020027DC[];

extern const u16 gUnknown_080D7EEC[];

/*
static const u16 gUnknown_080D7EEC[] = {
	0xB0,  0xC0,  0,
	0xB0,  0xD0,  0,
	0xB0,  0xE0,  0,
	0xB0,  0xF0,  0,
	0xB0,  0x100, 0,
	0xB0,  0x110, 0,

	0xF0,  0x140, 1,
	0xF0,  0x150, 1,
	0xF0,  0x160, 1,
	0xF0,  0x170, 1,
	0xF0,  0x180, 1,
	0xF0,  0x190, 1,
	0xF0,  0x1A0, 1,

	0x100, 0x200, 2,
	0xF0,  0x220, 2,
	0xE0,  0x240, 2,
}; //*/

void SetSecondaryHBlankHandler(void(*)(void));

enum {
	BM_BGPAL_6 = 6,
	BM_BGPAL_TILESET_BASE = 7,
};

void sub_803005C(struct BMVSyncProc* proc) {
	if (!proc->tileGfxAnimStart)
		return;

	if (proc->tileGfxAnimClock) {
		proc->tileGfxAnimClock--;
		return;
	}

	proc->tileGfxAnimClock = proc->tileGfxAnimCurrent->time;

	CpuFastCopy(
		proc->tileGfxAnimCurrent->data,
		BG_TILE_ADDR(0x140),
		proc->tileGfxAnimCurrent->size
	);

	if ((++proc->tileGfxAnimCurrent)->time == 0)
		proc->tileGfxAnimCurrent = proc->tileGfxAnimStart;
}

void sub_80300A4(struct BMVSyncProc* proc) {
	if (!proc->tilePalAnimStart)
		return;

	if (proc->tilePalAnimClock) {
		proc->tilePalAnimClock--;
		return;
	}

	proc->tilePalAnimClock = proc->tilePalAnimCurrent->time;

	CpuCopy16(
		proc->tilePalAnimCurrent->data,
		proc->tilePalAnimCurrent->colorStart + (0x10 * BM_BGPAL_6) + gPaletteBuffer,
		proc->tilePalAnimCurrent->colorCount*2
	);

	EnablePaletteSync();

	if ((++proc->tilePalAnimCurrent)->time == 0)
		proc->tilePalAnimCurrent = proc->tilePalAnimStart;
}

void SetupGameVBlank6C_TileAnimations(struct BMVSyncProc* proc) {
	proc->tileGfxAnimClock = 0;
	proc->tilePalAnimClock = 0;

	proc->tileGfxAnimStart = proc->tileGfxAnimCurrent =
		gChapterDataAssetTable[GetROMChapterStruct(gUnknown_0202BCF0.chapterIndex)->mapTileAnim1Id];

	proc->tilePalAnimStart = proc->tilePalAnimCurrent =
		gChapterDataAssetTable[GetROMChapterStruct(gUnknown_0202BCF0.chapterIndex)->mapTileAnim2Id];
}

void GameVBlank6C_Destructor(struct BMVSyncProc* proc) {
	SetSecondaryHBlankHandler(NULL);
}

void GameVBlank6C_Loop(struct BMVSyncProc* proc) {
	Proc_GotoLabel((struct Proc*)(proc), 0);
}

void SetupWeatherGraphics_Maybe(void);

void SetupGameVBlank6C(void) {
	SetupGameVBlank6C_TileAnimations(
		(struct BMVSyncProc*) Proc_Create(gUnknown_0859D8B8, ROOT_PROC_0)
	);

	SetupWeatherGraphics_Maybe();
	gUnknown_0202BCB0.gameGfxSemaphore = 0;
}

void sub_8030174(void) {
	Proc_DeleteAllWithScript(gUnknown_0859D8B8);
}

void BlockGameGraphicsLogic(void) {
	if (++gUnknown_0202BCB0.gameGfxSemaphore > 1)
		return; // gfx was already blocked, nothing needs to be done.

	SetSecondaryHBlankHandler(NULL);
	gPaletteBuffer[0] = 0;
	EnablePaletteSync();
	Proc_BlockEachWithMark(1);
}

void UnblockGameGraphicsLogic(void) {
	struct Proc* proc;

	if (!gUnknown_0202BCB0.gameGfxSemaphore)
		return; // wasn't blocked

	if (--gUnknown_0202BCB0.gameGfxSemaphore)
		return; // still blocked

	Proc_UnblockEachWithMark(1);

	proc = Proc_Find(gUnknown_0859D8B8);

	if (proc) {
		// restart vblank proc
		Proc_Delete(proc);
		SetupGameVBlank6C();
	}
}

void SetupOAMSpliceForWeather(unsigned weatherId) {
	switch (weatherId) {

	case 1:
	case 2:
	case 4:
	case 6:
		SetupOAMBufferSplice(0x20);
		break;

	case 5:
		SetupOAMBufferSplice(0x10);
		break;

	default:
		SetupOAMBufferSplice(0);
		break;

	} // switch (weatherId)
}

void sub_8030240(void) {
	SetupOAMSpliceForWeather(gUnknown_0202BCF0.chapterWeatherId);
	SetSecondaryHBlankHandler(NULL);
}

void sub_8030258(void) {
	int i;

	int gfxTileIndices[] = {
		0x29,
		0x09,
		0x08
	};

	SetupOAMSpliceForWeather(gUnknown_0202BCF0.chapterWeatherId);

	for (i = 0; i < 0x40; ++i) {
		unsigned templateIndex = (i & 0xF) * 3;

		gUnknown_020027DC[i].xPosition = AdvanceGetLCGRNValue();
		gUnknown_020027DC[i].yPosition = AdvanceGetLCGRNValue();

		gUnknown_020027DC[i].xSpeed = gUnknown_080D7EEC[templateIndex + 0] * 2;
		gUnknown_020027DC[i].ySpeed = gUnknown_080D7EEC[templateIndex + 1] * 2;
		gUnknown_020027DC[i].typeId = gUnknown_080D7EEC[templateIndex + 2];

		gUnknown_020027DC[i].gfxIndex = gfxTileIndices[gUnknown_080D7EEC[templateIndex + 2]];
	}
}

void sub_80302D0(void) {
	if (GetPrimaryOAMSize()) {
		struct { short x, y; } origins[3];
		int i;

		struct WeatherParticle* it = gUnknown_020027DC + ((GetGameClock() % 2) * 0x20);

		origins[0].x = (gUnknown_0202BCB0.xCameraReal * 12) / 16;
		origins[0].y = gUnknown_0202BCB0.yCameraReal;

		origins[1].x = gUnknown_0202BCB0.xCameraReal;
		origins[1].y = gUnknown_0202BCB0.yCameraReal;

		origins[2].x = (gUnknown_0202BCB0.xCameraReal * 20) / 16;
		origins[2].y = gUnknown_0202BCB0.yCameraReal;

		for (i = 0; i < 0x20; ++i) {
			it->xPosition += it->xSpeed;
			it->yPosition += it->ySpeed;

			CallARM_PushToPrimaryOAM(
				((it->xPosition >> 8) - origins[it->typeId].x) & 0xFF,
				((it->yPosition >> 8) - origins[it->typeId].y) & 0xFF,
				gUnknown_08590F44,
				0x1000 + it->gfxIndex
			);

			++it;
		}
	}
}

void sub_8030390(void) {
	int i;

	SetupOAMSpliceForWeather(gUnknown_0202BCF0.chapterWeatherId);

	for (i = 0; i < 0x40; ++i) {
		unsigned templateIndex = (i & 0xF) * 3;

		gUnknown_020027DC[i].xPosition = AdvanceGetLCGRNValue();
		gUnknown_020027DC[i].yPosition = AdvanceGetLCGRNValue();

		gUnknown_020027DC[i].xSpeed   = gUnknown_080D7EEC[templateIndex + 0] * 6;
		gUnknown_020027DC[i].ySpeed   = gUnknown_080D7EEC[templateIndex + 1] * 16;
		gUnknown_020027DC[i].gfxIndex = gUnknown_080D7EEC[templateIndex + 2];
	}
}

void sub_80303F4(void) {
	if (GetPrimaryOAMSize()) {
		int i;

		struct WeatherParticle* it = gUnknown_020027DC + ((GetGameClock() % 2) * 0x20);

		for (i = 0; i < 0x20; ++i) {
			it->xPosition += it->xSpeed;
			it->yPosition += it->ySpeed;

			CallARM_PushToPrimaryOAM(
				((it->xPosition >> 8) - gUnknown_0202BCB0.xCameraReal) & 0xFF,
				((it->yPosition >> 8) - gUnknown_0202BCB0.yCameraReal) & 0xFF,
				gUnknown_0859D968[it->gfxIndex],
				0
			);

			++it;
		}
	}
}

void sub_8030474(void) {
	int i;

	SetupOAMSpliceForWeather(gUnknown_0202BCF0.chapterWeatherId);

	CopyDataWithPossibleUncomp(gUnknown_085A3964, gUnknown_02020188);
	CopyTileGfxForObj(gUnknown_02020188, OBJ_VRAM0 + 0x1C * 0x20, 4, 4);

	for (i = 0; i < 0x40; ++i) {
		gUnknown_020027DC[i].xPosition = AdvanceGetLCGRNValue();
		gUnknown_020027DC[i].yPosition = (AdvanceGetLCGRNValue() % 160 + 240) & 0xFF;

		gUnknown_020027DC[i].xSpeed = (AdvanceGetLCGRNValue() & 0x7) - 32;
		gUnknown_020027DC[i].ySpeed = 0;
	}
}

void sub_80304E4(void) {
	if (GetPrimaryOAMSize()) {
		int i;

		struct WeatherParticle* it = gUnknown_020027DC + ((GetGameClock() % 2) * 0x20);

		for (i = 0; i < 0x20; ++i) {
			it->xPosition += it->xSpeed;

			CallARM_PushToPrimaryOAM(
				((it->xPosition & 0xFF) - 0x10) & 0x1FF,
				it->yPosition,
				gUnknown_08590F54,
				0x1000 + 0x1C
			);

			++it;
		}
	}
}

void sub_8030540(void) {
	int i;

	u8 typeLookup[] = { 0, 0, 0, 0, 0, 0, 1, 1 };

	SetupOAMSpliceForWeather(gUnknown_0202BCF0.chapterWeatherId);

	CopyDataWithPossibleUncomp(gUnknown_085A39EC, gUnknown_02020188);
	CopyTileGfxForObj(gUnknown_02020188, OBJ_VRAM0 + 0x18 * 0x20, 8, 4);

	for (i = 0; i < 0x40; ++i) {
		unsigned type = typeLookup[i & 7];

		gUnknown_020027DC[i].xPosition = AdvanceGetLCGRNValue();
		gUnknown_020027DC[i].yPosition = AdvanceGetLCGRNValue();

		gUnknown_020027DC[i].ySpeed    = (AdvanceGetLCGRNValue() & 0x3FF) - 0x100;
		gUnknown_020027DC[i].gfxIndex  = type;

		switch (type) {

		case 0:
			gUnknown_020027DC[i].xSpeed = 0x700 + (AdvanceGetLCGRNValue() & 0x1FF);
			break;

		case 1:
			gUnknown_020027DC[i].xSpeed = 0xA00 + (AdvanceGetLCGRNValue() & 0x1FF);
			break;

		} // switch(type)
	}
}

void sub_80305FC(void) {
	if (GetPrimaryOAMSize()) {
		int i;

		struct WeatherParticle* it = gUnknown_020027DC + ((GetGameClock() % 2) * 0x20);

		for (i = 0; i < 0x20; ++i) {
			it->xPosition += it->xSpeed;
			it->yPosition += it->ySpeed;

			CallARM_PushToPrimaryOAM(
				((it->xPosition >> 8) - gUnknown_0202BCB0.xCameraReal) & 0xFF,
				((it->yPosition >> 8) - gUnknown_0202BCB0.yCameraReal) & 0xFF,
				gUnknown_08590F54,
				0x1000 + 0x18 + (it->gfxIndex * 4)
			);

			++it;
		}

	}
}

void sub_8030674(void) {
	u16 nextLine = (REG_VCOUNT + 1);

	if (nextLine > 160)
		nextLine = 0;

	nextLine += gUnknown_0202BCB0.yCameraReal / 2;

	if (nextLine >= 320)
		((u16*)(PLTT))[0] = 0;
	else
		((u16*)(PLTT))[0] = nextLine[gUnknown_02002ADC.lines];
}

void sub_80306CC(void) {
	u16* palIt = gUnknown_02002ADC.lines;
	int i = 0;

	void(*handler)(void) = sub_8030674;

	for (; i < 320; ++i)
		*palIt++ = RGB(0, 0, (31 - i / 10));

	SetSecondaryHBlankHandler(handler);
}

void nullsub_12(void) {}

void sub_8030714(void) {
	const u16* src;
	u16* dst;

	u16 nextLine = (REG_VCOUNT + 1);

	if (nextLine < 96)
		return;

	if (nextLine >= 160)
		return;

	nextLine -= 96;

	src  = gUnknown_02002ADC.fireGradient[0];
	src += nextLine * 8;

	dst = ((u16*)(PLTT)) + 0x70 + (nextLine % 8) * 8;

	CpuFastCopy(src, dst, 8);
}

void sub_8030758(void) {
	int k, j, i;

	for (i = 0; i < 4; ++i) {
		for (j = 0; j < 0x10; ++j) {
			const int color = gPaletteBuffer[0x10 * (i + BM_BGPAL_TILESET_BASE) + j];

			int r = RED_VALUE(color);
			int g = GREEN_VALUE(color);
			int b = BLUE_VALUE(color);

			for (k = 0; k < 8; ++k) {
				r = r + 2;

				if (r > 31)
					r = 31;

				gUnknown_02002ADC.fireGradient[k][0x10 * i + j] = 
					(b << 10) + (g << 5) + r;
			}
		}
	}
}

void sub_80307D8(void) {
	int i, j, k;

	sub_8019974();

	for (i = 0; i < 4; ++i) {
		for (j = 0; j < 0x10; ++j) {
			const int color = gPaletteBuffer[0x10 * (i + BM_BGPAL_TILESET_BASE) + j];

			int r = RED_VALUE(color);
			int g = GREEN_VALUE(color);
			int b = BLUE_VALUE(color);

			for (k = 0; k < 8; ++k) {
				r = r + 2;

				if (r > 31)
					r = 31;

				gUnknown_02002ADC.fireGradient[k][0x10 * i + j] = 
					(b << 10) + (g << 5) + r;
			}
		}
	}

	SetSecondaryHBlankHandler(sub_8030714);
} // sub_80307D8

void sub_8030868(void) {
	int i;

	SetupOAMSpliceForWeather(gUnknown_0202BCF0.chapterWeatherId);
	CopyDataWithPossibleUncomp(gUnknown_085A3A84, OBJ_VRAM0 + 0x18 * 0x20);
	CopyToPaletteBuffer(gUnknown_085A3AC0, 0x340, 0x20);

	for (i = 0; i < 0x10; ++i) {
		gUnknown_020027DC[i].xPosition = AdvanceGetLCGRNValue();
		gUnknown_020027DC[i].yPosition = AdvanceGetLCGRNValue();

		gUnknown_020027DC[i].xSpeed = -gUnknown_080D7EEC[i*3 + 0];
		gUnknown_020027DC[i].ySpeed = -gUnknown_080D7EEC[i*3 + 1];
	}
}

void sub_80308CC(void) {
	sub_80307D8();
	sub_8030868();
}

void sub_80308DC(void) {
	int i, j;

	CpuFastCopy(
		gPaletteBuffer + BM_BGPAL_TILESET_BASE * 0x10,
		((u16*)(PLTT)) + BM_BGPAL_TILESET_BASE * 0x10,

		0x20 * 4
	);

	for (i = 12; i < 16; ++i) {
		const int color = gPaletteBuffer[(BM_BGPAL_TILESET_BASE + 2) * 0x10 + i];

		int r = RED_VALUE(color);
		int g = GREEN_VALUE(color);
		int b = BLUE_VALUE(color);

		for (j = 0; j < 8; ++j) {
			r = r + 2;

			if (r > 31)
				r = 31;

			gUnknown_02002ADC.fireGradient[j][0x10 * 2 + i] = 
				(b << 10) + (g << 5) + r;
		}

	}
}

void sub_8030948(void) {
	struct WeatherParticle* it = gUnknown_020027DC;

	if (GetPrimaryOAMSize()) {
		int i;

		for (i = 0; i < 0x10; ++i, ++it) {
			int yDisplay;
			int objTile;

			it->xPosition += it->xSpeed;
			it->yPosition += it->ySpeed;

			yDisplay = ((it->yPosition >> 8) - gUnknown_0202BCB0.yCameraReal) & 0xFF;

			if (yDisplay < 0x40)
				continue;

			if (yDisplay > 0xA0)
				continue;

			objTile = 31 - ((yDisplay - 0x40) / 8);

			if (objTile < 24)
				objTile = 24;

			CallARM_PushToPrimaryOAM(
				((it->xPosition >> 8) - gUnknown_0202BCB0.xCameraReal) & 0xFF,
				yDisplay,
				gUnknown_08590F44,
				(0xA << 12) + objTile
			);
		}
	}
}
