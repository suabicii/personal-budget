#include <iostream>
#include "UserManager.h"
#include "IncomesManager.h"
#include "ExpensesManager.h"
#include "Balance.h"

using namespace std;

class PersonalBudget
{
    UserManager userManager;
    IncomesManager *incomesManager;
    ExpensesManager *expensesManager;
    Balance *balance;
    const string NAME_OF_FILE_WITH_INCOMES;
    const string NAME_OF_FILE_WITH_EXPENSES;

public:
    PersonalBudget(string nameOfFileWithUsers, string nameOfFileWithIncomes, string nameOfFileWithExpenses)
        : userManager(nameOfFileWithUsers), NAME_OF_FILE_WITH_INCOMES(nameOfFileWithIncomes), NAME_OF_FILE_WITH_EXPENSES(nameOfFileWithExpenses)
    {
        incomesManager = NULL;
        expensesManager = NULL;
        balance = NULL;
    }
    ~PersonalBudget()
    {
        delete incomesManager;
        delete expensesManager;
        incomesManager = NULL;
        expensesManager = NULL;
    }
    void registerNewUser();
    bool userLogging();
    void userLogout();
    void changePassword();
    void addIncome();
    void addExpense();
    void showBalanceFromCurrentMonth();
    void showBalanceFromPreviousMonth();
    void showBalanceFromAnyPeriod();
};