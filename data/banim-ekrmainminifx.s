    .include "animscr.inc"
    .include "gba_sprites.inc"
	.section .data

	.global AnimSprite_EkrMainMini_L_Far
AnimSprite_EkrMainMini_L_Far:
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0000, -48, 8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0004, -16, 8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0008, 16, 8
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x000C, 48, 8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x000D, -48, -8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0011, -16, -8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0015, 16, -8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0019, -48, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x001D, -16, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0039, 0, -16
    ANIM_SPRITE_END

	.global AnimScr_EkrMainMini_L_Far
AnimScr_EkrMainMini_L_Far:  @ 0x085C72AC
    ANIMSCR_FORCE_SPRITE AnimSprite_EkrMainMini_L_Far, 4
    ANIMSCR_BLOCKED

	.global AnimSprite_EkrMainMini_R_Far
AnimSprite_EkrMainMini_R_Far:
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0000, 16, 8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0004, -16, 8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0008, -48, 8
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x000C, -56, 8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x000D, 16, -8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0011, -16, -8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0015, -48, -8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0019, 16, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x001D, 0, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0039, -32, -16
    ANIM_SPRITE_END

	.global AnimScr_EkrMainMini_R_Far
AnimScr_EkrMainMini_R_Far:  @ 0x085C7338
    ANIMSCR_FORCE_SPRITE AnimSprite_EkrMainMini_R_Far, 4
    ANIMSCR_BLOCKED

	.global AnimSprite_EkrMainMini_L_Close
AnimSprite_EkrMainMini_L_Close:
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0000, -48, 8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0004, -16, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x0008, 16, 8
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x000A, 32, 8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x000B, -48, -8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x000F, -16, -8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x0013, 16, -8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0015, -48, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0019, -16, -16
    ANIM_SPRITE_END

	.global AnimScr_EkrMainMini_L_Close
AnimScr_EkrMainMini_L_Close:  @ 0x085C73B8
    ANIMSCR_FORCE_SPRITE AnimSprite_EkrMainMini_L_Close, 4
    ANIMSCR_BLOCKED

	.global AnimSprite_EkrMainMini_R_Close
AnimSprite_EkrMainMini_R_Close:
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0000, 16, 8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0004, -16, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x0008, -32, 8
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x000A, -40, 8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x000B, 16, -8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x000F, -16, -8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x0013, -32, -8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0015, 16, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0019, -16, -16
    ANIM_SPRITE_END

	.global AnimScr_EkrMainMini_R_Close
AnimScr_EkrMainMini_R_Close:  @ 0x085C7438
    ANIMSCR_FORCE_SPRITE AnimSprite_EkrMainMini_R_Close, 4
    ANIMSCR_BLOCKED

.global AnimSprite_085C7440
AnimSprite_085C7440:  @ 0x5C7440
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x1000, -107, -8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x1008, -75, -8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x1004, -59, -8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x1008, -27, -8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0000, 11, -8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x0008, 43, -8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0004, 59, -8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x0008, 91, -8
    ANIM_SPRITE_END

.global AnimScr_085C74AC
AnimScr_085C74AC: @ 0x5C74AC
    ANIMSCR_FORCE_SPRITE AnimSprite_085C7440, 4
    ANIMSCR_BLOCKED
