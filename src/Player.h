
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

public:
	Player(sf::Texture& playerTexture, const std::vector<sf::IntRect>& animationTextureRects);
	void update(const float delta);
	void jump();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
#endif /* PLAYER_H_ */
