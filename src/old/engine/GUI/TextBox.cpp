/*
 * TextBox.cpp
 *
 *  Created on: 27-Sep-2019
 *      Author: pluto
 */

#include "TextBox.h"

TextBox::TextBox(std::string boxText, sf::Font* sfmlFont, const sf::Color defaultFillColor, const sf::Color defaultOutlineColor, sf::Vector2f* position, sf::Vector2f* boxSize) : defaultFillColor(defaultFillColor), defaultOutlineColor(defaultOutlineColor) {

	/*const int boxHeight = sfmlText->getLocalBounds().height + sfmlText->getCharacterSize();
	const int boxWidth = sfmlText->getLocalBounds().width;*/

	TextBox::sfmlBox = new sf::RectangleShape(*boxSize);
	sfmlBox->setPosition(*(const_cast<sf::Vector2f*>(position)));
	sfmlBox->setFillColor(defaultFillColor);
	sfmlBox->setOutlineColor(defaultOutlineColor);
	sfmlBox->setOutlineThickness(5);

	TextBox::sfmlText = new sf::Text(boxText, *sfmlFont);
	sfmlText->setPosition(*position);

	delete position;
	//delete boxSize;
}

TextBox::~TextBox() {
	delete sfmlBox;
	delete sfmlText;
}

void TextBox::setPosition(const sf::Vector2f* newPosition) {
	TextBox::sfmlBox->setPosition(*newPosition);
	delete newPosition;
}

const sf::Vector2f TextBox::getPosition() {
	return TextBox::sfmlBox->getPosition();
}

const sf::FloatRect TextBox::getGlobalBounds() {
	return TextBox::sfmlBox->getGlobalBounds();
}

void TextBox::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.draw(*sfmlBox, states);
	target.draw(*sfmlText, states);
	/*sf::Text t(boxText, sfmlFont);
	t.setCharacterSize(100);
	t.setFillColor(sf::Color::Blue);
	target.draw(t, states);
	std::cout << "Came here3\n";*/
}

void TextBox::setAlternateColor(const sf::Color color, const sf::Color outlineColor) {
	alternateFillColor = color;
	alternateOutlineColor = outlineColor;
}

bool TextBox::isColorChanged() {
	return colorChanged;
}

void TextBox::toggleColor() {
	if(colorChanged) {
		sfmlBox->setFillColor(defaultFillColor);
		sfmlBox->setOutlineColor(defaultOutlineColor);
		colorChanged = false;
	} else {
		sfmlBox->setFillColor(alternateFillColor);
		sfmlBox->setOutlineColor(alternateOutlineColor);
		colorChanged = true;
	}
}
