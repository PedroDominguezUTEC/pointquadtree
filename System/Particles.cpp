#include "Particles.h"

Double calculate_distance(Particle &a, Particle &b){
    return sqrt(pow((a.get_x()-b.get_x()),2) + pow((a.get_y()-b.get_y()), 2));
}

Double impulse_fx(Particle &a, Particle &b){

    Double dx = b.get_x() - a.get_x();
    Double dy = b.get_y() - a.get_y();
    Double dvx = b.get_vx() - a.get_vx();
    Double dvy = b.get_vy() - a.get_vy();
    Double dv_dr = dx*dvx + dy*dvy;
    Double distance = (calculate_distance(a, b));

    Double magnitude = 2 * a.get_mass() * b.get_mass() * dv_dr / (distance * (a.get_mass() + b.get_mass()));

    return magnitude * dx / distance;
}

Double impulse_fy(Particle &a, Particle &b){
    Double dx = b.get_x() - a.get_x();
    Double dy = b.get_y() - a.get_y();
    Double dvx = b.get_vx() - a.get_vx();
    Double dvy = b.get_vy() - a.get_vy();
    Double dv_dr = dx*dvx + dy*dvy;
    Double distance = (calculate_distance(a, b));

    Double magnitude = 2 * a.get_mass() * b.get_mass() * dv_dr / (distance * (a.get_mass() + b.get_mass()));

    return magnitude * dy / distance;
}

Particles::Particles() = default;

Particles::Particles(int number): number_of_particles(number){

    // 1 PARTICULA
    /*for(int i = 0; i < number_of_particles; i++)
        particles.emplace_back(0,0,1,1,30,0.5);*/

    // 10 PARTICULAS
    /* particles = {{0,0,1,1,30,0.5},
                 {800,600,1,1,30,0.5},
                 {100,0,1,1,30,0.5},
                 {300,600,1,1,30,0.5},
                 {0,400,1,1,30,0.5},
                 {0,600,1,1,30,0.5},
                 {200,100,1,1,30,0.5},
                 {200,400,1,1,30,0.5},
                 {500,500,1,1,30,0.5},
                 {500,100,1,1,30,0.5}};*/

    // GENERADORA DE PARTICULAS
    random_device rd;
    mt19937 generator(rd());
    uniform_real_distribution<double> distribution(-3,3);

    int column = 0, row = 25;
    for(int i = 0; i < number_of_particles; i++) {
        //if (i% row == 0)
        //    column += 20;
        //particles.emplace_back(i%row * 1000/row, column, distribution(generator),distribution(generator),2, 1);
        uniform_real_distribution<double> distribution1(0,1000);
        uniform_real_distribution<double> distribution2(0,500);
        particles.emplace_back(distribution1(generator), distribution2(generator), distribution(generator),distribution(generator),2, 1);
    }
}


//DIBUJO DE CADA PARTICULA
void Particles::draw(sf::RenderWindow* window) {
    for (auto &p : particles){
        sf::CircleShape shape(p.get_radius());
        shape.setFillColor(sf::Color::Red);
        shape.setPosition(p.get_x(), p.get_y());
        window->draw(shape);
    }
}

void Particles::move(){

    // COMPARACION DE COLISION ENTRE PARTICULAS
    for(int i = 0; i < particles.size(); i ++) {
        for (int j = 0; j < particles.size(); j++) {
            if (i != j) {
                if (ceil((calculate_distance(particles[i], particles[j]))) <= 2 * particles[i].get_radius()) {

                    if (particles[i].get_last_collision() != j || particles[i].get_last_collision() == -1) {

                        Double fx = impulse_fx(particles[i], particles[j]);
                        Double fy = impulse_fy(particles[i], particles[j]);

                        particles[i].set_vx(particles[i].get_vx() + fx / particles[i].get_mass());
                        particles[i].set_vy(particles[i].get_vy() + fy / particles[i].get_mass());
                        particles[j].set_vx(particles[j].get_vx() - fx / particles[j].get_mass());
                        particles[j].set_vy(particles[j].get_vy() - fy / particles[j].get_mass());

                        particles[i].set_last_collision(j);
                        particles[j].set_last_collision(i);
                    }
                }
            }
        }

    // COLISION CON PAREDES
    if (particles[i].get_x() + particles[i].get_vx() <= 0 ||
        particles[i].get_x() + particles[i].get_vx() >= 1000 - 2*particles[i].get_radius())
    {
        particles[i].set_vx(-particles[i].get_vx());
        particles[i].set_last_collision(-1);
    }

    if (particles[i].get_y() + particles[i].get_vy() <= 0 ||
        particles[i].get_y() + particles[i].get_vy() >= 700 - 2*particles[i].get_radius())
    {
        particles[i].set_vy(-particles[i].get_vy());
        particles[i].set_last_collision(-1);
    }

    //MOVIMIENTO DE PARTICULAS
    particles[i].set_x(particles[i].get_x() + particles[i].get_vx());
    particles[i].set_y(particles[i].get_y() + particles[i].get_vy());
    }
}

vector<Particle> Particles::get_particles() {
    return particles;
}
