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

void PersonalBudget::changePassword()
{
    userManager.changePassword();
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
    balance = new Balance(NAME_OF_FILE_WITH_INCOMES, NAME_OF_FILE_WITH_EXPENSES, userManager.getIdOfLoggedUser());
    balance->getBalanceFromCurrentMonth();
    delete balance;
    balance = NULL;
}

void PersonalBudget::showBalanceFromPreviousMonth()
{
    balance = new Balance(NAME_OF_FILE_WITH_INCOMES, NAME_OF_FILE_WITH_EXPENSES, userManager.getIdOfLoggedUser());
    balance->getBalanceFromPreviousMonth();
    delete balance;
    balance = NULL;
}

void PersonalBudget::showBalanceFromAnyPeriod()
{
    balance = new Balance(NAME_OF_FILE_WITH_INCOMES, NAME_OF_FILE_WITH_EXPENSES, userManager.getIdOfLoggedUser());
    balance->getBalanceFromAnyPeriod();
    delete balance;
    balance = NULL;
}