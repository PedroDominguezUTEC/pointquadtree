#include "Collision_System.h"

Collision_System::Collision_System(sf::RenderWindow* wnd, int num): window(wnd){

    Particles particles(num);
    auto wndsize = window->getSize();
    QuadTree qt(0, wndsize.x, 0, wndsize.y);
    while (window->isOpen())
    {
        sf::Event event{};
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();

            // evento de click
            
        }
        //window->clear();
        particles.draw(window);
        qt.draw(window, particles);
        //particles.move();
        window->display();
    }
}