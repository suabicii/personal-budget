#include <iostream>
#include <vector>
#include "User.h"
#include "XMLFile.h"

class FileWithUsers : public XMLFile
{
    const string NAME_OF_FILE_WITH_USERS;

    string replaceUserDataToLinesWithDataSeparatedByVerticalLines();

public:
    FileWithUsers();
    void writeUserToFile();
    vector<User> loadUsersFromFile();
};