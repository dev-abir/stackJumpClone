/*
 * GameSettings.h
 *
 *  Created on: 29-Dec-2019
 *      Author: pluto
 */

#ifndef GAME_SETTINGS_H_
#define GAME_SETTINGS_H_

///////Display Settings///////
#define WIDTH 600
#define HEIGHT 600


///////Fonts///////
#define SERIF_FONT_FILE "resources/fonts/FreeSerif.ttf"


///////Physics///////
#define g 9.8 //In metre per second square


///////Main Menu///////
#define MAIN_MENU_FONT_FILE SERIF_FONT_FILE
#define MAIN_MENU_BACKGROUND_TEXTURE_FILE "resources/sky1.png"


///////Pause Menu///////
#define PAUSE_MENU_FONT_FILE MAIN_MENU_FONT_FILE


///////New Game///////
#define NEW_GAME_BACKGROUND_TEXTURE_FILE "resources/island.png"
#define NEW_GAME_PLAYER_TEXTURE_FILE "resources/slime.png"
#define NEW_GAME_PLAYER_TEXTURE_WIDTH 49
#define NEW_GAME_PLAYER_TEXTURE_HEIGHT 47
#define MASS_OF_PLAYER 2 //In kg
#define FORCE_IMPARTED_ON_PRESSING_KEY_UP 2000


#endif /* GAME_SETTINGS_H_ */
