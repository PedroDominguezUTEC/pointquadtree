#include "../System/Particles.h"

struct Point{
    float x;
    float y;

    Point() {x=-1, y=-1;}
    Point(float x, float y) {
        this->x = x;
        this->y = y;
    }
};

struct QuadTree{
    // Limits
    float min_x = 0;
    float min_y = 0;
    float max_x = 0;
    float max_y = 0;

    // Children
    QuadTree *noroeste;
    QuadTree *noreste;
    QuadTree *suroeste;
    QuadTree *sureste;

    // Data
    bool leaf = true;   // a leaf holds a maximum of 1 point
    bool empty = true;
    Point point;  // si es hoja, guarda un punto, si no es hoja es vacío

    QuadTree() {}
    explicit QuadTree(float min_x, float max_x, float min_y, float max_y);
    void insert(sf::RenderWindow* window, Point &p);
    //void remove(sf::RenderWindow* window, Point &p);

    void draw(sf::RenderWindow* window, Particles& particles);

    void print();
};
