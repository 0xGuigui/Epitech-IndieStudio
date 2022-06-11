/*
** EPITECH PROJECT, 2022
** environementHandler.hpp
** File description:
** Handle the environment
*/

#include "components/environmentHandler.hpp"

std::string &EnvironmentHandler::ltrim(std::string &s) {
    auto it = std::find_if(s.begin(), s.end(),
                           [](char c) {
                               return !std::isspace<char>(c, std::locale::classic());
                           });
    s.erase(s.begin(), it);
    return s;
}

void EnvironmentHandler::init(const std::string &configPath) {
    std::fstream file(configPath);

    if (!file.is_open())
        throw std::runtime_error("Can't open file " + configPath);
}

void EnvironmentHandler::parseHeader(std::string &header) {

}

void EnvironmentHandler::parseLine(std::string &line) {

}

void EnvironmentHandler::draw() {

}
