
#ifndef PLAYER_H_
#define PLAYER_H_
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
 
class Player : public sf::Drawable {

private:
	float velocityY = 0.0;
	sf::Sprite playerSprite;
	float initialPositionY;
	const std::vector<sf::IntRect>& animationTextureRects;
	unsigned int animationIndex = 0;
	bool jumping = false;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override; // window.draw(...) will be able to access it(see : https://stackoverflow.com/questions/39240085/access-of-member-functions-in-c-inheritance). This method should not be available for any other class, because they will never use it, so why make it public?

public:
	Player(sf::Texture& playerTexture, const std::vector<sf::IntRect>& animationTextureRects);
	void update(const float delta);
	void jump();
};
#endif /* PLAYER_H_ */
