/*
 * MainMenu.cpp
 *
 *  Created on: 25-Sep-2019
 *      Author: pluto
 */

#include "MainMenu.h"

/*
 *
 * TODO : If the player changes FPS in settings, then you must change the FPS in PhysicsObject class
 *
 */

MainMenu::MainMenu() :
		Scene(false) {
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

	newGame = new TextBox("New Game", &menuFont, sf::Color::Red,
			sf::Color::Blue,
			new sf::Vector2f(menuBoxDistanceFromLeftEdge,
					firstMenuBoxDistanceFromTopEdge), menuBoxSize);
	newGame->setAlternateColor(sf::Color::Green, sf::Color::Magenta);
	settings = new TextBox("Settings", &menuFont, sf::Color::Red,
			sf::Color::Blue,
			new sf::Vector2f(menuBoxDistanceFromLeftEdge,
					newGame->getPosition().y + verticalDistanceBetweenTwoBoxes),
			menuBoxSize);
	settings->setAlternateColor(sf::Color::Green, sf::Color::Magenta);


	delete menuBoxSize;
}

MainMenu::~MainMenu() {
	delete newGame;
	delete settings;
	//delete MainMenu::newScene; //(It will be deleted in Scene.cpp's destructor)
}

void MainMenu::update(const float delta) {
}

void MainMenu::draw(sf::RenderWindow &window) const {
	window.draw(background);
	window.draw(*newGame);
	window.draw(*settings);
	//newGame->setPosition(sf::Vector2f((newGame->getPosition().x + 1), (newGame->getPosition().y + 1)));
}

void MainMenu::actionOnKeyRelase(sf::Keyboard::Key key, const float delta) {

}

void MainMenu::actionOnMouseClick(sf::Mouse::Button button, const sf::RenderWindow* window, const float delta) {
	if (button == sf::Mouse::Left) {
		if (isMouseIntercept(newGame->getGlobalBounds(), window)) {
			std::cout << "Starting New Game\n";
			Scene::setNewScene(new NewGame);
		}
	}
}

void MainMenu::actionOnMouseMove(const sf::RenderWindow* window, const float delta) {
	if (isMouseIntercept(newGame->getGlobalBounds(), window)) {
		if (!newGame->isColorChanged()) newGame->toggleColor();
	} else {
		if (newGame->isColorChanged()) newGame->toggleColor();
	}
}


void MainMenu::actionOnKeyPress(sf::Keyboard::Key key, const float delta) {
	std::cout << key << " is pressed\n";
}
