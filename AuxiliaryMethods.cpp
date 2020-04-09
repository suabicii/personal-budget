#include "AuxiliaryMethods.h"

string AuxiliaryMethods::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

char AuxiliaryMethods::enterChar()
{
    string entry = "";
    char sign = {0};

    while (true)
    {
        getline(cin, entry);

        if (entry.length() == 1)
        {
            sign = entry[0];
            break;
        }
        else
            cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return sign;
}

int AuxiliaryMethods::enterInteger()
{
    string entry;
    int number = 0;

    while (true)
    {
        getline(cin, entry);

        stringstream myStream(entry);
        if (myStream >> number)
            break;
        if (!entry.empty())
            cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}

string AuxiliaryMethods::enterLine()
{
    string entry = "";
    cin.sync();
    getline(cin, entry);
    return entry;
}

bool AuxiliaryMethods::isYearLeap(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return true;
    else
        return false;
}

int AuxiliaryMethods::checkAmountOfDaysInMount(int month, int year)
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

bool AuxiliaryMethods::correctDayOfMonth(int day, int daysInMonth)
{
    if (day >= 1 && day <= daysInMonth)
        return true;
    else
        return false;
}

bool AuxiliaryMethods::verifyDateFormat(string date)
{
    int year;
    int month;
    int day;
    int daysInMonth;

    year = atoi(date.substr(0, 4).c_str());
    month = atoi(date.substr(5, 2).c_str());
    day = atoi(date.substr(8, 2).c_str());
    daysInMonth = checkAmountOfDaysInMount(month, year);

    if (!(year >= 2000 && year <= 2020))
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
    else if (!correctDayOfMonth(day, daysInMonth))
    {
        cout << "Nieprawidlowy format. Podaj dzien wiekszy od 01 i nie wiekszy od " << daysInMonth << ": ";
        Sleep(1500);
        return false;
    }
    else
        return true;
}

string AuxiliaryMethods::addDate()
{
    string date = "";
    int year;
    int month;
    int day;

    while (true)
    {
        date = enterLine();

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

string AuxiliaryMethods::changeFirstLetterToBigAndRestToSmall(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

int AuxiliaryMethods::convertDateInStringToInt(string date)
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

string AuxiliaryMethods::convertDateInIntToString(int date)
{
    string dateWithoutHyphens = convertIntToString(date);
    string fullDate;

    fullDate = dateWithoutHyphens.substr(0, 4) + "-" + dateWithoutHyphens.substr(4, 2) + "-" + dateWithoutHyphens.substr(6, 2);

    return fullDate;
}