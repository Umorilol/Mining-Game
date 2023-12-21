#include"Ui.h"

#include <iostream>

Ui::Ui() {
	Initialize();
}

void Ui::Initialize() {
	if(!skills_tex_.loadFromFile("res/Inventory.png")) {
		std::cout << "Inventory Texture not loaded" << "\n";
	}
	else {
		skills_sprite_.setTexture(skills_tex_);
		std::cout << "Inventory texture loaded: " << "\n";
		
	}
	skills_sprite_.setPosition(0,0);
}

void Ui::Update(sf::View& view) {
	//if ( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::K )
		//skills_shown_ = !skills_shown_;

	skills_sprite_.setPosition(view.getCenter().x + 100.f, view.getCenter().y + 20.f);
	//skills_sprite_.setPosition(view.getCenter());
}
