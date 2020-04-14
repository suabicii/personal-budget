#include "Balance.h"

void Balance::displayIncomes(vector<Income> incomes)
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

void Balance::displayExpenses(vector<Expense> expenses)
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

vector<Income> Balance::getIncomesFromCurrentMonth()
{
    int currentDate = AuxiliaryMethods::convertDateInStringToInt(AuxiliaryMethods::getCurrentDate());
    vector<Income> incomesFromCurrentMonth;
    vector<Income>::iterator it = incomes.begin();
    // 20200414 / 100 + 1
    // 20200400 + 1
    int beginningOfMonth = (currentDate / 100) * 100;

    for (it; it != incomes.end(); it++)
    {
        if (it->getDate() >= beginningOfMonth && it->getDate() <= currentDate)
            incomesFromCurrentMonth.push_back(*it);
    }
    return incomesFromCurrentMonth;
}

vector<Expense> Balance::getExpensesFromCurrentMonth()
{
    int currentDate = AuxiliaryMethods::convertDateInStringToInt(AuxiliaryMethods::getCurrentDate());
    vector<Expense> expensesFromCurrentMonth;
    vector<Expense>::iterator it = expenses.begin();
    int beginningOfMonth = (currentDate / 100) * 100;

    for (it; it != expenses.end(); it++)
    {
        if (it->getDate() >= beginningOfMonth && it->getDate() <= currentDate)
            expensesFromCurrentMonth.push_back(*it);
    }
    return expensesFromCurrentMonth;
}

float Balance::countBalanceFromCurrentMonth()
{
    system("cls");
    cout << " >>> BILANS Z BIEZACEGO MIESIACA <<<" << endl;
    cout << endl;

    cout << "Przychody:" << endl;
    displayIncomes(getIncomesFromCurrentMonth());

    cout << "Wydatki: " << endl;
    displayExpenses(getExpensesFromCurrentMonth());

    return 0;
}