
class Enemy: public sf::Sprite {
    float moveSpeed = 1.f;
public:
    Enemy(int sizeScreen, sf::Texture *texture) {
        setTexture(*texture);
        setScale(0.3f,0.3f);
        kill();
    }

    void kill() {
    	setPosition(rand()%1700,-400.f);
    }

    void update() {
    	move(0.f,moveSpeed);
    	if(getPosition().y > 1700) {
    		kill();
    	}
    }
};