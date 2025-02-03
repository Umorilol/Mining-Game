#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Item.h"

// Parent class for mineral

struct MineralType {
	// id used for map generation
	int id;	
	double xp_;
	int timer_multiplier_;
};

class Mineral : public Item{
public:
	MineralType type_;

	Mineral() = default;
	Mineral( const MineralType& );
	virtual ~Mineral() = default;
};
