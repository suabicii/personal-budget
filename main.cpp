#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include "Markup.h"
#include "PersonalBudget.h"

using namespace std;

int main()
{
    CMarkup xml;
    PersonalBudget personalBudget("users.xml", "incomes.xml", "expenses.xml");

    return 0;
}
