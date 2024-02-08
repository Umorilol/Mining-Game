#include"TempTile.h"

TempTile::TempTile(sf::Vector2f pos, sf::Color color) : Tile(pos) {
	this->position_ = pos;
	this->tile_.setPosition(position_);
	this->tile_.setFillColor(color);
}

TempTile::TempTile(sf::Vector2f pos, sf::Texture &texture) : Tile(pos) {
        this->position_ = pos;
        this->tile_.setPosition(position_);
        this->sprite_.setTexture(texture);
}
