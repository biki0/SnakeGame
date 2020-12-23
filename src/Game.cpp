#include "Game.hpp"

//constructor
Game::Game() {

	initVar();
	initWindow();

	setText();
	drawScore();

}

//destructor
Game::~Game() {
	delete window;
}

//function to initialize variables
void Game::initVar() {
	window = nullptr;
	width = 800;
	height = 600;
	snake.setWinSize(width, height);
	gameStart = true;
	pause = true;
	gameOver = false;
}

//set our window size, title & framelimit
void Game::initWindow(){
	window = new sf::RenderWindow(sf::VideoMode(width, height), "Classic Snake");
	window->setFramerateLimit(60);
}

//check if window is open and return T/F
bool Game::isRunning() {
	return window->isOpen();
}

void Game::setText() {
	if (!font.loadFromFile("assets/old_school_united_regular.ttf")) { std::cout << "Error! not loaded" << std::endl; }


	score.setFont(font);

}

void Game::drawScore() {
	score.setString(std::to_string(snake.getScore()));
	score.setFillColor(sf::Color::White);
	score.setCharacterSize(25);
	score.setPosition(sf::Vector2f(50, 50));
}

void Game::beforeGameStart() {
	if (gameStart && pause) {
		sf::Text n;
		n.setFont(font);
		n.setCharacterSize(40);
		n.setString("SNAKE");
		n.setFillColor(sf::Color::Green);
		n.setPosition(350,120);

		sf::Text s;
		s.setFont(font);
		s.setCharacterSize(30);
		s.setString("Space TO PLAY");
		s.setPosition(300, 500);

		sf::Text h;
		h.setFont(font);
		h.setCharacterSize(25);
		h.setString("Eat Red Fruits & Avoid Yellow Fruits");
		h.setPosition(150, 300);
		
		sf::Text p;
		p.setFont(font);
		p.setCharacterSize(25);
		p.setString("Escape to pause anytime");
		p.setPosition(250, 325);

		window->clear(sf::Color::Black);
		window->draw(n);
		window->draw(s);
		window->draw(h);
		window->draw(p);
		window->display();
	}
	else {
		sf::Text s;
		s.setFont(font);
		s.setCharacterSize(40);
		s.setString("SPACE TO UNPAUSE");
		s.setPosition(window->getSize().x/3, window->getSize().y / 2);
		window->clear(sf::Color::Black);
		window->draw(s);
		window->display();
	}
}


void Game::over() {

	sf::Text s;
	s.setFont(font);
	s.setCharacterSize(30);
	s.setString("GAME OVER PRESS ENTER TO PLAY AGAIN OR Q TO QUIT");
	s.setPosition(100, 300);
	window->clear(sf::Color::Black);
	window->draw(s);
	window->display();

}


//get events & function to update game
void Game::update() {

	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window->close();
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		gameStart = false;
		pause = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		pause = true;
	}

	if (!pause && !gameOver) {
		snake.update();
		snake.fruitEaten();
		snake.outOfBound();
		snake.dead();
		snake.poisonCollison();
		score.setString(std::to_string(snake.getScore()));
		gameOver = snake.getGameOver();
	}
	if (gameOver) { 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
			window->close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			playAgain = true;
		}
		over();
	}
	
	if (playAgain) {
		snake.reset();
		pause = false;
		gameOver = false;
		playAgain = false;
	}
	

}

//function to draw to screen
void Game::render() {

	if (!pause && !gameOver) {
		window->clear(sf::Color::Black);

		//Draw here

		snake.render(window);

		window->draw(score);

		window->display();
	}
	else if(pause){ beforeGameStart(); }

}