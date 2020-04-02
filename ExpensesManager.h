#include <iostream>
#include <vector>
#include "User.h"
#include "Expense.h"

using namespace std;

class ExpensesManager
{
    vector<Expense> expenses;
    const int ID_OF_LOGGED_USER;

public:
    ExpensesManager();
    void addExpense();
    void loadExpensesFromFile();
};