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

public:

/*
 *
 *
 *
 *
 *
 *
 *
	//TODO : override    virtual void draw(RenderTarget& target, RenderStates states) const = 0;









*/
	Player(sf::Texture& playerTexture, const std::vector<sf::IntRect>& animationTextureRects) : playerSprite(playerTexture), animationTextureRects(animationTextureRects) {
		playerSprite.setTextureRect(animationTextureRects.at(0));
		initialPositionY = playerSprite.getGlobalBounds().top;
		playerSprite.setPosition((WINDOW_WIDTH / 2.0) - (playerSprite.getLocalBounds().width / 2.0), (WINDOW_HEIGHT - playerSprite.getLocalBounds().height)); // place at bottom-middle of window
	}

	void update() {
		if(playerSprite.getGlobalBounds().top <= initialPositionY) velocityY += ACCELERATION_DUE_TO_GRAVITY;
		else playerSprite.setPosition(playerSprite.getPosition().x, initialPositionY);

		playerSprite.setPosition(playerSprite.getPosition().x, playerSprite.getPosition().y + velocityY);

		std::cout << playerSprite.getPosition().y << std::endl;

		if(animationIndex >= (animationTextureRects.size() - 1)) animationIndex = 0;

		playerSprite.setTextureRect(animationTextureRects.at(animationIndex));

		animationIndex++;
	}

	void jump() { velocityY += 5.0f; }

	sf::Sprite* const getSprite() { return &playerSprite; }

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
	sf::Sprite playerSprite = *player.getSprite();

	std::cout << player.getSprite() << " " << &playerSprite << std::endl;

	///////FPS///////
	sf::Clock clock;
	unsigned int frameCounter = 0, currentFPS;

	///////MAIN LOOP///////
	while (window.isOpen()) {

		//CODE FOR FPS COUNTER STARTS
		if (clock.getElapsedTime().asMilliseconds() >= 1000.0) {
			std::cout << "Current FPS : " << frameCounter << "\n";
			currentFPS = frameCounter;
			frameCounter = 0;
			clock.restart();
		}
		//CODE FOR FPS COUNTER ENDS

		const float delta = INITIAL_FPS / currentFPS;

		///////EVENT HANDLING///////
		sf::Event event;
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) window.close();

			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) window.close();
				if (event.key.code == sf::Keyboard::Space) player.jump();
			}

			/*if (event.type == sf::Event::KeyReleased) playerTextureRect.left = 0;*/

			/*if (event.type == sf::Event::MouseButtonPressed) std::cout << event.mouseButton.button << " is pressed\n";

			if (event.type == sf::Event::MouseMoved) std::cout << "Mouse moved\n";*/
		}

		///////UPDATE///////
		player.update();

		std::cout << playerSprite.getPosition().x << " " << playerSprite.getPosition().y << std::endl;

		///////CLEARING SCREEN AND RENDERING///////
		window.clear();
		window.draw(background);
		window.draw(playerSprite);

		window.display();
		frameCounter += 1;
	}
	return EXIT_SUCCESS;
}
