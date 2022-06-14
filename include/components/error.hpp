/*
** EPITECH PROJECT, 2022
** error.hpp
** File description:
** Custom error handling for Indie Studio
*/

#pragma once

#include <exception>
#include <string>

namespace bmb {
    class ResourceConnectorException : public std::exception {
    private:
        const std::string _message;

    public:
        explicit ResourceConnectorException(std::string message) : _message(std::move(message)) {};

        explicit ResourceConnectorException(const char *message) : _message(std::string(message)) {};

        [[nodiscard]] const char *what() const noexcept override {
            return _message.c_str();
        }
    };

    class EnvironmentHandlerException : public std::exception {
    private:
        const std::string _message;

    public:
        explicit EnvironmentHandlerException(std::string message) : _message(std::move(message)) {};

        explicit EnvironmentHandlerException(const char *message) : _message(std::string(message)) {};

        [[nodiscard]] const char *what() const noexcept override {
            return _message.c_str();
        }
    };
}
