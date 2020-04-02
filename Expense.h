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
    int setDate(int newDate);
    string setItem(string newItem);
    float setAmount(float newAmount);
    int getDate();
    string getItem();
    float getAmount();
};

#endif