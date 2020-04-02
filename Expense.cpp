#include "Expense.h"

void Expense::setDate(int newDate)
{
    date = newDate;
}

void Expense::setItem(string newItem)
{
    item = newItem;
}

void Expense::setAmount(float newAmount)
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