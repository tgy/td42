#ifndef PLAYER_HH
# define PLAYER_HH

class Player
{
  public:
    Player(unsigned money, unsigned life_nb);
    void add_money(unsigned money);
    bool remove_money(unsigned money);
    bool remove_a_life(); //Returns (life_nb_ > 0) after removing a life.
  private:
    unsigned money_;
    unsigned life_nb_;
};

#endif /* PLAYER_HH */
