//#include <iostream>
#include <fstream>

#include "map_reader.hh"

bool MapReader::read_map(std::string file)
{
  std::string line;
  std::ifstream mapfile(file);
  if (mapfile.is_open())
  {
    getline(mapfile, line);
    //width_ = line.length();
    //height_ = 0;
    while (getline(mapfile, line))
    {
      //height_++;
      for (std::string::iterator it=line.begin(); it!=line.end(); it++)
      {

      }
    }
    mapfile.close();
    return true;
  }
  else
  {
    //std::cerr << "Could not open file '" << file << "'." << std::endl;
    return false;
  }
}
