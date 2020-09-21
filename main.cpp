#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "classes.h"

int main() {
    int shipMoveSpeed = 4;
    int sizeScreen = 2000;
    sf::RenderWindow window(sf::VideoMode(sizeScreen, sizeScreen), "Level 1");
    // define a triangle
    sf::Texture textureShip, textureLaser;
    textureShip.loadFromFile("textures/spaceship.png");
    textureLaser.loadFromFile("textures/laser2.png");
    Spaceship spaceship(shipMoveSpeed,sizeScreen,&textureShip);
    Laser laser;
    laser.setTexture(textureLaser);

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
        laser.update();
        window.clear();
        if (laser.active) {
            window.draw(laser);
        }
        window.draw(spaceship);
        window.display();
    }

    return 0;
}