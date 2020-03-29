
#include "Player.h"

/**
 *
 * @Author : Abir Ganguly.
 *
 * License :
 *
 */
Player::Player(sf::Texture& playerTexture, const std::vector<sf::IntRect>& animationTextureRects) : playerSprite(playerTexture), animationTextureRects(animationTextureRects) {
	playerSprite.setTextureRect(animationTextureRects.at(0));
	playerSprite.setPosition((WINDOW_WIDTH / 2.0) - (playerSprite.getLocalBounds().width / 2.0), (WINDOW_HEIGHT - PlayerSprite.getLocalBounds().height)); // place at bottom-middle of window
	initialPositionY = playerSprite.getGlobalBounds().top;
}

void Player::update(const float delta) {
	///////UPDATING VELOCITY & POSITION///////
	velocityY += (ACCELERATION_DUE_TO_GRAVITY * delta);
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

void Player::jump() {
	if (!jumping) {
		velocityY = -10.0f;
		jumping = true;
	}
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(playerSprite);
}
