#include"Tile.h"

Tile::Tile(sf::Vector2f pos) {
	this->position_ = pos;
	this->tile_.setPosition(position_);
	this->tile_.setSize(size_);
}
