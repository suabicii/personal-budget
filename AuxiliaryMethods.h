#ifndef AUXILIARY_METHODS_H
#define AUXILIARY_METHODS_H

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <Windows.h>
#include <time.h>

using namespace std;

class AuxiliaryMethods
{

public:
    static string convertIntToString(int number);
    static string convertFloatToString(float number);
    static char enterChar();
    static int enterInteger();
    static float enterFloat();
    static string enterNumber();
    static string enterLine();
    static string changeFirstLetterToBigAndRestToSmall(string text);
};

#endif