#ifndef INCOMES_MANAGER_H
#define INCOMES_MANAGER_H

#include <iostream>
#include <vector>
#include "User.h"
#include "Income.h"

using namespace std;

class IncomesManager
{
    vector<Income> incomes;
    const int ID_OF_LOGGED_USER;

public:
    IncomesManager();
    void addIncome();
    void loadIncomesFromFile();
};

#endif