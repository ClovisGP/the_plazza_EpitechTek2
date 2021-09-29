/*
** EPITECH PROJECT, 2021
** B-CCP-400-MAR-4-1-theplazza-rodrigue.bouschet [WSL: Ubuntu-20.04]
** File description:
** argGestion
*/
#include "../include/proto.hpp"

int findArg(int choice, char **av)
{
    return (std::stoi(av[choice]));
}