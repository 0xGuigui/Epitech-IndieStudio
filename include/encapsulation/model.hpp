/*
** EPITECH PROJECT, 2022
** model.hpp
** File description:
** include
*/

#include <string>
#include "raylib.h"

namespace bmb {
	class IndieModel {
		public:
			IndieModel() = default;
			explicit IndieModel(const Model &model) : _model(model) {};

			explicit IndieModel(const std::string &fileName) : _model(::LoadModel(fileName.c_str())) {};

			~IndieModel() {
				UnloadModel(_model);
			}
			void LoadModel(const std::string &fileName) {
				_model = ::LoadModel(fileName.c_str());
			}
			operator Model() const {
				return _model;
			}
		private:
			Model _model{};
	};
};