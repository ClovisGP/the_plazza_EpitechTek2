/*
** EPITECH PROJECT, 2021
** B-CCP-400-MAR-4-1-theplazza-rodrigue.bouschet [WSL: Ubuntu-20.04]
** File description:
** Pizza
*/

#include "../include/class/Pizza.hpp"

Pizza::Pizza()
{
}

Pizza::~Pizza()
{
}

void Pizza::Regina(int mul)
{
    sleep(1 * mul);
}

void Pizza::Margarita(int mul)
{
    sleep(2 * mul);
}

void Pizza::Americana(int mul)
{
    sleep(2 * mul);
}

void Pizza::Fantasia(int mul)
{
    sleep(4 * mul);
}