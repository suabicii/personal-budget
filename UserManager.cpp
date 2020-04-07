#include "UserManager.h"

User UserManager::enterNewUserData()
{
    User user;
    string name;
    string surname;
    string login;
    string password;

    user.setId(getIdOfNewUser());

    cout << "Podaj imie: ";
    name = AuxiliaryMethods::enterLine();
    user.setName(AuxiliaryMethods::changeFirstLetterToBigAndRestToSmall(name));

    cout << "Podaj nazwisko: ";
    surname = AuxiliaryMethods::enterLine();
    user.setSurname(AuxiliaryMethods::changeFirstLetterToBigAndRestToSmall(surname));

    do
    {
        cout << "Podaj login: ";
        login = AuxiliaryMethods::enterLine();
        user.setLogin(login);
    } while (doesLoginExist(login));

    cout << "Podaj haslo: ";
    password = AuxiliaryMethods::enterLine();
    user.setPassword(password);

    return user;
}

void UserManager::registerNewUser()
{
    User user = enterNewUserData();

    users.push_back(user);
    fileWithUsers.writeUserToFile(user);

    cout << "Konto zalozone pomyslnie" << endl;
    Sleep(1500);
}

int UserManager::getIdOfNewUser()
{
    if (users.empty())
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::doesLoginExist(string login)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl;
            cout << "Istnieje uzytkownik o podanym loginie";
            return true;
        }
    }
    return false;
}

void UserManager::userLogging()
{
    User user;
    string login = "", password = "";
    vector<User>::iterator it;

    cout << endl;
    cout << "Podaj login: ";
    login = AuxiliaryMethods::enterLine();

    for (it = users.begin(); it != users.end(); it++)
    {
        if (it->getLogin() == login)
        {
            for (int i = 3; i > 0; i--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << i << ": ";
                password = AuxiliaryMethods::enterLine();

                if (it->getPassword() == password)
                {
                    cout << endl;
                    cout << "Zalogowales(-as) sie" << endl;
                    Sleep(1500);
                    idOfLoggedUser = it->getId();
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            Sleep(1500);
            return;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl;
    cout << endl;
    Sleep(1500);
}

void UserManager::displayAllUsers()
{
    for (int i = 0; i < users.size(); i++)
    {
        cout << users[i].getId() << "|";
        cout << users[i].getLogin() << "|";
        cout << users[i].getPassword() << endl;
    }
}

bool UserManager::isUserLoggedIn()
{
    if (idOfLoggedUser > 0)
        return true;
    else
        return false;
}

int UserManager::getIdOfLoggedUser()
{
    return idOfLoggedUser;
}