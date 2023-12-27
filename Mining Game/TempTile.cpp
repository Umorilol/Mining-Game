#include"TempTile.h"

TempTile::TempTile(sf::Vector2f pos, sf::Color color) : Tile(pos) {
	this->position_ = pos;
	this->tile_.setPosition(position_);
	this->tile_.setFillColor(color);
}
