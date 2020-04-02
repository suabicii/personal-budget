#include <iostream>

using namespace std;

class User
{
    int id;
    string name;
    string surname;
    string login;
    string password;

public:
    int setId(int newId);
    string setName(string newName);
    string setSurname(string newSurname);
    string setLogin(string newLogin);
    string setPassword(string newPassword);
    int getId();
    string getName();
    string getSurname();
    string getLogin();
    string getPassword();
};