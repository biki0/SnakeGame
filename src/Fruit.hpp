#pragma once

#include <iostream>
#include <ctime>

#include <SFML/Graphics.hpp>

class Fruit {

public:

	sf::RectangleShape food;

	Fruit();
		
	void drawFood();

	void render(sf::RenderWindow* window);
};

