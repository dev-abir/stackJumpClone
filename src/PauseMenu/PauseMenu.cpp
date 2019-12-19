/*
 * PauseMenu.cpp
 *
 *  Created on: 18-Dec-2019
 *      Author: pluto
 */

#include "PauseMenu.h"

PauseMenu::PauseMenu() : Scene(false) {
		if (!menuFont.loadFromFile(MAIN_MENU_FONT_FILE)) {
			std::cerr << "Cannot load " << SERIF_FONT_FILE << "\n";
			throw EXCEPTION_CANNOT_OPEN_FILE;
		} else if (!backgroundTexture.loadFromFile(MAIN_MENU_BACKGROUND_TEXTURE_FILE)) {
			std::cerr << "Cannot load " << MAIN_MENU_BACKGROUND_TEXTURE_FILE << "\n";
			throw EXCEPTION_CANNOT_OPEN_FILE;
		}

		background.setTexture(backgroundTexture);

		/*
		 *
		 * new TextBox("New Game", &menuFont, sf::Color::Blue);
		 *
		 * I could have constructed the above line to be like :
		 * new TextBox("New Game", menuFont, sf::Color::Blue);
		 *
		 *
		 * But sfml will delete menuFont, if you don't pass it as a pointer....(Why???)
		 *
		 */

		sf::Vector2f *menuBoxSize = new sf::Vector2f(150, 50);

		unsigned int nBoxes = 3;
		unsigned int verticalDistanceBetweenTwoBoxes = 100;

		unsigned int menuBoxDistanceFromLeftEdge = (600 - menuBoxSize->x) / 2;
		unsigned int firstMenuBoxDistanceFromTopEdge = (600
				- ((nBoxes - 1) * verticalDistanceBetweenTwoBoxes)
				- (nBoxes * menuBoxSize->y)) / 2;

	settings = new TextBox("Resume", &menuFont, sf::Color::Red, sf::Color::Blue,
					new sf::Vector2f(menuBoxDistanceFromLeftEdge,
							settings->getPosition().y
									+ verticalDistanceBetweenTwoBoxes), menuBoxSize);
			settings->setAlternateColor(sf::Color::Green, sf::Color::Magenta);

	resume = new TextBox("Resume", &menuFont, sf::Color::Red, sf::Color::Blue,
				new sf::Vector2f(menuBoxDistanceFromLeftEdge,
						resume->getPosition().y
								+ verticalDistanceBetweenTwoBoxes), menuBoxSize);
		resume->setAlternateColor(sf::Color::Green, sf::Color::Magenta);

}

PauseMenu::~PauseMenu() {
	delete resume;
	delete settings;
}

void PauseMenu::update(const float delta) {
}

void PauseMenu::draw(sf::RenderWindow &window) const {
	window.draw(*resume);
	window.draw(*settings);
}

void PauseMenu::actionOnKeyRelase(sf::Keyboard::Key key, const float delta) {
}

void PauseMenu::actionOnMouseClick(sf::Mouse::Button button,
		const sf::RenderWindow *window, const float delta) {
	if (button == sf::Mouse::Left) {
			if (isMouseIntercept(resume->getGlobalBounds(), window)) {
				std::cout << "Starting New Game\n";
				//TODO : This line                            Scene::setNewScene(new NewGame);
			}
		}
}

void PauseMenu::actionOnMouseMove(const sf::RenderWindow *window,
		const float delta) {
	if (isMouseIntercept(resume->getGlobalBounds(), window)) {
			if (!resume->isColorChanged()) resume->toggleColor();
		} else {
			if (resume->isColorChanged()) resume->toggleColor();
		}
}

void PauseMenu::actionOnKeyPress(sf::Keyboard::Key key, const float delta) {
}
