/*
** EPITECH PROJECT, 2022
** Game.hpp
** File description:
** serialization.cpp
*/

#include "../../../include/save/Serializationcopy.hpp"

void bmb::Serialization::fileWriter() {
    std::ofstream saveOut("save.save", std::ios::binary);
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

void bmb::Serialization::setSaveData(std::vector<bmb::IndieBomb> bombArray, std::vector<bmb::Player> playerArray, std::vector<IndieVector3> destructibleObstacleArray, std::vector<IndiePowerUp> bonusArray) {
    int i = 0;
    for (auto it = bombArray.begin(); it != bombArray.end(); it++, i++);
    this->headerSave.bombNumber = i;
    this->headerSave.sizeOfMap = destructibleObstacleArray.size();
    this->headerSave.sizeOfBonus = bombArray.size();
    i = 0;
    for (auto it = playerArray.begin(); it != playerArray.end(); it++, i++);
    this->headerSave.playerNumber = i;
    this->headerSave.mapNumber = 1;
    this->mapSave.map = destructibleObstacleArray;
    this->mapSave.bonus = bonusArray;

    for (auto it = playerArray.begin(); it != playerArray.end(); it++) {
        this->playerSave.position = it->getPosition();
        this->playerSave.color = it->getColor();
        this->playerSave.fireUp = it->getForce();
        this->playerSave.speedUp = it->getSpeed();
        this->playerSave.wallPass = it->getGhost();
        this->playerSave.bombUp = it->getBombLeft();
        this->bombSaveArray.push_back(bombSave);
    }
    for (auto it = bombArray.begin(); it != bombArray.end(); it++) {
        this->bombSave.position = it->getPosition();
        this->bombSave.frame = it->getFrame();
        this->bombSave.color = it->getColor();
        this->bombSaveArray.push_back(bombSave);
    }
}

bmb::Serialization::Serialization() {

}

bmb::Serialization::~Serialization() {

}
