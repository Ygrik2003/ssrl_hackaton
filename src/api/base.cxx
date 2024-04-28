#include "base.h"

int base::api::file_open(std::string filename, file_permission mode)
{
    const char* mode_fopen;
    switch (mode)
    {
        case base::file_permission::read:
            mode_fopen = "r";
            break;
        case base::file_permission::write:
            mode_fopen = "w";
            break;
        case base::file_permission::append:
            mode_fopen = "a";
            break;
        case base::file_permission::read_byte:
            mode_fopen = "rb";
            break;
        case base::file_permission::write_byte:
            mode_fopen = "wb";
            break;
        case base::file_permission::append_byte:
            mode_fopen = "ab";
            break;
        case base::file_permission::read_write:
            mode_fopen = "w+";
            break;
        case base::file_permission::read_append:
            mode_fopen = "a+";
            break;
        case base::file_permission::read_write_byte:
            mode_fopen = "wb+";
            break;
        case base::file_permission::read_append_byte:
            mode_fopen = "ab+";
            break;
    }
    fopen(filename.c_str(), mode_fopen);
    return 0;
}
