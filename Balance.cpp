#include "Balance.h"

void Balance::displayIncomes(vector<Income> incomesToDisplay)
{
    cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < incomesToDisplay.size(); i++)
    {
        cout << "Id: " << incomesToDisplay[i].getId() << "|";
        cout << "Id konta: " << incomesToDisplay[i].getUserId() << "|";
        cout << "Data: " << OperationsOnDates::convertDateInIntToString(incomesToDisplay[i].getDate()) << "|";
        cout << "Dotyczy: " << incomesToDisplay[i].getItem() << "|";
        cout << "Kwota: " << incomesToDisplay[i].getAmount() << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
    }
}

void Balance::displayExpenses(vector<Expense> expensesToDisplay)
{
    cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < expensesToDisplay.size(); i++)
    {
        cout << "Id: " << expensesToDisplay[i].getId() << "|";
        cout << "Id konta: " << expensesToDisplay[i].getUserId() << "|";
        cout << "Data: " << OperationsOnDates::convertDateInIntToString(expensesToDisplay[i].getDate()) << "|";
        cout << "Dotyczy: " << expensesToDisplay[i].getItem() << "|";
        cout << "Kwota: " << expensesToDisplay[i].getAmount() << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
    }
}

vector<Income> Balance::getIncomesFromCurrentMonth()
{
    vector<Income> incomesFromCurrentMonth;
    vector<Income>::iterator it = incomes.begin();
    // 20200414 / 100 + 1
    // 20200400 + 1
    int beginningOfMonth = ((CURRENT_DATE / 100) * 100) + 1;

    for (it; it != incomes.end(); it++)
    {
        if (it->getDate() >= beginningOfMonth && it->getDate() <= CURRENT_DATE)
            incomesFromCurrentMonth.push_back(*it);
    }
    return incomesFromCurrentMonth;
}

vector<Expense> Balance::getExpensesFromCurrentMonth()
{
    vector<Expense> expensesFromCurrentMonth;
    vector<Expense>::iterator it = expenses.begin();
    int beginningOfMonth = ((CURRENT_DATE / 100) * 100) + 1;

    for (it; it != expenses.end(); it++)
    {
        if (it->getDate() >= beginningOfMonth && it->getDate() <= CURRENT_DATE)
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

void Balance::getBalanceFromCurrentMonth()
{
    vector<Income> incomesFromCurrentMonth = getIncomesFromCurrentMonth();
    vector<Expense> expensesFromCurrentMonth = getExpensesFromCurrentMonth();
    float finalResult = 0;
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

    finalResult = sumOfIncomes - sumOfExpenses;

    cout << "Wynik: " << finalResult << endl;
    system("pause");
}

vector<Income> Balance::getIncomesFromPreviousMonth()
{
    vector<Income> incomesFromPreviousMonth;
    vector<Income>::iterator it = incomes.begin();
    int beginningOfPreviousMonth = ((CURRENT_DATE / 100) * 100 - 100) + 1;
    ;
    int previousMonth = OperationsOnDates::getMonth(OperationsOnDates::convertDateInIntToString(beginningOfPreviousMonth));
    int previousYear = OperationsOnDates::getYear(OperationsOnDates::convertDateInIntToString(beginningOfPreviousMonth));
    int endOfPreviousMonth = beginningOfPreviousMonth + OperationsOnDates::getAmountOfDaysInMonth(previousMonth, previousYear) - 1;

    for (it; it != incomes.end(); it++)
    {
        if (it->getDate() >= beginningOfPreviousMonth && it->getDate() <= endOfPreviousMonth)
            incomesFromPreviousMonth.push_back(*it);
    }
    return incomesFromPreviousMonth;
}

vector<Expense> Balance::getExpensesFromPreviousMonth()
{
    vector<Expense> expensesFromPreviousMonth;
    vector<Expense>::iterator it = expenses.begin();
    int beginningOfPreviousMonth = ((CURRENT_DATE / 100) * 100 - 100) + 1;
    ;
    int previousMonth = OperationsOnDates::getMonth(OperationsOnDates::convertDateInIntToString(beginningOfPreviousMonth));
    int previousYear = OperationsOnDates::getYear(OperationsOnDates::convertDateInIntToString(beginningOfPreviousMonth));
    int endOfPreviousMonth = beginningOfPreviousMonth + OperationsOnDates::getAmountOfDaysInMonth(previousMonth, previousYear) - 1;

    for (it; it != expenses.end(); it++)
    {
        if (it->getDate() >= beginningOfPreviousMonth && it->getDate() <= endOfPreviousMonth)
            expensesFromPreviousMonth.push_back(*it);
    }
    return expensesFromPreviousMonth;
}

void Balance::getBalanceFromPreviousMonth()
{
    vector<Income> incomesFromPreviousMonth = getIncomesFromPreviousMonth();
    vector<Expense> expensesFromPreviousMonth = getExpensesFromPreviousMonth();
    float finalResult = 0;
    float sumOfIncomes = 0;
    float sumOfExpenses = 0;

    sortIncomesAndExpencesByDate(incomesFromPreviousMonth, expensesFromPreviousMonth);
    sumOfIncomes = sumIncomes(incomesFromPreviousMonth);
    sumOfExpenses = sumExpenses(expensesFromPreviousMonth);

    system("cls");
    cout << " >>> BILANS Z POPRZEDNIEGO MIESIACA <<<" << endl;
    cout << endl;

    cout << "Przychody:" << endl;
    displayIncomes(incomesFromPreviousMonth);
    cout << "Suma: " << sumOfIncomes << endl;
    cout << endl;

    cout << "Wydatki: " << endl;
    displayExpenses(expensesFromPreviousMonth);
    cout << "Suma: " << sumOfExpenses << endl;
    cout << endl;

    finalResult = sumOfIncomes - sumOfExpenses;

    cout << "Wynik: " << finalResult << endl;
    system("pause");
}