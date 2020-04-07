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
            year = atoi(date.substr(0, 4).c_str());
            month = atoi(date.substr(5, 7).c_str());
            day = atoi(date.substr(8, 10).c_str());

            if ((year >= 2000 && year <= 2020) && (month >= 1 && month <= 12) && (day >= 1 && day <= 31))
                break;
        }
        cout << "Niepoprawny format. Podaj date w formacie rrrr-mm-dd" << endl;
        Sleep(1500);
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