#pragma once
#include <SFML/Graphics.hpp>
#include "Mineral.h"

class Tile {
public:
	sf::RectangleShape tile_;
	sf::Texture texture_;
	sf::Sprite sprite_;
	sf::Vector2f position_;
	const sf::Vector2f size_{ 30.f,30.f };

	Tile( sf::Vector2f );

	virtual ~Tile() = default;
};

class TempTile : public Tile {
public:
	TempTile() = default;
	TempTile( sf::Vector2f, sf::Color );
	TempTile( sf::Vector2f, sf::Texture& );
};