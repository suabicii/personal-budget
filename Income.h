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
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(float newAmount);
    int getDate();
    string getItem();
    float getAmount();
};

#endif