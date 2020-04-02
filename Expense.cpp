#include "Expense.h"

int Expense::setDate(int newDate)
{
    date = newDate;
}

string Expense::setItem(string newItem)
{
    item = newItem;
}

float Expense::setAmount(float newAmount)
{
    amount = newAmount;
}

int Expense::getDate()
{
    return date;
}

string Expense::getItem()
{
    return item;
}

float Expense::getAmount()
{
    return amount;
}