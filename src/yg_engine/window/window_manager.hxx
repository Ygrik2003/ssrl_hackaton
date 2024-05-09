#pragma once

#include "window/render/render_context.hxx"

#include <cstdint>

namespace yg
{

#pragma pack(push, 8)
struct window_config
{
    uint16_t size_x;
    uint16_t size_y;

    bool is_fullscreen;
    bool is_resizeble;

    enum
    {
        SFML,
        SDL
    } backend_type;
    enum
    {
        OpenGL,
        Vulkan
    } render_context_type;
};
#pragma pack(pop)

class window
{
public:
    enum result_code
    {
        SUCCESS,
        ERROR
    };

    virtual result_code initialize(window_config config)            = 0;
    virtual result_code process_events()                            = 0;
    virtual result_code capture_render_context(render_context* ctx) = 0;
};

class window_manager
{
public:
    window_manager(window_config config, window* backend, render_context* ctx);
};

} // namespace yg