#include"Ui.h"
#include <iostream>

Ui::Ui() {
	Initialize();
}

void Ui::Initialize() {
	skills_sprite_.setPosition( 0, 0 );
	skills_sprite_.setScale( .5f, .5f );
}

void Ui::Update( const sf::View& view ) {
	skills_sprite_.setPosition( view.getCenter().x + 100.f, view.getCenter().y + 35.f );	// I can redo this to be more mathematical forgor
}
