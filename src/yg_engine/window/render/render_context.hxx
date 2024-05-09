#pragma once

namespace yg
{
class render_context
{
public:
    enum result_code
    {
        SUCCESS,
        ERROR
    };

    virtual result_code initialize()      = 0;
    virtual result_code render_triangle() = 0;
};
} // namespace yg