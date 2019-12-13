/*
 * MainMenu.h
 *
 *  Created on: 25-Sep-2019
 *      Author: pluto
 */

#ifndef MAINMENU_MAINMENU_H_
#define MAINMENU_MAINMENU_H_

#include "../Scene.h"
#include <string>
#include <iostream>

#include "../Misc/Common.h"
#include "../Misc/Exceptions.h"
#include "../Misc/TextBox.h"
#include "../NewGame/NewGame.h"

class MainMenu final : public Scene {
private:
	sf::Texture backgroundTexture;
	sf::Font menuFont;
	sf::Sprite background;
	TextBox* newGame;
	TextBox* resume;
	TextBox* settings;

	bool willChangeScene = false;


public:
	MainMenu();
	virtual ~MainMenu();
	void update(const float delta) override;
	void draw(sf::RenderWindow & window) const override;

	void actionOnKeyRelase(sf::Keyboard::Key, const float delta) override;
	void actionOnMouseClick(sf::Mouse::Button, const sf::RenderWindow* window, const float delta) override;
	void actionOnMouseMove(const sf::RenderWindow* window, const float delta) override;
	void actionOnKeyPress(sf::Keyboard::Key, const float delta) override;
};

#endif /* MAINMENU_MAINMENU_H_ */
