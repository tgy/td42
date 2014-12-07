#ifndef PLAYSTATE_HH
# define PLAYSTATE_HH
# include <memory>
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
        std::shared_ptr<Turret> turret_;
        void insert_mode(std::shared_ptr<Turret> t);
        void exit_insert_mode();
        void exit_insert_mode_and_create();
};

#endif /* !PLAYSTATE_HH */
