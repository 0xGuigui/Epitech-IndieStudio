/*
** EPITECH PROJECT, 2022
** image.hpp
** File description:
** include
*/

#pragma once

#include "includes.hpp"

namespace bmb {
    class IndieImage {
        public:
            IndieImage() {}
            ~IndieImage() {
                UnloadImage(image);
            }
            IndieImage(Image image) {
                this->image = image;
            }
            IndieImage(std::string filename) {
                image = LoadImage(filename.c_str());
            };
            void LoadRaw(std::string filename, int width, int height, int format, int headerSize) {
                image = LoadImageRaw(filename.c_str(), width, height, format, headerSize);
            }
            Image getImage() {
                return image;
            }
            bool Export(std::string filename) {
                return ExportImage(image, filename.c_str());
            }
            bool ExportAsCode(std::string filename) {
                ExportImageAsCode(image, filename.c_str());
            }
            void GenerateColor(int width, int height, Color color) {
                image = GenImageColor(width, height, color);
            }
            void GenerateGradientV(int width, int height, Color top, Color bottom) {
                image = GenImageGradientV(width, height, top, bottom);
            }
            void GenerateGradientH(int width, int height, Color left, Color right) {
                image = GenImageGradientH(width, height, left, right);
            }
            void GenerateGradientRadial(int width, int height, float density, Color inner, Color outer) {
                image = GenImageGradientRadial(width, height, density, inner, outer);
            }
        private:
            Image image;
    };
};