
#include "Plank.h"

Plank::Plank(sf::Texture plankTexture, std::vector<sf::FloatRect>& allDrawableBoundaries, const sf::Vector2f position, float velocity) : plankSprite(plankTexture), allDrawableBoundaries(allDrawableBoundaries), velocityX(velocity) {
	plankSprite.setPosition(position);
}

void Plank::update(const float delta) {
	if (!hidden) {
		plankSprite.setPosition(plankSprite.getPosition().x  + (velocityX * delta), plankSprite.getPosition().y);
	}
}

void Plank::show() {
	hidden = false;
}

void  Plank::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(plankSprite);
}

sf::FloatRect Plank::getGlobalBounds() const {
	return plankSprite.getGlobalBounds();
}