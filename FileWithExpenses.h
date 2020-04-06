#ifndef FILE_WITH_EXPENSES
#define FILE_WITH_EXPENSES

#include <iostream>
#include <vector>
#include "Expense.h"
#include "XMLFile.h"

using namespace std;

class FileWithExpenses : public XMLFile
{
    Expense getExpenseFromFile();

public:
    FileWithExpenses(string fileName) : XMLFile(fileName) {}
    void saveExpenseToFile();
    int loadExpensesFromFile();
};

#endif