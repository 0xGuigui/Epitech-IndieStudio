/*
** EPITECH PROJECT, 2022
** image.hpp
** File description:
** include
*/

#pragma once

#include "color.hpp"

namespace bmb {
    class IndieImage {
        public:
            IndieImage() {}
            ~IndieImage() {
                UnloadImage(image);
            }
            IndieImage(std::string filename) {
                image = LoadImage(filename.c_str());
            };
            IndieImage(IndieImage &image) {
                this->image = ImageCopy(image.getImage());
            }
            void LoadRaw(const std::string &filename, int width, int height, int format, int headerSize) {
                image = LoadImageRaw(filename.c_str(), width, height, format, headerSize);
            }
            Image getImage() {
                return image;
            }
            bool Export(const std::string &filename) {
                return ExportImage(image, filename.c_str());
            }
            bool ExportAsCode(const std::string &filename) {
                ExportImageAsCode(image, filename.c_str());
                return true;
            }
            void GenerateColor(int width, int height, IndieColor &color) {
                image = GenImageColor(width, height, color);
            }
            void GenerateGradientV(int width, int height, IndieColor &top, IndieColor &bottom) {
                image = GenImageGradientV(width, height, top, bottom);
            }
            void GenerateGradientH(int width, int height, IndieColor &left, IndieColor &right) {
                image = GenImageGradientH(width, height, left, right);
            }
            void GenerateGradientRadial(int width, int height, float density, IndieColor &inner, IndieColor &outer) {
                image = GenImageGradientRadial(width, height, density, inner, outer);
            }
            void GenerateChecked(int width, int height, int checksX, int checksY, IndieColor &col1, IndieColor &col2) {
                image = GenImageChecked(width, height, checksX, checksY, col1, col2);
            }
            void GenerateWhiteNoise(int width, int height, float factor) {
                image = GenImageWhiteNoise(width, height, factor);
            }
            void GenerateImageCellular(int width, int height, int tileSize) {
                image = GenImageCellular(width, height, tileSize);
            }
            operator Image () {
                return this->image;
            }
        private:
            Image image;
    };
};