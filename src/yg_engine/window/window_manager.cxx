#include "window/window_manager.hxx"

#include <cassert>

yg::window_manager::window_manager(window_config   config,
                                   window*         backend,
                                   render_context* ctx)
{

    assert(backend->initialize(config) != window::result_code::ERROR &&
           "Can't initialize window backend");

    assert(backend->capture_render_context(ctx) != window::result_code::ERROR &&
           "Can't capture render context");

    assert(ctx->initialize() != render_context::result_code::ERROR &&
           "Can't initialize render context");
}