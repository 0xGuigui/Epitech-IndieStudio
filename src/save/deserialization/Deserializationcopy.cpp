/*
** EPITECH PROJECT, 2022
** Game.hpp
** File description:
** deserialization.cpp
*/

#include "../../../include/save/Deserializationcopy.hpp"

void bmb::Deserialization::fileReader() {
    std::string output("");

    std::ifstream file_input("save.save");
    if (!file_input.is_open())
        return;
    while (getline(file_input, output));
    this->input = (char*)&output;
    file_input.close();
}

void bmb::Deserialization::setSaveData() {
    char *header;
    char *temp;

    header = strtok(this->input, "\n");
    this->headerSave = (*reinterpret_cast<bmb::headerSave_t*>(header));
    temp = strtok(this->input, "\n");
    this->mapSave = (*reinterpret_cast<bmb::mapSave_t*>(temp));
    for (int i = 0; i < this->headerSave.playerNumber; i++) {
        temp = strtok(this->input, "\n");
        this->playerSaveArray.push_back((*reinterpret_cast<bmb::playerSave_t*>(temp)));
    }
    for (int i = 0; i < this->headerSave.bombNumber; i++) {
        temp = strtok(this->input, "\n");
        this->bombSaveArray.push_back((*reinterpret_cast<bmb::bombSave_t*>(temp)));
    }
}

std::vector<bmb::playerSave_t> bmb::Deserialization::getPlayerSaveArray() {
    return this->playerSaveArray;
}

std::vector<bmb::bombSave_t> bmb::Deserialization::getBombSaveArray() {
    return this->bombSaveArray;
}

bmb::mapSave_t bmb::Deserialization::getMapSave() {
    return this->mapSave;
}

bmb::Deserialization::Deserialization() {

}

bmb::Deserialization::~Deserialization() {
}