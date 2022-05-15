#ifndef PARTICLE_COLLISIONER_COLLISION_SYSTEM_H
#define PARTICLE_COLLISIONER_COLLISION_SYSTEM_H

#include "Particles.h"

class Collision_System {
private:
    sf::RenderWindow* window{};
public:
    Collision_System(sf::RenderWindow* wnd, int num);
};

#endif