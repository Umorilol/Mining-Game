#pragma once
#include <SFML/Graphics.hpp>
#include "Mineral.h"


class MineralTile {
public:
	sf::RectangleShape mineral_tile_;
	sf::Vector2f position_;
	sf::Vector2f size_ {30.f,30.f};
	Mineral mineral_;
	bool mined_ {false};
	int timer_;

	MineralTile(sf::Vector2f, Mineral);
};
