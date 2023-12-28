#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

// Parent class for mineral has size (should make a few textures and also practice sprites), a rectangle shape, double xp value, level_ requirement;

class Mineral {
public:
	sf::Color color_;
	double xp_;
	int timer_multiplier_;
	Mineral();
	virtual ~Mineral() = default;
};

class Coal : public Mineral {
public:
	Coal();
};

class Iron : public Mineral
{
public:
	Iron();
};

enum
{
	
};