#ifndef GAMESTATE_HH
# define GAMESTATE_HH
# include <list>
# include <memory>
# include <SFML/Graphics.hpp>

class GameState
{
    public:
        virtual void draw(sf::RenderWindow& w) = 0;
        virtual void update(unsigned elapsed_ms) = 0;
        static std::list<std::shared_ptr<GameState>> stack;
};

#endif /* !GAMESTATE_HH */
