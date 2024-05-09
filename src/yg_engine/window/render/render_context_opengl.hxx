#include "window/render/render_context.hxx"

namespace yg
{
class render_context_opengl : public render_context
{
    result_code initialize() override;
    result_code render_triangle() override;
};
} // namespace yg