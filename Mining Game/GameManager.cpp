#include "GameManager.h"

GameManager::GameManager() = default;

void GameManager::setup(sf::RenderWindow* window) {
	fill_map();
	for (auto& i : map_array_) {
		for (char j : i) {
			std::cout << j;
		}
		std::cout << std::endl;
	}

	Coal coal;
	Iron iron;
	this->window_ = window;
	srand(time(nullptr));
	guy_.player_.setPosition(50.f, 50.f);
	std::vector<Mineral> mineral_vector;
	mineral_vector.emplace_back(coal);
	mineral_vector.emplace_back(iron);

	for (int i = 0; i < 12; i++) {
		mineral_vector_.emplace_back(std::make_unique<MineralTile>(mineral_position_, mineral_vector[i % 2]));
		mineral_position_.x += rand() % 80;
		mineral_position_.y += rand() % 60;
	}
	GameLoop();
}

void GameManager::fill_map() {	// Temp char read from file fed into switch that puts correct tile into array
	int i = 0, j = 0;
	char temp_ = ' ';
	map_file_.open("mapV1.txt", std::ios::in);
	if (!map_file_) {
		std::cout << "file not opened!" << std::endl;
	}
	while (!map_file_.eof()) {
		map_file_ >> temp_;
		switch(temp_) {
		case '1':
			
			break;
		}
		/*i++;
		if (i >= 33) {
			j++;
			i = 0;
		}*/
	}
	map_file_.close();
}

void GameManager::GameLoop() {
	while (window_->isOpen()) {
		for (auto event = sf::Event{}; window_->pollEvent(event);) {
			if (event.type == sf::Event::Closed)
				window_->close();

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				window_->close();
		}
		delta_time_ = clock_.restart().asSeconds();
		update();
		draw(window_);
	}
}

void GameManager::update() {
	guy_.update(delta_time_);

	for (auto& i : mineral_vector_) {
		if (guy_.collision(i->mineral_tile_) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !i->mined_) {
			m_time_ = update_clock_.restart();
			i->mineral_tile_.setFillColor(sf::Color::Red);
			guy_.xp_ += i->mineral_.xp_;
			std::cout << guy_.xp_ << " / " << guy_.next_level_ << "\n";
			i->mined_ = true;
		}
		if (i->mined_) {
			i->timer_++;
			if (i->timer_ >= i->mineral_.timer_multiplier_ / delta_time_ * 5) {
				i->mineral_tile_.setFillColor(i->mineral_.color_);
				i->mined_ = false;
				i->timer_ = 0;
			}
		}
	}
}

void GameManager::draw(sf::RenderWindow* window) const {
	window->clear();
	//Minerals
	for (auto& i : mineral_vector_) {
		window->draw(i->mineral_tile_);
	}
	//Player
	window->draw(guy_.player_);

	window->display();
}
