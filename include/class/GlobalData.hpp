/*
** EPITECH PROJECT, 2021
** B-CCP-400-MAR-4-1-theplazza-rodrigue.bouschet [WSL: Ubuntu-20.04]
** File description:
** globalData
*/
#ifndef GLOBALDATA_HPP_
#define GLOBALDATA_HPP_

#include "interface/IGlobalData.hpp"
#include <iostream>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <cstdlib>
#include <unistd.h>
#include <fstream>

class GlobalData : public IGlobalData
{
    public:
        GlobalData(int mulCookTi, int nbCook, int timeIngre);
        ~GlobalData();
        virtual int getMulCookTi(void) const;
        virtual int getNbCook(void) const;
        virtual int getTimeIngre(void) const;
        virtual char *getFifoPlazza(void);
        virtual int setFifoPlazza(char * const &str);
        virtual int getNbKitchen(void) const;
        virtual void setNbKitchen(int nb);
        virtual bool checkLock(void);
        virtual int lockLock(void);
        virtual int unlockLock(void);
    private:
        const int _mulCookTi;
        const int _nbCook;
        const int _timeIngre;
        int _nbKitchen;
        char *_fifoPlazza;
        std::mutex _lock;
};

#endif /* !GLOBALDATA_HPP_ */
