/*
** EPITECH PROJECT, 2022
** npatchInfo.hpp
** File description:
** encapsulation
*/

#pragma once

#include "rectangle.hpp"

namespace bmb {
	class IndieNPatchInfo {
		private:
			NPatchInfo _patch;
		public:
			IndieNPatchInfo() {};
			IndieNPatchInfo(IndieRectangle source, int left, int top, int right, int bottom, int layout) {
				_patch = {
					.source = source,
					.left = left,
					.top = top,
					.right = right,
					.bottom = bottom,
					.layout = layout
				};
			}
			IndieNPatchInfo(NPatchInfo info) {
				_patch = info;
			}
			void Load(IndieRectangle source, int left, int top, int right, int bottom, int layout) {
				_patch = {
					.source = source,
					.left = left,
					.top = top,
					.right = right,
					.bottom = bottom,
					.layout = layout
				};
			}
			operator NPatchInfo () {
				return _patch;
			}
	};
};