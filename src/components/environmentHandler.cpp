/*
** EPITECH PROJECT, 2022
** environementHandler.hpp
** File description:
** Handle the environment
*/

#include "indie.hpp"
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
    unsigned short xCount;
    unsigned short yCount;

    if (!file.is_open())
        throw std::runtime_error("Can't open file " + configPath);
    while (std::getline(file, line)) {
        ltrim(line);
        if (line.empty() || line[0] == '#')
            continue;
        std::istringstream iss(line);
        if (!(iss >> x >> y >> z >> xCount >> yCount >> modelName)) {
            throw bmb::EnvironmentHandlerException("Invalid line: '" + line += "'");
        }
        bmb::IndieModel &model = indie.loader.models.getResource(modelName);
        bmb::RenderChunk newChunk(x, y, z, xCount, yCount);

        addBlock(model, newChunk);
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

void bmb::EnvironmentHandler::drawChunk(bmb::IndieModel &model, bmb::RenderChunk &chunk) {
    auto [xCount, yCount] = chunk.getChunkBoundaries();
    bmb::IndieVector3 position = chunk.getPosition();

    for (unsigned short x = 0; x < xCount; x++, position.decrementX(1.0f)) {
        position.setZ(chunk.getPosition().getZ());
        for (unsigned short y = 0; y < yCount; y++, position.incrementZ(1.0f)) {
            model.Draw(position, 1.0f, WHITE);
        }
    }
}

void bmb::EnvironmentHandler::draw() {
    for (auto &data: _renderData) {
        for (auto &chunk: std::get<1>(data)) {
            drawChunk(std::get<0>(data), chunk);
        }
    }
}
