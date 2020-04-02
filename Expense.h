#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense
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