#ifndef MENUSTATE_HH
# define MENUSTATE_HH
# include "gamestate.hh"

class MenuState : public GameState
{
  public:
    MenuState();
    virtual ~MenuState() = default;
    void draw(sf::RenderWindow& w);
    void update(unsigned elapsed_ms);
  protected:
};

#endif /* !MENUSTATE_HH */
