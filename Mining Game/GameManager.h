#pragma once
#include<SFML\Graphics.hpp>
#include<SFML\System.hpp>
#include"Mineral.h"
#include"Player.h"
#include"MineralTile.h"

class GameManager{
public:
	sf::RenderWindow* window_;
	sf::Clock clock_;
	sf::Clock update_clock_;
	float delta_time_{0};
	int counter_{0};
	sf::Time m_time_ = sf::seconds(0.f);
	sf::Time m_timer_ = sf::seconds(5.f);

	Player guy_;
	sf::Vector2f mineral_position_;
	std::vector<std::unique_ptr<MineralTile>> mineral_vector_;

	GameManager();
	void setup(sf::RenderWindow* window);
	void GameLoop();
	void update();
	void draw(sf::RenderWindow*) const;
};