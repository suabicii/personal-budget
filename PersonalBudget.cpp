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
        return true;
    }
    return false;
}

void PersonalBudget::displayAllUsers()
{
    userManager.displayAllUsers();
}