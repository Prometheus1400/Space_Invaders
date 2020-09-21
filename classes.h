class Spaceship: public sf::Sprite {
    float moveSpeed;
public:
    Spaceship(float speed, int sizeScreen, sf::Texture *texture) {
        moveSpeed = speed;
        setTexture(*texture);
        setScale(0.25f,0.25f);
        setPosition(sizeScreen/2.0f,sizeScreen*0.89f);

    }
    void left() {
        if (getPosition().x > 0) {
            move(-moveSpeed,0.f);
        }
    }
    void right() {
        if (getPosition().x < 1795) {
            move(moveSpeed,0.f);
        }
    }
};

class Laser: public sf::Sprite {
    float speed = 10;
public:
    bool active;
    Laser() {
        active = false;
        setScale(0.5f,0.2f);
    }

    void kill() {
        active = false;
    }

    void fire(float x, float y) {
        if (!active) {
            setPosition(x-93.8f,y-20);
            active = true;

        }
    }
    void update() {
        if (active && getPosition().y > -200) {
            move(0.f,-speed);
        } else {
            active = false;
        }
    }
};