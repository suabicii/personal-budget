#ifndef INCOMES_MANAGER_H
#define INCOMES_MANAGER_H

#include <iostream>
#include <vector>
#include <Windows.h>
#include "User.h"
#include "Income.h"
#include "FileWithIncomes.h"
#include "AuxiliaryMethods.h"

using namespace std;

class IncomesManager
{
    vector<Income> incomes;
    const int ID_OF_LOGGED_USER;
    FileWithIncomes fileWithIncomes;
    Income addDataOfIncome();

public:
    IncomesManager(string nameOfFileWithIncomes, int idOfLoggedUser) : fileWithIncomes(nameOfFileWithIncomes), ID_OF_LOGGED_USER(idOfLoggedUser) {}
    void addIncome();
    void loadIncomesFromFile();
    void displayIncomes();
};

#endif