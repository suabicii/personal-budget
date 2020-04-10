#ifndef FILE_WITH_EXPENSES
#define FILE_WITH_EXPENSES

#include <iostream>
#include <vector>
#include "Expense.h"
#include "AuxiliaryMethods.h"
#include "XMLFile.h"

using namespace std;

class FileWithExpenses : public XMLFile
{
    int lastExpenseId;

    Expense getExpenseFromFile();

public:
    FileWithExpenses(string fileName) : XMLFile(fileName) {}
    void saveExpenseToFile(Expense expense);
    vector<Expense> loadExpensesFromFile(int idOfLoggedUser);
    int getIdOfLastExpense();
};

#endif