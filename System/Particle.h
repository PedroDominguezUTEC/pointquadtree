#ifndef PARTICLE_COLLISIONER_PARTICLE_H
#define PARTICLE_COLLISIONER_PARTICLE_H

#include "LibraryHeader.h"

class Particle {

    Float rx, ry;
    Float vx, vy;
    Float radius;
    Float mass;
    Float last_collision;

public:
    Particle();
    Particle(Float x, Float y, Float vx_, Float vy_, Float r, Float m);

    Float get_x();
    Float get_y();
    Float get_vx();
    Float get_vy();
    Float get_radius();
    Float get_mass();
    Float get_last_collision();

    void set_x(Float _x);
    void set_y(Float _y);
    void set_vx(Float _vx);
    void set_vy(Float _vy);
    void set_radius(Float _radius);
    void set_mass(Float _mass);
    void set_last_collision(Float last);

};

#endif