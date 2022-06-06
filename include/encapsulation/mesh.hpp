/*
** EPITECH PROJECT, 2022
** camera2d
** File description:
** camera2d
*/

#pragma once

#include "raylib.h"
#include "vector.hpp"
#include "image.hpp"
#include "material.hpp"
#include "matrix.hpp"

namespace bmb {
    class IndieMesh {
    private:
        Mesh _mesh;
        BoundingBox _boundingBox;

    public:
        IndieMesh() {};
        ~IndieMesh() {};

        void Upload(bool dynamic) {
            return UploadMesh(&this->_mesh, dynamic);
        };

        void UpdateBuffer(int index, void *data, int dataSize, int offset) {
            return UpdateMeshBuffer(this->_mesh, index, data, dataSize, offset);
        };

        void Unload() {
            return UnloadMesh(this->_mesh);
        };

        void Draw(IndieMaterial material, IndieMatrix transform) {
            return DrawMesh(this->_mesh, material, transform);
        };
        //pointer to fix
        void DrawInstanced(IndieMaterial material, IndieMatrix transform, int instances) {
           return DrawMeshInstanced(this->_mesh, material, transform, instances);
        };
        bool Export(const char *filename) {
            return ExportMesh(this->_mesh, filename);
        };

        BoundingBox GetBoundingBox() {
            return GetMeshBoundingBox(this->_mesh);
        };

        void GenTangents() {
            return GenMeshTangents(&this->_mesh);
        };

        void GenMeshBinormals() {
            return GenMeshBinormals();
        };

        Mesh GenPoly(int sides, float radius)
        {
            return GenMeshPoly(sides, radius);
        };

        Mesh GenPlane(float width, float length, int resX, int resZ)
        {
            return GenMeshPlane(width, length, resX, resZ);
        };

        Mesh GenCube(float width, float height, float length)
        {
            return GenMeshCube(width, height, length);
        };

        Mesh GenSphere(float radius, int rings, int slices)
        {
            return GenMeshSphere(radius, rings, slices);
        };

        Mesh GenHemiSphere(float radius, int rings, int slices)
        {
            return GenMeshHemiSphere(radius, rings, slices);
        };

        Mesh GenCylinder(float radius, float height, int slices)
        {
            return GenMeshCylinder(radius, height, slices);
        };

        Mesh GenCone(float radius, float height, int slices)
        {
            return GenMeshCone(radius, height, slices);
        };

        Mesh GenTorus(float radius, float size, int radSeg, int sides)
        {
            return GenMeshTorus(radius, size, radSeg, sides);
        };

        Mesh GenKnot(float radius, float size, int radSeg, int sides)
        {
            return GenKnot(radius, size, radSeg, sides);
        };

        Mesh GenHeightmap(Image heightmap, Vector3 size)
        {
            return GenMeshHeightmap(heightmap, size);
        };

        Mesh GenCubicmap(Image cubicmap, Vector3 cubeSize)
        {
            return GenMeshCubicmap(cubicmap, cubeSize);
        };

    };
}
