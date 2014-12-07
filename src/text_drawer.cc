#include <string>
#include <vector>
#include <iostream>

#include "text_drawer.hh"
#include "player.hh"
#include "mouse.hh"
#include "map.hh"
#include "settings.hh"

//sf::RenderWindow window_;

void TextDrawer::display_money(sf::RenderWindow& w)
{
    sf::Font f;
    f.loadFromFile("resources/GoodDog.otf");

    sf::Text text;
    text.setFont(f);
    text.setPosition(50, 0);
    text.setCharacterSize(24);
    text.setColor(sf::Color::Yellow);
    text.setString(std::to_string(Player::get_money()));

    w.draw(text);
}

void TextDrawer::display_lifes(sf::RenderWindow& w)
{
    sf::Font f;
    f.loadFromFile("resources/GoodDog.otf");

    sf::Text text;
    text.setFont(f);
    text.setPosition(0, 0);
    text.setCharacterSize(24);
    text.setColor(sf::Color::Red);
    text.setString(std::to_string(Player::get_life_nb()));

    w.draw(text);
}

void TextDrawer::display_time(sf::RenderWindow& w)
{
    sf::Font f;
    f.loadFromFile("resources/GoodDog.otf");

    sf::Text text;
    text.setFont(f);
    text.setPosition(100, 0);
    text.setCharacterSize(24);
    text.setColor(sf::Color::Green);
    std::chrono::duration<double> elapsed = std::chrono::system_clock::now() -
                                            Player::get_start_time();
    int seconds = elapsed.count();
    text.setString(std::to_string(seconds));

    w.draw(text);
}

void TextDrawer::display_lost(sf::RenderWindow& w)
{
    sf::Font f;
    f.loadFromFile("resources/GoodDog.otf");

    sf::Text text;
    text.setFont(f);
    text.setPosition(Settings::screen_width / 2 - 50,
                     Settings::screen_height / 2);
    text.setCharacterSize(40);
    text.setColor(sf::Color::Red);
    text.setString("You lost!");

    w.draw(text);
}

void TextDrawer::display_win(sf::RenderWindow& w)
{
    sf::Font f;
    f.loadFromFile("resources/GoodDog.otf");

    sf::Text text;
    text.setFont(f);
    text.setPosition(Settings::screen_width / 2 - 50,
                     Settings::screen_height / 2);
    text.setCharacterSize(40);
    text.setColor(sf::Color::Yellow);
    text.setString("You won!");

    w.draw(text);
}

void TextDrawer::display_restart(sf::RenderWindow& w)
{
    sf::Font f;
    f.loadFromFile("resources/GoodDog.otf");

    sf::Text text;
    text.setFont(f);
    text.setPosition(Settings::screen_width / 2 - 175,
                     Settings::screen_height / 2 + 100);
    text.setCharacterSize(40);
    text.setColor(sf::Color::Blue);
    text.setString("== Press 'enter' to restart ==");

    w.draw(text);
}

void TextDrawer::display_mouse_coords(sf::RenderWindow& w)
{
    sf::Font f;
    f.loadFromFile("resources/arial.ttf");

    sf::Text text;
    text.setFont(f);
    text.setCharacterSize(17);
    text.setColor(sf::Color::Blue);
    text.setPosition(Settings::screen_width - 250, 0);

    if (Mouse::is_cursor_in_bound(w))
    {
        std::pair<int, int> p = Mouse::get_mouse_pos(w);
        text.setString("(" + std::to_string(p.first) +
                "; " + std::to_string(p.second) + ")");
    }
    else
        text.setString("Out of bounds!");

    w.draw(text);
}

void TextDrawer::display_mouse_coords_on_map(sf::RenderWindow& w)
{
    sf::Font f;
    f.loadFromFile("resources/arial.ttf");

    sf::Text text;
    text.setFont(f);
    text.setCharacterSize(17);
    text.setColor(sf::Color::Cyan);
    text.setPosition(Settings::screen_width - 125, 0);

    if (Mouse::is_cursor_in_bound(w))
    {
        unsigned pos_x;
        unsigned pos_y;
        std::pair<int, int> p = Mouse::get_mouse_pos(w);
        Map::screen_to_map(p.first, p.second, pos_x, pos_y);
        text.setString("(" + std::to_string(pos_x) +
                "; " + std::to_string(pos_y) + ")");
    }
    else
        text.setString("Out of bounds!");

    w.draw(text);
}
