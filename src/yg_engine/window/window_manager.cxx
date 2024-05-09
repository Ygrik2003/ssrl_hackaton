#include "window/window_manager.hxx"

yg::window_manager::window_manager(window_config config)
{
    SDL_Window* wnd =
        SDL_CreateWindow("Tanchiki", config.size_x, config.size_y, 0);
}