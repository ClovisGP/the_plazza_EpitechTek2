/*
** EPITECH PROJECT, 2021
** B-CCP-400-MAR-4-1-theplazza-rodrigue.bouschet [WSL: Ubuntu-20.04]
** File description:
** Kitchen
*/

#include "../include/class/Kitchen.hpp"

Kitchen::Kitchen()
{
    _listCommand.push_back("END PROGRAM");
    _listCommand.push_back("STATUS");
    _listCommand.push_back("OK");
    _listCommand.push_back("NEW");
    _button = true;

    _stockIngre.push_back(5); //doe
    _stockIngre.push_back(5); //tomato
    _stockIngre.push_back(5); //greyere
    _stockIngre.push_back(5); //ham
    _stockIngre.push_back(5); //mushrom
    _stockIngre.push_back(5); //streak
    _stockIngre.push_back(5); //eggplant
    _stockIngre.push_back(5); //goat cheese
    _stockIngre.push_back(5); //chief love
}

Kitchen::~Kitchen()
{
}

int Kitchen::checkEndProgram(GlobalData &CData)
{
    size_t index = 0;
    std::string tmp = readInFifo(CData);
    if (tmp == "Error") return (-1);
    for (; _listCommand.size() > index; index++)
    {
        if (tmp.find(_listCommand[index]) != std::string::npos)
            break;
    }
    switch (index)
    {
        case 0: //fermeture
            _button = false;
            return (1);
        case 1:
            statusDisplay();
            writeInFifo(CData, (char *)"OK\n"); //les stocks et l'occupation des threads
            return (0);
        case 2://c'est juste un ok
            return (0);
        case 3://lancement des thread de pizza
            if (static_cast<int>(_listCook.size()) < CData.getNbCook())
            {
                writeInFifo(CData, (char *)"LUNCH pizza xl");
                addCook(tmp, CData.getMulCookTi());
            }
            return (0);
        default : //si on comprends pas on ferme
            _button = false;
            return (1);
    }
    return (0);
}

bool Kitchen::getButton(void) const
{
    return (_button);
}

int Kitchen::addCook(std::string SCommand, int mul)
{
    char *token = strtok((char *)SCommand.c_str(), "-");
    token = strtok(NULL, "-");
    char *type = token;
    token = strtok(NULL, "-");
    char *size = token;
    std::string result;
    std::string resultBis;

    switch (atoi(size))
    {
        case 1:
            resultBis = "S";
            break;
        case 2:
            resultBis = "M";
            break;
        case 4:
            resultBis = "L";
            break;
        case 8:
            resultBis = "XL";
            break;
        case 16:
            resultBis = "XXL";
            break;
    }
    _MCook.lock();
    switch (atoi(type))
    {
        case 1:
            result = "Regina ";
            result.append(resultBis);
            if (takeIngre(Regina) == 0)
            {
                _listCook.push_back(std::thread (bakePizza, Regina, mul));
                _listPizza.push_back(result);
            } else
                std::cout << "Cook-> Ingrédient manquant pour " << result << ". Réessayer plus tard." << std::endl;
            break;
        case 2:
            result = "Margarita ";
            result.append(resultBis);
            if (takeIngre(Margarita) == 0)
            {
                _listCook.push_back(std::thread (bakePizza, Margarita, mul));
                _listPizza.push_back(result);
            } else
                std::cout << "Cook-> Ingrédient manquant pour " << result << ". Réessayer plus tard." << std::endl;
            break;
        case 4:
            result = "Americana ";
            result.append(resultBis);
            if (takeIngre(Americana) == 0)
            {
                _listCook.push_back(std::thread (bakePizza, Americana, mul));
                _listPizza.push_back(result);
            } else
                std::cout << "Cook-> Ingrédient manquant pour " << result << ". Réessayer plus tard." << std::endl;
            break;
        case 8:
            result = "Fantasia ";
            result.append(resultBis);
            if (takeIngre(Americana) == 0)
            {
                _listCook.push_back(std::thread (bakePizza, Fantasia, mul));
                _listPizza.push_back(result);
            } else
                std::cout << "Cook-> Ingrédient manquant pour " << result << ". Réessayer plus tard." << std::endl;
            break;
    }
    _MCook.unlock();
    return (0);
}

