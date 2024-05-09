#pragma once

#include "window/window_manager.hxx"

namespace yg
{
class window_sdl : public window
{
    result_code initialize(window_config config) override;
    result_code process_events() override;
    result_code capture_render_context(render_context* ctx) override;
};
} // namespace yg