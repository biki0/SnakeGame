#pragma once

#include <iostream>
#include <ctime>
#include <vector>

#include <SFML/Graphics.hpp>


class Enemy {


public:

	Enemy();

	sf::Clock clock;

	int pAmount;

	std::vector<sf::CircleShape> poison;
	sf::Texture t;


	void spawnPoison();

	void removePoison();

	void render(sf::RenderWindow* window);


};

