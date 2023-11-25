#include "Mineral.h"

Mineral::Mineral() {
	this->xp_ = 0.0;
}

Coal::Coal() {
	this->timer_multiplier_ = 5;
	this->color_ = sf::Color::Cyan;
	this->xp_ = 20.0;
}

Iron::Iron() {
	this->timer_multiplier_ = 10;
	this->color_ = sf::Color::Green;
	this->xp_ = 40.0;
}


