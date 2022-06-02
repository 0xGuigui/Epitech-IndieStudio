/*
** EPITECH PROJECT, 2022
** model.hpp
** File description:
** include
*/

#include "includes.hpp"

namespace bmb {
	class IndieModel {
		public:
			IndieModel() {};
			IndieModel(Model model) {
				this->model = model;
			}
			IndieModel(const std::string &fileName) {
				model = ::LoadModel(fileName.c_str());
			}
			~IndieModel() {
				UnloadModel(model);
			}
			void LoadModel(const std::string &fileName) {
				model = ::LoadModel(fileName.c_str());
			}
			operator Model() {
				return model;
			}
		private:
			Model model;
	};
};