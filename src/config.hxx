#include <stdint.h>

namespace config
{
const uint8_t  fps           = 60;
const uint16_t window_size_x = 512;
const uint16_t window_size_y = 512;
const uint16_t cells_count_x = 4;
const uint16_t cells_count_y = 4;
const uint16_t cell_size_x   = window_size_x / cells_count_x;
const uint16_t cell_size_y   = window_size_y / cells_count_y;

const uint8_t count_tanks = 4;

const uint8_t tank_hp  = 4;
const uint8_t brick_hp = 4;

} // namespace config