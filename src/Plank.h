
#ifndef PLANK_H_
#define PLANK_H_
#include <iostream>

#include <SFML/Graphics.hpp>

#include "settings.h"

/**
 *
 * @Author : Abir Ganguly.
 *
 * License :
 *
 */
 
class Plank : public sf::Drawable {

private:
	sf::Sprite plankSprite;
	float velocityX = 0.0f;
	float initialPositionY;
	bool hidden = true;
	std::vector<sf::FloatRect>& allDrawableBoundaries;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override; // window.draw(...) will be able to access it(see : https://stackoverflow.com/questions/39240085/access-of-member-functions-in-c-inheritance). This method should not be available for any other class, because they will never use it, so why make it public?

public:
	Plank(sf::Texture plankTexture, std::vector<sf::FloatRect>& allDrawableBoundaries, const sf::Vector2f position, float velocity);
	void show();
	void update(const float delta);
	sf::FloatRect getGlobalBounds() const;
};
#endif /* PLANK_H_ */
