/*
** EPITECH PROJECT, 2021
** B-CCP-400-MAR-4-1-theplazza-rodrigue.bouschet [WSL: Ubuntu-20.04]
** File description:
** IPizza
*/

#ifndef IPIZZA_HPP_
#define IPIZZA_HPP_
#include "../../proto.hpp"

class IPizza
{
    public:
        virtual ~IPizza() = default;
        virtual void Regina(int mul) = 0;
        virtual void Margarita(int mul) = 0;
        virtual void Americana(int mul) = 0;
        virtual void Fantasia(int mul) = 0;
};

#endif /* !IPIZZA_HPP_ */