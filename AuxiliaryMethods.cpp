#include "AuxiliaryMethods.h"

string AuxiliaryMethods::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::convertFloatToString(float number)
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
            entry.clear();
        }

        if (!entry.empty())
            cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
        else
            break;
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

float AuxiliaryMethods::enterFloat()
{
    string entry;
    float number = 0;

    while (true)
    {
        getline(cin, entry);

        for (int i = 0; i < entry.length(); i++)
        {
            if (!(entry[i] == '.' || entry[i] == ',' || (entry[i] >= '0' && entry[i] <= '9')))
            {
                cout << "To nie jest liczba. Wpisz ponownie. " << endl;
                entry.clear();
                break;
            }
            if (entry[i] == ',')
                entry[i] = '.';
        }

        if (!entry.empty())
            break;
    }

    number = atof(entry.c_str());

    return number;
}

string AuxiliaryMethods::enterLine()
{
    string entry = "";
    cin.sync();
    getline(cin, entry);
    return entry;
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