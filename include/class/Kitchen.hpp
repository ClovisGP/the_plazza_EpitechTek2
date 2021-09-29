/*
** EPITECH PROJECT, 2021
** B-CCP-400-MAR-4-1-theplazza-rodrigue.bouschet [WSL: Ubuntu-20.04]
** File description:
** Kitchen
*/

#ifndef KITCHEN_HPP_
#define KITCHEN_HPP_
#include "interface/IKitchen.hpp"

class Kitchen : public IKitchen
{
    public:
        Kitchen();
        ~Kitchen();
        virtual int checkEndProgram(GlobalData &CData);
        virtual bool getButton(void) const;
        virtual int addCook(std::string SCommand, int mul);
        virtual int checkCook(void);
        virtual int getNbCook(void) const;
        virtual int takeIngre(int type);
        virtual int checkIngre(int type);
        virtual void fillIngre(void);
        virtual void statusDisplay(void) const;
    private:
        bool _button;
        std::vector<std::string> _listCommand;
        std::vector<std::thread> _listCook;
        std::vector<std::string> _listPizza;
        std::vector<int> _stockIngre;
        std::mutex _MCook;
        std::mutex _MIngre;
};

#endif /* !KITCHEN_HPP_ */