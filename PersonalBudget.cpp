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
        return true;
    }
    return false;
}

void PersonalBudget::userLogout()
{
    delete incomesManager;
    delete expensesManager;
    incomesManager = NULL;
    expensesManager = NULL;
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