#include <stdexcept>
#include <memory>
#include <cmath>
#include <cassert>
#include <iostream>

#include "gamestates/playstate.hh"
#include "gamestates/endstate.hh"
#include "settings.hh"
#include "map_reader.hh"
#include "player.hh"
#include "mouse.hh"
#include "map.hh"
#include "text_drawer.hh"
#include "turrets/basic.hh"
#include "turrets/sniper.hh"
#include "turrets/super.hh"
#include "mobs/foot_soldier.hh"
#include "mobs/horse_soldier.hh"
#include "mobs/tank_soldier.hh"
#include "pathfinding.hh"

PlayState::PlayState(std::string map)
         : turret_{nullptr}
{
    if (!MapReader::set_size(map))
        throw std::logic_error("Could not load map '" + map + "'.");
    Map::init();
    Map::init_draw(100, 100);
    Map::init_draw(0, 50);
    if (!MapReader::read_map(map))
        throw std::logic_error("Error reading map '" + map + "'.");
    Player::init(500, 10, std::chrono::system_clock::now());
    this->levels.push_back(Level("resources/levels/1.td42"));
    this->levels.push_back(Level("resources/levels/2.td42"));
    this->levels.push_back(Level("resources/levels/3.td42"));
    this->levels.push_back(Level("resources/levels/4.td42"));
    this->levels.push_back(Level("resources/levels/5.td42"));
    ms_before_next_level = 100;
    ms_before_next_mob = TIME_BETWEEN_MOBS;
}

void PlayState::insert_mode(std::shared_ptr<Turret> t)
{
    turret_ = t;
    t->set_opacity(100);
}

void PlayState::exit_insert_mode()
{
    turret_ = nullptr;
    ms_before_next_level = 100;
}

void PlayState::exit_insert_mode_and_create()
{
    if (turret_ != nullptr)
    {
        if (!Player::remove_money(turret_->get_cost()))
        {
            turret_ = nullptr;
            return;
        }
        auto pos = turret_->get_pos();
        if (pos.first < 0 || pos.first >= Map::width || pos.second < 0
                || pos.second >= Map::height
                || Map::cells[pos.first][pos.second].type != CellType::Empty)
        {
            turret_ = nullptr;
            return;
        }
        Map::cells[pos.first][pos.second].type = CellType::Tower;
        turret_->set_opacity(255);
        Map::turrets.push_front(turret_);
        turret_ = nullptr;
        for (auto& enemy : Map::ennemies)
            enemy->update_pathfinding();
    }
}

void PlayState::draw(sf::RenderWindow& w)
{
    if (turret_ != nullptr)
    {
        auto pos = Mouse::get_mouse_pos(w);
        unsigned px;
        unsigned py;
        Map::screen_to_map(pos.first, pos.second, px, py);
        turret_->set_pos(px, py);
    }
    Map::draw(w, turret_);
    TextDrawer::display_time(w);
    TextDrawer::display_lifes(w);
    TextDrawer::display_money(w);
    TextDrawer::display_mouse_coords(w);
    TextDrawer::display_mouse_coords_on_map(w);
}

bool is_arrived(float x1, float x2, float y1, float y2)
{
    int ix1 = x1;
    int ix2 = x2;
    int iy1 = y1;
    int iy2 = y2;
    if (ix1 == ix2 && iy1 == iy2)
        return true;
    float dx = fabs(x1 - x2);
    float dy = fabs(y1 - y2);
    return dx < 0.2f && dy < 0.2f;
}

void PlayState::update(unsigned elapsed_ms)
{
    if (this->levels.size() == 0)
    {
        GameState::stack.pop_back();
        auto ptr = std::make_shared<EndState>();
        GameState::stack.push_back(ptr);
    }
    else if (ms_before_next_level <= 0)
    {
        if (ms_before_next_mob <= 0)
        {
            if (!this->levels.front().make_mob())
            {
                std::cout << "NEW LEVEL" << std::endl;
                this->levels.pop_front();
                ms_before_next_level = TIME_BETWEEN_LEVELS;
            }
            else
                ms_before_next_mob = TIME_BETWEEN_MOBS;
        }
        else
            ms_before_next_mob -= elapsed_ms;
    }
    else
        ms_before_next_level -= elapsed_ms;
    for (std::list<std::shared_ptr<Mob>>::iterator i = Map::ennemies.begin();
            i != Map::ennemies.end();)
    {
        if ((*i)->dead())
            i = Map::ennemies.erase(i);
        else
        {
            (*i)->move();
            auto pos = (*i)->get_pos();
            if (is_arrived(pos.first, Map::finish_mobs.first,
                           pos.second, Map::finish_mobs.second))
            {
                std::cout << "xd" << std::endl;
                (*i)->harakiri();
                if (!Player::remove_a_life())
                {
                    GameState::stack.pop_back();
                    auto ptr = std::make_shared<EndState>();
                    GameState::stack.push_back(ptr);
                }
                i = Map::ennemies.erase(i);
            }
            else
                ++i;
        }
    }
    for (std::shared_ptr<Turret> turret : Map::turrets)
        turret->attack(elapsed_ms);
    ++elapsed_ms;
}
