#ifndef PLAYSTATE_HH
# define PLAYSTATE_HH
# include "gamestate.hh"
# include "turret.hh"

class PlayState : public GameState
{
    public:
        PlayState(std::string map);
        virtual ~PlayState() = default;
        void draw(sf::RenderWindow& w);
        void update(unsigned elapsed_ms);
    protected:
};

#endif /* !PLAYSTATE_HH */
