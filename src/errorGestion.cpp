/*
** EPITECH PROJECT, 2021
** B-CCP-400-MAR-4-1-theplazza-rodrigue.bouschet [WSL: Ubuntu-20.04]
** File description:
** ErrorGestion
*/
#include "../include/proto.hpp"

void printTest()
{
    std::cout << "Bonjour je suis une foncion de test" << std::endl;
}

bool checkStrDigit(const std::string &str)
{
    if (str == "") return (false);
    for(std::size_t comp = 0; comp < str.size(); comp++)
    {
        if (std::isdigit(str[comp]) == false && str[comp] != '.' && str[comp] != '-')
            return (false);
    }
    return (true);
}

int errorGestion(int ac, char **av)
{
    if (ac == 4) {
        if (checkStrDigit(av[1]) && checkStrDigit(av[2]) && checkStrDigit(av[3]))
            return (SUCCESS_CODE);
        else
            return (ERROR_CODE);
    } else
        return (ERROR_CODE);
}