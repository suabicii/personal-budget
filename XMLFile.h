#include <iostream>

using namespace std;

class XMLFile
{
    string fileName;

protected:
    string replaceDataOfPartOfBudgetToLinesWithDataSeparatedByVerticalLines();
    int getIdOfPartOfBudgetFromDataSeparatedByVerticalLines();

public:
    XMLFile();
    bool isFileEmpty();
    void loadFromFile();
    void updateFile();
};