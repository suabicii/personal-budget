#ifndef FILE_WITH_USERS
#define FILE_WITH_USERS

#include <iostream>
#include <vector>
#include <Windows.h>
#include <cstdio>
#include "User.h"
#include "XMLFile.h"

class FileWithUsers : public XMLFile
{

public:
    FileWithUsers(string fileName) : XMLFile(fileName) {}
    void writeUserToFile(User user);
    vector<User> loadUsersFromFile();
    void writeAllUsersToFile(vector<User> &users);
};

#endif