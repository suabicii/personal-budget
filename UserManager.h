#ifndef USER_MANAGER_H
#define USER_MANAGER_H

#include <iostream>
#include <vector>
#include <Windows.h>
#include "User.h"
#include "FileWithUsers.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UserManager
{
    int idOfLoggedUser;
    vector<User> users;
    FileWithUsers fileWithUsers;

    User enterNewUserData();
    int getIdOfNewUser();
    bool doesLoginExist(string login);

public:
    UserManager(string nameOfFileWithUsers) : fileWithUsers(nameOfFileWithUsers)
    {
        idOfLoggedUser = 0;
        fileWithUsers.loadUsersFromFile();
    }
    void registerNewUser();
    void userLogging();
    void userLogout();
    void changePassword();
};

#endif