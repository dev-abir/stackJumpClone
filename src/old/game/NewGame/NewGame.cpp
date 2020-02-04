/*
 * NewGame.cpp
 *
 *  Created on: 06-Oct-2019
 *      Author: pluto
 */

#include "NewGame.h"

NewGame::NewGame() : Scene(false) {
	if (!backgroundTexture.loadFromFile(NEW_GAME_BACKGROUND_TEXTURE_FILE)) {
		std::cerr << "Cannot load " << NEW_GAME_BACKGROUND_TEXTURE_FILE << "\n";
		throw EXCEPTION_CANNOT_OPEN_FILE;
	}
	background.setTexture(backgroundTexture);

	if (!playerTexture.loadFromFile(NEW_GAME_PLAYER_TEXTURE_FILE, sf::IntRect(0, 0, NEW_GAME_PLAYER_TEXTURE_WIDTH, NEW_GAME_PLAYER_TEXTURE_HEIGHT))) {
		std::cerr << "Cannot load " << NEW_GAME_PLAYER_TEXTURE_FILE << "\n";
		throw EXCEPTION_CANNOT_OPEN_FILE;
	}

	player.setTexture(playerTexture);
	player.setPosition(WIDTH / 2, (HEIGHT - player.getGlobalBounds().height));
}

NewGame::~NewGame() {
	// TODO Auto-generated destructor stub
}

void NewGame::draw(sf::RenderWindow &window) const {
	window.draw(background);
	window.draw(player);
}

void NewGame::update(const float delta) {
	extern unsigned int currentFPS;
	const float time = 1.0 / currentFPS;
	std::cout << "time : " << time << "\n";
	std::cout << "acceleration : " << acceleration << "\n";
	if(player.getPosition().y >= (HEIGHT - player.getGlobalBounds().height)) {
		acceleration = 0;
		playerCurrentVelocity = 0;
	} else {
		acceleration -= g;
		player.move(0, -(playerCurrentVelocity * time + (1.0 / 2.0) * acceleration * time * time)); //s = ut+(1/2)at<square>, -ve value of move(x, y)'s second argument means the player will move upwards
	}
	if(playerMoveUp && (player.getPosition().y >= (HEIGHT - player.getGlobalBounds().height))) {
		acceleration = FORCE_IMPARTED_ON_PRESSING_KEY_UP / MASS_OF_PLAYER;
		playerCurrentVelocity = playerCurrentVelocity + (acceleration * time); //v = u+at
		player.move(0, -(playerCurrentVelocity * time + (1.0 / 2.0) * acceleration * time * time)); //s = ut+(1/2)at<square>, -ve value of move(x, y)'s second argument means the player will move upwards
	}
	playerMoveUp = false;
}

void NewGame::actionOnKeyRelase(sf::Keyboard::Key key, const float delta) {
}

void NewGame::actionOnMouseClick(sf::Mouse::Button button, const sf::RenderWindow* window, const float delta) {
}

void NewGame::actionOnKeyPress(sf::Keyboard::Key key, const float delta) {
	if(key == sf::Keyboard::Right) {
		player.move(delta, 0);
	}
	if(key == sf::Keyboard::Up) {
		playerMoveUp = true;
	}
	if(key == sf::Keyboard::Space) {
		pause();
	}
}

void NewGame::pause() {
	Scene::setNewScene(new PauseMenu);
}

/*Scene* NewGame::getNewScene() const {
	return nullptr;
}*/

void NewGame::actionOnMouseMove(const sf::RenderWindow* window, const float delta) {
}

/*bool NewGame::getWillChangeScene() const {
	return false;
}*/

/*void NewGame::setNewScene(Scene *newScene) {
}*/
