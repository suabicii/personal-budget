#ifndef OPERATIONS_ON_DATES
#define OPERATIONS_ON_DATES

#include <iostream>
#include <string>
#include <time.h>
#include <Windows.h>
#include "AuxiliaryMethods.h"

using namespace std;

class OperationsOnDates
{
    static bool verifyDateFormat(string date);
    static bool isYearLeap(int year);
    static bool isDayOfMountCorrect(int day, int daysInMonth);

public:
    static string addDate();
    static int getYear(string date);
    static int getMonth(string date);
    static int getDay(string date);
    static int getAmountOfDaysInMonth(int month, int year);
    static string getCurrentDate();
    static int convertDateInStringToInt(string date);
    static string convertDateInIntToString(int date);
};

#endif