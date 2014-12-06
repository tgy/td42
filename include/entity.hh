#ifndef ENTITY_HH
# define ENTITY_HH

class Entity
{
  public:
    Entity(unsigned life, float x, float y, float direction);
    virtual ~Entity() = default;
    float get_x();
    float get_y();
    float get_direction();
    unsigned get_life();
    unsigned get_life_max();
    void set_life(unsigned life);
  protected:
    unsigned life_;
    unsigned life_max_;
    float x_;
    float y_;
    float direction_;
};

#endif /* !ENTITY_HH */
