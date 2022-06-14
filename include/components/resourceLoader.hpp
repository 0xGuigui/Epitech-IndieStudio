/*
** EPITECH PROJECT, 2022
** resourceLoader.hpp
** File description:
** resourceLoader.hpp
*/

#pragma once

#include <iostream>
#include <string>
#include <filesystem>
#include "error.hpp"
#include "../external/robin_hood.hpp"
#include "../encapsulation/texture.hpp"
#include "../encapsulation/sound.hpp"
#include "../encapsulation/image.hpp"
#include "../encapsulation/model.hpp"

namespace bmb {
    class IResourceConnector {
    public:
        virtual ~IResourceConnector() = default;

        [[nodiscard]] virtual const std::vector<std::string> &getPaths() const = 0;

        virtual void addResources(const std::filesystem::directory_entry &entry) = 0;
    };

    template<class T>
    class ResourceConnector : public IResourceConnector {
    private:
        const std::vector<std::string> _paths;
        const std::vector<std::string> _fileExtensions;
        robin_hood::unordered_flat_map<std::string, T> _resources;

    public:
        ResourceConnector() : _paths(), _fileExtensions(), _resources() {};

        explicit ResourceConnector(const std::string &subPath, std::vector<std::string> fileExtensions = {}) :
                _paths(std::vector<std::string>{subPath}),
                _fileExtensions(std::move(fileExtensions)) {};

        explicit ResourceConnector(std::vector<std::string> subPaths, std::vector<std::string> fileExtensions = {}) :
                _paths(std::move(subPaths)),
                _fileExtensions(std::move(fileExtensions)) {};

        ~ResourceConnector() override = default;

        /*
         * Get list of lookup paths
         */
        [[nodiscard]] const std::vector<std::string> &getPaths() const override {
            return _paths;
        }

        /*
         * Get list of acceptable file
         */
        [[nodiscard]] const std::vector<std::string> &getFileExtensions() const {
            return _fileExtensions;
        }

        /*
         * Manually add a resource by giving a path to it
         */
        void addResource(const std::string &name, const std::string &path) {
            if (_resources.contains(name)) {
                throw ResourceConnectorException("A resource with the \"" + name + "\" already exists");
            }
            _resources.insert({name, std::move(T(path))});
        }

        /*
         * Manually add a resource by giving an object
         */
        void addResource(const std::string &name, T resource) {
            if (_resources.contains(name)) {
                throw ResourceConnectorException("A resource with the \"" + name + "\" already exists");
            }
            _resources.insert({name, std::move(resource)});
        }

        /*
         * Add resource using the cpp modern filesystem
         */
        void addResources(const std::filesystem::directory_entry &entry) override {
            if (!entry.is_directory()) {
                throw ResourceConnectorException("Error: \"" + entry.path().string() + "\" is not a directory");
            }
            for (auto &file : std::filesystem::recursive_directory_iterator(entry)) {
                if (!file.is_regular_file()) {
                    continue;
                }
                if (_fileExtensions.empty() || std::find(_fileExtensions.begin(), _fileExtensions.end(),
                                                         file.path().extension().string()) != _fileExtensions.end()) {
                    this->addResource(file.path().stem().string(), file.path().string());
                }
            }
        }

        /*
         * This function is similar to [] operator but it will throw an exception if the resource is not found
         */
        [[nodiscard]] T &getResource(const std::string &name) {
            auto it = _resources.find(name);

            if (it == _resources.end()) {
                throw ResourceConnectorException("Error: \"" + name + "\" is not a valid resource");
            }
            return it->second;
        }

        /*
         * Used to access an element of the resource map
         */
        T &operator[](const std::string &name) {
            return _resources[name];
        }
    };

    class ResourceLoader {
    public:
        // List of all connectors
        ResourceConnector<IndieTexture2D> textures;
        ResourceConnector<IndieSound> sounds;
        ResourceConnector<IndieMusic> musics;
        ResourceConnector<IndieImage> images;
        ResourceConnector<IndieModel> models;


    private:
        // Add your connectors here for building process
        std::vector<std::reference_wrapper<IResourceConnector>> _connectors = {
                textures,
                sounds,
                images,
                musics,
                models
        };

    public:
        explicit ResourceLoader(const std::string &rootFolderName) :
                textures("textures"),
                sounds("audio", {".ogg"}),
                musics("audio", {".mp3"}),
                images("images"),
                models("models") {
            std::string rootPath = std::filesystem::current_path().string() + "/" + rootFolderName;

            for (auto &file: std::filesystem::directory_iterator(rootPath)) {
                if (!file.is_directory()) {
                    continue;
                }
                for (auto i: _connectors) {
                    const std::vector<std::string> &paths = i.get().getPaths();

                    if (std::find(paths.begin(), paths.end(), file.path().stem().string()) != paths.end()) {
                        i.get().addResources(file);
                    }
                }
            }
        };
    };
}
