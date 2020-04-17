#include "XMLFile.h"

bool XMLFile::isFileEmpty(string fileName)
{
    CMarkup xml;
    if (!xml.Load(MCD_2PCSZ(fileName)))
        return true;
    else
        return false;
}

string XMLFile::getFileName()
{
    return FILE_NAME;
}