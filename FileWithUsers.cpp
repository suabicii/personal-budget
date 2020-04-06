#include "FileWithUsers.h"

void FileWithUsers::writeUserToFile(User user)
{
    CMarkup xml;

    if (isFileEmpty(MCD_2PCSZ(getFileName())))
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("users");
    }
    else
    {
        xml.Load(MCD_2PCSZ(getFileName()));
        xml.FindElem();
        xml.IntoElem();
    }

    xml.AddElem("user");
    xml.IntoElem();
    xml.AddElem("userId", user.getId());
    xml.AddElem("login", user.getLogin());
    xml.AddElem("password", user.getPassword());
    xml.AddElem("name", user.getName());
    xml.AddElem("surname", user.getSurname());

    xml.Save(getFileName());
}

vector<User> FileWithUsers::loadUsersFromFile()
{
    User user;
    vector<User> users;
    CMarkup xml;

    xml.Load(MCD_2PCSZ(getFileName()));

    xml.FindElem();
    xml.IntoElem();

    while (true)
    {
        if (xml.FindElem("user"))
        {
            xml.IntoElem();
            xml.FindElem("userId");
            user.setId(atoi(MCD_2PCSZ(xml.GetData())));

            xml.FindElem("login");
            user.setLogin(MCD_2PCSZ(xml.GetData()));

            xml.FindElem("password");
            user.setPassword(MCD_2PCSZ(xml.GetData()));

            xml.FindElem("name");
            user.setName(MCD_2PCSZ(xml.GetData()));

            xml.FindElem("surname");
            user.setSurname(MCD_2PCSZ(xml.GetData()));

            xml.OutOfElem();
            users.push_back(user);
        }
        else
        {
            break;
        }
    }

    return users;
}