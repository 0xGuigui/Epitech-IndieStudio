/*
** EPITECH PROJECT, 2022
** model.hpp
** File description:
** include
*/

#pragma once

#include <cstring>
#include "mesh.hpp"

namespace bmb {
	class IndieModel {
        private:
            Model _model{};
            float _scale = 1.0f;

		public:
			IndieModel() = default;

			IndieModel(const Model &model) : _model(model) {};

			explicit IndieModel(const std::string &fileName) : _model(::LoadModel(fileName.c_str())) {};

			IndieModel(IndieMesh mesh) {
				_model = LoadModelFromMesh(mesh);
			}
			~IndieModel() = default;

            void setScale(float scale) {
                _scale = scale;
            }
            float getScale() const {
                return _scale;
            }
			void LoadModel(const std::string &fileName) {
				_model = ::LoadModel(fileName.c_str());
			}
			void LoadFromMesh(IndieMesh mesh) {
				_model = LoadModelFromMesh(mesh);
			}
			void Draw(const IndieVector3& position, float scale, IndieColor tint) {
				DrawModel(_model, position, scale, tint);
			}
			void DrawEx(const IndieVector3& position, const IndieVector3& rotationAxis, float rotationAngle, const IndieVector3& scale, IndieColor tint) {
				DrawModelEx(_model, position, rotationAxis, rotationAngle, scale, tint);
			}
			BoundingBox getBoundingBox() {
				return GetModelBoundingBox(_model);
			}
			Model &getModel() {
				return _model;
			}

            bool operator ==(const IndieModel &model) const {
                return memcmp(&this->_model, &model._model, sizeof(Model)) == 0;
            }

			operator Model() {
				return _model;
			}
			operator Model *() {
                return &_model;
            }
	};
};