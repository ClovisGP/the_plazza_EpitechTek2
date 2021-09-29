/*
** EPITECH PROJECT, 2021
** test [WSL: Ubuntu-20.04]
** File description:
** commandTraitement
*/
#include "../include/proto.hpp"

//sorry but I am out of time
std::string prepareCommand(std::string SType)
{
    std::string str = "NEW-";
    if (SType.find("Regina") != std::string::npos)
        str.append("1-");
    else if (SType.find("Margarita") != std::string::npos)
        str.append("2-");
    else if (SType.find("Americana") != std::string::npos)
        str.append("4-");
    else if (SType.find("Fantasia") != std::string::npos)
        str.append("8-");
    else
        return ("");
    if (SType.find("S") != std::string::npos)
        str.append("1");
    else if (SType.find("M") != std::string::npos)
        str.append("2");
    else if (SType.find("L") != std::string::npos)
        str.append("4");
    else if (SType.find("XL") != std::string::npos)
        str.append("8");
    else if (SType.find("XXL") != std::string::npos)
        str.append("16");
    else
        return ("");
    return (str);   
}

int commandPizza(GlobalData &CData, std::string SCommand)
{
    std::vector<std::string> tmp = strToVectorStr(SCommand, " ");
    if (static_cast<int>(tmp.size()) < 2)
    {
        std::cout << "Erreur la commande \"" << SCommand << "\" n'est pas valide" << std::endl;
        return (-1);
    }
    std::string str = prepareCommand(tmp[0]);
    if (str == "")
    {
        std::cout << "Erreur la commande \"" << SCommand << "\" n'est pas valide" << std::endl;
        return (-1);
    }
    writeInFifo(CData, (char *)str.c_str());
    if (readInFifo(CData).find("LUNCH") != std::string::npos) {
        std::cout << "Kitchen-> Une pizza " << tmp[0] << " " << tmp[1] << " commence a être préparé" << std::endl;
        return (0);
    } else {
        std::cout << "Kitchen-> Une pizza " << tmp[0] << " " << tmp[1] << " ne peut pas être préparé, réessayer plus tard" << std::endl;
        return (-1);
    }
}

int traitementCommand(GlobalData &CData, std::vector<std::string> VCommand)
{
    pid_t pid = 0;
    bool button = false;
    
    for (int index = 0; static_cast<int>(VCommand.size()) > index; index++)
    {
        if (strcmp(VCommand[index].c_str(),"status") == 0)
        {
            std::cout << "Reception-> Nombre de cuisine active : " << CData.getNbKitchen() << std::endl;
            if (CData.getNbKitchen() != 0)
            {
                writeInFifo(CData, (char *)"STATUS");
                readInFifo(CData);
            }
        } else if (CData.getNbKitchen() < 1) {
            pid = fork();
            button = true;
            if (pid == 0) break;
            else {
                if (checkNewKitchen(CData) == 0)
                {
                    CData.setNbKitchen(CData.getNbKitchen() + 1);
                    commandPizza(CData, VCommand[index]);
                }
            }
        } else {
            commandPizza(CData, VCommand[index]);
        }
    }
    if (pid == 0 && button == true)
    {
        lunchKitchen(CData);
        return (-1);
    }
    return (SUCCESS_CODE);
}