#include"Ui.h"
#include <iostream>

Ui::Ui() {
	Initialize();
}

void Ui::Initialize() {
	if (!text_font_.loadFromFile("res/arial.ttf")) {
		std::cout<<"Font Not Loaded!" << "\n";
	}
	// Text is blurry these are values that I am testing around with an temporary to have a representation of xp in the game
	xp_text_.setFont(text_font_);
	xp_text_.setFillColor(sf::Color::Black);
	xp_text_.setCharacterSize(24);
	xp_text_.setOutlineColor(sf::Color::Black);
	xp_text_.setOutlineThickness(.3f);
	xp_text_.setScale(.2f, .2f);
	skills_sprite_.setPosition( 0, 0 );
	skills_sprite_.setScale( .6f, .6f );
}

void Ui::Update( const sf::View& view, sf::Vector2f xp_vals ) {
	skills_sprite_.setPosition( view.getCenter().x + 90.f, view.getCenter().y + 25.f );	// I can redo this to be more mathematical forgor
	xp_text_.setString(std::to_string(static_cast<int>(xp_vals.x)) + " / " + std::to_string(static_cast<int>(xp_vals.y)));
	xp_text_.setPosition( skills_sprite_.getPosition().x + 3.f, skills_sprite_.getPosition().y + 6.f);
}
