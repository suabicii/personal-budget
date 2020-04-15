#include "OperationsOnDates.h"

string OperationsOnDates::addDate()
{
    string date = "";
    int year;
    int month;
    int day;

    while (true)
    {
        date = AuxiliaryMethods::enterLine();

        if (date.length() == 10)
        {
            if (verifyDateFormat(date))
                break;
        }
        else
        {
            cout << "Niepoprawny format. Podaj date w formacie rrrr-mm-dd" << endl;
            Sleep(1500);
        }
    }

    return date;
}

int OperationsOnDates::getYear(string date)
{
    int year = atoi(date.substr(0, 4).c_str());
    return year;
}

int OperationsOnDates::getMonth(string date)
{
    int month = atoi(date.substr(5, 2).c_str());
    return month;
}

int OperationsOnDates::getDay(string date)
{
    int day = atoi(date.substr(8, 2).c_str());
    return day;
}

bool OperationsOnDates::isYearLeap(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return true;
    else
        return false;
}

int OperationsOnDates::getAmountOfDaysInMonth(int month, int year)
{
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 9:
        return 31;
    case 2:
        if (isYearLeap(year))
            return 29;
        else
            return 28;
    default:
        return 30;
    }
}

bool OperationsOnDates::isDayOfMountCorrect(int day, int daysInMonth)
{
    if (day >= 1 && day <= daysInMonth)
        return true;
    else
        return false;
}

bool OperationsOnDates::verifyDateFormat(string date)
{
    int year = getYear(date);
    int month = getMonth(date);
    int day = getDay(date);
    int daysInMonth = getAmountOfDaysInMonth(month, year);
    string currentDate = getCurrentDate();
    int currentYear = getYear(currentDate);

    if (!(year >= 2000 && year <= currentYear))
    {
        cout << "Nieprawidlowy format. Rok musi sie miescic w przedziale: od 2000 do aktualnego roku: ";
        Sleep(1500);
        return false;
    }
    else if (!(month >= 1 && month <= 12))
    {
        cout << "Nieprawidlowy format. Podaj miesiac z przedzialu od 01 od 12: ";
        Sleep(1500);
        return false;
    }
    else if (!isDayOfMountCorrect(day, daysInMonth))
    {
        cout << "Nieprawidlowy format. Podaj dzien wiekszy od 01 i nie wiekszy od " << daysInMonth << ": ";
        Sleep(1500);
        return false;
    }
    else
        return true;
}

string OperationsOnDates::getCurrentDate()
{
    time_t currentTimeInSeconds;
    tm *date;
    string fullDate;
    string month;
    string day;

    time(&currentTimeInSeconds);
    date = localtime(&currentTimeInSeconds);

    date->tm_mon++;

    month = date->tm_mon < 10 ? "0" + AuxiliaryMethods::convertIntToString(date->tm_mon) : AuxiliaryMethods::convertIntToString(date->tm_mon);
    day = date->tm_mday < 10 ? "0" + AuxiliaryMethods::convertIntToString(date->tm_mday) : AuxiliaryMethods::convertIntToString(date->tm_mday);

    fullDate = AuxiliaryMethods::convertIntToString(1900 + date->tm_year) + "-" + month + "-" + day;

    return fullDate;
}

int OperationsOnDates::convertDateInStringToInt(string date)
{
    string dateWithoutHyphens;
    int dateAsInt;

    for (int i = 0; i < date.length(); i++)
    {
        if (date[i] == '-')
        {
            continue;
        }
        dateWithoutHyphens += date[i];
    }

    dateAsInt = atoi(dateWithoutHyphens.c_str());
    return dateAsInt;
}

string OperationsOnDates::convertDateInIntToString(int date)
{
    string dateWithoutHyphens = AuxiliaryMethods::convertIntToString(date);
    string fullDate;

    fullDate = dateWithoutHyphens.substr(0, 4) + "-" + dateWithoutHyphens.substr(4, 2) + "-" + dateWithoutHyphens.substr(6, 2);

    return fullDate;
}