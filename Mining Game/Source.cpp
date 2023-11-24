#include "GameManager.h"
// Mining Game

int main(int argc, char* argv[])
{
	sf::RenderWindow window(sf::VideoMode(600.f, 400.f), "Mining Game", sf::Style::Close);
	GameManager manager;
	manager.setup(&window);

	return 0;
}

