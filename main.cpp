#include <SFML/Graphics.hpp>
#include "Game_play.h"

int main()
{

    sf::RenderWindow window(sf::VideoMode(1300, 700), "El Anillo de Poder");
    window.setFramerateLimit(60);

    Game_play GP(window);

    sf::View _view(sf::FloatRect(0.f,0.f,1100.f,600.f));//1300, 700

    window.setView(_view);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }


        }


        GP.update(window);
        _view.setCenter(GP.get_camera_position());//.x,415
        window.setView(_view);

        GP.cmd();

        window.clear();
        GP.draw(window);
        window.display();
    }

    return 0;
}
