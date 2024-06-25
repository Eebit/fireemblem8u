	.INCLUDE "macro.inc"

	.SYNTAX UNIFIED

	THUMB_FUNC_START sub_804D2A4
sub_804D2A4: @ 0x0804D2A4
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x30
	mov r1, sp
	ldr r0, _0804D348  @ gUnknown_080DA20C
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r0, [r0]
	str r0, [r1]
	add r6, sp, #0x10
	adds r1, r6, #0
	ldr r0, _0804D34C  @ gUnknown_080DA21C
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r0, [r0]
	str r0, [r1]
	add r0, sp, #0x20
	mov r8, r0
	mov r1, r8
	ldr r0, _0804D350  @ gUnknown_080DA22C
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _0804D354  @ Img_PhaseChangeUnk
	ldr r1, _0804D358  @ 0x06014000
	bl Decompress
	ldr r0, _0804D35C  @ Img_PhaseChangeSquares
	ldr r1, _0804D360  @ 0x06002000
	bl Decompress
	ldr r0, _0804D364  @ gUnknown_085AE7EC
	ldr r1, _0804D368  @ 0x06002800
	bl Decompress
	ldr r5, _0804D36C  @ gPlaySt
	ldrb r0, [r5, #0xf]
	lsls r0, r0, #2
	add r0, sp
	ldr r0, [r0]
	ldr r4, _0804D370  @ gGenericBuffer
	adds r1, r4, #0
	bl Decompress
	ldr r1, _0804D374  @ 0x06002980
	adds r0, r4, #0
	movs r2, #3
	movs r3, #3
	bl Copy2dChr
	ldrb r0, [r5, #0xf]
	lsls r0, r0, #2
	adds r6, r6, r0
	ldr r0, [r6]
	movs r1, #0xa0
	movs r2, #0x20
	bl CopyToPaletteBuffer
	ldrb r0, [r5, #0xf]
	lsls r0, r0, #2
	add r8, r0
	mov r1, r8
	ldr r0, [r1]
	movs r1, #0x90
	lsls r1, r1, #2
	movs r2, #0x20
	bl CopyToPaletteBuffer
	ldr r1, _0804D378  @ gUnknown_03001860
	ldrb r0, [r5, #0xf]
	str r0, [r1]
	movs r0, #0
	strb r0, [r5, #0xf]
	add sp, #0x30
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804D348: .4byte gUnknown_080DA20C
_0804D34C: .4byte gUnknown_080DA21C
_0804D350: .4byte gUnknown_080DA22C
_0804D354: .4byte Img_PhaseChangeUnk
_0804D358: .4byte 0x06014000
_0804D35C: .4byte Img_PhaseChangeSquares
_0804D360: .4byte 0x06002000
_0804D364: .4byte gUnknown_085AE7EC
_0804D368: .4byte 0x06002800
_0804D36C: .4byte gPlaySt
_0804D370: .4byte gGenericBuffer
_0804D374: .4byte 0x06002980
_0804D378: .4byte gUnknown_03001860

	THUMB_FUNC_END sub_804D2A4

	THUMB_FUNC_START sub_804D37C
sub_804D37C: @ 0x0804D37C
	push {r4, lr}
	ldr r1, _0804D3D0  @ gPlaySt
	ldr r0, _0804D3D4  @ gUnknown_03001860
	ldr r0, [r0]
	strb r0, [r1, #0xf]
	ldr r4, _0804D3D8  @ gLCDControlBuffer
	ldrb r1, [r4, #1]
	movs r0, #0x21
	negs r0, r0
	ands r0, r1
	movs r1, #0x41
	negs r1, r1
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	strb r0, [r4, #1]
	bl SetDefaultColorEffects
	ldrb r2, [r4, #0xc]
	movs r1, #4
	negs r1, r1
	adds r0, r1, #0
	ands r0, r2
	strb r0, [r4, #0xc]
	ldrb r2, [r4, #0x10]
	adds r0, r1, #0
	ands r0, r2
	movs r2, #1
	orrs r0, r2
	strb r0, [r4, #0x10]
	ldrb r0, [r4, #0x14]
	ands r1, r0
	movs r0, #2
	orrs r1, r0
	strb r1, [r4, #0x14]
	ldrb r0, [r4, #0x18]
	movs r1, #3
	orrs r0, r1
	strb r0, [r4, #0x18]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804D3D0: .4byte gPlaySt
_0804D3D4: .4byte gUnknown_03001860
_0804D3D8: .4byte gLCDControlBuffer

	THUMB_FUNC_END sub_804D37C

	THUMB_FUNC_START StopBGM2
StopBGM2: @ 0x0804D3DC
	push {lr}
	ldr r1, _0804D3EC  @ gMPlayInfo_BGM2
	movs r0, #0x34
	bl StartBgm
	pop {r0}
	bx r0
	.align 2, 0
_0804D3EC: .4byte gMPlayInfo_BGM2

	THUMB_FUNC_END StopBGM2

	THUMB_FUNC_START sub_804D3F0
sub_804D3F0: @ 0x0804D3F0
	push {lr}
	lsls r1, r1, #1
	adds r0, #0x1e
	adds r2, r0, r1
	ldrh r1, [r2]
	cmp r1, #0
	beq _0804D408
	movs r3, #0xff
	lsls r3, r3, #8
	adds r0, r3, #0
	orrs r1, r0
	strh r1, [r2]
_0804D408:
	pop {r0}
	bx r0

	THUMB_FUNC_END sub_804D3F0

	THUMB_FUNC_START sub_804D40C
sub_804D40C: @ 0x0804D40C
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
_0804D412:
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_804D3F0
	adds r4, #1
	cmp r4, #4
	ble _0804D412
	pop {r4, r5}
	pop {r0}
	bx r0

	THUMB_FUNC_END sub_804D40C

	THUMB_FUNC_START sub_804D428
sub_804D428: @ 0x0804D428
	push {r4, r5, r6, lr}
	ldr r5, _0804D46C  @ Pal_LinkArenaActiveBannerFx
	ldr r0, _0804D470  @ gUnk_Sio_0203DDDC
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0804D466
	bl GetGameClock
	adds r2, r0, #0
	movs r0, #0x1f
	ands r2, r0
	asrs r2, r2, #1
	movs r1, #0
	ldr r0, _0804D474  @ gPaletteBuffer
	movs r4, #0xf
	ldr r6, _0804D478  @ 0x00000322
	adds r3, r0, r6
_0804D44E:
	adds r0, r2, r1
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	strh r0, [r3]
	adds r3, #2
	adds r1, #1
	cmp r1, #0xe
	ble _0804D44E
	bl EnablePaletteSync
_0804D466:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804D46C: .4byte Pal_LinkArenaActiveBannerFx
_0804D470: .4byte gUnk_Sio_0203DDDC
_0804D474: .4byte gPaletteBuffer
_0804D478: .4byte 0x00000322

	THUMB_FUNC_END sub_804D428

	THUMB_FUNC_START sub_804D47C
sub_804D47C: @ 0x0804D47C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	movs r0, #0
	mov r9, r0
	movs r1, #0
	str r1, [sp, #4]
	mov sl, r1
_0804D494:
	ldr r1, [r7, #0x2c]
	ldr r2, [r7, #0x30]
	ldr r3, [sp, #4]
	adds r2, r2, r3
	movs r0, #0xf
	mov r4, r9
	ands r0, r4
	lsls r0, r0, #0xc
	movs r3, #0x80
	lsls r3, r3, #4
	adds r0, r0, r3
	str r0, [sp]
	movs r0, #4
	ldr r3, _0804D648  @ Sprite_LinkArena_NameBanner
	bl PutSprite
	ldr r4, _0804D64C  @ gSinLookup+0x80
	movs r1, #0
	ldrsh r0, [r4, r1]
	lsls r0, r0, #4
	movs r1, #0x80
	lsls r1, r1, #1
	bl Div
	adds r6, r0, #0
	lsls r6, r6, #0x10
	asrs r6, r6, #0x10
	ldr r2, _0804D650  @ gSinLookup
	movs r3, #0
	ldrsh r0, [r2, r3]
	negs r0, r0
	lsls r0, r0, #4
	movs r1, #0x80
	lsls r1, r1, #1
	bl Div
	adds r5, r0, #0
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	ldr r4, _0804D650  @ gSinLookup
	movs r1, #0
	ldrsh r0, [r4, r1]
	lsls r0, r0, #4
	movs r1, #0x80
	lsls r1, r1, #1
	bl Div
	adds r4, r0, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	ldr r2, _0804D64C  @ gSinLookup+0x80
	movs r3, #0
	ldrsh r0, [r2, r3]
	lsls r0, r0, #4
	movs r1, #0x80
	lsls r1, r1, #1
	bl Div
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	mov r0, r9
	adds r1, r6, #0
	adds r2, r5, #0
	adds r3, r4, #0
	bl SetObjAffine
	ldr r1, [r7, #0x38]
	movs r0, #1
	negs r0, r0
	cmp r1, r0
	beq _0804D5BE
	adds r3, r7, #0
	adds r3, #0x3c
	cmp r1, r9
	beq _0804D544
	mov r4, sl
	adds r1, r3, r4
	ldrh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #1
	cmp r0, r2
	bls _0804D53E
	subs r0, #8
	strh r0, [r1]
_0804D53E:
	ldr r0, [r7, #0x38]
	cmp r0, r9
	bne _0804D556
_0804D544:
	mov r4, sl
	adds r2, r3, r4
	ldrh r1, [r2]
	ldr r0, _0804D654  @ 0x0000014F
	cmp r1, r0
	bhi _0804D556
	adds r0, r1, #0
	adds r0, #8
	strh r0, [r2]
_0804D556:
	ldr r1, _0804D64C  @ gSinLookup+0x80
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #4
	add r3, sl
	mov r8, r3
	ldrh r1, [r3]
	bl Div
	adds r6, r0, #0
	lsls r6, r6, #0x10
	asrs r6, r6, #0x10
	ldr r3, _0804D650  @ gSinLookup
	movs r4, #0
	ldrsh r0, [r3, r4]
	negs r0, r0
	lsls r0, r0, #4
	mov r2, r8
	ldrh r1, [r2]
	bl Div
	adds r5, r0, #0
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	ldr r3, _0804D650  @ gSinLookup
	movs r4, #0
	ldrsh r0, [r3, r4]
	lsls r0, r0, #4
	mov r2, r8
	ldrh r1, [r2]
	bl Div
	adds r4, r0, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	ldr r3, _0804D64C  @ gSinLookup+0x80
	movs r1, #0
	ldrsh r0, [r3, r1]
	lsls r0, r0, #4
	mov r2, r8
	ldrh r1, [r2]
	bl Div
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	mov r0, r9
	adds r1, r6, #0
	adds r2, r5, #0
	adds r3, r4, #0
	bl SetObjAffine
_0804D5BE:
	ldr r1, [r7, #0x2c]
	subs r1, #0x30
	ldr r2, [r7, #0x30]
	ldr r3, [sp, #4]
	adds r2, r2, r3
	ldr r3, _0804D658  @ gUnknown_085AABB8
	mov r4, r9
	lsls r0, r4, #2
	adds r0, r0, r3
	ldr r3, [r0]
	movs r4, #0
	str r4, [sp]
	movs r0, #4
	bl PutSprite
	ldr r0, [sp, #4]
	adds r0, #0x18
	str r0, [sp, #4]
	movs r1, #2
	add sl, r1
	movs r2, #1
	add r9, r2
	mov r3, r9
	cmp r3, #3
	bgt _0804D5F2
	b _0804D494
_0804D5F2:
	ldr r2, [r7, #0x34]
	movs r0, #1
	negs r0, r0
	cmp r2, r0
	beq _0804D636
	ldr r1, [r7, #0x2c]
	subs r1, #0x48
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #3
	ldr r2, [r7, #0x30]
	adds r2, r2, r0
	adds r2, #8
	ldr r3, _0804D65C  @ gUnknown_080DA25C
	str r4, [sp]
	movs r0, #4
	bl PutSprite
	ldr r1, [r7, #0x2c]
	subs r1, #0x48
	ldr r2, [r7, #0x34]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #3
	ldr r2, [r7, #0x30]
	adds r2, r2, r0
	adds r2, #0x12
	ldr r3, _0804D660  @ gUnknown_080DA26A
	str r4, [sp]
	movs r0, #4
	bl PutSprite
	bl sub_804D428
_0804D636:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804D648: .4byte Sprite_LinkArena_NameBanner
_0804D64C: .4byte gSinLookup+0x80
_0804D650: .4byte gSinLookup
_0804D654: .4byte 0x0000014F
_0804D658: .4byte gUnknown_085AABB8
_0804D65C: .4byte gUnknown_080DA25C
_0804D660: .4byte gUnknown_080DA26A

	THUMB_FUNC_END sub_804D47C

	THUMB_FUNC_START sub_804D664
sub_804D664: @ 0x0804D664
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r6, r0, #0
	mov r8, r1
	adds r5, r2, #0
	ldr r4, _0804D6B0  @ gUnknown_085AABC8
	adds r0, r4, #0
	bl Proc_EndEach
	adds r0, r4, #0
	adds r1, r5, #0
	bl Proc_Start
	adds r1, r0, #0
	str r6, [r1, #0x2c]
	mov r0, r8
	str r0, [r1, #0x30]
	movs r0, #1
	negs r0, r0
	str r0, [r1, #0x34]
	str r0, [r1, #0x38]
	movs r3, #0x80
	lsls r3, r3, #1
	movs r2, #3
	adds r0, r1, #0
	adds r0, #0x42
_0804D69A:
	strh r3, [r0]
	subs r0, #2
	subs r2, #1
	cmp r2, #0
	bge _0804D69A
	adds r0, r1, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0804D6B0: .4byte gUnknown_085AABC8

	THUMB_FUNC_END sub_804D664

	THUMB_FUNC_START sub_804D6B4
sub_804D6B4: @ 0x0804D6B4
	push {lr}
	ldr r0, _0804D6C0  @ gUnknown_085AABC8
	bl Proc_EndEach
	pop {r0}
	bx r0
	.align 2, 0
_0804D6C0: .4byte gUnknown_085AABC8

	THUMB_FUNC_END sub_804D6B4

	THUMB_FUNC_START sub_804D6C4
sub_804D6C4: @ 0x0804D6C4
	push {lr}
	ldr r0, _0804D6D0  @ gUnknown_085AABC8
	bl Proc_Find
	pop {r1}
	bx r1
	.align 2, 0
_0804D6D0: .4byte gUnknown_085AABC8

	THUMB_FUNC_END sub_804D6C4

	THUMB_FUNC_START sub_804D6D4
sub_804D6D4: @ 0x0804D6D4
	push {r4, r5, lr}
	ldr r5, _0804D718  @ Pal_LinkArenaActiveBannerFx
	ldr r0, _0804D71C  @ gUnk_Sio_0203DDDC
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0804D712
	bl GetGameClock
	adds r2, r0, #0
	movs r0, #0x1f
	ands r2, r0
	asrs r2, r2, #1
	movs r1, #0
	ldr r0, _0804D720  @ gPaletteBuffer
	movs r4, #0xf
	adds r3, r0, #0
	adds r3, #0x42
_0804D6FA:
	adds r0, r2, r1
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	strh r0, [r3]
	adds r3, #2
	adds r1, #1
	cmp r1, #0xe
	ble _0804D6FA
	bl EnablePaletteSync
_0804D712:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804D718: .4byte Pal_LinkArenaActiveBannerFx
_0804D71C: .4byte gUnk_Sio_0203DDDC
_0804D720: .4byte gPaletteBuffer

	THUMB_FUNC_END sub_804D6D4

	THUMB_FUNC_START sub_804D724
sub_804D724: @ 0x0804D724
	push {r4, r5, r6, lr}
	ldr r5, _0804D768  @ Pal_LinkArenaActiveBannerFx
	ldr r0, _0804D76C  @ gUnk_Sio_0203DDDC
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0804D762
	bl GetGameClock
	adds r2, r0, #0
	movs r0, #0x1f
	ands r2, r0
	asrs r2, r2, #1
	movs r1, #0
	ldr r0, _0804D770  @ gPaletteBuffer
	movs r4, #0xf
	ldr r6, _0804D774  @ 0x00000262
	adds r3, r0, r6
_0804D74A:
	adds r0, r2, r1
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	strh r0, [r3]
	adds r3, #2
	adds r1, #1
	cmp r1, #0xe
	ble _0804D74A
	bl EnablePaletteSync
_0804D762:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804D768: .4byte Pal_LinkArenaActiveBannerFx
_0804D76C: .4byte gUnk_Sio_0203DDDC
_0804D770: .4byte gPaletteBuffer
_0804D774: .4byte 0x00000262

	THUMB_FUNC_END sub_804D724

	THUMB_FUNC_START sub_804D778
sub_804D778: @ 0x0804D778
	push {r4, lr}
	sub sp, #4
	movs r0, #1
	movs r1, #8
	movs r2, #0xc
	movs r3, #0
	bl SetBlendConfig
	movs r4, #0
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl SetBlendTargetA
	str r4, [sp]
	movs r0, #0
	movs r1, #1
	movs r2, #1
	movs r3, #1
	bl SetBlendTargetB
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	THUMB_FUNC_END sub_804D778

	THUMB_FUNC_START sub_804D7B0
sub_804D7B0: @ 0x0804D7B0
	push {lr}
	sub sp, #4
	adds r1, r0, #0
	ldr r2, [r1, #0x30]
	adds r0, r2, #0
	subs r0, #0x1f
	cmp r0, #0x79
	bhi _0804D7D2
	ldr r1, [r1, #0x2c]
	ldr r3, _0804D7D8  @ gUnknown_080DA27E
	movs r0, #0
	str r0, [sp]
	movs r0, #4
	bl PutSprite
	bl sub_804D724
_0804D7D2:
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_0804D7D8: .4byte gUnknown_080DA27E

	THUMB_FUNC_END sub_804D7B0

	THUMB_FUNC_START sub_804D7DC
sub_804D7DC: @ 0x0804D7DC
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r6, r0, #0
	mov r8, r1
	adds r5, r2, #0
	ldr r4, _0804D808  @ gUnknown_085AABD8
	adds r0, r4, #0
	bl Proc_EndEach
	adds r0, r4, #0
	adds r1, r5, #0
	bl Proc_Start
	str r6, [r0, #0x2c]
	mov r1, r8
	str r1, [r0, #0x30]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0804D808: .4byte gUnknown_085AABD8

	THUMB_FUNC_END sub_804D7DC

	THUMB_FUNC_START sub_804D80C
sub_804D80C: @ 0x0804D80C
	push {lr}
	ldr r0, _0804D828  @ gGfx_SupportMenu
	ldr r1, _0804D82C  @ 0x06016800
	bl Decompress
	ldr r0, _0804D830  @ gPal_SupportMenu
	movs r1, #0x90
	lsls r1, r1, #2
	movs r2, #0x20
	bl CopyToPaletteBuffer
	pop {r0}
	bx r0
	.align 2, 0
_0804D828: .4byte gGfx_SupportMenu
_0804D82C: .4byte 0x06016800
_0804D830: .4byte gPal_SupportMenu

	THUMB_FUNC_END sub_804D80C

	THUMB_FUNC_START sub_804D834
sub_804D834: @ 0x0804D834
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r2, r1, #0
	ldr r3, _0804D854  @ gUnknown_080DA2B0
	movs r0, #0x9d
	lsls r0, r0, #6
	str r0, [sp]
	movs r0, #1
	adds r1, r4, #0
	bl PutSprite
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804D854: .4byte gUnknown_080DA2B0

	THUMB_FUNC_END sub_804D834

	THUMB_FUNC_START sub_804D858
sub_804D858: @ 0x0804D858
	push {r4, r5, lr}
	ldr r5, _0804D884  @ gActiveUnit
	ldr r0, [r5]
	lsls r1, r1, #1
	adds r0, #0x1e
	adds r0, r0, r1
	ldrh r4, [r0]
	adds r0, r4, #0
	bl GetItemAttributes
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq _0804D89A
	adds r0, r4, #0
	bl GetItemMinRange
	cmp r0, #2
	ble _0804D888
	movs r0, #2
	b _0804D89C
	.align 2, 0
_0804D884: .4byte gActiveUnit
_0804D888:
	ldr r0, [r5]
	adds r1, r4, #0
	bl CanUnitUseWeapon
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804D89A
	movs r0, #1
	b _0804D89C
_0804D89A:
	movs r0, #3
_0804D89C:
	pop {r4, r5}
	pop {r1}
	bx r1

	THUMB_FUNC_END sub_804D858

	THUMB_FUNC_START sub_804D8A4
sub_804D8A4: @ 0x0804D8A4
	push {lr}
	adds r0, r1, #0
	adds r0, #0x3d
	ldrb r0, [r0]
	cmp r0, #2
	beq _0804D8C0
	ldr r0, _0804D8BC  @ gUnk_Sio_0203DD90
	adds r1, #0x3c
	ldrb r1, [r1]
	strb r1, [r0, #7]
	movs r0, #0x84
	b _0804D8C2
	.align 2, 0
_0804D8BC: .4byte gUnk_Sio_0203DD90
_0804D8C0:
	movs r0, #8
_0804D8C2:
	pop {r1}
	bx r1

	THUMB_FUNC_END sub_804D8A4

	THUMB_FUNC_START sub_804D8C8
sub_804D8C8: @ 0x0804D8C8
	ldr r2, _0804D8D8  @ gUnk_Sio_0203DD90
	adds r1, #0x3c
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r2, #6]
	movs r0, #0x17
	bx lr
	.align 2, 0
_0804D8D8: .4byte gUnk_Sio_0203DD90

	THUMB_FUNC_END sub_804D8C8

	THUMB_FUNC_START sub_804D8DC
sub_804D8DC: @ 0x0804D8DC
	push {r4, r5, r6, lr}
	adds r4, r1, #0
	ldr r0, _0804D938  @ gActiveUnit
	ldr r0, [r0]
	adds r1, #0x3c
	movs r2, #0
	ldrsb r2, [r1, r2]
	lsls r2, r2, #1
	adds r1, r0, #0
	adds r1, #0x1e
	adds r1, r1, r2
	ldrh r6, [r1]
	adds r1, r6, #0
	bl CanUnitUseWeapon
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r0, r6, #0
	bl GetItemMinRange
	cmp r0, #2
	ble _0804D90A
	movs r5, #0
_0804D90A:
	adds r0, r4, #0
	adds r0, #0x34
	lsls r2, r5, #0x18
	asrs r2, r2, #0x18
	movs r1, #0x2c
	ldrsh r3, [r4, r1]
	lsls r3, r3, #5
	movs r5, #0x2a
	ldrsh r1, [r4, r5]
	adds r3, r3, r1
	lsls r3, r3, #1
	ldr r1, _0804D93C  @ gBG0TilemapBuffer
	adds r3, r3, r1
	adds r1, r6, #0
	bl DrawItemMenuLine
	movs r0, #1
	bl BG_EnableSyncByMask
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0804D938: .4byte gActiveUnit
_0804D93C: .4byte gBG0TilemapBuffer

	THUMB_FUNC_END sub_804D8DC

	THUMB_FUNC_START sub_804D940
sub_804D940: @ 0x0804D940
	ldr r1, _0804D94C  @ gUnk_Sio_0203DD90
	movs r0, #0
	strb r0, [r1, #6]
	movs r0, #0x1b
	bx lr
	.align 2, 0
_0804D94C: .4byte gUnk_Sio_0203DD90

	THUMB_FUNC_END sub_804D940

	THUMB_FUNC_START sub_804D950
sub_804D950: @ 0x0804D950
	push {r4, r5, r6, r7, lr}
	adds r2, r0, #0
	ldr r1, _0804D9B8  @ gUnk_Sio_0203DD90
	movs r0, #0
	strb r0, [r1, #6]
	adds r7, r2, #0
	adds r7, #0x2d
	movs r0, #0
	ldrsb r0, [r7, r0]
	lsls r0, r0, #5
	adds r5, r2, #0
	adds r5, #0x2c
	movs r1, #0
	ldrsb r1, [r5, r1]
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _0804D9BC  @ gBG0TilemapBuffer
	adds r0, r0, r1
	adds r6, r2, #0
	adds r6, #0x2e
	movs r1, #0
	ldrsb r1, [r6, r1]
	adds r4, r2, #0
	adds r4, #0x2f
	movs r2, #0
	ldrsb r2, [r4, r2]
	movs r3, #0
	bl TileMap_FillRect
	movs r0, #0
	ldrsb r0, [r7, r0]
	lsls r0, r0, #5
	movs r1, #0
	ldrsb r1, [r5, r1]
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _0804D9C0  @ gBG1TilemapBuffer
	adds r0, r0, r1
	movs r1, #0
	ldrsb r1, [r6, r1]
	movs r2, #0
	ldrsb r2, [r4, r2]
	movs r3, #0
	bl TileMap_FillRect
	movs r0, #3
	bl BG_EnableSyncByMask
	movs r0, #0xb
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804D9B8: .4byte gUnk_Sio_0203DD90
_0804D9BC: .4byte gBG0TilemapBuffer
_0804D9C0: .4byte gBG1TilemapBuffer

	THUMB_FUNC_END sub_804D950

	THUMB_FUNC_START sub_804D9C4
sub_804D9C4: @ 0x0804D9C4
	adds r2, r0, #0
	movs r1, #0
	strb r1, [r2, #0x1e]
	strb r1, [r2, #0x18]
	strb r1, [r2, #0x1d]
	adds r3, r2, #0
	adds r3, #0x4a
	movs r0, #0xf
	strb r0, [r3]
	adds r0, r2, #0
	adds r0, #0x48
	strb r1, [r0]
	strh r1, [r2, #0x16]
	ldr r0, _0804D9F0  @ 0x04000134
	strh r1, [r0]
	ldr r2, _0804D9F4  @ 0x04000128
	ldr r3, _0804D9F8  @ 0x00002003
	adds r0, r3, #0
	strh r0, [r2]
	ldr r0, _0804D9FC  @ 0x0400012A
	strh r1, [r0]
	bx lr
	.align 2, 0
_0804D9F0: .4byte 0x04000134
_0804D9F4: .4byte 0x04000128
_0804D9F8: .4byte 0x00002003
_0804D9FC: .4byte 0x0400012A

	THUMB_FUNC_END sub_804D9C4

	THUMB_FUNC_START sub_804DA00
sub_804DA00: @ 0x0804DA00
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	bl sub_804DF24
	cmp r0, #0
	beq _0804DA16
	b _0804DDDE
_0804DA16:
	adds r0, r7, #0
	adds r0, #0x4a
	ldrb r1, [r0]
	mov sl, r0
	cmp r1, #0xf
	bls _0804DA2A
	subs r0, r1, #1
	mov r1, sl
	strb r0, [r1]
	b _0804DDDE
_0804DA2A:
	adds r1, r7, #0
	adds r1, #0x48
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804DA54
	movs r0, #0
	strb r0, [r1]
	ldr r0, _0804DA50  @ 0x04000128
	ldrh r0, [r0]
	movs r5, #0xfc
	ands r5, r0
	cmp r5, #8
	beq _0804DA54
	adds r0, r7, #0
	bl sub_804D9C4
	movs r0, #8
	eors r0, r5
	b _0804DDE0
	.align 2, 0
_0804DA50: .4byte 0x04000128
_0804DA54:
	ldrb r0, [r7, #0x18]
	cmp r0, #0xdf
	bls _0804DAA6
	adds r0, r7, #0
	bl sub_804DF38
	adds r5, r0, #0
	cmp r5, #0
	beq _0804DA68
	b _0804DDE0
_0804DA68:
	adds r0, r7, #0
	adds r0, #0x4b
	ldrb r0, [r0]
	cmp r0, #1
	bne _0804DA84
	ldrb r0, [r7, #0x18]
	cmp r0, #0xe1
	bls _0804DA84
	adds r0, r7, #0
	bl sub_804DF24
	cmp r0, #0
	bne _0804DA84
	b _0804DDCE
_0804DA84:
	adds r0, r7, #0
	bl sub_804DF24
	cmp r0, #0
	beq _0804DA90
	b _0804DDDE
_0804DA90:
	ldrh r0, [r7, #0x16]
	cmp r0, #0
	bne _0804DAA0
	adds r0, r7, #0
	bl sub_804D9C4
	movs r0, #0x71
	b _0804DDE0
_0804DAA0:
	subs r0, #1
	strh r0, [r7, #0x16]
	b _0804DDDE
_0804DAA6:
	ldrb r0, [r7, #0x18]
	cmp r0, #2
	bne _0804DAAE
	b _0804DBE4
_0804DAAE:
	cmp r0, #2
	bgt _0804DABC
	cmp r0, #0
	beq _0804DACA
	cmp r0, #1
	beq _0804DB86
	b _0804DD1C
_0804DABC:
	cmp r0, #0xd0
	bne _0804DAC2
	b _0804DC30
_0804DAC2:
	cmp r0, #0xd1
	bne _0804DAC8
	b _0804DCCA
_0804DAC8:
	b _0804DD1C
_0804DACA:
	movs r3, #0xe
	movs r5, #3
	ldr r0, _0804DB10  @ 0x04000120
	ldrh r0, [r0, #6]
	adds r1, r0, #0
	ldr r0, _0804DB14  @ 0x0000FFFF
	ldrb r2, [r7, #0x1e]
	adds r6, r2, #0
	cmp r1, r0
	bne _0804DAF2
	adds r4, r1, #0
	ldr r1, _0804DB18  @ 0x04000126
_0804DAE2:
	asrs r3, r3, #1
	subs r1, #2
	subs r5, #1
	cmp r5, #0
	beq _0804DAF2
	ldrh r0, [r1]
	cmp r0, r4
	beq _0804DAE2
_0804DAF2:
	movs r0, #0xe
	ands r3, r0
	strb r3, [r7, #0x1d]
	movs r5, #3
	ldr r0, _0804DB10  @ 0x04000120
	ldrh r0, [r0, #6]
	adds r4, r0, #0
	asrs r0, r2, #3
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0804DB20
	ldr r0, _0804DB1C  @ 0x00007208
	b _0804DB46
	.align 2, 0
_0804DB10: .4byte 0x04000120
_0804DB14: .4byte 0x0000FFFF
_0804DB18: .4byte 0x04000126
_0804DB1C: .4byte 0x00007208
_0804DB20:
	subs r5, #1
	cmp r5, #0
	beq _0804DB4C
	lsls r0, r5, #1
	ldr r1, _0804DB74  @ 0x04000120
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, #0
	adds r0, r2, #0
	asrs r0, r5
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0804DB20
	adds r0, r1, #0
	lsls r0, r5
	movs r1, #0xe4
	lsls r1, r1, #7
	orrs r0, r1
_0804DB46:
	cmp r4, r0
	beq _0804DB20
	movs r3, #0
_0804DB4C:
	adds r0, r3, #0
	ands r0, r6
	strb r0, [r7, #0x1e]
	cmp r3, #0
	bne _0804DB5C
	movs r0, #0xf
	mov r2, sl
	strb r0, [r2]
_0804DB5C:
	mov r1, sl
	ldrb r0, [r1]
	cmp r0, #0
	bne _0804DB78
	ldrb r0, [r7, #0x1d]
	ldrb r2, [r7, #0x1e]
	cmp r0, r2
	beq _0804DB7E
	adds r0, r7, #0
	bl sub_804DE3C
	b _0804DB86
	.align 2, 0
_0804DB74: .4byte 0x04000120
_0804DB78:
	subs r0, #1
	mov r1, sl
	strb r0, [r1]
_0804DB7E:
	ldrb r1, [r7, #0x1e]
	movs r2, #0xc4
	lsls r2, r2, #7
	b _0804DC86
_0804DB86:
	adds r1, r7, #0
	adds r1, #0x49
	movs r0, #0
	strb r0, [r1]
	movs r5, #3
	mov ip, r1
	ldr r3, _0804DBDC  @ gUnknown_03001864
_0804DB94:
	lsls r0, r5, #1
	ldr r2, _0804DBE0  @ 0x04000120
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r4, r0, #0
	asrs r0, r4, #8
	subs r2, r5, #1
	cmp r0, #0x72
	bne _0804DBBE
	lsls r0, r2, #1
	adds r0, r0, r3
	strh r4, [r0]
	movs r0, #0xff
	ands r4, r0
	movs r0, #1
	lsls r0, r5
	cmp r4, r0
	bne _0804DBBE
	ldrb r0, [r1]
	orrs r4, r0
	strb r4, [r1]
_0804DBBE:
	adds r5, r2, #0
	cmp r5, #0
	bne _0804DB94
	ldrb r0, [r7, #0x1d]
	mov r1, ip
	ldrb r1, [r1]
	cmp r0, r1
	bne _0804DB7E
	movs r0, #2
	strb r0, [r7, #0x18]
	mov r2, ip
	ldrb r1, [r2]
	movs r2, #0xc2
	lsls r2, r2, #7
	b _0804DC86
	.align 2, 0
_0804DBDC: .4byte gUnknown_03001864
_0804DBE0: .4byte 0x04000120
_0804DBE4:
	movs r5, #3
	movs r0, #0x49
	adds r0, r0, r7
	mov ip, r0
	mov r4, ip
	movs r6, #1
	ldr r1, _0804DC28  @ gUnknown_03001864
	mov r9, r1
	ldr r2, _0804DC2C  @ 0x04000120
	mov r8, r2
_0804DBF8:
	ldrb r3, [r4]
	adds r0, r3, #0
	asrs r0, r5
	ands r0, r6
	subs r2, r5, #1
	cmp r0, #0
	beq _0804DC1E
	lsls r0, r5, #1
	add r0, r8
	ldrh r1, [r0]
	lsls r0, r2, #1
	add r0, r9
	ldrh r0, [r0]
	cmp r1, r0
	beq _0804DC1E
	adds r0, r6, #0
	lsls r0, r5
	eors r3, r0
	strb r3, [r4]
_0804DC1E:
	adds r5, r2, #0
	cmp r5, #0
	bne _0804DBF8
	b _0804DD84
	.align 2, 0
_0804DC28: .4byte gUnknown_03001864
_0804DC2C: .4byte 0x04000120
_0804DC30:
	movs r3, #1
	movs r5, #3
	movs r0, #0x49
	adds r0, r0, r7
	mov ip, r0
	adds r6, r7, #0
	adds r6, #0x19
	ldr r1, _0804DC94  @ gUnknown_03001864
	mov r8, r1
_0804DC42:
	lsls r0, r5, #1
	ldr r2, _0804DC98  @ 0x04000120
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r4, r0, #0
	subs r2, r5, #1
	adds r0, r6, r2
	strb r4, [r0]
	mov r0, ip
	ldrb r1, [r0]
	asrs r1, r5
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _0804DC76
	asrs r0, r4, #8
	subs r0, #0x72
	cmp r0, #1
	bls _0804DC6A
	b _0804DDD4
_0804DC6A:
	lsls r0, r2, #1
	add r0, r8
	ldrh r0, [r0]
	cmp r4, r0
	bne _0804DC76
	movs r3, #0
_0804DC76:
	adds r5, r2, #0
	cmp r5, #0
	bne _0804DC42
	cmp r3, #0
	bne _0804DC9C
	ldrb r1, [r7, #0x1c]
	movs r2, #0xc6
	lsls r2, r2, #7
_0804DC86:
	adds r0, r2, #0
	orrs r1, r0
	adds r0, r7, #0
	bl sub_804DDF0
	b _0804DDE0
	.align 2, 0
_0804DC94: .4byte gUnknown_03001864
_0804DC98: .4byte 0x04000120
_0804DC9C:
	movs r0, #0xd1
	strb r0, [r7, #0x18]
	movs r3, #0x11
	movs r5, #3
	adds r1, r6, #2
_0804DCA6:
	ldrb r0, [r1]
	adds r3, r3, r0
	subs r1, #1
	subs r5, #1
	cmp r5, #0
	bne _0804DCA6
	strb r3, [r7, #0x14]
	movs r0, #0xff
	ands r3, r0
	movs r1, #0xc8
	lsls r1, r1, #7
	adds r0, r1, #0
	orrs r3, r0
	adds r0, r7, #0
	adds r1, r3, #0
	bl sub_804DDF0
	b _0804DDE0
_0804DCCA:
	movs r5, #3
	movs r2, #0x49
	ldrb r1, [r2, r7]
	ldr r2, _0804DD08  @ 0x04000126
	movs r3, #1
_0804DCD4:
	ldrh r0, [r2]
	adds r4, r0, #0
	adds r0, r1, #0
	asrs r0, r5
	ands r0, r3
	cmp r0, #0
	beq _0804DCE8
	asrs r0, r4, #8
	cmp r0, #0x73
	bne _0804DDD4
_0804DCE8:
	subs r2, #2
	subs r5, #1
	cmp r5, #0
	bne _0804DCD4
	adds r0, r7, #0
	bl MultiBoot
	adds r5, r0, #0
	cmp r5, #0
	bne _0804DD0C
	movs r0, #0xe0
	strb r0, [r7, #0x18]
	adds r0, #0xb0
	strh r0, [r7, #0x16]
	b _0804DDDE
	.align 2, 0
_0804DD08: .4byte 0x04000126
_0804DD0C:
	adds r0, r7, #0
	bl sub_804D9C4
	movs r0, #0x1e
	mov r1, sl
	strb r0, [r1]
	movs r0, #0x70
	b _0804DDE0
_0804DD1C:
	movs r5, #3
	movs r2, #0x49
	adds r2, r2, r7
	mov ip, r2
	mov r8, ip
	movs r0, #1
	mov r9, r0
_0804DD2A:
	mov r1, r8
	ldrb r6, [r1]
	adds r0, r6, #0
	asrs r0, r5
	mov r2, r9
	ands r0, r2
	cmp r0, #0
	beq _0804DD64
	lsls r0, r5, #1
	ldr r1, _0804DD80  @ 0x04000120
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, #0
	asrs r2, r4, #8
	ldrb r0, [r7, #0x18]
	lsrs r0, r0, #1
	movs r1, #0x62
	subs r1, r1, r0
	mov r3, r9
	lsls r3, r5
	cmp r2, r1
	bne _0804DD5E
	movs r0, #0xff
	ands r4, r0
	cmp r4, r3
	beq _0804DD64
_0804DD5E:
	eors r6, r3
	mov r2, r8
	strb r6, [r2]
_0804DD64:
	subs r5, #1
	cmp r5, #0
	bne _0804DD2A
	ldrb r0, [r7, #0x18]
	cmp r0, #0xc4
	bne _0804DD84
	mov r0, ip
	ldrb r1, [r0]
	movs r0, #0xe
	ands r0, r1
	strb r0, [r7, #0x1e]
	strb r5, [r7, #0x18]
	b _0804DB7E
	.align 2, 0
_0804DD80: .4byte 0x04000120
_0804DD84:
	mov r1, ip
	ldrb r0, [r1]
	cmp r0, #0
	bne _0804DD96
	adds r0, r7, #0
	bl sub_804D9C4
	movs r0, #0x50
	b _0804DDE0
_0804DD96:
	ldrb r0, [r7, #0x18]
	adds r0, #2
	strb r0, [r7, #0x18]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xc4
	bne _0804DDA6
	b _0804DB7E
_0804DDA6:
	ldrb r0, [r7, #0x18]
	ldr r1, [r7, #0x28]
	adds r0, r0, r1
	subs r1, r0, #3
	ldrb r2, [r1]
	lsls r2, r2, #8
	subs r0, #4
	ldrb r1, [r0]
	orrs r1, r2
	adds r0, r7, #0
	bl sub_804DDF0
	adds r5, r0, #0
	cmp r5, #0
	bne _0804DDE0
	adds r0, r7, #0
	adds r0, #0x4b
	ldrb r0, [r0]
	cmp r0, #1
	bne _0804DDDE
_0804DDCE:
	bl sub_804E03C
	b _0804DA2A
_0804DDD4:
	adds r0, r7, #0
	bl sub_804D9C4
	movs r0, #0x60
	b _0804DDE0
_0804DDDE:
	movs r0, #0
_0804DDE0:
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	THUMB_FUNC_END sub_804DA00

	THUMB_FUNC_START sub_804DDF0
sub_804DDF0: @ 0x0804DDF0
	push {r4, lr}
	adds r2, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _0804DE1C  @ 0x04000128
	ldrh r0, [r3]
	movs r4, #0x8c
	ands r4, r0
	cmp r4, #8
	bne _0804DE28
	ldr r0, _0804DE20  @ 0x0400012A
	strh r1, [r0]
	ldr r1, _0804DE24  @ 0x00002083
	adds r0, r1, #0
	strh r0, [r3]
	adds r1, r2, #0
	adds r1, #0x48
	movs r0, #1
	strb r0, [r1]
	movs r0, #0
	b _0804DE34
	.align 2, 0
_0804DE1C: .4byte 0x04000128
_0804DE20: .4byte 0x0400012A
_0804DE24: .4byte 0x00002083
_0804DE28:
	adds r0, r2, #0
	bl sub_804D9C4
	movs r0, #8
	eors r4, r0
	adds r0, r4, #0
_0804DE34:
	pop {r4}
	pop {r1}
	bx r1

	THUMB_FUNC_END sub_804DDF0

	THUMB_FUNC_START sub_804DE3C
sub_804DE3C: @ 0x0804DE3C
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #0x18]
	cmp r0, #0
	beq _0804DE4E
	adds r0, r1, #0
	bl sub_804D9C4
	b _0804DE5A
_0804DE4E:
	adds r2, r1, #0
	adds r2, #0x4a
	strb r0, [r2]
	strb r0, [r1, #0x1e]
	movs r0, #1
	strb r0, [r1, #0x18]
_0804DE5A:
	pop {r0}
	bx r0

	THUMB_FUNC_END sub_804DE3C

	THUMB_FUNC_START sub_804DE60
sub_804DE60: @ 0x0804DE60
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, [sp, #0x14]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldrb r0, [r5, #0x18]
	cmp r0, #0
	bne _0804DE9A
	ldrb r0, [r5, #0x1e]
	cmp r0, #0
	beq _0804DE9A
	adds r0, r5, #0
	adds r0, #0x4a
	ldrb r0, [r0]
	cmp r0, #0
	bne _0804DE9A
	str r6, [r5, #0x20]
	adds r2, #0xf
	movs r0, #0x10
	negs r0, r0
	ands r2, r0
	subs r0, #0xf0
	adds r1, r2, r0
	ldr r0, _0804DEA4  @ 0x0003FF00
	cmp r1, r0
	bls _0804DEA8
_0804DE9A:
	adds r0, r5, #0
	bl sub_804D9C4
	b _0804DF1C
	.align 2, 0
_0804DEA4: .4byte 0x0003FF00
_0804DEA8:
	adds r0, r6, r2
	str r0, [r5, #0x24]
	lsls r1, r7, #0x18
	movs r2, #0x80
	lsls r2, r2, #0x13
	adds r0, r1, r2
	asrs r0, r0, #0x18
	adds r2, r1, #0
	cmp r0, #8
	bhi _0804DF08
	lsls r0, r0, #2
	ldr r1, _0804DEC8  @ _0804DECC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804DEC8: .4byte _0804DECC
_0804DECC: @ jump table
	.4byte _0804DEF0 @ case 0
	.4byte _0804DEF0 @ case 1
	.4byte _0804DEF0 @ case 2
	.4byte _0804DEF0 @ case 3
	.4byte _0804DEFA @ case 4
	.4byte _0804DF00 @ case 5
	.4byte _0804DF00 @ case 6
	.4byte _0804DF00 @ case 7
	.4byte _0804DF00 @ case 8
_0804DEF0:
	lsls r4, r3, #3
	asrs r1, r2, #0x18
	movs r0, #3
	subs r0, r0, r1
	b _0804DF06
_0804DEFA:
	movs r0, #0x38
	adds r4, r3, #0
	b _0804DF06
_0804DF00:
	lsls r4, r3, #3
	asrs r0, r2, #0x18
	subs r0, #1
_0804DF06:
	orrs r4, r0
_0804DF08:
	movs r0, #0x3f
	ands r4, r0
	lsls r0, r4, #1
	movs r2, #0x7f
	negs r2, r2
	adds r1, r2, #0
	orrs r0, r1
	strb r0, [r5, #0x1c]
	movs r0, #0xd0
	strb r0, [r5, #0x18]
_0804DF1C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	THUMB_FUNC_END sub_804DE60

	THUMB_FUNC_START sub_804DF24
sub_804DF24: @ 0x0804DF24
	push {lr}
	ldrb r0, [r0, #0x18]
	cmp r0, #0xe9
	beq _0804DF30
	movs r0, #0
	b _0804DF32
_0804DF30:
	movs r0, #1
_0804DF32:
	pop {r1}
	bx r1

	THUMB_FUNC_END sub_804DF24

	THUMB_FUNC_START sub_804DF38
sub_804DF38: @ 0x0804DF38
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0x18]
	cmp r0, #0xe0
	beq _0804DF54
	cmp r0, #0xe0
	blt _0804DF64
	cmp r0, #0xe8
	bgt _0804DF64
	cmp r0, #0xe7
	blt _0804DF64
	movs r4, #3
	ldrb r5, [r3, #0x1e]
	b _0804DFC4
_0804DF54:
	movs r1, #0
	movs r0, #0xe1
	strb r0, [r3, #0x18]
	str r1, [r3, #4]
	movs r0, #0x80
	lsls r0, r0, #0xd
	str r0, [r3]
	b _0804DFB6
_0804DF64:
	movs r4, #3
	ldrb r5, [r3, #0x1e]
	movs r6, #1
	ldr r1, _0804DFC0  @ 0x04000126
_0804DF6C:
	ldrh r0, [r1]
	adds r2, r0, #0
	adds r0, r5, #0
	asrs r0, r4
	ands r0, r6
	cmp r0, #0
	beq _0804DF80
	ldr r0, [r3, #4]
	cmp r2, r0
	bne _0804DF54
_0804DF80:
	subs r1, #2
	subs r4, #1
	cmp r4, #0
	bne _0804DF6C
	ldrb r0, [r3, #0x18]
	adds r0, #1
	strb r0, [r3, #0x18]
	ldr r1, [r3]
	ldrh r0, [r3]
	str r0, [r3, #4]
	cmp r1, #0
	bne _0804DFAE
	ldr r0, [r3, #0x28]
	adds r1, r0, #0
	adds r1, #0xac
	ldrb r1, [r1]
	adds r0, #0xad
	ldrb r0, [r0]
	lsls r0, r0, #8
	orrs r1, r0
	str r1, [r3, #4]
	lsls r1, r1, #5
	str r1, [r3]
_0804DFAE:
	ldr r0, [r3]
	lsrs r0, r0, #5
	str r0, [r3]
_0804DFB4:
	ldrh r1, [r3]
_0804DFB6:
	adds r0, r3, #0
	bl sub_804DDF0
	b _0804E01C
	.align 2, 0
_0804DFC0: .4byte 0x04000126
_0804DFC4:
	lsls r0, r4, #1
	ldr r1, _0804E00C  @ 0x04000120
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r2, r0, #0
	adds r0, r5, #0
	asrs r0, r4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0804DFE0
	ldr r0, [r3, #4]
	cmp r2, r0
	bne _0804E010
_0804DFE0:
	subs r4, #1
	cmp r4, #0
	bne _0804DFC4
	ldrb r0, [r3, #0x18]
	adds r0, #1
	strb r0, [r3, #0x18]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xe9
	beq _0804E01A
	ldr r0, [r3, #0x28]
	adds r1, r0, #0
	adds r1, #0xae
	ldrb r1, [r1]
	adds r0, #0xaf
	ldrb r0, [r0]
	lsls r0, r0, #8
	orrs r1, r0
	str r1, [r3]
	str r1, [r3, #4]
	b _0804DFB4
	.align 2, 0
_0804E00C: .4byte 0x04000120
_0804E010:
	adds r0, r3, #0
	bl sub_804D9C4
	movs r0, #0x71
	b _0804E01C
_0804E01A:
	movs r0, #0
_0804E01C:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	THUMB_FUNC_END sub_804DF38

	THUMB_FUNC_START sub_804E024
sub_804E024: @ 0x0804E024
	mov r2, pc
	lsrs r2, r2, #0x18
	movs r1, #0xc
	cmp r2, #2
	beq _0804E036
	movs r1, #0xd
	cmp r2, #8
	beq _0804E036
	movs r1, #4
_0804E036:
	subs r0, r0, r1
	bgt _0804E036
	bx lr

	THUMB_FUNC_END sub_804E024

	THUMB_FUNC_START sub_804E03C
sub_804E03C: @ 0x0804E03C
	push {r4, r5, lr}
	movs r2, #0
	ldr r3, _0804E070  @ 0x04000128
	ldrh r1, [r3]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0804E060
	ldr r5, _0804E074  @ 0x0000795C
	movs r4, #0x80
_0804E050:
	adds r2, #1
	cmp r2, r5
	bgt _0804E060
	ldrh r1, [r3]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _0804E050
_0804E060:
	movs r0, #0x96
	lsls r0, r0, #2
	bl sub_804E024
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804E070: .4byte 0x04000128
_0804E074: .4byte 0x0000795C

	THUMB_FUNC_END sub_804E03C

.align 2, 0
