#include"Player.h"

Player::Player() {
		p_position_ = sf::Vector2f(20.f, 20.f);
		this->level_ = 1;
		this->xp_ = 0.0;
		this->next_level_ = 100.f;
		this->player_.setFillColor(sf::Color::Blue);
		this->player_.setSize(sf::Vector2f(20.f, 20.f));
		this->player_.setPosition(p_position_);
}

void Player::update(const float dt) {
		const int multiplier = 80;
		p_position_ = player_.getPosition();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A ) )
			p_position_.x -= 2 * dt * multiplier;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D ) )
			p_position_.x += 2 * dt * multiplier;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W ) )
			p_position_.y -= 2 * dt * multiplier;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S ) )
			p_position_.y += 2 * dt * multiplier;

		player_.setPosition(p_position_);

		if(this->xp_ >= this->next_level_) {
			level_++;
			this->next_level_ = next_level_ * 2;
			std::cout << "Level Up!" << "\n";
		}
}


bool Player::collision(const sf::RectangleShape& mineral) {
		if(p_position_.x < mineral.getPosition().x + mineral.getSize().x &&
			p_position_.x + player_.getSize().x > mineral.getPosition().x &&
			p_position_.y < mineral.getPosition().y + mineral.getSize().y &&
			p_position_.y + player_.getSize().y > mineral.getPosition().y) 
		{
			return true;
		}
		return false;
}