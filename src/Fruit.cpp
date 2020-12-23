#include "Fruit.hpp"

//constructor
Fruit::Fruit() {
	drawFood();
}

//set food color, size & position
void Fruit::drawFood() {

	food.setFillColor(sf::Color::Red);
	food.setSize(sf::Vector2f(25, 25));
	int x = rand() % 750;
	int y = rand() % 550;
	food.setPosition(sf::Vector2f(x, y));

}


//draw food to screen
void Fruit::render(sf::RenderWindow* window) {
	window->draw(food);
}
