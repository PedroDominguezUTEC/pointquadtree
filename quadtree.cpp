#include "quadtree.h"


QuadTree::QuadTree(float min_x, float max_x, float min_y, float max_y) {
    this->min_x = min_x;
    this->max_x = max_x;
    this->min_y = min_y;
    this->max_y = max_y;
}



void QuadTree::insert(sf::RenderWindow* window, Point &p) {
    // leaf and empty
    if (this->leaf && this->empty) {
        this->point = p;
        this->empty = false;
        return;
    }

    float MidPoint_x = (min_x + max_x)/2;
    float MidPoint_y = (min_y + max_y)/2;

    bool above = p.y <= MidPoint_y;
    bool left = p.x <= MidPoint_x;

    // not leaf
    if (!this->leaf) {
        if (above && left) suroeste->insert(window, p);
        if (above && !left) sureste->insert(window, p);
        if (!above && left) noroeste->insert(window, p);
        if (!above && !left) noreste->insert(window, p);
        return;
    }

    // before spliting, verify if there is the same point:
    if (p.x == point.x && p.y == point.y)
        return;

    // leaf and not empty (split)
    this->leaf = false;
    noroeste = new QuadTree(min_x, MidPoint_x, MidPoint_y+1, max_y);    // ariba izquierda
    noreste = new QuadTree(MidPoint_x+1, max_x, MidPoint_y+1, max_y);   // arriba derecha
    suroeste = new QuadTree(min_x, MidPoint_x, min_y, MidPoint_y);      // abajo izquierda
    sureste = new QuadTree(MidPoint_x+1, max_x, min_y, MidPoint_y);      // abajo derecha

    sf::Vertex linex[] =
    {
        sf::Vertex(sf::Vector2f(this->min_x, MidPoint_y)),
        sf::Vertex(sf::Vector2f(this->max_x, MidPoint_y))
    };

    sf::Vertex liney[] =
    {
        sf::Vertex(sf::Vector2f(MidPoint_x, this->min_y)),
        sf::Vertex(sf::Vector2f(MidPoint_x, this->max_y))
    };

    window->draw(linex, 2, sf::Lines);
    window->draw(liney, 2, sf::Lines);


    if (above && left) suroeste->insert(window, p);
    if (above && !left) sureste->insert(window, p);
    if (!above && left) noroeste->insert(window, p);
    if (!above && !left) noreste->insert(window, p);

    // Pass the current point into the leafs
    above = this->point.y <= MidPoint_y;
    left = this->point.x <= MidPoint_x;

    if (above && left) suroeste->insert(window, point);
    if (above && !left) sureste->insert(window, point);
    if (!above && left) noroeste->insert(window, point);
    if (!above && !left) noreste->insert(window, point);
}


void QuadTree::draw(sf::RenderWindow* window, Particles& particles) {
    auto ps = particles.get_particles();
    for (auto x : ps) {
        auto* p = new Point(x.get_x(), x.get_y());
        this->insert(window, *p);
    }
}

