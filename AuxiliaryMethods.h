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
    static bool verifyDateFormat(string date);
    static bool correctDayOfMonth(int day, int daysInMonth);
    static bool isYearLeap(int year);
    static int checkAmountOfDaysInMount(int month, int year);

public:
    static string convertIntToString(int number);
    static char enterChar();
    static int enterInteger();
    static string enterNumber();
    static string enterLine();
    static string addDate();
    static string getCurrentDate();
    static string changeFirstLetterToBigAndRestToSmall(string text);
    static int convertDateInStringToInt(string date);
    static string convertDateInIntToString(int date);
};

#endif