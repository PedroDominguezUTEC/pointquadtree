#include "../System/Particles.h"

struct Point{
	Float x = -1;
	Float y = -1;
	bool is_h = true;
	vector<Point*>* regions = new vector<Point*>(4);

	Point(){}
    Point(Float x, Float y) {
        	this->x = x;
        	this->y = y;
    }
};

class PointQuadTree{
    private:
        Point* root = new Point();
    public:
        PointQuadTree(){}
    
        void insert(sf::RenderWindow* window, Point* r, Point* p);
        
        void draw(sf::RenderWindow* window, Particles& particles);

        void print();
};
