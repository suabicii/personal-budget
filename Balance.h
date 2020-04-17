#include <iostream>
#include <vector>
#include <Windows.h>
#include <algorithm>
#include "Expense.h"
#include "Income.h"
#include "IncomesManager.h"
#include "ExpensesManager.h"
#include "AuxiliaryMethods.h"
#include "OperationsOnDates.h"

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
    const int CURRENT_DATE;

    void displayIncomes(vector<Income> incomesToDisplay);
    void displayExpenses(vector<Expense> expensesToDisplay);
    vector<Income> getIncomesFromCurrentMonth();
    vector<Expense> getExpensesFromCurrentMonth();
    void getPreviousMonth(int &beginningOfPreviousMonth, int &endOfPreviousMonth);
    vector<Income> getIncomesFromPreviousMonth();
    vector<Expense> getExpensesFromPreviousMonth();
    vector<Income> getIncomesFromAnyPeriod(int startDate, int endDate);
    vector<Expense> getExpensesFromAnyPeriod(int startDate, int endDate);
    void sortIncomesAndExpencesByDate(vector<Income> &incomesToSort, vector<Expense> &expensesToSort);
    float sumIncomes(vector<Income> incomesToSum);
    float sumExpenses(vector<Expense> expensesToSum);

public:
    Balance(string nameOfFileWithIncomes, string nameOfFileWithExpenses, int idOfLoggedUser)
        : ID_OF_LOGGED_USER(idOfLoggedUser), NAME_OF_FILE_WITH_INCOMES(nameOfFileWithIncomes), NAME_OF_FILE_WITH_EXPENSES(nameOfFileWithExpenses), CURRENT_DATE(OperationsOnDates::convertDateInStringToInt(OperationsOnDates::getCurrentDate()))
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
    void getBalanceFromCurrentMonth();
    void getBalanceFromPreviousMonth();
    void getBalanceFromAnyPeriod();
};