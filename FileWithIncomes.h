#ifndef FILE_WITH_INCOMES_H
#define FILE_WITH_INCOMES_H

#include <iostream>
#include <vector>
#include "Income.h"
#include "XMLFile.h"

using namespace std;

class FileWithIncomes : public XMLFile
{
    Income getIncomeFromFile();

public:
    FileWithIncomes(string fileName) : XMLFile(fileName) {}
    void saveIncomeToFile();
    int loadIncomesFromFile();
};

#endif