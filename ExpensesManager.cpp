#include "ExpensesManager.h"

void ExpensesManager::addExpense()
{
    Expense expense;

    cout << " >>> DODAWANIE NOWEGO WYDATKU <<<" << endl;
    cout << endl;

    expense = addDataOfExpense();

    expenses.push_back(expense);

    cout << "Wydatek zostal dodany" << endl;
    Sleep(1500);
}

Expense ExpensesManager::addDataOfExpense()
{
    string date = "";
    string item = "";
    float amount = 0;
    Expense expense;

    cout << "Podaj date wydatku (format: rrrr-mm-dd): ";
    date = AuxiliaryMethods::addDate();
    expense.setDate(AuxiliaryMethods::convertDateInStringToInt(date));

    cout << "Napisz, czego dotyczy dany wydatek: ";
    item = AuxiliaryMethods::enterLine();
    expense.setItem(item);

    cout << "Podaj wysokosc wydatku: ";
    cin >> amount;
    expense.setAmount(amount);

    return expense;
}

void ExpensesManager::displayExpenses()
{
    cout << "Wydatki:" << endl;
    for (int i = 0; i < expenses.size(); i++)
    {
        cout << "Data: " << expenses[i].getDate() << "|";
        cout << "Rodzaj: " << expenses[i].getItem() << "|";
        cout << "Wysokosc: " << expenses[i].getAmount() << endl;
    }
    system("pause");
}