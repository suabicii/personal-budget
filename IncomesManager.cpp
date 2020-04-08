#include "IncomesManager.h"

void IncomesManager::addIncome()
{
    Income income;

    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl;
    cout << endl;

    income = addDataOfIncome();

    incomes.push_back(income);

    fileWithIncomes.saveIncomeToFile(income);

    cout << "Przychod zostal dodany" << endl;
    Sleep(1500);
}

Income IncomesManager::addDataOfIncome()
{
    string date = "";
    string item = "";
    float amount = 0;
    Income income;

    income.setId(getIdOfNewIncome());
    income.setUserId(ID_OF_LOGGED_USER);

    cout << "Podaj date przychodu (format: rrrr-mm-dd): ";
    date = AuxiliaryMethods::addDate();
    income.setDate(AuxiliaryMethods::convertDateInStringToInt(date));

    cout << "Napisz, czego dotyczy dany przychod: ";
    item = AuxiliaryMethods::enterLine();
    income.setItem(item);

    cout << "Podaj wyosokosc przychodu: ";
    cin >> amount;
    income.setAmount(amount);

    return income;
}

void IncomesManager::displayIncomes()
{
    cout << "Przychody:" << endl;
    for (int i = 0; i < incomes.size(); i++)
    {
        cout << "id: " << incomes[i].getId() << "|";
        cout << "id uzytkownika: " << incomes[i].getUserId() << "|";
        cout << "Data: " << incomes[i].getDate() << "|";
        cout << "Rodzaj: " << incomes[i].getItem() << "|";
        cout << "Wysokosc: " << incomes[i].getAmount() << endl;
    }
    system("pause");
}

int IncomesManager::getIdOfNewIncome()
{
    return fileWithIncomes.getIdOfLastIncome() + 1;
}