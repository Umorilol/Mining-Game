#pragma once
#include<SFML\Graphics.hpp>
#include<SFML\System.hpp>
#include<fstream>
#include<iostream>
#include"Mineral.h"
#include"Player.h"
#include "TempTile.h"
#include"Tile.h"
#include"MineralTile.h"
#include "Ui.h"

class GameManager{
public:
	sf::RenderWindow* window_;
	sf::Clock clock_;
	sf::Clock update_clock_;
	float delta_time_{0};
	int counter_{0};
	sf::Time m_time_ = sf::seconds(0.f);
	sf::Time m_timer_ = sf::seconds(5.f);

	// Map
	std::ifstream map_file_;
	std::vector<std::unique_ptr<Tile>> map_vector_;

	Ui* hud_;
	Player* guy_;
	sf::View view_{sf::FloatRect(200.f, 200.f, 300.f, 200.f)};
	sf::Vector2f mineral_position_;
	std::vector<std::unique_ptr<MineralTile>> mineral_vector_;
	GameManager();
	void setup(sf::RenderWindow* window);
	void fill_map();
	void GameLoop();
	void update();
	void draw(sf::RenderWindow*) const;
	void KeyManager();
};
