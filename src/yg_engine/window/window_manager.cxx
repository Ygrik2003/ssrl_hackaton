#include "window/window_manager.hxx"

#include "window_manager.hxx"
#include <SDL3/SDL.h>

yg::window_manager::window_manager(window_config   config,
                                   window*         backend,
                                   render_context* ctx)
{
    backend->initialize(config);
    backend->capture_render_context(ctx);
    ctx->initialize();
}