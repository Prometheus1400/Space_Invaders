class Laser: public sf::Sprite {
public:
    // attributes
    float speed;
    bool active;
    // Constructor
    Laser(float laserSpeed, sf::Texture *texture) {
        speed = laserSpeed;
        active = false;
        setTexture(*texture);
        setScale(0.5f,0.2f);
        kill();
    }
    // other methods
    void kill() {
        active = false;
        setPosition(-500.f,-500.f);
    }

    void fire(float x, float y) {
        if (!active) {
            setPosition(x+65.f,y-20);
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