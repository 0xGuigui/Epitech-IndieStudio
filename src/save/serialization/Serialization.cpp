/*
** EPITECH PROJECT, 2022
** Game.hpp
** File description:
** serialization.cpp
*/

#include "save/Serialization.hpp"

void bmb::Serialization::fileWriter() {
    ofstream saveOut;

    saveOut.open("./save/data/save.save", std::ios::out|std::ios::app);

    saveOut << static_cast<string>(this->headerSave) << endl;
    saveOut << "\n" << endl;
    saveOut << static_cast<string>(this->mapSave) << endl;
    saveOut << "\n" << endl;
    for (it = this->mapSave.begin(); it != this->mapSave.end(); it++, i++) {
        saveOut << static_cast<string>(*it) << endl;
        saveOut << "\n" << endl;

    }
    for (it = this->bombSaveArray.begin(); it != this->bombSaveArray.end(); it++, i++) {
        saveOut << static_cast<string>(*it) << endl;
        saveOut << "\n" << endl;
    }
    saveOut << "\n" << endl;
    saveOut.close();
}

void bmb::Serialization::setSaveData(std::vector<bmb::IndieBomb> bombArray, std::vector<bmb::Player> playerArray, std::vector<IndieVector3> destructibleObstacleArray, std::vector<IndieVector3> bonusArray) {
    int i = 0;
    headerSave_t header;
    for (it = bombArray.begin(); it != bombArray.end(); it++, i++);
    header.bombNumber = i;
    i = 0;
    for (it = playerArray.begin(); it != playerArray.end(); it++, i++);
    header.playerNumber = i;
    header.mapNumber = 1;
    bmb::mapSave_t mapSave;
    mapSave.map = destructibleObstacleArray;
    mapSave.bonus = bonusArray;
    this->mapSave = mapSave;

    for (it = playerArray.begin(); it != playerArray.end(); it++, i++) {
        bmb::playerSave_t playerSave;
        playerSave.position = it.getPosition();
        playerSave.frame = it.getFrame();
        playerSave.color = it.getColor();
        playerSave.fireUp = it.getFireUp();
        playerSave.speedUp = it.getSpeedUp();
        playerSave.bombUp = it.getBombUp();
        playerSave.wallPass = it.getWallPass();
        this->bombSaveArray.push_back(bombSave);
    }
    for (it = bombArray.begin(); it != bombArray.end(); it++, i++) {
        bmb::bombSave_t bombSave;
        bombSave.position = it.getPosition();
        bombSave.frame = it.getFrame();
        bombSave.color = it.getColor();
        this->bombSaveArray.push_back(bombSave);
    }
}

bmb::Serialization::Serialization() {

}

bmb::Serialization::~Serialization() {

}
