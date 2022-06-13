/*
** EPITECH PROJECT, 2022
** Game.hpp
** File description:
** systemCall.hpp
*/

#pragma once

#include "indieStudio.hpp"
#include <unistd.h>
#include <fcntl.h>
#include <string>

namespace bmb {
    class systemCall {
        systemCall();
        ~systemCall();
        void cOpen(std::string pathname) {
            char *cPathname = new char [pathname.length()+1];
            std::strcpy (cPathname, str.c_str());

            this->open = open(cPathname, O_APPEND);
        };
        void cRead(int fd, std::string buffer, size_t count) {
            char *cBuffer = new char [buffer.length()+1];
            std::strcpy (cBuffer, str.c_str());

            this->t = read(fd, cBuffer, count);
        };
        void cWrite(int fd, std::string buffer, size_t count) {
            char *cBuffer = new char [buffer.length()+1];
            std::strcpy (cBuffer, str.c_str());

            write(fd, cBuffer, count);
        };
        void cClose(int fd) {
            int close(fd);
        }

        protected:
            int open;
            ssize_t t;
            char *buffer;
    };
}
