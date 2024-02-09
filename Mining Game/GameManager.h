#pragma once
#include<SFML\Graphics.hpp>
#include<SFML\System.hpp>
#include<fstream>
#include<iostream>
#include"Mineral.h"
#include"Player.h"
#include"Tile.h"
#include "Ui.h"
#include "MineralTile.h"
#include "TempTile.h"

class GameManager{
public:
	sf::RenderWindow window_;
	sf::Clock clock_;
	sf::Clock update_clock_;
	float delta_time_{0};
	int counter_{0};
	sf::Time m_time_ = sf::seconds(0.f);
	sf::Time m_timer_ = sf::seconds(5.f);
	sf::Texture coal_texture_;
	sf::Texture iron_texture_;
	sf::Texture mined_texture;

	MineralType coal_type{1,50.0, 2};
	MineralType iron_type{2, 75.0, 3};
	Mineral coal_{coal_type};
	Mineral iron_{iron_type};

	// Map
	std::ifstream map_file_;
	std::vector<std::unique_ptr<Tile>> map_vector_;
	Ui hud_;
	Player guy_;
	sf::View view_{sf::FloatRect(200.f, 200.f, 300.f, 200.f)};
	sf::Vector2f mineral_position_;
	std::vector<std::unique_ptr<MineralTile>> mineral_tile_vector_;
	GameManager();
	void fill_map();
	void GameLoop();
	void update();
	void draw();
	void KeyManager();
};
