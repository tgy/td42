#ifndef PLAYER_HH
# define PLAYER_HH

# include <chrono>

class Player
{
    public:
        static void init(unsigned money, unsigned life_nb,
                std::chrono::time_point<std::chrono::system_clock> s_time);
        static void add_money(unsigned money);
        static unsigned get_money();
        static unsigned get_life_nb();
        static std::chrono::time_point<std::chrono::system_clock> get_start_time();
        static bool remove_money(unsigned money);
        static bool remove_a_life(); //Returns (life_nb_ > 0) after removing a life.
    private:
        static std::chrono::time_point<std::chrono::system_clock> start_time_;
        static unsigned money_;
        static unsigned life_nb_;
};

#endif /* PLAYER_HH */
