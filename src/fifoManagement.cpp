/*
** EPITECH PROJECT, 2021
** test [WSL: Ubuntu-20.04]
** File description:
** fifoManagement
*/
#include "../include/proto.hpp"

int checkNewKitchen(GlobalData &CData)
{
    if (readInFifo(CData) == "New kitchen")
    {
        writeInFifo(CData, (char *)"OK\n");
        std::cout << "Reception-> Une nouvelle cuisine est ouverte" << std::endl;
        return (0);
    } else {
        std::cerr << "Reception-> Une cuisine n'a pas réussi à s'ouvrir" << std::endl;
        return (-1);
    }
}

int writeInFifo(GlobalData &CData, char *const &str)
{
    std::fstream fd(CData.getFifoPlazza(), std::ios::out);
    if (!fd) return (-1);
    fd.write(str, strlen(str) + 1);
    fd.close();
    return (0);
}

std::string readInFifo(GlobalData &CData)
{
    std::string line;
    std::ifstream fd(CData.getFifoPlazza());
    if (!fd) return ("Error1");
    if (fd.peek() != EOF && fd.peek() != '\n')
    {
        std::getline(fd, line);
    } else {
        fd.close();
        return ("Error2");
    }
    fd.close();
    return (line);
}