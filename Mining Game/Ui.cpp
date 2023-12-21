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
	skills_sprite_.setPosition(600 - skills_sprite_.getGlobalBounds().width, 400 - skills_sprite_.getGlobalBounds().height);
}

void Ui::Update(sf::Event event) {
	if ( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::K )
		skills_shown_ = !skills_shown_;
}
