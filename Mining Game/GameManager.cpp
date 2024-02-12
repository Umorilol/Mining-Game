#include "GameManager.h"
#include "MineralTile.h"
#include "TempTile.h"

GameManager::GameManager()
    : window_(sf::VideoMode(1200.f, 800.f), "Mining Game", sf::Style::Close),
	hud_(),
	guy_()
{
  if (!coal_texture_.loadFromFile("res/coal_sprite.png")) {
    std::cout << "coal sprite not loaded! " << "\n";
  }
  if (!iron_texture_.loadFromFile("res/iron_sprite.png")) {
    std::cout << "coal sprite not loaded! "
              << "\n";
  }
  if (!mined_texture.loadFromFile("res/mined_sprite.png"))
  {
    std::cout << "coal sprite not loaded! " << "\n";
  }
  else
  {
    std::cout << "sprites successfull " << "\n";
  }
  guy_.pl_sprite_.setPosition(50.f, 50.f);
  fill_map();
}

void GameManager::fill_map() {	// Temp char read from file fed into switch that puts correct tile into array; On a mineral_tile - add to vector here?
	sf::Vector2f tile_position(0.f, 0.f);
	int i = 0, j = 0;
	char temp = ' ';
	map_file_.open("res/mapV1.txt", std::ios::in);
	if (!map_file_) {
		std::cout << "file not opened!" << std::endl;
	}
	while (!map_file_.eof()) {
		map_file_ >> temp;
		switch(temp) {
		case '1': // Path 
			map_vector_.emplace_back(std::make_unique<TempTile>(tile_position, sf::Color(185, 185, 0, 155)));
			break;

		case '5': // grass
			map_vector_.emplace_back(std::make_unique<TempTile>(tile_position, sf::Color::Green));
			break;

		case '3': // Coal
			mineral_tile_vector_.emplace_back(std::make_unique<MineralTile>(tile_position, coal_, coal_texture_));
			break;

		case '4': // Iron
			mineral_tile_vector_.emplace_back(std::make_unique<MineralTile>(tile_position, iron_, iron_texture_));
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
	while ( window_.isOpen() ) {
		KeyManager();
		delta_time_ = clock_.restart().asSeconds();
		update();
		draw();
	}
}

void GameManager::update() {
	guy_.update(delta_time_);
	view_.setCenter(sf::Vector2f(guy_.pl_position_.x + (guy_.pl_sprite_.getGlobalBounds().width / 2), guy_.pl_position_.y + (guy_.pl_sprite_.getGlobalBounds().height / 2)));
	hud_.Update(view_);
	for(auto& i : mineral_tile_vector_) {
		if(guy_.collision(i->tile_) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !i->mined_) {
			m_time_ = update_clock_.restart();
			i->sprite_.setTexture(mined_texture);
			guy_.xp_ += i->mineral_.type_.xp_;
			std::cout << guy_.xp_ << " / " << guy_.next_level_ << "\n"	;
			i->mined_ = true;
		}
		if (i->mined_) {
			i->timer_++;
			if (i->timer_ >= i->mineral_.type_.timer_multiplier_ / delta_time_ * 5) {
				if(i->mineral_.type_.id == 1)
				{
                          i->sprite_.setTexture(coal_texture_);
				}
				if (i->mineral_.type_.id == 2) {
					i->sprite_.setTexture(iron_texture_);
				}
				i->mined_ = false;
				i->timer_ = 0;
			}
		}
	}
}

void GameManager::draw() {
	window_.clear();
	window_.setView(view_);
	//Map
	for (auto& i : map_vector_) {
                window_.draw(i->tile_);
	}
	//Minerals
	for (auto& i : mineral_tile_vector_) {
		window_.draw(i->tile_);
		window_.draw(i->sprite_);
	}
	//Player
	window_.draw(guy_.pl_sprite_);

	//UI
	if(hud_.skills_shown_ == true) {
		window_.draw(hud_.skills_sprite_);
	}

	window_.display();
}

void GameManager::KeyManager() {
	for ( auto event = sf::Event{}; window_.pollEvent( event );) {
		if ( event.type == sf::Event::Closed )
			window_.close();

		if ( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape )
			window_.close();

		if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::K) {
			hud_.skills_shown_ = !hud_.skills_shown_;
		}
	}
}
