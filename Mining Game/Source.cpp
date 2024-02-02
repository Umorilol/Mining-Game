#include "GameManager.h"
// Mining Game

int main(int argc, char* argv[])
{
	sf::RenderWindow window(sf::VideoMode(1200.f, 800.f), "Mining Game", sf::Style::Close);
	GameManager manager;
	manager.setup(&window);

	return 0;
}