int Kitchen::checkCook(void)
{
    size_t index = 0;

    for (; _listCook.size() > index; index++)
    {
        if (_listCook[index].joinable() == true)
        {
            _MCook.lock();
            _listCook[index].join();
            _listCook.erase(_listCook.begin() + index);
            std::cout << "Cook-> Une pizza est " << _listPizza[index] << " prête" << std::endl;
            _listPizza.erase(_listPizza.begin() + index);
            _MCook.unlock();
            index--;
        }
    }
    return (0);
}

int Kitchen::getNbCook(void) const
{
    return (static_cast<int>(_listCook.size()));
}

int Kitchen::takeIngre(int type)
{
    _MIngre.lock();
    if (checkIngre(type) == -1) return (-1);
    switch (type)
    {
        case 1:
            _stockIngre[0] = _stockIngre[0] - 1;
            _stockIngre[1] = _stockIngre[1] - 1;
            _stockIngre[2] = _stockIngre[2] - 1;
            break;
        case 2:
            _stockIngre[0] = _stockIngre[0] - 1;
            _stockIngre[1] = _stockIngre[1] - 1;
            _stockIngre[2] = _stockIngre[2] - 1;
            _stockIngre[3] = _stockIngre[3] - 1;
            _stockIngre[4] = _stockIngre[4] - 1;
            break;
        case 4:
            _stockIngre[0] = _stockIngre[0] - 1;
            _stockIngre[1] = _stockIngre[1] - 1;
            _stockIngre[2] = _stockIngre[2] - 1;
            _stockIngre[5] = _stockIngre[5] - 1;
            break;
        case 8:
            _stockIngre[0] = _stockIngre[0] - 1;
            _stockIngre[1] = _stockIngre[1] - 1;
            _stockIngre[2] = _stockIngre[2] - 1;
            _stockIngre[6] = _stockIngre[6] - 1;
            _stockIngre[7] = _stockIngre[7] - 1;
            _stockIngre[8] = _stockIngre[8] - 1;
            break;
    }
    _MIngre.unlock();
    return (0);
}

int Kitchen::checkIngre(int type)
{//à refaire en propre
    if ((_stockIngre[0] - 1) < 0) return (-1);
    if ((_stockIngre[1] - 1) < 0) return (-1);
    switch (type)
    {
        case 1:
            if ((_stockIngre[2] - 1) < 0) return (-1);
            break;
        case 2:
            if ((_stockIngre[2] - 1) < 0) return (-1);
            if ((_stockIngre[3] - 1) < 0) return (-1);
            if ((_stockIngre[4] - 1) < 0) return (-1);
            break;
        case 4:
            if ((_stockIngre[2] - 1) < 0) return (-1);
            if ((_stockIngre[5] - 1) < 0) return (-1);
            break;
        case 8:
            if ((_stockIngre[6] - 1) < 0) return (-1);
            if ((_stockIngre[7] - 1) < 0) return (-1);
            if ((_stockIngre[8] - 1) < 0) return (-1);
            break;
    }
    return (0);
}

void Kitchen::fillIngre(void)
{
    _MIngre.lock();
    for (size_t index = 0; _stockIngre.size() > index; index++)
    {
        if (_stockIngre[index] < 5)
            _stockIngre[index] = _stockIngre[index] + 1;
    }
    _MIngre.unlock();
}

void Kitchen::statusDisplay(void) const
{
    std::cout << "-->STATUS" << std::endl;
    std::cout << "  -->Une cuisine contenant " << _listCook.size() << " cuisiniers" << std::endl;
    for (int index = 0; static_cast<int>(_listPizza.size()) > index ; index++)
        std::cout << "     ->Un cuisinier sur une " << _listPizza[index] << std::endl;
    std::cout << "     ->Stock: doe = " << _stockIngre[0] << "; tomato = " << _stockIngre[1]  << "; gruyere = " << _stockIngre[2];
    std::cout << "; ham = " << _stockIngre[3] << "; mushrooms = " << _stockIngre[4]  << "; steak = " << _stockIngre[5];
    std::cout << "; eggplant = " << _stockIngre[6] << "; goat cheese = " << _stockIngre[7]  << "; chief love = " << _stockIngre[8] << std::endl;
}