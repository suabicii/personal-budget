#ifndef FILE_WITH_INCOMES_H
#define FILE_WITH_INCOMES_H

#include <iostream>
#include <vector>
#include "Income.h"
#include "XMLFile.h"
#include "OperationsOnDates.h"
#include "Markup.h"

using namespace std;

class FileWithIncomes : public XMLFile
{
    int lastIncomeId;

    Income getIncomeFromFile();

public:
    FileWithIncomes(string fileName) : XMLFile(fileName) {}
    void saveIncomeToFile(Income income);
    vector<Income> loadIncomesFromFile(int idOfLoggedUser);
    int getIdOfLastIncome();
};

#endif