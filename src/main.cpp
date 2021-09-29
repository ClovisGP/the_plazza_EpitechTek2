/*
** EPITECH PROJECT, 2021
** B-CCP-400-MAR-4-1-theplazza-rodrigue.bouschet [WSL: Ubuntu-20.04]
** File description:
** main
*/
#include "../include/proto.hpp"

int reception(GlobalData &CData)
{
    std::string line = "a"; 

    for (; line != "QUIT" && line != "";)
    {
        std::getline(std::cin, line);
        if (line != "QUIT" && line != "") {
            if (traitementCommand(CData, strToVectorStr(line, ";")) == -1) break;
        }
    }
    if (CData.getNbKitchen() != 0)
        writeInFifo(CData, (char *)"END PROGRAM\n");
    return (SUCCESS_CODE);
}

int main(int ac , char **av)
{
    if (errorGestion(ac, av) == 84) return (ERROR_CODE);
    GlobalData CData(findArg(1, av), findArg(2, av), findArg(3, av));
    CData.setFifoPlazza((char *)"/tmp/fifoPlazza");
    mkfifo(CData.getFifoPlazza(), 0666);

    return (reception(CData));;
}