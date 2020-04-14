#include <iostream>
#include <vector>
#include <Windows.h>
#include "User.h"
#include "Expense.h"
#include "Income.h"
#include "IncomesManager.h"
#include "ExpensesManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class Balance
{
    vector<Income> incomes;
    vector<Expense> expenses;
    IncomesManager *incomesManager;
    ExpensesManager *expensesManager;
    const int ID_OF_LOGGED_USER;
    const string NAME_OF_FILE_WITH_INCOMES;
    const string NAME_OF_FILE_WITH_EXPENSES;

    void displayIncomes(vector<Income> incomes);
    void displayExpenses(vector<Expense> expenses);
    vector<Income> getIncomesFromCurrentMonth();
    vector<Expense> getExpensesFromCurrentMonth();

public:
    Balance(string nameOfFileWithIncomes, string nameOfFileWithExpenses, int idOfLoggedUser)
        : ID_OF_LOGGED_USER(idOfLoggedUser), NAME_OF_FILE_WITH_INCOMES(nameOfFileWithIncomes), NAME_OF_FILE_WITH_EXPENSES(nameOfFileWithExpenses)
    {
        incomesManager = new IncomesManager(NAME_OF_FILE_WITH_INCOMES, ID_OF_LOGGED_USER);
        expensesManager = new ExpensesManager(NAME_OF_FILE_WITH_EXPENSES, ID_OF_LOGGED_USER);
        incomes = incomesManager->getIncomes();
        expenses = expensesManager->getExpenses();
    }
    ~Balance()
    {
        delete incomesManager;
        delete expensesManager;
    }
    float countBalanceFromCurrentMonth();
};