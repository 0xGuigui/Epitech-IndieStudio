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
#include "vector"
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
        short _count;
        char _scale;

    public:
        RenderChunk(float x, float y, float z, int count, float scale) {
            this->_x = static_cast<short>(x * CHUNK_FLOATING_POINT);
            this->_y = static_cast<short>(y * CHUNK_FLOATING_POINT);
            this->_z = static_cast<short>(z * CHUNK_FLOATING_POINT);
            this->_count = static_cast<short>(count);
            this->_scale = static_cast<char>(scale * CHUNK_FLOATING_POINT);
        }

        IndieVector3 getPosition() const {
            return {static_cast<float>(this->_x) / CHUNK_FLOATING_POINT,
                    static_cast<float>(this->_y) / CHUNK_FLOATING_POINT,
                    static_cast<float>(this->_z) / CHUNK_FLOATING_POINT};
        }

        int getCount() const {
            return this->_count;
        }

        float getScale() const {
            return static_cast<float>(this->_scale) / CHUNK_FLOATING_POINT;
        }
    };

    typedef std::tuple<IndieModel &, std::vector<RenderChunk>> ModelRenderChunks;

    class EnvironmentHandler {
    private:
        std::vector<ModelRenderChunks> _renderData;
        std::unordered_map<std::string, bmb::IndieModel> fakeMap = {
                {"grass_block", bmb::IndieModel("assets/models/grass_block.glb")},
                {"tnt", bmb::IndieModel("assets/models/tnt.glb")},
                {"stone", bmb::IndieModel("assets/models/stone.glb")},
                {"dirt", bmb::IndieModel("assets/models/dirt.glb")},
                {"cobblestone", bmb::IndieModel("assets/models/cobblestone.glb")},
        };

    public:
        EnvironmentHandler() = default;

        ~EnvironmentHandler() = default;

        std::string& ltrim(std::string &s);

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
    };
}
