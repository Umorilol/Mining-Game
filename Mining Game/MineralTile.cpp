#include"MineralTile.h"

MineralTile::MineralTile(const sf::Vector2f position, Mineral mineral) : Tile(position)  {
	this->mineral_ = mineral;
	this->timer_ = 0;
	this->position_ = position;
	this->tile_.setFillColor(mineral_.color_);
}

