#ifndef FILE_WITH_USERS
#define FILE_WITH_USERS

#include <iostream>
#include <vector>
#include "User.h"
#include "XMLFile.h"

class FileWithUsers : public XMLFile
{
    string replaceUserDataToLinesWithDataSeparatedByVerticalLines();

public:
    FileWithUsers(string fileName) : XMLFile(fileName) {}
    void writeUserToFile(User user);
    vector<User> loadUsersFromFile();
};

#endif