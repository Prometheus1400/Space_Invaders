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