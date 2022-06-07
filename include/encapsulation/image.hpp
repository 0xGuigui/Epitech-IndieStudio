/*
** EPITECH PROJECT, 2022
** image.hpp
** File description:
** include
*/

#pragma once

#include "color.hpp"
#include <string>

namespace bmb {
    class IndieImage {
        private:
            Image _image{};

        public:
            IndieImage() = default;
            ~IndieImage() {
                // UnloadImage(_image);
            }
            explicit IndieImage(const std::string& filename) : _image(LoadImage(filename.c_str())) {}
            IndieImage(Image image) {
                this->_image = ImageCopy(image);
            }
            IndieImage(std::string text, int fontSize, IndieColor color) {
                _image = ImageText(text.c_str(), fontSize, color);
            }
            void LoadRaw(const std::string &filename, int width, int height, int format, int headerSize) {
                _image = LoadImageRaw(filename.c_str(), width, height, format, headerSize);
            }
            Image getImage() const {
                return _image;
            }
            bool Export(const std::string &filename) {
                return ExportImage(_image, filename.c_str());
            }
            bool ExportAsCode(const std::string &filename) {
                ExportImageAsCode(_image, filename.c_str());
                return true;
            }
            void GenerateColor(int width, int height, IndieColor &color) {
                _image = GenImageColor(width, height, color);
            }
            void GenerateGradientV(int width, int height, IndieColor &top, IndieColor &bottom) {
                _image = GenImageGradientV(width, height, top, bottom);
            }
            void GenerateGradientH(int width, int height, IndieColor &left, IndieColor &right) {
                _image = GenImageGradientH(width, height, left, right);
            }
            void GenerateGradientRadial(int width, int height, float density, IndieColor &inner, IndieColor &outer) {
                _image = GenImageGradientRadial(width, height, density, inner, outer);
            }
            void GenerateChecked(int width, int height, int checksX, int checksY, IndieColor &col1, IndieColor &col2) {
                _image = GenImageChecked(width, height, checksX, checksY, col1, col2);
            }
            void GenerateWhiteNoise(int width, int height, float factor) {
                _image = GenImageWhiteNoise(width, height, factor);
            }
            void GenerateImageCellular(int width, int height, int tileSize) {
                _image = GenImageCellular(width, height, tileSize);
            }
            operator Image() const {
                return _image;
            }
    };
};