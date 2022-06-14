/*
** EPITECH PROJECT, 2022
** Game.hpp
** File description:
** serialization.cpp
*/

#include "../../../include/save/Serialization.hpp"

void bmb::Serialization::fileWriter() {
    std::ofstream saveOut("./save/data/save.save", std::ios::binary);
    saveOut.write((char*)&this->headerSave, sizeof(this->headerSave));
    saveOut.write("\n", sizeof(char));
    saveOut.write((char*)&this->mapSave, sizeof(this->mapSave));
    saveOut.write("\n", sizeof(char));
    for (auto it = this->playerSaveArray.begin(); it != this->playerSaveArray.end(); it++) {
        saveOut.write((char*)&it, sizeof(it));
        saveOut.write("\n", sizeof(char));
    }
    for (auto it = this->bombSaveArray.begin(); it != this->bombSaveArray.end(); it++) {
        saveOut.write((char*)&it, sizeof(it));
        saveOut.write("\n", sizeof(char));
    }
    saveOut.close();
}

void bmb::Serialization::setSaveData(std::vector<bmb::IndieBomb> bombArray, std::vector<bmb::Player> playerArray, std::vector<IndieVector3> destructibleObstacleArray, std::vector<IndieVector3> bonusArray) {
    int i = 0;
    for (auto it = bombArray.begin(); it != bombArray.end(); it++, i++);
    this->headerSave.bombNumber = i;
    i = 0;
    for (auto it = playerArray.begin(); it != playerArray.end(); it++, i++);
    this->headerSave.playerNumber = i;
    this->headerSave.mapNumber = 1;
    this->mapSave.map = destructibleObstacleArray;
    this->mapSave.bonus = bonusArray;

    for (auto it = playerArray.begin(); it != playerArray.end(); it++) {
        this->playerSave.position = it->getPlayerPosition();
        this->playerSave.color = it->getPlayerColor();
        this->playerSave.fireUp = it->getForceBonus();
        this->playerSave.speedUp = it->getSpeedBonus();
        this->playerSave.wallPass = it->getGhostBonus();
        this->playerSave.bombUp = it->getForceBonus();
        this->bombSaveArray.push_back(bombSave);
    }
    for (auto it = bombArray.begin(); it != bombArray.end(); it++) {
        this->bombSave.position = it->getBombPosition();
        this->bombSave.frame = it->getFrame();
        this->bombSave.color = it->getBombColor();
        this->bombSaveArray.push_back(bombSave);
    }
}

bmb::Serialization::Serialization() {

}

bmb::Serialization::~Serialization() {

}
