#ifndef BN_SPRITE_ITEMS_ALIEN_H
#define BN_SPRITE_ITEMS_ALIEN_H

#include "bn_sprite_item.h"

//{{BLOCK(alien_bn_gfx)

//======================================================================
//
//	alien_bn_gfx, 8x32@4, 
//	+ palette 16 entries, not compressed
//	+ 4 tiles not compressed
//	Total size: 32 + 128 = 160
//
//	Time-stamp: 2025-06-07, 08:23:12
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_ALIEN_BN_GFX_H
#define GRIT_ALIEN_BN_GFX_H

#define alien_bn_gfxTilesLen 128
extern const bn::tile alien_bn_gfxTiles[4];

#define alien_bn_gfxPalLen 32
extern const bn::color alien_bn_gfxPal[16];

#endif // GRIT_ALIEN_BN_GFX_H

//}}BLOCK(alien_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item alien(sprite_shape_size(sprite_shape::SQUARE, sprite_size::SMALL), 
            sprite_tiles_item(span<const tile>(alien_bn_gfxTiles, 4), bpp_mode::BPP_4, compression_type::NONE, 4), 
            sprite_palette_item(span<const color>(alien_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

