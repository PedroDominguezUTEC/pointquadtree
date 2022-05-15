#include "Particle.h"

Particle::Particle() = default;

Particle::Particle(Float x, Float y, Float vx_, Float vy_, Float r, Float m):
                rx(x), ry(y), vx(vx_), vy(vy_), radius(r), mass(m) {}

Float Particle::get_x() {return rx;}

Float Particle::get_y() {return ry;}

Float Particle::get_vx() {return vx;}

Float Particle::get_vy() {return vy;}

Float Particle::get_radius() {return radius;}

Float Particle::get_mass() {return mass;}

Float Particle::get_last_collision() {return last_collision;}


void Particle::set_x(Float _x) {rx = _x;}

void Particle::set_y(Float _y) {ry = _y;}

void Particle::set_vx(Float _vx) {vx = _vx;}

void Particle::set_vy(Float _vy) {vy = _vy;}

void Particle::set_radius(Float _radius) {radius = _radius;}

void Particle::set_mass(Float _mass) {mass = _mass;}

void Particle::set_last_collision(Float last) {last_collision = last;}