#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

// Parent class for mineral

struct MineralType {
	// id used for map generation
	int id;	
	double xp_;
	int timer_multiplier_;
};

class Mineral {
public:
	MineralType type_;

	Mineral() = default;
	Mineral( const MineralType& );
	virtual ~Mineral() = default;
};
