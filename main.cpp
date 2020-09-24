#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "classes/spaceship.h"
#include "classes/laser.h"
#include "classes/enemy.h"

int main() {
    srand(time(0));
    int sizeScreen       = 2000;
    float userMoveSpeed  = 4;
    float enemyMoveSpeed = 1;
    float laserMoveSpeed = 4;
    sf::RenderWindow window(sf::VideoMode(sizeScreen, sizeScreen), "Level 1");
    // load textures
    sf::Texture textureShip, textureLaser, textureEnemy, textureEnemySmall;
    textureShip.loadFromFile("textures/spaceship.png");
    textureLaser.loadFromFile("textures/laser3.png");
    textureEnemy.loadFromFile("textures/enemy.png");
    textureEnemySmall.loadFromFile("textures/enemySmall.png");
    // load audio
    sf::SoundBuffer buffer;
    buffer.loadFromFile("textures/laserSound.wav");
    // declare classes
    Spaceship spaceship(userMoveSpeed,sizeScreen,&textureShip);
    Laser laser(laserMoveSpeed, &textureLaser, &buffer);
    Enemy enemy(enemyMoveSpeed, sizeScreen, &textureEnemy);
    Enemy enemy2(enemyMoveSpeed, sizeScreen, &textureEnemySmall); //TEST

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
        // Test
        if(laser.getGlobalBounds().intersects(enemy2.getGlobalBounds())) {
            laser.kill();
            enemy2.kill();
        }

        // updates moving objects
        laser.update();
        enemy.update();
        enemy2.update();//Test
        // clears the screen for clean draw
        window.clear();
        // draws the objects
        window.draw(laser);
        window.draw(spaceship);
        window.draw(enemy);
        window.draw(enemy2);//Test
        window.display();
    }
    return 0;
}