/*
** EPITECH PROJECT, 2021
** B-CCP-400-MAR-4-1-theplazza-rodrigue.bouschet [WSL: Ubuntu-20.04]
** File description:
** GlobalData
*/
#include "../include/class/GlobalData.hpp"

GlobalData::GlobalData(int mulCookTi, int nbCook, int timeIngre) : _mulCookTi(mulCookTi), _nbCook(nbCook), _timeIngre(timeIngre)
{
    _nbKitchen = 0;
}

GlobalData::~GlobalData()
{
}

int GlobalData::getMulCookTi(void) const
{
    return (_mulCookTi);
}

int GlobalData::getNbCook(void) const
{
    return (_nbCook);
}

int GlobalData::getTimeIngre(void) const
{
    return (_timeIngre);
}

char *GlobalData::getFifoPlazza(void)
{
    return (_fifoPlazza);
}

int GlobalData::setFifoPlazza(char * const &str)
{
    _fifoPlazza = (char *)malloc(sizeof(char) * (strlen(str) + 1));
    if (!_fifoPlazza) return (-1);
    strcpy(_fifoPlazza, str);
    return (0);
}

int GlobalData::getNbKitchen(void) const
{
    return (_nbKitchen);
}

void GlobalData::setNbKitchen(int nb)
{
    _nbKitchen = nb;
}

bool GlobalData::checkLock(void)
{
    return (_lock.try_lock());
}

int GlobalData::lockLock(void)
{
    if (_lock.try_lock() == false)
    {
        _lock.lock();
        return (0);
    }
    return (-1);
}
int GlobalData::unlockLock(void)
{
    _lock.unlock();
    return (0);
}