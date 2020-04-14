#include "Balance.h"

void Balance::displayIncomes()
{
    cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < incomes.size(); i++)
    {
        cout << "Id: " << incomes[i].getId() << "|";
        cout << "Id konta: " << incomes[i].getUserId() << "|";
        cout << "Data: " << AuxiliaryMethods::convertDateInIntToString(incomes[i].getDate()) << "|";
        cout << "Dotyczy: " << incomes[i].getItem() << "|";
        cout << "Kwota: " << incomes[i].getAmount() << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
    }
}

void Balance::displayExpenses()
{
    cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < expenses.size(); i++)
    {
        cout << "Id: " << expenses[i].getId() << "|";
        cout << "Id konta: " << expenses[i].getUserId() << "|";
        cout << "Data: " << AuxiliaryMethods::convertDateInIntToString(expenses[i].getDate()) << "|";
        cout << "Dotyczy: " << expenses[i].getItem() << "|";
        cout << "Kwota: " << expenses[i].getAmount() << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
    }
}

float Balance::countBalanceFromCurrentMonth()
{
    system("cls");
    cout << " >>> BILANS Z BIEZACEGO MIESIACA <<<" << endl;
    cout << endl;

    cout << "Przychody:" << endl;
    displayIncomes();

    cout << "Wydadtki: " << endl;
    displayExpenses();

    return 0;
}