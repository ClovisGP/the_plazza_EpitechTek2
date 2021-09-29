/*
** EPITECH PROJECT, 2021
** B-CCP-400-MAR-4-1-theplazza-rodrigue.bouschet [WSL: Ubuntu-20.04]
** File description:
** IKitchen
*/

#ifndef IKITCHEN_HPP_
#define IKITCHEN_HPP_
#include "../../proto.hpp"

class IKitchen
{
    public:
        virtual ~IKitchen() = default;
        virtual int checkEndProgram(GlobalData &CData) = 0;
        virtual bool getButton(void) const = 0;
        virtual int addCook(std::string SCommand, int mul) = 0;
        virtual int checkCook(void) = 0;
        virtual int getNbCook(void) const = 0;
        virtual int takeIngre(int type) = 0;
        virtual int checkIngre(int type) = 0;
        virtual void fillIngre(void) = 0;
        virtual void statusDisplay(void) const = 0;
};

#endif /* !IKITCHEN_HPP_ */
