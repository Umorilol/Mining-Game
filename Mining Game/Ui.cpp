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
	skills_sprite_.setScale(.5f, .5f);
}

void Ui::Update(const sf::View& view) {
	skills_sprite_.setPosition(view.getCenter().x + 100.f, view.getCenter().y + 35.f);	// I can redo this to be more mathematical forgor
}
