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

        IndieMesh(Mesh mesh) {
            _mesh = mesh;
        }
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

        void GenPoly(int sides, float radius)
        {
            _mesh = GenMeshPoly(sides, radius);
        };

        void GenPlane(float width, float length, int resX, int resZ)
        {
            _mesh = GenMeshPlane(width, length, resX, resZ);
        };

        void GenCube(float width, float height, float length)
        {
            _mesh = GenMeshCube(width, height, length);
        };

        void GenSphere(float radius, int rings, int slices)
        {
            _mesh = GenMeshSphere(radius, rings, slices);
        };

        void GenHemiSphere(float radius, int rings, int slices)
        {
            _mesh = GenMeshHemiSphere(radius, rings, slices);
        };

        void GenCylinder(float radius, float height, int slices)
        {
            _mesh = GenMeshCylinder(radius, height, slices);
        };

        void GenCone(float radius, float height, int slices)
        {
            _mesh = GenMeshCone(radius, height, slices);
        };

        void GenTorus(float radius, float size, int radSeg, int sides)
        {
            _mesh = GenMeshTorus(radius, size, radSeg, sides);
        };

        void GenKnot(float radius, float size, int radSeg, int sides)
        {
            _mesh = GenMeshKnot(radius, size, radSeg, sides);
        };

        void GenHeightmap(Image heightmap, Vector3 size)
        {
            _mesh = GenMeshHeightmap(heightmap, size);
        };

        void GenCubicmap(Image cubicmap, Vector3 cubeSize)
        {
            _mesh = GenMeshCubicmap(cubicmap, cubeSize);
        };
        operator Mesh () {
            return _mesh;
        }
    };
}
