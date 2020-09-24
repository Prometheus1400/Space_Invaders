class Enemy: public sf::Sprite {
public:
	// attributes
	float moveSpeed;
	// Constructor
    Enemy(float speed, int sizeScreen, sf::Texture *texture) {
    	moveSpeed = speed;
        setTexture(*texture);
        setScale(0.3f,0.3f);
        kill();
    }
    // other methods
    void kill() {
    	setPosition(rand()%1700,-(rand()%500)-400.f);
    }

    void update() {
    	move(0.f,moveSpeed);
    	if(getPosition().y > 1700) {
    		kill();
    	}
    }
};