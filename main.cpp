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
    bool isUserLoggedIn = false;

    while (1)
    {
        if (!isUserLoggedIn)
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
                isUserLoggedIn = personalBudget.userLogging();
                break;
            case '3':
                exit(0);
            default:
                cout << "Nie ma takiej opcji w menu!" << endl;
                Sleep(1500);
                break;
            }
        }
        else
        {
            system("cls");
            cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
            cout << "---------------------------" << endl;
            cout << "1. Dodaj przychod" << endl;
            cout << "2. Dodaj wydatek" << endl;
            cout << "3. Bilans z biezacego miesiaca" << endl;
            cout << "4. Bilans z poprzedniego miesiaca" << endl;
            cout << "5. Bilans z wybranego okresu" << endl;
            cout << "---------------------------" << endl;
            cout << "6. Zmien haslo" << endl;
            cout << "7. Wyloguj sie" << endl;
            cout << "---------------------------" << endl;
            cout << "Twoj wybor: ";
            choice = AuxiliaryMethods::enterChar();

            switch (choice)
            {
            case '1':
                personalBudget.addIncome();
                break;
            case '2':
                personalBudget.addExpense();
                break;
            case '3':
                personalBudget.showBalanceFromCurrentMonth();
                break;
            case '4':
                /* code */
                break;
            case '5':
                /* code */
                break;
            case '6':
                /* code */
                break;
            case '7':
                personalBudget.userLogout();
                isUserLoggedIn = false;
                break;
            default:
                cout << "Nie ma takiej opcji w menu!" << endl;
                Sleep(1500);
                break;
            }
        }
    }

    return 0;
}
