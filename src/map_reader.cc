#include <fstream>
#include <string>
#include <iostream>
#include <cassert>

#include "map_reader.hh"
#include "map.hh"

#define START 'S'
#define TOWER 'T'
#define EMPTY 'E'
#define FINNISH 'F'
#define OBSTACLE 'O'
#define B_OBSTACLE 'B'

bool MapReader::set_size(std::string file)
{
    std::string line;
    std::ifstream mapfile(file);
    if (!mapfile.is_open())
    {
        std::cerr << "Error: Could not open file '" << file << "'." << std::endl;
        return false;
    }
    unsigned y = 0;
    getline(mapfile, line);
    Map::width = line.length();
    while (getline(mapfile, line))
        y++;
    Map::height = y + 1;
    //std::cout << "w:" << Map::width << ", h:" << Map::height << std::endl;
    mapfile.close();
    return true;
}

bool MapReader::read_map(std::string file)
{
    std::string line;
    std::ifstream mapfile(file);
    if (mapfile.is_open())
    {
        unsigned x;
        unsigned y = 0;
        while (getline(mapfile, line))
        {
            x = 0;
            for (char& c : line)
            {
                switch (c)
                {
                    case START:
                        Map::cells[x][y].type = Empty;
                        Map::start_mobs.first = x;
                        Map::start_mobs.second = y;
                        break;
                    case TOWER:
                        Map::cells[x][y].type = Tower;
                        break;
                    case EMPTY:
                        Map::cells[x][y].type = Empty; //TODO:Invalid read/write
                        break;
                    case FINNISH:
                        Map::cells[x][y].type = Empty;
                        Map::finish_mobs.first = x;
                        Map::finish_mobs.second = y;
                        break;
                    case OBSTACLE:
                        Map::cells[x][y].type = Obstacle;
                        break;
                    case B_OBSTACLE:
                        Map::cells[x][y].type = Blocking_obstacle;
                        break;
                }
                x++;
            }
            y++;
        }
        Map::width = x;
        Map::height = y;
        mapfile.close();
        return true;
    }
    else
        return false;
}
