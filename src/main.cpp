#include "bn_core.h"
#include "bn_regular_bg_ptr.h"
#include "bn_sprite_text_generator.h"
#include "bn_vector.h"
#include "bn_keypad.h"
#include "common_variable_8x8_sprite_font.h"
#include "bn_sprite_animate_actions.h"
#include "bn_sprite_ptr.h"
#include "bn_random.h"
#include "bn_sound_items.h"
#include "bn_music_items.h"
#include "bn_log.h"

#include "bn_regular_bg_items_bg.h"
#include "bn_sprite_items_alien.h"
#include "bn_sprite_items_crosshair.h"

bool is_alien_hit(bn::fixed_point crosshair, bn::fixed_point alien)
{
    //if (crosshair.y() >= (alien.y() - 4) && crosshair.y() <= (alien.y() + 4))
    if (bn::abs(crosshair.y() - alien.y()) < 4)
    {
        //if (crosshair.x() > (alien.x() - 4) && crosshair.x() <= (alien.y() + 4))
        if (bn::abs(crosshair.x() - alien.y()) < 4)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    bn::core::init();

    //background
    bn::regular_bg_ptr bg = bn::regular_bg_items::bg.create_bg(0,0);
    
    //set up text generator
    bn::sprite_text_generator text_generator(common::variable_8x8_sprite_font);
    bn::vector<bn::sprite_ptr, 32> ohno_text;
    bn::vector<bn::sprite_ptr, 32> info_text;
    bn::vector<bn::sprite_ptr, 32> start_text;

    bool menupause = true;

    bn::random random;

    //set up alien sprite
    bn::sprite_ptr alien_sprite = bn::sprite_items::alien.create_sprite(50, 45);
    alien_sprite.set_visible(false);
    alien_sprite.remove_camera();

    bn::sprite_animate_action<4> alien_action = bn::create_sprite_animate_action_forever(
            alien_sprite, 6, bn::sprite_items::alien.tiles_item(), 0, 1, 2, 3);

    //set up crosshair
    bn::sprite_ptr crosshair_sprite = bn::sprite_items::crosshair.create_sprite(0, 0);
    crosshair_sprite.set_visible(false);
    crosshair_sprite.remove_camera();


    while(true)
    {
        bn::core::update();

        // initial menu loop
	    if (menupause == true)
        {
            ohno_text.clear();
            info_text.clear();
            start_text.clear();
            text_generator.generate(-96, -68, "OH NO! ALIENS IN YOUR HOUSE!", ohno_text);
            text_generator.generate(-96, -58, "Press A to suck them up.", info_text);
            text_generator.generate(-96, -48, "Press Start to start!", start_text);
            if (bn::keypad::start_pressed())
            {
                menupause = false;
                ohno_text.clear();
                info_text.clear();
                start_text.clear();
                alien_sprite.set_visible(true); 
                crosshair_sprite.set_visible(true);
                bn::music_items::alien.play();
            }
        }
        
        // start of game
        if (menupause == false)
        {

            if (bn::keypad::up_held() && crosshair_sprite.y() > -80)
            {
                crosshair_sprite.set_y(crosshair_sprite.y() - 1);
            }
            if (bn::keypad::down_held() && crosshair_sprite.y() < 80)
            {
                crosshair_sprite.set_y(crosshair_sprite.y() + 1);
            }
            if (bn::keypad::left_held() && crosshair_sprite.x() > -120)
            {
                crosshair_sprite.set_x(crosshair_sprite.x() - 1);
            }
            if (bn::keypad::right_held() && crosshair_sprite.x() < 120)
            {
                crosshair_sprite.set_x(crosshair_sprite.x() + 1);
            }

            
            if (bn::keypad::a_pressed() && is_alien_hit(crosshair_sprite.position(), alien_sprite.position()))
            {
                bn::sound_items::suck.play(); 
                int x = (random.get_int() % 240) - 120; 
                int y = (random.get_int() % 160) - 80;
                BN_LOG(x," ", y);
                alien_sprite.set_position(x, y);
            }
            if (bn::keypad::a_pressed())
            {
                BN_LOG("a ", crosshair_sprite.x(), ", ", crosshair_sprite.y());
            }
            if (bn::keypad::b_pressed())
            {
                BN_LOG("b", alien_sprite.x(), ", ", alien_sprite.y());
            }

            alien_action.update();
        }


    }
}
