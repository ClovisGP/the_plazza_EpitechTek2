/*
** EPITECH PROJECT, 2021
** B-CCP-400-MAR-4-1-theplazza-rodrigue.bouschet [WSL: Ubuntu-20.04]
** File description:
** commandManagement
*/
#include "../include/proto.hpp"

int countOccurence(std::string src, char target)
{
    int comp = 0;

    for (int index = 0; src[index] != '\0'; index++)
    {
        if (src[index] == target)
            comp++;
    }
    return (comp);
}

std::string strCleanSpace(std::string src)
{
    std::string result;
    std::size_t index;

    for (index = 0; src[index] == ' '; index++);
    for (; src[index] != '\0'; index++)
        result += src[index];
    index = result.size() - 1;
    if ((src[index] == ' ' || src[index + 1] == ' ') || (src[index] == ' ' && src[index + 1] == ' '))
    {
        for (; result[index] == ' '; index--)
            result.pop_back();
    }
    result += '\0';
    return (result);
}

std::string recupStrInStr(std::string src, std::string target, int index)
{
    std::string result;
    int comp;
    int indexCompa = 1;

    for(comp = 0; src[comp] != '\0'; comp++)
    {
        if (indexCompa == index && src[comp] != target[0]) result += src[comp];
        if (src[comp] == target[0]) indexCompa++;
    }
    result += '\0';
    return (result);
}

std::vector<std::string> strToVectorStr(std::string line, std::string target)
{
    std::vector<std::string> command;
    int nbTarget = countOccurence(line, target[0]) + 1;

    if (nbTarget > 0)
    {
        for (int comp = 1; nbTarget >= comp; comp++)
            command.push_back(strCleanSpace(recupStrInStr(line, ";", comp)));
    }
    else
    {
        command.push_back(strCleanSpace(line));
    }
    return (command);
}