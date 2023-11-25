#pragma once
#include<SFML\Graphics.hpp>
#include "Mineral.h"

class Player
{
public:
	sf::RectangleShape player_;
	sf::Vector2f p_position_;
	float xp_;
	int level_;
	float next_level_;
	Player();
	void update(const float dt);
	bool collision(const sf::RectangleShape& mineral);
};

class InventoryItem : public Player {
public:
	Mineral mineral_;
	int stack_num_;
};
