#include <iostream>
#include <vector>
#include "User.h"

using namespace std;

class UserManager
{
    int idOfLoggedUser;
    vector<User> users;
    User enterNewUserData();
    int getIdOfNewUser();
    bool doesLoginExist();

public:
    void registerNewUser();
    void userLogging();
    void userLogout();
    void changePassword();
};