
@{{BLOCK(alien_bn_gfx)

@=======================================================================
@
@	alien_bn_gfx, 8x32@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2025-06-07, 08:29:51
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global alien_bn_gfxTiles		@ 128 unsigned chars
	.hidden alien_bn_gfxTiles
alien_bn_gfxTiles:
	.word 0x00616100,0x00666600,0x00061000,0x60066006,0x06666660,0x00BB5500,0x00666600,0x06600660
	.word 0x00616100,0x00666600,0x00061000,0x00066000,0x66666666,0x00B55B00,0x00666600,0x00600600
	.word 0x00161600,0x00666600,0x00016000,0x00066000,0x06666660,0x6055BB06,0x00666600,0x00666600
	.word 0x00161600,0x00666600,0x00016000,0x00066000,0x66666666,0x00B55B00,0x00666600,0x00600600

	.section .rodata
	.align	2
	.global alien_bn_gfxPal		@ 32 unsigned chars
	.hidden alien_bn_gfxPal
alien_bn_gfxPal:
	.hword 0x0000,0x463E,0x46BC,0x535F,0x637E,0x477F,0x4B35,0x4710
	.hword 0x576C,0x630B,0x6A86,0x6A27,0x3147,0x3D67,0x61A8,0x51FD

@}}BLOCK(alien_bn_gfx)
