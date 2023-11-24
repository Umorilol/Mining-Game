#include"MineralTile.h"

MineralTile::MineralTile(const sf::Vector2f position, Mineral mineral) {
	this->mineral_ = mineral;
	this->timer_ = 0;
	this->position_ = position;
	this->mineral_tile_.setSize(size_);
	this->mineral_tile_.setPosition(position_);
	this->mineral_tile_.setFillColor(mineral_.color_);
}

