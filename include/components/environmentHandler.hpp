/*
** EPITECH PROJECT, 2022
** environementHandler.hpp
** File description:
** Handle the environment
*/

#pragma once

#include "components/error.hpp"
#include "encapsulation/model.hpp"
#include "encapsulation/color.hpp"
#include "encapsulation/vector.hpp"
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>

#define CHUNK_FLOATING_POINT 10

namespace bmb {
    class RenderChunk {
    private:
        short _x;
        short _y;
        short _z;
        unsigned short _xCount;
        unsigned short _yCount;

    public:
        RenderChunk(float x, float y, float z, unsigned short xCount, unsigned short yCount) {
            _x = static_cast<short>(x * CHUNK_FLOATING_POINT);
            _y = static_cast<short>(y * CHUNK_FLOATING_POINT);
            _z = static_cast<short>(z * CHUNK_FLOATING_POINT);
            _xCount = xCount;
            _yCount = yCount;
        }

        [[nodiscard]] IndieVector3 getPosition() const {
            return {static_cast<float>(this->_x) / CHUNK_FLOATING_POINT,
                    static_cast<float>(this->_y) / CHUNK_FLOATING_POINT,
                    static_cast<float>(this->_z) / CHUNK_FLOATING_POINT};
        }

        [[nodiscard]] auto getChunkBoundaries() const {
            struct ChunkBoundaries {
                unsigned short xCount;
                unsigned short yCount;
            };
            return ChunkBoundaries{this->_xCount, this->_yCount};
        }
    };

    typedef std::tuple<IndieModel &, std::vector<RenderChunk>> ModelRenderChunks;

    class EnvironmentHandler {
    private:
        std::vector<ModelRenderChunks> _renderData;

    public:
        EnvironmentHandler() = default;

        ~EnvironmentHandler() = default;

        static std::string& ltrim(std::string &s);

        /*
         * Open and parse config file for environment
         */
        void init(const std::string &configPath = "data/environment.indie");

        /*
         * Add a new block to the render process
         */
        void addBlock(IndieModel &model, bmb::RenderChunk &chunk);

        /*
         * Draw all blocks in the world
         */
        void draw();

        /*
         * Draw a block chunk
         */
        static void drawChunk(IndieModel &model, RenderChunk &chunk);
    };
}
