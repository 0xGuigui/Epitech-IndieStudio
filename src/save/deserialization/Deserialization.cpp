/*
** EPITECH PROJECT, 2022
** Game.hpp
** File description:
** deserialization.cpp
*/

#include "../../../include/save/Deserialization.hpp"

void bmb::Deserialization::fileReader() {
    std::string output("");

    std::ifstream file_input("./save/data/save.save");
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
    static_cast<bmb::headerSave>(header);
    this->headerSave = header;
    temp = strtok(this->input, "\n");
    static_cast<bmb::mapSave>(temp);
    this->mapSave = temp;
    static_cast<string> temp;
    temp = "";
    for (int i = 0; i < this->headerSave.playerNumber; i++) {
        temp = strtok(this->input, "\n");
        static_cast<bmb::playerSave>(temp);
        this->playerSaveArray.push_back(temp);
        static_cast<string> temp;
        temp = "";
    }
    for (int i = 0; i < this->headerSave.bombNumber; i++) {
        temp = strtok(this->input, "\n");
        static_cast<bmb::bombSave>(temp);
        this->bombSaveArray.push_back(temp);
        static_cast<string> temp;
        temp = "";
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