#pragma once
#include<SFML\Graphics.hpp>

class Ui
{
public:
	
	sf::Texture skills_tex_;
	sf::Sprite skills_sprite_;
	bool skills_shown_ {true};
	Ui();
	void Initialize();
	void Update(sf::View&);
	void Draw();
};