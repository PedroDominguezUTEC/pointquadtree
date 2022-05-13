#ifndef PARTICLE_COLLISIONER_PARTICLES_H
#define PARTICLE_COLLISIONER_PARTICLES_H

#include "Particle.h"

class Particles{
    int number_of_particles;
    vector<Particle> particles;

public:
    Particles();
    explicit Particles(int number);

    void draw(sf::RenderWindow* window);
    void move();
    vector<Particle> get_particles();

};


#endif