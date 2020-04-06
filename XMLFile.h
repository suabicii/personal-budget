#ifndef XML_FILE_H
#define XML_FILE_H

#include <iostream>
#include "Markup.h"

using namespace std;

class XMLFile
{
    const string FILE_NAME;

protected:
    string replaceDataOfPartOfBudgetToLinesWithDataSeparatedByVerticalLines();
    int getIdOfPartOfBudgetFromDataSeparatedByVerticalLines();
    bool isFileEmpty(string fileName);

public:
    XMLFile(string fileName) : FILE_NAME(fileName)
    {
    }
    void loadFromFile();
    void updateFile();
    string getFileName();
};

#endif