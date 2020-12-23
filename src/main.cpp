#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Game.hpp"


int main()
{
    

    Game game;

    while (game.isRunning()) {

        game.update();

        game.render();
    }



    return 0;
}