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
    string currentDate = "";
    float amount = 0;
    Income income;
    char choice;

    income.setId(fileWithIncomes.getIdOfLastIncome() + 1);
    income.setUserId(ID_OF_LOGGED_USER);

    while (true)
    {
        system("cls");
        cout << "Wybierz jakiej daty dotyczy dany przychod:" << endl;
        cout << "1. Dzisiejsza" << endl;
        cout << "2. Inna" << endl;
        cout << "Twoj wybor: ";
        choice = AuxiliaryMethods::enterChar();

        if (choice == '1')
        {
            currentDate = OperationsOnDates::getCurrentDate();
            income.setDate(OperationsOnDates::convertDateInStringToInt(currentDate));
            break;
        }
        else if (choice == '2')
        {
            cout << "Podaj date przychodu (format: rrrr-mm-dd): ";
            date = OperationsOnDates::addDate();
            income.setDate(OperationsOnDates::convertDateInStringToInt(date));
            break;
        }
        else
        {
            cout << "Nie ma takiej opcji." << endl;
            Sleep(1500);
        }
    }

    cout << "Napisz, czego dotyczy dany przychod: ";
    item = AuxiliaryMethods::enterLine();
    income.setItem(item);

    cout << "Podaj kwote przychodu: ";
    cin >> amount;
    income.setAmount(amount);

    return income;
}

vector<Income> IncomesManager::getIncomes()
{
    return incomes;
}