#include <string>
#include <vector>
#include <iostream>

#include "text_drawer.hh"
#include "player.hh"
#include "mouse.hh"
#include "map.hh"
#include "settings.hh"

sf::RenderWindow window_;

void TextDrawer::display_money(sf::RenderWindow& w)
{
    sf::Text text;

    //sf::Font f;
    //f.loadFromFile("resources/GoodDog.otf");
    //text.setFont();

    text.setString(std::to_string(Player::get_money()));
    sf::Font f;
    f.loadFromFile("resources/GoodDog.otf");
    text.setFont(f);
    text.setPosition(50, 0);

    text.setCharacterSize(24);

    text.setColor(sf::Color::Yellow);

    //text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    w.draw(text);
}

void TextDrawer::display_lifes(sf::RenderWindow& w)
{
    sf::Text text;

    //sf::Font f;
    //f.loadFromFile("resources/GoodDog.otf");
    //text.setFont();

    sf::Font f;
    f.loadFromFile("resources/GoodDog.otf");
    text.setFont(f);
    text.setString(std::to_string(Player::get_life_nb()));
    text.setPosition(0, 0);

    text.setCharacterSize(24);

    text.setColor(sf::Color::Red);

    //text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    w.draw(text);
}

void TextDrawer::display_time(sf::RenderWindow& w)
{
    sf::Text text;

    //sf::Font f;
    //f.loadFromFile("resources/GoodDog.otf");
    //text.setFont();

    std::chrono::duration<double> elapsed = std::chrono::system_clock::now() -
                                            Player::get_start_time();
    int seconds = elapsed.count();
    text.setString(std::to_string(seconds));
    sf::Font f;
    f.loadFromFile("resources/GoodDog.otf");
    text.setFont(f);
    text.setPosition(100, 0);

    text.setCharacterSize(24);

    text.setColor(sf::Color::Green);

    //text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    w.draw(text);
}

void TextDrawer::display_mouse_coords(sf::RenderWindow& w)
{
    sf::Text text;

    //sf::Font f;
    //f.loadFromFile("resources/GoodDog.otf");
    //text.setFont();
    std::pair<int, int> p = Mouse::get_mous_pos(w);
    text.setString("(" + std::to_string(p.first) +
                   "; \t" + std::to_string(p.second) + ")");
    sf::Font f;
    f.loadFromFile("resources/arial.ttf");
    text.setFont(f);
    text.setPosition(Settings::screen_width - 200, 0);

    text.setCharacterSize(17);

    text.setColor(sf::Color::Blue);

    //text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    w.draw(text);
}

void TextDrawer::display_mouse_coords_on_map(sf::RenderWindow& w)
{
    std::pair<int, int> p = Mouse::get_mous_pos(w);
    unsigned pos_x;
    unsigned pos_y;
    Map::screen_to_map(p.first, p.second, pos_x, pos_y);
    sf::Text text;
    text.setString("(" + std::to_string(pos_x) +
                   "; \t" + std::to_string(pos_y) + ")");
    sf::Font f;
    f.loadFromFile("resources/arial.ttf");
    text.setFont(f);
    text.setPosition(Settings::screen_width - 100, 0);

    text.setCharacterSize(17);

    text.setColor(sf::Color::Cyan);

    //text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    w.draw(text);
}
