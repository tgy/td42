#ifndef PLAYSTATE_HH
# define PLAYSTATE_HH
# include "gamestate.hh"

class PlayState : public GameState
{
  public:
    PlayState();
    virtual ~PlayState() = default;
    void draw(sf::RenderWindow& w);
    void update(unsigned elapsed_ms);
  protected:
};

#endif /* !PLAYSTATE_HH */
