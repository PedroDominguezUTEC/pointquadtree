#include "System/Collision_System.h"

/*
int main() {
    QuadTree qt(0, 10, 0, 10);
    Point p1(0, 0);
    Point p2(0, 1);
    Point p3(1, 0);
    Point p4(1, 1);
    Point p5(1, 1);

    qt.insert(p1);
    qt.insert(p2);
    qt.insert(p3);
    qt.insert(p4);
    //qt.insert(p5);

    qt.print();

    return 0;
}
*/


int randomparticles(){
    srand(0);
    return 5 + rand() % 4;
}

int interface(){
    int number_particles = 0;
    while (number_particles < 1 || number_particles > 250)
        {
            cout << "How many particles do you wish to see? (Max 250): "; cin >> number_particles;
            if (number_particles > 250)
                cout << "-Error- Try again";
        }
    return number_particles;
}



int main()
{
    
    int number_particles = randomparticles();


    //RENDERIZADO DE PANTALLA
    sf::RenderWindow window(sf::VideoMode(width, height), "Particle_Collision");
    Collision_System start(&window, number_particles);

    return 0;
}

