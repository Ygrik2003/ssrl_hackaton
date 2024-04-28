#include "game.h"
int main()
{
    sf::RenderWindow window(
        sf::VideoMode(config::window_size_x, config::window_size_y),
        "Tanchiki!!!",
        0);

    while (game_state & base::game_state::is_running)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return 0;
            }
        }

        // if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
        //      (sf::Keyboard::isKeyPressed(sf::Keyboard::A))))
        // {
        // }
        // if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
        //      (sf::Keyboard::isKeyPressed(sf::Keyboard::D))))
        // {
        // }
        // if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
        //      (sf::Keyboard::isKeyPressed(sf::Keyboard::W))))
        // {
        // }
        // if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
        //      (sf::Keyboard::isKeyPressed(sf::Keyboard::S))))
        // {
        // }
        // if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) ||
        //      (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))))
        // {
        // }

        if (check_tanks_collision())
        {
        }

        window.clear(sf::Color(0, 0, 0));
        render_map(&window);
        render_tanks(&window);
        window.display();

        sf::sleep(sf::microseconds(1e6 / config::fps));
    }

    return 0;
}