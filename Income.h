#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income
{
    int date;
    string item;
    float amount;

public:
    int setDate(int newDate);
    string setItem(string newItem);
    float setAmount(float newAmount);
    int getDate();
    string getItem();
    float getAmount();
};

#endif