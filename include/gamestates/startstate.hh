#ifndef STARTSTATE_HH
# define STARTSTATE_HH
# include "gamestate.hh"

class StartState : public GameState
{
    public:
        StartState();
        virtual ~StartState() = default;
        void draw(sf::RenderWindow& w);
        void update(unsigned elapsed_ms);
    protected:
        sf::Texture logo_;
        sf::Sprite logo_sprite_;
        float logo_step_;
        float logo_size_;
        float logo_final_size_;
        float logo_x_;
        float logo_y_;
        int wait_time_;
};

#endif /* !STARTSTATE_HH */
