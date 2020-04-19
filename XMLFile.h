#ifndef XML_FILE_H
#define XML_FILE_H

#include <iostream>
#include "Markup.h"

using namespace std;

class XMLFile
{
    const string FILE_NAME;

protected:
    bool fileExists(string fileName);

public:
    XMLFile(string fileName) : FILE_NAME(fileName)
    {
    }
    string getFileName();
};

#endif