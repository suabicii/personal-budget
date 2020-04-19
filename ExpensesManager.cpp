#include "ExpensesManager.h"

void ExpensesManager::addExpense()
{
    Expense expense;

    cout << " >>> DODAWANIE NOWEGO WYDATKU <<<" << endl;
    cout << endl;

    expense = addDataOfExpense();

    expenses.push_back(expense);

    fileWithExpenses.saveExpenseToFile(expense);

    cout << "Wydatek zostal dodany" << endl;
    Sleep(1500);
}

Expense ExpensesManager::addDataOfExpense()
{
    string date = "";
    string item = "";
    float amount = 0;
    Expense expense;
    string currentDate = "";
    char choice;

    expense.setId(fileWithExpenses.getIdOfLastExpense() + 1);
    expense.setUserId(ID_OF_LOGGED_USER);

    while (true)
    {
        system("cls");
        cout << "Wybierz jakiej daty dotyczy dany wydatek:" << endl;
        cout << "1. Dzisiejsza" << endl;
        cout << "2. Inna" << endl;
        cout << "Twoj wybor: ";
        choice = AuxiliaryMethods::enterChar();

        if (choice == '1')
        {
            currentDate = OperationsOnDates::getCurrentDate();
            expense.setDate(OperationsOnDates::convertDateInStringToInt(currentDate));
            break;
        }
        else if (choice == '2')
        {
            cout << "Podaj date wydatku (format: rrrr-mm-dd): ";
            date = OperationsOnDates::addDate();
            expense.setDate(OperationsOnDates::convertDateInStringToInt(date));
            break;
        }
        else
        {
            cout << "Nie ma takiej opcji." << endl;
            Sleep(1500);
        }
    }

    cout << "Napisz, czego dotyczy dany wydatek: ";
    item = AuxiliaryMethods::enterLine();
    expense.setItem(item);

    cout << "Podaj kwote wydatku: ";
    amount = AuxiliaryMethods::enterFloat();
    expense.setAmount(amount);

    return expense;
}

vector<Expense> ExpensesManager::getExpenses()
{
    return expenses;
}