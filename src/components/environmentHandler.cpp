/*
** EPITECH PROJECT, 2022
** environementHandler.hpp
** File description:
** Handle the environment
*/

#include "components/environmentHandler.hpp"

std::string &bmb::EnvironmentHandler::ltrim(std::string &s) {
    auto it = std::find_if(s.begin(), s.end(),
                           [](char c) {
                               return !std::isspace<char>(c, std::locale::classic());
                           });
    s.erase(s.begin(), it);
    return s;
}

void bmb::EnvironmentHandler::init(const std::string &configPath) {
    std::fstream file(configPath);
    std::string line;
    std::string modelName;
    float x, y, z;
    int count;
    float scale;

    if (!file.is_open())
        throw std::runtime_error("Can't open file " + configPath);
    while (std::getline(file, line)) {
        ltrim(line);
        if (line.empty() || line[0] == '#')
            continue;
        std::istringstream iss(line);
        if (!(iss >> x >> y >> z >> count >> scale >> modelName)) {
            throw bmb::EnvironmentHandlerException("Invalid line: '" + line += "'");
        }
        // Get model
        // @TODO use the resource loader
        auto it = fakeMap.find(modelName);
        if (it != fakeMap.end()) {
            bmb::RenderChunk newChunk(x, y, z, count, scale);

            addBlock(it->second, newChunk);
        } else {
            throw bmb::EnvironmentHandlerException("Unknown model: " + modelName += " in line: '" + line += "'");
        }
    }
}

void bmb::EnvironmentHandler::addBlock(bmb::IndieModel &model, bmb::RenderChunk &chunk) {
    auto it = std::find_if(_renderData.begin(), _renderData.end(),
                           [&model](const ModelRenderChunks &data) {
                               return std::get<0>(data) == model;
                           });

    if (it == _renderData.end()) {
        _renderData.push_back(ModelRenderChunks(model, std::vector<RenderChunk>{chunk}));
    } else {
        std::get<1>(*it).push_back(chunk);
    }
}

void bmb::EnvironmentHandler::draw() {
    for (auto &data: _renderData) {
        for (auto &chunk: std::get<1>(data)) {
            IndieVector3 position = chunk.getPosition();
            int count = chunk.getCount();
            float scale = chunk.getScale();

            for (int i = 0; i < count; i++) {
                std::get<0>(data).Draw(position, scale, WHITE);
                position.incrementZ(1);
            }
        }
    }
}
