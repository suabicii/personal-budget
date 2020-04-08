#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income
{
    int id;
    int date;
    string item;
    float amount;

public:
    void setId(int newId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(float newAmount);
    int getId();
    int getDate();
    string getItem();
    float getAmount();
};

#endif