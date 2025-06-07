
@{{BLOCK(crosshair_bn_gfx)

@=======================================================================
@
@	crosshair_bn_gfx, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles Metatiled by 2x2 not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2025-06-07, 08:29:51
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global crosshair_bn_gfxTiles		@ 128 unsigned chars
	.hidden crosshair_bn_gfxTiles
crosshair_bn_gfxTiles:
	.word 0x10000000,0x10000000,0x10000000,0x10000000,0x00000000,0x00000000,0x00000000,0x00001111
	.word 0x00000001,0x00000001,0x00000001,0x00000001,0x00000000,0x00000000,0x00000000,0x11110000
	.word 0x00001111,0x00000000,0x00000000,0x00000000,0x10000000,0x10000000,0x10000000,0x10000000
	.word 0x11110000,0x00000000,0x00000000,0x00000000,0x00000001,0x00000001,0x00000001,0x00000001

	.section .rodata
	.align	2
	.global crosshair_bn_gfxPal		@ 32 unsigned chars
	.hidden crosshair_bn_gfxPal
crosshair_bn_gfxPal:
	.hword 0x0000,0x3147,0x3D67,0x61A8,0x51FD,0x576C,0x6A27,0x6A86
	.hword 0x630B,0x463E,0x46BC,0x4710,0x4B35,0x477F,0x535F,0x637E

@}}BLOCK(crosshair_bn_gfx)
