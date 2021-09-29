/*
** EPITECH PROJECT, 2021
** test [WSL: Ubuntu-20.04]
** File description:
** kitchenManagement
*/
#include "../include/proto.hpp"

void waitReapro(int milliSec)
{
    usleep(milliSec);
}

void reaproIngre(GlobalData &CData, Kitchen &CKitchen)
{
    while (CKitchen.getButton() == true)
    {
        std::thread reapro(waitReapro, CData.getTimeIngre());
        reapro.join();
        CKitchen.fillIngre();
    }
}

void bakePizza(int pizza, int mul)
{
    switch(pizza)
    {
        case 1:
            sleep(1 * mul);
            break;
        case 2:
            sleep(2 * mul);
            break;
        case 4:
            sleep(2 * mul);
            break;
        case 8:
            sleep(4 * mul);
            break;
    }
}

int gestionCook(GlobalData &CData, Kitchen &CKitchen)
{
    while (CKitchen.getButton() == true)
    {
        CKitchen.checkCook();
    }
    while (CKitchen.getNbCook() > 0)
        CKitchen.checkCook();
    return (0);
}

int lunchKitchen(GlobalData &CData)
{
    sleep(0.1);
    writeInFifo(CData, (char *)"New kitchen\n");
    sleep(0.1);
    readInFifo(CData);
    Kitchen Ckitchen;
    
    std::thread CookManager(gestionCook, std::ref(CData), std::ref(Ckitchen));
    std::thread IngreManager(reaproIngre, std::ref(CData), std::ref(Ckitchen));
    while (1)
    {
        if (Ckitchen.checkEndProgram(CData) == 1)
            break;
    }
    CookManager.join();
    IngreManager.join();
    exit (0);
}