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
    read,             // only read
    write,            // only write (erase all content of file)
    append,           // write append to end of file
    read_byte,        // like read, but in byte mode
    write_byte,       // like write, but in byte mode
    append_byte,      // like append, but in byte mode
    read_write,       // like write, but u can read
    read_append,      // like append, but u can read
    read_write_byte,  // like read_write, but in byte mode
    read_append_byte, // like read_append, but in byte mode
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
