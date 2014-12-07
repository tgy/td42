#include <algorithm>
#include <fstream>

#include "level.hh"
#include "mobs/foot_soldier.hh"
#include "mobs/horse_soldier.hh"
#include "mobs/tank_soldier.hh"
#include "map.hh"

Level::Level()
{
    this->series_ = "11111222122212331123";
}

Level::Level(std::string path)
{
    std::ifstream infile(path);
    if (infile.fail())
        this->series_ = "1122132233232223333311233";
    else
    {
        std::string lol;
        std::getline(infile, lol);
        this->series_ = lol;
    }
}

bool Level::make_mob()
{
    if (this->series_.length() == 0)
        return false;

    if (Map::at(Map::finish_mobs).type != CellType::Empty)
        return true;

    char c = this->series_[0];

    switch (c)
    {
        case '1':
            Map::ennemies.push_back(std::make_shared<FootSoldier>(
                Map::start_mobs.first, Map::start_mobs.second));
            break;
        case '2':
            Map::ennemies.push_back(std::make_shared<HorseSoldier>(
                Map::start_mobs.first, Map::start_mobs.second));
            break;
        case '3':
            Map::ennemies.push_back(std::make_shared<TankSoldier>(
                Map::start_mobs.first, Map::start_mobs.second));
            break;
        default:
            break;
    }

    this->series_.erase(0, 1);

    return true;
}
