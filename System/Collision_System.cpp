#include "Collision_System.h"

Collision_System::Collision_System(sf::RenderWindow* wnd, int num): window(wnd){

    Particles particles(num);
    PointQuadTree qt;

    //window->clear();
    particles.draw(window);
    qt.draw(window, particles);
    //particles.move();
    window->display();

    while (window->isOpen())
    {
        sf::Event event{};
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    
                    Particle newParticle(event.mouseButton.x, event.mouseButton.y, 2, 2, 10, 1); 

                    window->clear();

                    particles.insert(newParticle);

                    qt.draw(window, particles);
                    particles.draw(window);

                    window->display();
                }
            }   
        }
    }
}