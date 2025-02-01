#include"Player.h"
#include <iostream>

Player::Player() {
	pl_position_ = sf::Vector2f( 20.f, 20.f );
	this->level_ = 1;
	this->xp_ = 0.0;
	this->next_level_ = 100.f;
	this->pl_sprite_.setPosition( pl_position_ );
}

void Player::update( const float dt ) {
	float multiplier = 80.f;
	pl_position_ = pl_sprite_.getPosition();
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::A ) )
		pl_position_.x -= 2.f * dt * multiplier;
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::D ) )
		pl_position_.x += 2.f * dt * multiplier;
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::W ) )
		pl_position_.y -= 2.f * dt * multiplier;
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::S ) )
		pl_position_.y += 2.f * dt * multiplier;

	pl_sprite_.setPosition( pl_position_ );

	if ( this->xp_ >= this->next_level_ ) {
		level_++;
		this->next_level_ = next_level_ * 2;
		std::cout << "Level Up!" << "\n";
	}
}

bool Player::collision( const sf::RectangleShape& mineral ) {
	if ( pl_position_.x < mineral.getPosition().x + mineral.getSize().x &&
		pl_position_.x + pl_sprite_.getGlobalBounds().width > mineral.getPosition().x &&
		pl_position_.y < mineral.getPosition().y + mineral.getSize().y &&
		pl_position_.y + pl_sprite_.getGlobalBounds().height > mineral.getPosition().y )
	{
		return true;
	}
	return false;
}