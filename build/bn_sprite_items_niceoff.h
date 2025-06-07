#ifndef BN_SPRITE_ITEMS_NICEOFF_H
#define BN_SPRITE_ITEMS_NICEOFF_H

#include "bn_sprite_item.h"

//{{BLOCK(niceoff_bn_gfx)

//======================================================================
//
//	niceoff_bn_gfx, 64x64@4, 
//	+ palette 16 entries, not compressed
//	+ 64 tiles Metatiled by 8x8 not compressed
//	Total size: 32 + 2048 = 2080
//
//	Time-stamp: 2025-06-07, 08:23:12
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_NICEOFF_BN_GFX_H
#define GRIT_NICEOFF_BN_GFX_H

#define niceoff_bn_gfxTilesLen 2048
extern const bn::tile niceoff_bn_gfxTiles[64];

#define niceoff_bn_gfxPalLen 32
extern const bn::color niceoff_bn_gfxPal[16];

#endif // GRIT_NICEOFF_BN_GFX_H

//}}BLOCK(niceoff_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item niceoff(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(niceoff_bn_gfxTiles, 64), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(niceoff_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

