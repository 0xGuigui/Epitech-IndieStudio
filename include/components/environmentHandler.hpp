/*
** EPITECH PROJECT, 2022
** environementHandler.hpp
** File description:
** Handle the environment
*/

#pragma once

#include "encapsulation/model.hpp"
#include "vector"
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

class EnvironmentHandler {
private:
    std::vector<Model> _models;

public:
    EnvironmentHandler() = default;

    ~EnvironmentHandler() = default;

    std::string& ltrim(std::string &s);

    /*
     * Parse and alloc ressources for data
     */
    void parseHeader(std::string &header);

    /*
     * Add new bloc
     */
    void parseLine(std::string &line);

    /*
     * Open and parse config file for environment
     */
    void init(const std::string &configPath = "data/environment.indie");

    /*
     * Draw all blocks in the world
     */
    void draw();
};
