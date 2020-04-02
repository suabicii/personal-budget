#include "Income.h"

int Income::setDate(int newDate)
{
    date = newDate;
}

string Income::setItem(string newItem)
{
    item = newItem;
}

float Income::setAmount(float newAmount)
{
    amount = newAmount;
}

int Income::getDate()
{
    return date;
}

string Income::getItem()
{
    return item;
}

float Income::getAmount()
{
    return amount;
}