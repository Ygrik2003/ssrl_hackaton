#include "base.h"
#include "config.h"

base::game_state game_state{ base::game_state::is_running };

// Map elements
std::vector<std::pair<int, int>>       bricks;       // breaking blocks
std::map<std::pair<int, int>, uint8_t> bricks_state; // breaking blocks

std::vector<std::pair<int, int>> unbreak_bricks{
    { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 }, { 1, 3 }, { 2, 3 },
    { 3, 3 }, { 3, 2 }, { 3, 1 }, { 3, 0 }, { 2, 0 }, { 1, 0 },
}; // it is boundary of map
std::vector<std::pair<int, int>> water{ { 1, 2 } }; // cant move to this cell
std::vector<std::pair<int, int>> grass{ { 1, 1 },
                                        { 2, 2 },
                                        { 2, 1 } }; // can move to this cell

// Tanks position
std::pair<int, int>              player_tank{ 1, 1 };
std::vector<std::pair<int, int>> bot_tanks{};

sf::Image res_image;

sf::Texture tex_water;
sf::Texture tex_grass;
sf::Texture tex_brick;
sf::Texture tex_unbreak_brick;
sf::Texture tex_tank;

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

void render_map(sf::RenderWindow* window)
{
    sf::Sprite sprite_grass(tex_grass);
    sprite_grass.setScale(config::cell_size_x / 16., config::cell_size_y / 16.);
    for (const auto& point : grass)
    {
        sprite_grass.setPosition(point.first * config::cell_size_x,
                                 point.second * config::cell_size_y);

        base::api::render_sprite(window, sprite_grass);
    }

    sf::Sprite sprite_unbreak_brick(tex_unbreak_brick);
    sprite_unbreak_brick.setScale(config::cell_size_x / 16.,
                                  config::cell_size_y / 16.);

    for (const auto& point : unbreak_bricks)
    {
        sprite_unbreak_brick.setPosition(point.first * config::cell_size_x,
                                         point.second * config::cell_size_y);

        base::api::render_sprite(window, sprite_unbreak_brick);
    }

    sf::Sprite sprite_water(tex_water);
    sprite_water.setScale(config::cell_size_x / 16., config::cell_size_y / 16.);
    for (const auto& point : water)
    {
        sprite_water.setPosition(point.first * config::cell_size_x,
                                 point.second * config::cell_size_y);

        base::api::render_sprite(window, sprite_water);
    }
}

void render_tanks(sf::RenderWindow* window)
{
    sf::Sprite sprite_tank(tex_tank);
    sprite_tank.setScale(config::cell_size_x / 11., config::cell_size_y / 16.);

    sprite_tank.setPosition(player_tank.first * config::cell_size_x,
                            player_tank.second * config::cell_size_y);

    base::api::render_sprite(window, sprite_tank);
}

int main()
{
    res_image.loadFromFile("res/res.png");

    tex_water.loadFromImage(res_image, sf::IntRect({ 0, 19 }, { 16, 16 }));
    tex_grass.loadFromImage(res_image, sf::IntRect({ 37, 0 }, { 16, 16 }));
    // tex_brick.loadFromImage(res_image, sf::IntRect({ 19, 0 }, { 16, 16 }));
    tex_unbreak_brick.loadFromImage(res_image, sf::IntRect(0, 0, 16, 16));

    tex_tank.loadFromImage(res_image, sf::IntRect(0, 93, 10, 16));

    for (const auto& brick : bricks)
    {
        bricks_state[brick] = config::brick_hp;
    }

    sf::RenderWindow window(
        sf::VideoMode(config::window_size_x, config::window_size_y),
        "Tanchiki!!!",
        0);

    while (game_state & base::game_state::is_running)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return 0;
            }
        }

        std::pair<int, int> old_player_tank{ player_tank };

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
             (sf::Keyboard::isKeyPressed(sf::Keyboard::A))))
        {
            player_tank.first--;
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
             (sf::Keyboard::isKeyPressed(sf::Keyboard::D))))
        {
            player_tank.first++;
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
             (sf::Keyboard::isKeyPressed(sf::Keyboard::W))))
        {
            player_tank.second--;
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
             (sf::Keyboard::isKeyPressed(sf::Keyboard::S))))
        {
            player_tank.second++;
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) ||
             (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))))
        {
        }
        std::cout << "Old Tank position: " << "[" << old_player_tank.first
                  << ", " << old_player_tank.second << "]" << std::endl;

        std::cout << "New Tank position: " << "[" << player_tank.first << ", "
                  << player_tank.second << "]" << std::endl;

        if (check_tanks_collision())
        {
            player_tank = old_player_tank;
        }

        window.clear(sf::Color(0, 0, 0));
        render_map(&window);
        render_tanks(&window);
        window.display();
        sf::sleep(sf::microseconds(1e6 / config::fps));
    }

    return 0;
}