#ifndef PLAYSTATE_HH
# define PLAYSTATE_HH
# include <memory>
# include <list>

# include "level.hh"
# include "gamestate.hh"
# include "turret.hh"

# define TIME_BETWEEN_MOBS 200
# define TIME_BETWEEN_LEVELS 100000

class PlayState : public GameState
{
    public:
        PlayState(std::string map);
        virtual ~PlayState() = default;
        void draw(sf::RenderWindow& w);
        void update(unsigned elapsed_ms);

        std::list<Level> levels;
        long ms_before_next_level;
        long ms_before_next_mob;
        void insert_mode(std::shared_ptr<Turret> t);
        void exit_insert_mode();
        void exit_insert_mode_and_create();
    protected:
        std::shared_ptr<Turret> turret_;
};

#endif /* !PLAYSTATE_HH */
