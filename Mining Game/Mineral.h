#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

// Parent class for mineral has size (should make a few textures and also practice sprites), a rectangle shape, double xp value, level_ requirement;
	
struct MineralType {
	sf::Color color_;
	double xp_;
	int timer_multiplier_;
};


class Mineral {
public:
	MineralType type_;


	Mineral() = default;
	Mineral(const MineralType&);
	virtual ~Mineral() = default;
};

