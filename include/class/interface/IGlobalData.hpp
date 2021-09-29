/*
** EPITECH PROJECT, 2021
** B-CCP-400-MAR-4-1-theplazza-rodrigue.bouschet [WSL: Ubuntu-20.04]
** File description:
** IGlobalData
*/
#ifndef IGLOBALDATA_HPP_
#define IGLOBALDATA_HPP_
#include <vector>
#include <thread>
#include <mutex>

class IGlobalData
{
    public:
        virtual ~IGlobalData() = default;
        virtual int getMulCookTi(void) const = 0;
        virtual int getNbCook(void) const = 0;
        virtual int getTimeIngre(void) const = 0;
        virtual char *getFifoPlazza(void) = 0;
        virtual int setFifoPlazza(char * const &str) = 0;
        virtual int getNbKitchen(void) const = 0;
        virtual void setNbKitchen(int nb) = 0;
        virtual bool checkLock(void) = 0;
        virtual int lockLock(void) = 0;
        virtual int unlockLock(void) = 0;
    private:
};

#endif /* !IGLOBALDATA_HPP_ */
