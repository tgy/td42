#ifndef ENDSTATE_HH
# define ENDSTATE_HH
# include "gamestate.hh"

class EndState : public GameState
{
    public:
        EndState();
        virtual ~EndState() = default;
        void draw(sf::RenderWindow& w);
        void update(unsigned elapsed_ms);
    private:
};

#endif /* !ENDSTATE_HH */
