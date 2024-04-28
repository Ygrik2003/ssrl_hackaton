#include "base.h"

void base::api::render_sprite(sf::RenderWindow* window, sf::Sprite sprite)
{
    window->draw(sprite);
}
