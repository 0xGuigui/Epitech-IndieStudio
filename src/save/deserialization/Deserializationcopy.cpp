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

    //header = strtok(this->input, "\n");
    header = this->input.substr(0, sizeof(bmb::headerSave_t));
    this->input.erase(0, sizeof(bmb::headerSave_t));
    this->headerSave = (*reinterpret_cast<bmb::headerSave_t*>(header));
    //temp = strtok(this->input, "\n");
    for (int i = 0; i < this->headerSave.sizeOfMap; i++) {
        temp = this->input.substr(0, sizeof(IndieVector3));
        this->desMap.push_back(temp);
        this->input.erase(0, sizeof(IndieVector3));
    }
    for (int i = 0; i < this->headerSave.sizeOfBonus; i++) {
        temp = this->input.substr(0, sizeof(IndiePowerUp));
        this->desMap.push_back(temp);
        this->input.erase(0, sizeof(IndiePowerUp));
    }
    this->mapSave = (*reinterpret_cast<bmb::mapSave_t*>(temp));
    for (int i = 0; i < this->headerSave.playerNumber; i++) {
        //temp = strtok(this->input, "\n");
        temp = this->input.substr(0, sizeof(bmb::playerSave_t));
        this->input.erase(0, sizeof(bmb::playerSave_t));
        this->playerSaveArray.push_back((*reinterpret_cast<bmb::playerSave_t*>(temp)));
    }
    for (int i = 0; i < this->headerSave.bombNumber; i++) {
        //temp = strtok(this->input, "\n");
        temp = this->input.substr(0, sizeof(bmb::bombSave_t));
        this->input.erase(0, sizeof(bmb::bombSave_t));
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