/*
** EPITECH PROJECT, 2021
** B-CCP-400-MAR-4-1-theplazza-rodrigue.bouschet [WSL: Ubuntu-20.04]
** File description:
** proto
*/

#ifndef PROTO_H_
#define PROTO_H_

//#include <vector>
//#include <string>
//#include <utility>

//#include <fstream>

#include "class/GlobalData.hpp"
#include "class/Kitchen.hpp"
#include "class/Pizza.hpp"
#include <iostream>
#include <thread>
#include <mutex>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <chrono>


#define SUCCESS_CODE 0
#define ERROR_CODE 84

enum PizzaType
{
    Regina = 1,
    Margarita = 2,
    Americana = 4,
    Fantasia = 8
};
enum PizzaSize
{
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16
};

int errorGestion(int ac, char **av);
bool checkStrDigit(const std::string &str);
int findArg(int choice, char **av);
int receipReception(GlobalData &CData);
std::string recupStrInStr(std::string src, std::string target, int index);
std::vector<std::string> strToVectorStr(std::string line, std::string target);
std::string strCleanSpace(std::string src);
int countOccurence(std::string src, char target);
int traitementCommand(GlobalData &CData, std::vector<std::string> VCommand);
int lunchKitchen(GlobalData &CData);
void printTest();
std::string readInFifo(GlobalData &CData);
int writeInFifo(GlobalData &CData, char *const &str);
int checkNewKitchen(GlobalData &CData);
void bakePizza(int pizza, int mul);
void waitReapro(int milliSec);
#endif /* !PROTO_H_ */