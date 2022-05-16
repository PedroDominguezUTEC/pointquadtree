#include "pquadtree.h"


void PointQuadTree::insert(sf::RenderWindow* window, Point* r, Point* p) {
    if (r->is_h) {
        r = p;
        r->is_h = false;
        
        int left = 0, right = width, up = 0, down = height;
        
        sf::Vertex linex[] =
        {
            sf::Vertex(sf::Vector2f(left, p->y)),
            sf::Vertex(sf::Vector2f(right, p->y))
        };

        sf::Vertex liney[] =
        {
            sf::Vertex(sf::Vector2f(p->x, up)),
            sf::Vertex(sf::Vector2f(p->x, down))
        };

        window->draw(linex, 2, sf::Lines);
        window->draw(liney, 2, sf::Lines);

        return;
    }

    Point* temp = r;

    if (p->x > temp->x){
        if (p->y > temp->y){
            insert(window, temp->regions->at(1), p);
        } else {
            insert(window, temp->regions->at(3), p);
        }
    } else if (p->y > temp->y) {
        insert(window, temp->regions->at(0), p);
    } else 
        insert(window, temp->regions->at(2), p);
}

void PointQuadTree::draw(sf::RenderWindow* window, Particles& particles) {
    auto ps = particles.get_particles();
    for (auto x : ps) {
        Point* p = new Point(x.get_x() + x.get_radius(), x.get_y() + x.get_radius());
        this->insert(window, this->root, p);
    }
}