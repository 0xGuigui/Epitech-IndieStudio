/*
** EPITECH PROJECT, 2022
** music.hpp
** File description:
** include
*/

#pragma once
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <time.h>
#include <uuid/uuid.h>

namespace bmb {
    //-Nothing: no bonus, no softblock
    //-Block: can't be switched with softblock
    //-Softblock: can be switched with Bonus
    enum Block {
        NOTHING,
        BLOCK,
        PLAYER,
        SOFTBLOCK
    };

    //-Wallpass: Player pass through soft blocks
    //-Bombup: Increase bomb number that a PLayer can push
    //-Fireup: Increase fire size when a bomb explode
    //-Speedup: Increase Player speed
    enum Bonus {
        WALLPASS,
        BOMBUP,
        FIREUP,
        SPEEDUP
    };

    //Soft block state when map need to be modified and regenerated
    enum State {
        EXPLODED, //become bonus
        EATEN //become nothing
    };

    class Map {
    private:
        std::string _buffer;
        std::vector<std::string> _mapLayout;
        std::string _path;
        time_t _time;
        int _rand;

    protected:
        std::vector<std::vector<int>> generatedMap;

    public:
        Map();
        ~Map() {};
        std::vector<std::vector<int>> getMap();
        void setMapObstacle();
        void setMap(int x, int y, bmb::State state);

    private:
        void _readMapLayout();
        int _getRandomNumber();
        void charMapToIntMap();
        int _uuid();
    };
}


//Fst, second, last, previous last lines only hard block,
//other line between 0-20% block(s), in these blocks between 0-50% softblock, then 25% chances to be a bonus