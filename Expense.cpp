#include "Expense.h"

void Expense::setId(int newId)
{
    id = newId;
}

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

int Expense::getId()
{
    return id;
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