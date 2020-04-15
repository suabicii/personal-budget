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
    int beginningOfMonth = ((currentDate / 100) * 100) + 1;

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
    int beginningOfMonth = ((currentDate / 100) * 100) + 1;

    for (it; it != expenses.end(); it++)
    {
        if (it->getDate() >= beginningOfMonth && it->getDate() <= currentDate)
            expensesFromCurrentMonth.push_back(*it);
    }
    return expensesFromCurrentMonth;
}

void Balance::sortIncomesAndExpencesByDate(vector<Income> &incomesToSort, vector<Expense> &expensesToSort)
{
    sort(incomesToSort.begin(), incomesToSort.end(),
         [](Income &income1, Income &income2) {
             return (income1.getDate() < income2.getDate());
         });
    sort(expensesToSort.begin(), expensesToSort.end(),
         [](Expense &expense1, Expense &expense2) {
             return (expense1.getDate() < expense2.getDate());
         });
}

float Balance::sumIncomes(vector<Income> incomesToSum)
{
    float sum = 0;

    for (int i = 0; i < incomesToSum.size(); i++)
    {
        sum += incomesToSum[i].getAmount();
    }
    return sum;
}

float Balance::sumExpenses(vector<Expense> expensesToSum)
{
    float sum = 0;

    for (int i = 0; i < expensesToSum.size(); i++)
    {
        sum += expensesToSum[i].getAmount();
    }
    return sum;
}

float Balance::countBalanceFromCurrentMonth()
{
    vector<Income> incomesFromCurrentMonth = getIncomesFromCurrentMonth();
    vector<Expense> expensesFromCurrentMonth = getExpensesFromCurrentMonth();
    float balanceFromCurrentMonth = 0;
    float sumOfIncomes = 0;
    float sumOfExpenses = 0;

    sortIncomesAndExpencesByDate(incomesFromCurrentMonth, expensesFromCurrentMonth);
    sumOfIncomes = sumIncomes(incomesFromCurrentMonth);
    sumOfExpenses = sumExpenses(expensesFromCurrentMonth);

    system("cls");
    cout << " >>> BILANS Z BIEZACEGO MIESIACA <<<" << endl;
    cout << endl;

    cout << "Przychody:" << endl;
    displayIncomes(incomesFromCurrentMonth);
    cout << "Suma: " << sumOfIncomes << endl;
    cout << endl;

    cout << "Wydatki: " << endl;
    displayExpenses(expensesFromCurrentMonth);
    cout << "Suma: " << sumOfExpenses << endl;
    cout << endl;

    balanceFromCurrentMonth = sumOfIncomes - sumOfExpenses;

    return balanceFromCurrentMonth;
}