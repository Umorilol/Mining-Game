#pragma once
#include"Tile.h"

// Make this a subclass of Tile

class MineralTile : public Tile {
public:
	Mineral mineral_;
	bool mined_{ false };
	int timer_;

	MineralTile( const sf::Vector2f, Mineral mineral, sf::Texture& );
};
