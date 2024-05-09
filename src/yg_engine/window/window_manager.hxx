#include "ygforwards.hxx"

#include <SDL3/SDL.h>

namespace yg
{

#pragma pack(push, 8)
struct window_config
{
    uint16_t size_x;
    uint16_t size_y;

    bool is_fullscreen;
    bool is_resizeble;
};
#pragma pack(pop)

class window_manager
{
public:
    window_manager(window_config config);

    void sdl_backend();
    // void sfml_backend();
    void init_opengl_context();
};

} // namespace yg