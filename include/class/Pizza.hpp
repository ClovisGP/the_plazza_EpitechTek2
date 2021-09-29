/*
** EPITECH PROJECT, 2021
** B-CCP-400-MAR-4-1-theplazza-rodrigue.bouschet [WSL: Ubuntu-20.04]
** File description:
** Pizza
*/

#ifndef PIZZA_HPP_
#define PIZZA_HPP_
#include "interface/IPizza.hpp"

class Pizza : public IPizza
{
    public:
        Pizza();
        ~Pizza();
        virtual void Regina(int mul);
        virtual void Margarita(int mul);
        virtual void Americana(int mul);
        virtual void Fantasia(int mul);
    private:
};

#endif /* !PIZZA_HPP_ */