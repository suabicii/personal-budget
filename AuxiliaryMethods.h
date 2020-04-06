#ifndef AUXILIARY_METHODS_H
#define AUXILIARY_METHODS_H

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethods
{
public:
    static string convertIntToString(int number);
    static char enterChar();
    static int enterInteger();
    static string enterNumber();
    static string enterLine();
    static string addDate();
    static string changeFirstLetterToBigAndRestToSmall(string text);
};

#endif