#include <iostream>
#include <windows.h>
#include "Markup.h"
#include "PersonalBudget.h"
#include "AuxiliaryMethods.h"

using namespace std;

int main()
{
    CMarkup xml;
    PersonalBudget personalBudget("users.xml", "incomes.xml", "expenses.xml");
    char choice;

    while (1)
    {
        system("cls");
        cout << "    >>> MENU  GLOWNE <<<" << endl;
        cout << "---------------------------" << endl;
        cout << "1. Rejestracja" << endl;
        cout << "2. Logowanie" << endl;
        cout << "3. Koniec programu" << endl;
        cout << "---------------------------" << endl;
        cout << "Twoj wybor: ";
        choice = AuxiliaryMethods::enterChar();

        switch (choice)
        {
        case '1':
            personalBudget.registerNewUser();
            break;
        case '2':
            personalBudget.userLogging();
            break;
        case '3':
            exit(0);
        default:
            cout << "Nie ma takiej opcji w menu!" << endl;
            Sleep(1500);
            break;
        }
    }

    return 0;
}
