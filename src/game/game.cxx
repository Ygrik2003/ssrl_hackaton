#include "base.h"
#include "config.h"

bool check_tanks_collision()
{
    std::vector<std::pair<int, int>> set_from_player_tank = { player_tank };

    auto collide_with_unbreaking_bricks =
        _::intersection<std::vector<std::pair<int, int>>>(set_from_player_tank,
                                                          unbreak_bricks);
    base::debug::print_vector_of_points(collide_with_unbreaking_bricks,
                                        "collide_with_unbreaking_bricks");

    auto collide_with_bricks =
        _::intersection<std::vector<std::pair<int, int>>>(set_from_player_tank,
                                                          bricks);
    base::debug::print_vector_of_points(collide_with_bricks,
                                        "collide_with_bricks");

    auto collide_with_grass = _::intersection<std::vector<std::pair<int, int>>>(
        set_from_player_tank, grass);
    base::debug::print_vector_of_points(collide_with_grass,
                                        "collide_with_grass");

    auto collide_with_water = _::intersection<std::vector<std::pair<int, int>>>(
        set_from_player_tank, water);
    base::debug::print_vector_of_points(collide_with_water,
                                        "collide_with_water");

    std::cout << (int)(collide_with_bricks.empty() ||
                       collide_with_unbreaking_bricks.empty() ||
                       collide_with_water.empty())
              << std::endl;
    return collide_with_bricks != std::vector<std::pair<int, int>>{} ||
           collide_with_unbreaking_bricks !=
               std::vector<std::pair<int, int>>{} ||
           collide_with_water != std::vector<std::pair<int, int>>{};
}

void render_map();
void render_tanks();
void render_projectiles();