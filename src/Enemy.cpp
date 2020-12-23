#include "Enemy.hpp"

Enemy::Enemy() {
	pAmount = 0;
}


void Enemy::spawnPoison() {

	float x = rand() % 750;
	float y = rand() % 550;


	if (clock.getElapsedTime().asSeconds() > 2) {
		
		poison.push_back(sf::CircleShape(15));
		poison[pAmount].setFillColor(sf::Color::Yellow);
		poison[pAmount].setPosition(x, y);
		pAmount += 1;
	
		clock.restart();
	}

}

void Enemy::removePoison() {

	if (pAmount > 2) {
		int x = 0;
		pAmount = x;
	}

}


void Enemy::render(sf::RenderWindow* window) {
	for (int i = 0; i < pAmount; ++i) {
		window->draw(poison[i]);
	}
}

