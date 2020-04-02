#include <iostream>
#include <vector>
#include "Expense.h"
#include "XMLFile.h"

using namespace std;

class FileWithExpenses : public XMLFile
{
    const string NAME_OF_FILE_WITH_EXPENSES;

    Expense getExpenseFromFile();

public:
    FileWithExpenses();
    void saveExpenseToFile();
    int loadExpensesFromFile();
};