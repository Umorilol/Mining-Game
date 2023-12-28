#include "Mineral.h"

Mineral::Mineral()  {
	this->xp_ = 0.0;
}

Coal::Coal() {
	this->timer_multiplier_ = 5;
	this->color_ = sf::Color(32, 32, 32, 155);
	this->xp_ = 20.0;
}

Iron::Iron() {
	this->timer_multiplier_ = 10;
	this->color_ = sf::Color(160, 160, 160, 155);
	this->xp_ = 40.0;
}




