/*
 * NewGame.h
 *
 *  Created on: 06-Oct-2019
 *      Author: pluto
 */

#ifndef NEWGAME_NEWGAME_H_
#define NEWGAME_NEWGAME_H_

#include "../Scene.h"
#include "../Misc/Common.h"

class NewGame final : public Scene {

private:
	sf::Texture backgroundTexture;
	sf::Sprite background;

	sf::Texture platformTexture;
	sf::Sprite platform;

	sf::Texture playerTexture;
	sf::Sprite player;

	bool playerMoveRight = false;
	bool playerMoveLeft = false;
	bool playerMoveUp = false;

	float playerCurrentVelocity = 0;
	float acceleration;

	void setNewScene(Scene *newScene) override;

	void applyForce(sf::Vector2f);

public:
	NewGame();
	virtual ~NewGame();
	void draw(sf::RenderWindow &window) const override;
	void update(const float delta) override;
	Scene* getNewScene() const override;
	bool getWillChangeScene() const override;
	void actionOnKeyRelase(sf::Keyboard::Key, const float delta) override;
	void actionOnMouseClick(sf::Mouse::Button, const sf::RenderWindow* window, const float delta) override;
	void actionOnKeyPress(sf::Keyboard::Key, const float delta) override;
	void pause() override;
	void actionOnMouseMove(const sf::RenderWindow* window, const float delta) override;
};

#endif /* NEWGAME_NEWGAME_H_ */
