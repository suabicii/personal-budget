#include "Income.h"

void Income::setId(int newId)
{
    id = newId;
}

void Income::setUserId(int newUserId)
{
    userId = newUserId;
}

void Income::setDate(int newDate)
{
    date = newDate;
}

void Income::setItem(string newItem)
{
    item = newItem;
}

void Income::setAmount(float newAmount)
{
    amount = newAmount;
}

int Income::getId()
{
    return id;
}

int Income::getUserId()
{
    return userId;
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