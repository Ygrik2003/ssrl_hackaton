#pragma once

#include "window/window_manager.hxx"

namespace yg
{
class window_sdl : public window
{
public:
    window_sdl(render_context::render_api render_api) noexcept;

    ~window_sdl() noexcept             = default;
    window_sdl(const window_sdl& ctx)  = delete;
    window_sdl(const window_sdl&& ctx) = delete;

    result_code initialize(const window_config& config) override;
    result_code process_events() override;
    result_code capture_render_context(render_context* ctx) override;

private:
    SDL_WindowFlags window_flags;
    SDL_Window*     wnd;
    SDL_GLContext   gl_context;
};
} // namespace yg