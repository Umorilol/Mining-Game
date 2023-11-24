#include "GameManager.h"

GameManager::GameManager()=default;

void GameManager::setup(sf::RenderWindow* window) {
	this->window_ = window;
	srand(time(nullptr));
	guy_.player_.setPosition(50.f, 50.f);
	Coal coal;
	Iron iron;
	std::vector<Mineral> mineral_vector;
	mineral_vector.emplace_back(coal);
	mineral_vector.emplace_back(iron);

	for(int i = 0; i < 12; i++) {
		mineral_vector_.emplace_back(std::make_unique<MineralTile>(mineral_position_, mineral_vector[i%2]));
		mineral_position_.x += rand() % 80;
		mineral_position_.y += rand() % 60;
	}
	GameLoop();
}

void GameManager::GameLoop() {
	while ( window_->isOpen() ) {
		for ( auto event = sf::Event{}; window_->pollEvent( event );) {
			if ( event.type == sf::Event::Closed )
				window_->close();

			if ( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape )
				window_->close();
		}
		delta_time_ = clock_.restart().asSeconds();
		update();
		draw(window_);
	}	
}

void GameManager::update() {
	guy_.update(delta_time_);

	for(auto& i : mineral_vector_) {
		if(guy_.collision(i->mineral_tile_) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !i->mined_) {
			m_time_ = update_clock_.restart();
			i->mineral_tile_.setFillColor(sf::Color::Red);
			guy_.xp_ += i->mineral_.xp_;
			std::cout << guy_.xp_ << "\n";
			i->mined_ = true;
			guy_.mineral_inventory_.emplace_back(i->mineral_);
		}
		if(i->mined_) {
			i->timer_ ++;
			if(i->timer_ >= 5 / delta_time_ * 5) {
				i->mineral_tile_.setFillColor(i->mineral_.color_);
				i->mined_ = false;
				i->timer_ = 0;
			}
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
			std::cout << "Inventory size: " << guy_.mineral_inventory_.size() << "\n";
		}
	}
}

void GameManager::draw(sf::RenderWindow* window) const {
	window->clear();
	//Minerals
	for(auto& i : mineral_vector_) {
		window->draw(i->mineral_tile_);
	}
	//Player
	window->draw(guy_.player_);

	window->display();
}
