#include "PersonalBudget.h"

void PersonalBudget::registerNewUser()
{
    userManager.registerNewUser();
}

bool PersonalBudget::userLogging()
{
    userManager.userLogging();
    if (userManager.isUserLoggedIn())
    {
        incomesManager = new IncomesManager(NAME_OF_FILE_WITH_INCOMES, userManager.getIdOfLoggedUser());
        expensesManager = new ExpensesManager(NAME_OF_FILE_WITH_EXPENSES, userManager.getIdOfLoggedUser());
        balance = new Balance(NAME_OF_FILE_WITH_INCOMES, NAME_OF_FILE_WITH_EXPENSES, userManager.getIdOfLoggedUser());
        return true;
    }
    return false;
}

void PersonalBudget::userLogout()
{
    delete incomesManager;
    delete expensesManager;
    delete balance;
    incomesManager = NULL;
    expensesManager = NULL;
    balance = NULL;
}

void PersonalBudget::addIncome()
{
    incomesManager->addIncome();
}

void PersonalBudget::addExpense()
{
    expensesManager->addExpense();
}

void PersonalBudget::displayIncomes()
{
    incomesManager->displayIncomes();
}

void PersonalBudget::displayExpenses()
{
    expensesManager->displayExpenses();
}

void PersonalBudget::showBalanceFromCurrentMonth()
{
    float ballanceFromCurrentMonth = balance->countBalanceFromCurrentMonth();

    cout << ballanceFromCurrentMonth << endl;
    system("pause");
}