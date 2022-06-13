/*
** EPITECH PROJECT, 2022
** Game.hpp
** File description:
** serialization.cpp
*/

#include "../../../include/save/Serialization.hpp"


std::string bmb::Serialization::getSaveData() {
    ofstream saveOut; // outdata is like cin


    saveOut.open("./save/data/save.save", std::ios::out|std::ios::app);
    if( !saveOut ) {
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }

    saveOut<< "test" << endl;
    saveOut.close();
    return "";
}

void bmb::Serialization::setSaveData() {

}

bmb::Serialization::Serialization() {
    this->sysCall;
}

bmb::Serialization::~Serialization() {
}
