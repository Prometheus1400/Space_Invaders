#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "classes/spaceship.h"
#include "classes/laser.h"
#include "classes/enemy.h"

int main() {
    srand(time(0));
    int shipMoveSpeed = 4;
    int sizeScreen = 2000;
    sf::RenderWindow window(sf::VideoMode(sizeScreen, sizeScreen), "Level 1");
    // load textures
    sf::Texture textureShip, textureLaser, textureEnemy;
    textureShip.loadFromFile("textures/spaceship.png");
    textureLaser.loadFromFile("textures/laser3.png");
    textureEnemy.loadFromFile("textures/enemy.png");
    // declare classes
    Spaceship spaceship(shipMoveSpeed,sizeScreen,&textureShip);
    Laser laser(&textureLaser);
    Enemy enemy(sizeScreen, &textureEnemy);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
             // left key is pressed: move our character
            spaceship.left();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
             // left key is pressed: move our character
            spaceship.right();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
             // left key is pressed: move our character
            laser.fire(spaceship.getPosition().x,spaceship.getPosition().y);
        }

        // detect collision
        if(laser.getGlobalBounds().intersects(enemy.getGlobalBounds())) {
            laser.kill();
            enemy.kill();
        }

        // updates moving objects
        laser.update();
        enemy.update();
        // clears the screen for clean draw
        window.clear();
        // draws the objects
        window.draw(laser);
        window.draw(spaceship);
        window.draw(enemy);
        window.display();
    }
    return 0;
}