#ifndef ENTITY_HH
# define ENTITY_HH

class Entity
{
  public:
    Entity(unsigned life, float x, float y, float direction, unsigned power,
           float range, unsigned fixed_res = 0);
    virtual ~Entity() = default;

    float get_x();
    float get_y();
    float get_direction();
    float get_range();
    unsigned get_life();
    unsigned get_life_max();
    unsigned get_power();

  protected:
    unsigned life_;
    unsigned life_max_;
    unsigned fixed_res_;
    unsigned power_;
    float x_;
    float y_;
    float direction_;
    float range_;
};

#endif /* !ENTITY_HH */
