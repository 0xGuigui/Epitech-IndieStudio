/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** draw
*/

#pragma once

#include "raylib.h"
#include "color.hpp"
#include "texture.hpp"

namespace bmb {
    class indieDrawer {
        public:
            indieDrawer() = default;
            ~indieDrawer() = default;
            static void indieDrawTexture(Texture2D texture, int posX, int posY, Color tint) {
                return DrawTexture(texture, posX, posY, tint);
            }
            static void indieDrawTextureV(Texture2D texture, Vector2 position, Color tint) {
                return DrawTextureV(texture, position, tint);
            }
            static void indieDrawTextureEx(Texture2D texture, Vector2 position, float rotation, float scale, Color tint) {
                return DrawTextureEx(texture, position, rotation, scale, tint);
            }
            static void indieDrawTextureRec(Texture2D texture, Rectangle source, Vector2 position, Color tint) {
                return DrawTextureRec(texture, source, position, tint);
            }
            static void indieDrawTextureQuad(Texture2D texture, Vector2 tiling, Vector2 offset, Rectangle quad, Color tint) {
                return DrawTextureQuad(texture, tiling, offset, quad, tint);
            }
            static void indieDrawTextureTiled(Texture2D texture, Rectangle source, Rectangle dest, Vector2 origin, float rotation, float scale, Color tint) {
                return DrawTextureTiled(texture, source, dest, origin, rotation, scale, tint);
            }
            static void indieDrawTexturePro(Texture2D texture, Rectangle source, Rectangle dest, Vector2 origin, float rotation, Color tint) {
                return DrawTexturePro(texture, source, dest, origin, rotation, tint);
            }
            static void indieDrawTexturePoly(Texture2D texture, Vector2 center, Vector2 *points, Vector2 *texcoords, int pointCount, Color tint) {
                return DrawTexturePoly(texture, center, points, texcoords, pointCount, tint);
            }
    };
}