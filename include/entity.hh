#ifndef ENTITY_HH
# define ENTITY_HH

class Entity
{
  public:
    float get_x();
    float get_y();
    float get_direction();
  private:
    float x_;
    float y_;
    float direction_;
};

#endif /* !ENTITY_HH */
