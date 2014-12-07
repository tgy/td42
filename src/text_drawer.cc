#include <string>
#include <iostream>

#include "text_drawer.hh"
#include "player.hh"

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
    text.setPosition(142, 666);

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
    //std::cout << elapsed.count() << std::endl;
    text.setString(std::to_string(elapsed.count()));
    sf::Font f;
    f.loadFromFile("resources/GoodDog.otf");
    text.setFont(f);
    text.setPosition(100, 0);

    text.setCharacterSize(24);

    text.setColor(sf::Color::Blue);

    //text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    w.draw(text);
}
