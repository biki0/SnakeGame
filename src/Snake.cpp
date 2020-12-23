#include "Snake.hpp"

//constructor
Snake::Snake() {
	initVar();
	drawHead();
	setSound();
}

//function to initialize variables
void Snake::initVar() {
	speed = 6;
	bodyLength = 1;
	mU = false;
	mL = false;
	mD = false;
	mR = false;
	score = 0;
	gameOver = false;
	
}

//function to set window width and height to vector
void Snake::setWinSize(int x, int y) {
	winSize.x = x;
	winSize.y = y;
}

//setting snake's head color, size & position
void Snake::drawHead() {
	body.push_back(sf::RectangleShape(sf::Vector2f(25, 25)));
	body[0].setFillColor(sf::Color::Green);
	body[0].setPosition(800 / 2, 600 / 2);
}

//logic to increase snake's body when fruit is eaten
void Snake::fruitEaten() {

	float x = rand() % 750;
	float y = rand() % 550;

	if (body[0].getGlobalBounds().intersects(fruit.food.getGlobalBounds())) {
		eS.play();
		score += 1;
		fruit.food.setPosition(x, y);

		body.push_back(sf::RectangleShape(sf::Vector2f(25, 25)));
		body[bodyLength].setFillColor(sf::Color::Green);
		bodyLength += 1;
	}

	for (int i = bodyLength - 1; i > 0; --i) {
		body[i].setPosition(sf::Vector2f(body[i - 1].getPosition().x, body[i - 1].getPosition().y));
	}


}

//check if snake is out of screen; if so reposition to oposite side 
void Snake::outOfBound() {

	int x = body[0].getPosition().x;
	int y = body[0].getPosition().y;

	if (body[0].getPosition().x < 0) {
		body[0].setPosition(winSize.x, y);
	}
	else if (body[0].getPosition().y < 0) {
		body[0].setPosition(x, winSize.y);
	}
	else if (body[0].getPosition().x > winSize.x) {
		body[0].setPosition(sf::Vector2f(0, y));
	}
	else if (body[0].getPosition().y > winSize.y) {
		body[0].setPosition(sf::Vector2f(x, 0));
	}
}

//move snake according to user input
void Snake::Move() {

		if (mU) { body[0].move(0, -speed); }
		else if (mL) { body[0].move(-speed, 0); }
		else if (mD) { body[0].move(0, speed);  }
		else if (mR) { body[0].move(speed, 0);  }
		else { body[0].move(speed, 0); }
	
	
}

//check if snake's head touches tail; if so game is over
void Snake::dead() {

	for (int i = 2; i < bodyLength; ++i) {
		if ((body[1].getPosition(), body[0].getPosition()) == body[i].getPosition()) {
			std::cout << "Game over" << std::endl;
			gOS.play();
			gameOver = true;
		}

	}

}

void Snake::poisonCollison() {

	for (int i = 0; i < enemy.pAmount; ++i) {
		if (body[0].getGlobalBounds().intersects(enemy.poison[i].getGlobalBounds())) {
			gOS.play();
			enemy.pAmount -= 1;
			enemy.poison.resize(enemy.pAmount);
			gameOver = true;
			std::cout << "Poison hit; GAME OVER" << std::endl;
		}
	}

}



//get user input & move snake
void Snake::userInput() {


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !mD) {
		mU = true;
		mL = false;
		mD = false;
		mR = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && !mR) {
		mL = true;
		mU = false;
		mD = false;
		mR = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !mU) {
		mD = true;
		mU = false;
		mL = false;
		mR = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && !mL) {
		mR = true;
		mU = false;
		mL = false;
		mD = false;
	}
	
	Move();
	
}

int Snake::getScore() {
	return score;
}


bool Snake::getGameOver() {
	return gameOver;
}

void Snake::setSound() {
	if (!gOverSound.loadFromFile("assets/game_over.wav")) {
		std::cout << "AUDIO NOT FOUND" << std::endl;
	}
	gOS.setBuffer(gOverSound);

	if (!eatenS.loadFromFile("assets/eat_sound.wav")) {
		std::cout << "AUDIO NOT FOUND" << std::endl;
	}
	eS.setBuffer(eatenS);

}



void Snake::reset() {
	bodyLength = 1;
	score = 0;
	gameOver = false;
}

//update game
void Snake::update() {
	
	userInput();
	enemy.spawnPoison();
	enemy.removePoison();


}

//draw snake, enemy & fruit to screen
void Snake::render(sf::RenderWindow *window) {
	
	enemy.render(window);

	for (int i = 0; i < bodyLength; ++i) {
		window->draw(body[i]);
	}
	fruit.render(window);
}


