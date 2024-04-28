#include <array>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Cursor.hpp>

#include "underscore.h"

#define PROJ_DEBUG_INFO

namespace base
{

enum game_state
{
    is_running = 1 << 0,
    is_pause   = 1 << 1,
    is_end     = 1 << 2
};

enum file_permission
{
    read   = 1 << 0,
    write  = 1 << 1,
    append = 1 << 2
};

enum cell_type
{
    grass,
    water,
    bricks,
    unbreak_bricks
};

namespace api
{
int  file_open(std::string filename, file_permission);
void render_sprite(sf::RenderWindow* window, sf::Sprite sprite);
int  sound_play();
int  event();
} // namespace api

namespace debug
{
void print_vector_of_points(std::vector<std::pair<int, int>> points,
                            std::string                      title = "")
{
#ifdef PROJ_DEBUG_INFO
    if (title != "")
    {
        std::cout << "============== " << title
                  << " ==============" << std::endl;
    }
    if (points == std::vector<std::pair<int, int>>{})
    {
        std::cout << "Vector is empty" << std::endl;
        return;
    }
    for (const auto& point : points)
    {
        std::cout << "[" << point.first << ", " << point.second << "]"
                  << std::endl;
    }
#endif
}
}; // namespace debug

} // namespace base
