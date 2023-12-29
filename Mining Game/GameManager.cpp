#include "GameManager.h"

#include "MineralTile.h"
#include "TempTile.h"

GameManager::GameManager() = default;

void GameManager::setup(sf::RenderWindow* window) {
	fill_map();
	this->window_ = window;
	guy_ = new Player();
	hud_ = new Ui();
	srand(time(nullptr));
	guy_->pl_sprite_.setPosition(50.f, 50.f);

	GameLoop();
}

void GameManager::fill_map() {	// Temp char read from file fed into switch that puts correct tile into array; On a mineral_tile - add to vector here?
	sf::Vector2f tile_position(0.f, 0.f);
	int i = 0, j = 0;
	char temp = ' ';
	map_file_.open("mapV1.txt", std::ios::in);
	if (!map_file_) {
		std::cout << "file not opened!" << std::endl;
	}
	while (!map_file_.eof()) {
		map_file_ >> temp;
		switch(temp) {
		case '1': // Path 
			map_vector_.emplace_back(std::make_unique<TempTile>(tile_position, sf::Color(185, 185, 0, 155)));
			break;
		case '5':
			map_vector_.emplace_back(std::make_unique<TempTile>(tile_position, sf::Color::Green));
			break;

		case '3': // Coal
			mineral_tile_vector_.emplace_back(std::make_unique<MineralTile>(tile_position, coal_ ));
			break;

		case '4': // Iron
			mineral_tile_vector_.emplace_back(std::make_unique<MineralTile>(tile_position, iron_));
			break;

		case '-':
			tile_position.y += 30;
			tile_position.x = -30;
			std::cout << tile_position.y << "\n";
			break;

		default:
			std::cout << "Character not recognized " << "\n"; 
			break;
		}
		tile_position.x +=30;
	}
	map_file_.close();
}

void GameManager::GameLoop() {
	while ( window_->isOpen() ) {
		KeyManager();
		delta_time_ = clock_.restart().asSeconds();
		update();
		draw(window_);
	}
}

void GameManager::update() {
	guy_->update(delta_time_);
	view_.setCenter(sf::Vector2f(guy_->pl_position_.x + (guy_->pl_sprite_.getGlobalBounds().width / 2), guy_->pl_position_.y + (guy_->pl_sprite_.getGlobalBounds().height / 2)));
	hud_->Update(view_);
	for(auto& i : mineral_tile_vector_) {
		if(guy_->collision(i->tile_) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !i->mined_) {
			m_time_ = update_clock_.restart();
			i->tile_.setFillColor(sf::Color::Red);
			guy_->xp_ += i->mineral_.type_.xp;
			std::cout << guy_->xp_ << " / " << guy_->next_level_ << "\n"	;
			i->mined_ = true;
		}
		if (i->mined_) {
			i->timer_++;
			if (i->timer_ >= i->mineral_.type_.timer_multiplier / delta_time_ * 5) {
				i->tile_.setFillColor(i->mineral_.type_.color);
				i->mined_ = false;
				i->timer_ = 0;
			}
		}
	}
}

void GameManager::draw(sf::RenderWindow* window) const {
	window->clear();
	window->setView(view_);
	//Map
	for (auto& i : map_vector_) {
		window->draw(i->tile_);
	}
	//Minerals
	for (auto& i : mineral_tile_vector_) {
		window->draw(i->tile_);
	}
	//Player
	window->draw(guy_->pl_sprite_);

	//UI
	if(hud_->skills_shown_ == true) {
		window->draw(hud_->skills_sprite_);
	}

	window->display();
}

void GameManager::KeyManager() {
	for ( auto event = sf::Event{}; window_->pollEvent( event );) {
		if ( event.type == sf::Event::Closed )
			window_->close();

		if ( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape )
			window_->close();

		if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::K) {
			hud_->skills_shown_ = !hud_->skills_shown_;
		}
	}
}
