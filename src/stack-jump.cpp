//============================================================================
// Name        : stack-jump.cpp
// Author      : Abir Ganguly.
// Version     :
// Copyright   : Your copyright notice
// Description : Stack jump game application entry point.
//============================================================================
#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

#include "settings.h"

/**
 *
 * @Author : Abir Ganguly.
 *
 * License :
 *
 */


class Player : public sf::Drawable {

private:
	float velocityY = 0.0;
	sf::Sprite playerSprite;
	float initialPositionY;
	const std::vector<sf::IntRect>& animationTextureRects;
	unsigned int animationIndex = 0;
	bool jumping = false;

public:

	Player(sf::Texture& playerTexture, const std::vector<sf::IntRect>& animationTextureRects) : playerSprite(playerTexture), animationTextureRects(animationTextureRects) {
		playerSprite.setTextureRect(animationTextureRects.at(0));
		playerSprite.setPosition((WINDOW_WIDTH / 2.0) - (playerSprite.getLocalBounds().width / 2.0), (WINDOW_HEIGHT - playerSprite.getLocalBounds().height)); // place at bottom-middle of window
		initialPositionY = playerSprite.getGlobalBounds().top;
	}

	void update(const float delta) {
		///////UPDATING VELOCITY & POSITION///////
 		velocityY += ACCELERATION_DUE_TO_GRAVITY;
		std::cout << delta << "\n";
		playerSprite.setPosition(playerSprite.getPosition().x, playerSprite.getPosition().y + (velocityY * delta));


		///////COLLISION DETECTION///////
		if(playerSprite.getPosition().y >= (initialPositionY)) {
 			playerSprite.setPosition(playerSprite.getPosition().x, initialPositionY);
			velocityY = 0;
			jumping = false;
		}


		///////UPDATING ANIMATION///////
		if(animationIndex >= (animationTextureRects.size() - 1)) animationIndex = 0;
		playerSprite.setTextureRect(animationTextureRects.at(animationIndex));
		animationIndex++;
	}

	void jump() {
		if (!jumping) {
			velocityY = -10.0f;
			jumping = true;
		}
	}

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
		target.draw(playerSprite);
	}
};



int main() {


	///////RENDER WINDOW///////
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, sf::Style::Close);
	//window->setVerticalSyncEnabled(true); //Or else use : window->setFramerateLimit(60); (But don't use both at the same time)
	window.setFramerateLimit(INITIAL_FPS);


	///////BACKGROUND///////
	sf::Texture backgroundTexture;
	if(!backgroundTexture.loadFromFile(BACKGROUND_TEXTURE_FILE)) {
		std::cerr << "Failed to load texture " << BACKGROUND_TEXTURE_FILE << "\n";
		return EXIT_FAILURE;
	}
	sf::Sprite background(backgroundTexture);


	///////PLAYER///////
	sf::Texture playerTexture;
	if(!playerTexture.loadFromFile(PLAYER_TEXTURE_FILE)) {
		std::cerr << "Failed to load texture " << PLAYER_TEXTURE_FILE << "\n";
		return EXIT_FAILURE;
	}
	const std::vector<sf::IntRect> playerAnimationTextureRects{
				sf::IntRect(0, 0, PLAYER_TEXTURE_WIDTH, PLAYER_TEXTURE_HEIGHT),
				sf::IntRect(PLAYER_TEXTURE_WIDTH, 0, PLAYER_TEXTURE_WIDTH, PLAYER_TEXTURE_HEIGHT),
				sf::IntRect(0, PLAYER_TEXTURE_HEIGHT, PLAYER_TEXTURE_WIDTH, PLAYER_TEXTURE_HEIGHT),
				sf::IntRect(PLAYER_TEXTURE_WIDTH, PLAYER_TEXTURE_HEIGHT, PLAYER_TEXTURE_WIDTH, PLAYER_TEXTURE_HEIGHT),
	};
	Player player(playerTexture, playerAnimationTextureRects);


	///////FPS///////
	sf::Clock deltaClock;
	sf::Clock fpsClock;
	unsigned int frameCounter = 0, currentFPS;


	///////MAIN LOOP///////
	while (window.isOpen()) {

		// <CODE FOR FPS COUNTER STARTS>
		if (fpsClock.getElapsedTime().asMilliseconds() >= 1000.0) {
			std::cout << "Current FPS : " << frameCounter << "\n";
			currentFPS = frameCounter;
			frameCounter = 0;
			fpsClock.restart();
		}
		// <CODE FOR FPS COUNTER ENDS>

		float delta = ((1.0 / INITIAL_FPS) * 1000.0) / deltaClock.getElapsedTime().asMilliseconds();
		deltaClock.restart();


		///////EVENT HANDLING///////
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) window.close();
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) window.close();
				if (event.key.code == sf::Keyboard::Space) player.jump();
			}
			/*if (event.type == sf::Event::KeyReleased) playerTextureRect.left = 0;
			if (event.type == sf::Event::MouseButtonPressed) std::cout << event.mouseButton.button << " is pressed\n";
			if (event.type == sf::Event::MouseMoved) std::cout << "Mouse moved\n";*/
		}


		///////UPDATE///////
		player.update(delta);


		///////CLEARING SCREEN AND RENDERING///////
		window.clear();
		window.draw(background);
		window.draw(player);
		window.display();


		///////INCREASING FRAME COUNTER(FOR DISPLAYING FPS)///////
		frameCounter += 1;
	}
	return EXIT_SUCCESS;
}
