#include "User.h"

int User::setId(int newId)
{
    id = newId;
}

string User::setName(string newName)
{
    name = newName;
}

string User::setSurname(string newSurname)
{
    surname = newSurname;
}

string User::setLogin(string newLogin)
{
    login = newLogin;
}

string User::setPassword(string newPassword)
{
    password = newPassword;
}

int User::getId()
{
    return id;
}

string User::getName()
{
    return name;
}

string User::getSurname()
{
    return surname;
}

string User::getLogin()
{
    return login;
}

string User::getPassword()
{
    return password;
}