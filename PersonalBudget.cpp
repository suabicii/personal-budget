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
        return true;
    }
    return false;
}

void PersonalBudget::userLogout()
{
    delete incomesManager;
    incomesManager = NULL;
}

void PersonalBudget::addIncome()
{
    incomesManager->addIncome();
}

void PersonalBudget::displayIncomes()
{
    incomesManager->displayIncomes();
}