#pragma once
#include"Tile.h"

class TempTile : public Tile {
public:
	TempTile() = default;
	TempTile( sf::Vector2f, sf::Color );
	TempTile( sf::Vector2f, sf::Texture& );
};