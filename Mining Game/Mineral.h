#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Item.h"

// Parent class for mineral has size (should make a few textures and also practice sprites), a rectangle shape, double xp value, level_ requirement;

struct MineralType {
	sf::Color color;
	double xp;
	int timer_multiplier;
};


class Mineral : public Item {
public:
	MineralType type_;

	Mineral() = default;
	Mineral(const MineralType&);
	virtual ~Mineral() = default;
};

