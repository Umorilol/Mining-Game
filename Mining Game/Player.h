#pragma once
#include<SFML\Graphics.hpp>
#include "Mineral.h"

class Player
{
public:
	sf::Texture pl_texture_;
	sf::Sprite pl_sprite_;

	sf::Vector2f pl_position_;
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
