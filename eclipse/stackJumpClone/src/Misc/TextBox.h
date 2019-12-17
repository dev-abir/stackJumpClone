/*
 * TextBox.h
 *
 *  Created on: 27-Sep-2019
 *      Author: pluto
 */

#ifndef MISC_TEXTBOX_H_
#define MISC_TEXTBOX_H_

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class TextBox final : public sf::Drawable {
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::RectangleShape* sfmlBox;
	sf::Text* sfmlText;
	bool colorChanged = false;

	sf::Color defaultFillColor;
	sf::Color defaultOutlineColor;
	sf::Color alternateFillColor;
	sf::Color alternateOutlineColor;


public:
	TextBox(std::string boxText, sf::Font* sfmlFont, const sf::Color defaultFillColor, const sf::Color defaultOutlineColor, sf::Vector2f* position, sf::Vector2f* boxSize);
	virtual ~TextBox();

	void setPosition(const sf::Vector2f* newPosition);
	const sf::Vector2f getPosition();
	const sf::FloatRect getGlobalBounds();
	void setAlternateColor(const sf::Color color, const sf::Color outlineColor);
	bool isColorChanged();
	void toggleColor();
};

#endif /* MISC_TEXTBOX_H_ */
