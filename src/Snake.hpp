#pragma once
#include <iostream>
#include <vector>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Fruit.hpp"
#include "Enemy.hpp"

class Snake {

private:

	sf::Clock clock;
	sf::SoundBuffer gOverSound;
	sf::Sound gOS;

	sf::SoundBuffer eatenS;
	sf::Sound eS;

	bool mU, mL, mD, mR; //move up, move left, move down, move right

	Fruit fruit;
	Enemy enemy;

	std::vector<sf::RectangleShape> body;
	float speed;
	int bodyLength;

	int score;
	bool gameOver;

	sf::Vector2f winSize;
	
	void initVar();

public:

	Snake();

	void setWinSize(int x, int y);

	void drawHead();
	void fruitEaten();
	void outOfBound();

	void Move();
	void dead();

	void poisonCollison();

	void userInput();

	int getScore();

	bool getGameOver();

	void setSound();

	void reset();

	void update();
	void render(sf::RenderWindow *window);



};

