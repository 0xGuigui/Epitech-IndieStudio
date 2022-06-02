/*
** EPITECH PROJECT, 2022
** music.hpp
** File description:
** include
*/

#include "../include/Map.hpp"

bmb::Map::Map()
{
    this->_buffer = "";
    this->_mapLayout = {{}};
    this->_path = "src/map/map.map";
    this->_rand = 0;
    this->generatedMap = {{}};
}

std::vector<std::vector<int>> bmb::Map::getMap()
{
    return (this->generatedMap);
}

void bmb::Map::setMap(int x, int y, bmb::State state)
{
    if (this->generatedMap[y][x] == SOFTBLOCK) {}
        //generate random bonus
}

void bmb::Map::_readMapLayout()
{
    std::ifstream file(this->_path);

    if (!file.is_open()) {
        std::cerr << "'" << this->_path << "': cannot open file" << std::endl;
        exit(84);
    }

    while (getline(file, this->_buffer)) {
        std::string temp;
        std::stringstream stream(this->_buffer);
        while (stream >> temp)
            this->_mapLayout.push_back(temp);
    }

    file.close();

    if (this->_mapLayout.empty()) {
        std::cerr << "empty file" << std::endl;
        exit(84);
    }
    _mapLayout.erase(_mapLayout.begin());
}

void bmb::Map::charMapToIntMap()
{
    int i = 0;

    for (auto it = this->_mapLayout.begin(); it != this->_mapLayout.end(); it++, i++) {
        this->generatedMap.push_back({});
        for (auto itt = it->begin(); itt != (*it).end(); itt++)
            this->generatedMap[i].push_back(static_cast<int>(*itt) - 48);
    }
}

void bmb::Map::setMapObstacle()
{
    //fst generate hardblocks
    //snd generate softblocks
    this->_readMapLayout();
    this->charMapToIntMap();
    if (this->_mapLayout.size() < 4)
        return;
    for (int i = 2; i < this->_mapLayout.size() - 2; i++) {
        int hardblockQuantity = this->_getRandomNumber();
        int softblockQuantity = hardblockQuantity / 4;
        hardblockQuantity /= 2;
        for (int j = 0; j < hardblockQuantity; j++) {
            int hardblock = this->_getRandomNumber() + 2;
            if (hardblock < this->_mapLayout[i].length() - 2)
                this->generatedMap[i][hardblock] = bmb::Block::BLOCK;
        }
        for (int j = 0; j < softblockQuantity; j++) {
            int softblock = this->_getRandomNumber() + 2;
            if (softblock < this->_mapLayout[i].length() - 2 && this->generatedMap[i][softblock] == bmb::Block::NOTHING)
                this->generatedMap[i][softblock] = bmb::Block::SOFTBLOCK;
        }
    }
    for (std::vector<int> &vec : this->generatedMap) {
        //int obstacle = this->_getRandomNumber() + 2;
        for (int i : vec)
            std::cout << i;
        std::cout << std::endl;
    }
}

int bmb::Map::_getRandomNumber()
{
    srand(this->_uuid());
    return rand() % this->_mapLayout[0].length();
}

int bmb::Map::_uuid()
{
    uuid_t out;

    uuid_generate_random(out);
    return (out[0]);
}