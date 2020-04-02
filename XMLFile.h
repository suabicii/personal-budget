#ifndef XML_FILE_H
#define XML_FILE_H

#include <iostream>

using namespace std;

class XMLFile
{
    const string FILE_NAME;

protected:
    string replaceDataOfPartOfBudgetToLinesWithDataSeparatedByVerticalLines();
    int getIdOfPartOfBudgetFromDataSeparatedByVerticalLines();

public:
    XMLFile(string fileName) : FILE_NAME(fileName)
    {
    }
    bool isFileEmpty();
    void loadFromFile();
    void updateFile();
};

#endif