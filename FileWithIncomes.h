#include <iostream>
#include <vector>
#include "Income.h"
#include "XMLFile.h"

using namespace std;

class FileWithIncomes : public XMLFile
{
    const string NAME_OF_FILE_WITH_INCOMES;

    Income getIncomeFromFile();

public:
    FileWithIncomes();
    void saveIncomeToFile();
    int loadIncomesFromFile();
};