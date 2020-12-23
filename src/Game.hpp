#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Snake.hpp"


class Game {

private:

	int width;
	int height;

	sf::RenderWindow* window;
	sf::Event event;
	
	sf::Font font;
	sf::Text score;

	Snake snake;

	bool gameStart, pause;
	bool playAgain;
	bool gameOver;
	bool sp;
	void initVar();
	void initWindow();




public:
	Game();
	~Game();

	bool isRunning();

	void setText();
	void drawScore();

	void beforeGameStart();


	void over();
	void update();
	void render();


};

