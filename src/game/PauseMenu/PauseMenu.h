/*
 * PauseMenu.h
 *
 *  Created on: 18-Dec-2019
 *      Author: pluto
 */

#ifndef PAUSEMENU_PAUSEMENU_H_
#define PAUSEMENU_PAUSEMENU_H_

#include <Scene/Scene.h>
#include "GameSettings.h"
#include <GUI/TextBox.h>
#include <Util/Util.h>

class PauseMenu final : public Scene {

  private:
	sf::Texture backgroundTexture;
	sf::Font menuFont;
	sf::Sprite background;
	TextBox *settings;
	TextBox *resume;

	bool willChangeScene = false;

  public:
	PauseMenu();
	virtual ~PauseMenu();
	void update(const float delta) override;
	void draw(sf::RenderWindow &window) const override;

	void actionOnKeyRelase(sf::Keyboard::Key, const float delta) override;
	void actionOnMouseClick(sf::Mouse::Button, const sf::RenderWindow *window,
							const float delta) override;
	void actionOnMouseMove(const sf::RenderWindow *window, const float delta)
	override;
	void actionOnKeyPress(sf::Keyboard::Key, const float delta) override;
};

#endif /* PAUSEMENU_PAUSEMENU_H_ */
