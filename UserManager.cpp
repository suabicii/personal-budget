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
    user.setName(name);

    cout << "Podaj nazwisko: ";
    surname = AuxiliaryMethods::enterLine();
    user.setSurname(surname);

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