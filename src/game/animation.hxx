#include <SFML/Graphics.hxxpp>

class animation_sprite
{
public:
    animation_sprite(const sf::Image& image, sf::);
};

/// @brief
class animation_fabric
{
public:
    animation_fabric();

    animation_sprite get_animation();
};