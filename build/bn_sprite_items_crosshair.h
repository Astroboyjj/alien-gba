#ifndef BN_SPRITE_ITEMS_CROSSHAIR_H
#define BN_SPRITE_ITEMS_CROSSHAIR_H

#include "bn_sprite_item.h"

//{{BLOCK(crosshair_bn_gfx)

//======================================================================
//
//	crosshair_bn_gfx, 16x16@4, 
//	+ palette 16 entries, not compressed
//	+ 4 tiles Metatiled by 2x2 not compressed
//	Total size: 32 + 128 = 160
//
//	Time-stamp: 2025-06-07, 08:23:12
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CROSSHAIR_BN_GFX_H
#define GRIT_CROSSHAIR_BN_GFX_H

#define crosshair_bn_gfxTilesLen 128
extern const bn::tile crosshair_bn_gfxTiles[4];

#define crosshair_bn_gfxPalLen 32
extern const bn::color crosshair_bn_gfxPal[16];

#endif // GRIT_CROSSHAIR_BN_GFX_H

//}}BLOCK(crosshair_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item crosshair(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(crosshair_bn_gfxTiles, 4), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(crosshair_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

