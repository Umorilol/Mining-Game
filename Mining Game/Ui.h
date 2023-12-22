#pragma once
#include<SFML\Graphics.hpp>

class Ui
{
public:
	
	sf::Texture skills_tex_;
	sf::Sprite skills_sprite_;
	bool skills_shown_ {false};
	Ui();
	void Initialize();
	void Update(const sf::View&);
};