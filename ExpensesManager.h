#ifndef EXPENSES_MANAGER_H
#define EXPENSES_MANAGER_H

#include <iostream>
#include <vector>
#include <Windows.h>
#include "User.h"
#include "Expense.h"
#include "FileWithExpenses.h"
#include "AuxiliaryMethods.h"
#include "OperationsOnDates.h"

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
        expenses = fileWithExpenses.loadExpensesFromFile(ID_OF_LOGGED_USER);
    }
    void addExpense();
    void loadExpensesFromFile();
    void displayExpenses();
    vector<Expense> getExpenses();
};

#endif