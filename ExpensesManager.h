#ifndef EXPENSES_MANAGER_H
#define EXPENSES_MANAGER_H

#include <iostream>
#include <vector>
#include <Windows.h>
#include "User.h"
#include "Expense.h"
#include "FileWithExpenses.h"
#include "AuxiliaryMethods.h"

using namespace std;

class ExpensesManager
{
    vector<Expense> expenses;
    const int ID_OF_LOGGED_USER;
    FileWithExpenses fileWithExpenses;
    Expense addDataOfExpense();

public:
    ExpensesManager(string nameOfFileWithExpenses, int idOfLoggedUser)
        : fileWithExpenses(nameOfFileWithExpenses), ID_OF_LOGGED_USER(idOfLoggedUser)
    {
    }
    void addExpense();
    void loadExpensesFromFile();
    void displayExpenses();
};

#endif