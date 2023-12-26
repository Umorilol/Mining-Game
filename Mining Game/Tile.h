#pragma once
#include <SFML/Graphics.hpp>
#include "Mineral.h"

class Tile {
public:
	sf::RectangleShape tile_;
	sf::Vector2f position_;
	const sf::Vector2f size_ {30.f,30.f};

	Tile(sf::Vector2f);
};

