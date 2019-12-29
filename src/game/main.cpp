#include <iostream>
#include <SFML/Graphics.hpp>

#include "MainMenu/MainMenu.h"
#include "Misc/Common.h"
#include "Scene.h"

/**
 *
 * @Author : Abir Ganguly.
 *
 * License :
 *
 */


/*
 * This Game is programmed using SI units(metric system)
 *
 */

unsigned int expectedFPS = 60;
unsigned int currentFPS = expectedFPS;

void cleanup() {

}

int main() {
	sf::RenderWindow *window = new sf::RenderWindow(
		sf::VideoMode(WIDTH, HEIGHT), "Stack jump clone", sf::Style::Close);

	//window->setVerticalSyncEnabled(true); //Or else use : window->setFramerateLimit(60); (But don't use both at the same time)
	window->setFramerateLimit(expectedFPS);

	MainMenu *mainMenu;

	try {
		mainMenu = new MainMenu;
	} catch (int exception) {
		return exception;
	}

	Scene *currentScene = mainMenu;

	sf::Clock clock;

	unsigned int frameCounter = 0;

	while (window->isOpen()) {

		if (clock.getElapsedTime().asMilliseconds() >= 1000.0) {
			std::cout << "Current FPS : " << frameCounter << "\n";
			currentFPS = frameCounter;
			frameCounter = 0;
			clock.restart();
		}

		float delta = expectedFPS / currentFPS;

		sf::Event event;
		while (window->pollEvent(event)) {
			//////////////////////////////////////////////////////////////////////////////////////////////////
			if (event.type == sf::Event::Closed) {
				window->close();
				cleanup();
			}

			//////////////////////////////////////////////////////////////////////////////////////////////////
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) {
					window->close();
					cleanup();
				} else {
					//256
					currentScene->actionOnKeyPress(event.key.code, delta);
				}
			}
			if (event.type == sf::Event::KeyReleased) {
				currentScene->actionOnKeyRelase(event.key.code, delta);
			}

			//////////////////////////////////////////////////////////////////////////////////////////////////
			if (event.type == sf::Event::MouseButtonPressed) {
				currentScene->actionOnMouseClick(event.mouseButton.button, window, delta);
			}

			if (event.type == sf::Event::MouseMoved) {
				currentScene->actionOnMouseMove(window, delta);
			}
		}
		window->clear();
		currentScene->update(delta);
		currentScene->draw(*window);
		window->display();
		frameCounter += 1;

		if(currentScene->getWillChangeScene()) {
			currentScene = currentScene->getNewScene();
		}
	}
	delete mainMenu;
	delete window;
	return 0;
}
