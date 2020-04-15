#include "FileWithIncomes.h"

void FileWithIncomes::saveIncomeToFile(Income income)
{
    CMarkup xml;

    if (isFileEmpty(getFileName()))
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("incomes");
        xml.IntoElem();
    }
    else
    {
        xml.Load(MCD_2PCSZ(getFileName()));
        xml.FindElem();
        xml.IntoElem();
    }

    xml.AddElem("income");
    xml.IntoElem();
    xml.AddElem("incomeId", income.getId());
    xml.AddElem("userId", income.getUserId());
    xml.AddElem("date", OperationsOnDates::convertDateInIntToString(income.getDate()));
    xml.AddElem("item", income.getItem());
    xml.AddElem("amount", income.getAmount());

    xml.Save(MCD_2PCSZ(getFileName()));
}

Income FileWithIncomes::getIncomeFromFile()
{
    CMarkup xml;
    Income income;

    xml.Load(MCD_2PCSZ(getFileName()));

    xml.FindElem();
    xml.IntoElem();

    for (int i = 0; i < lastIncomeId; i++)
    {
        xml.FindElem("income");
    }

    xml.IntoElem();

    xml.FindElem("incomeId");
    income.setId(atoi(MCD_2PCSZ(xml.GetData())));
    xml.FindElem("userId");
    income.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
    xml.FindElem("date");
    income.setDate(OperationsOnDates::convertDateInStringToInt(MCD_2PCSZ(xml.GetData())));
    xml.FindElem("item");
    income.setItem(MCD_2PCSZ(xml.GetData()));
    xml.FindElem("amount");
    income.setAmount(atof(MCD_2PCSZ(xml.GetData())));

    return income;
}

vector<Income> FileWithIncomes::loadIncomesFromFile(int idOfLoggedUser)
{
    CMarkup xml;
    Income income;
    vector<Income> incomes;
    int userIdFromFile;

    lastIncomeId = 0;

    xml.Load(MCD_2PCSZ(getFileName()));

    xml.FindElem();
    xml.IntoElem();

    while (true)
    {
        if (xml.FindElem("income"))
        {
            xml.IntoElem();
            xml.FindElem("incomeId");
            lastIncomeId = atoi(MCD_2PCSZ(xml.GetData()));
            xml.FindElem("userId");
            userIdFromFile = atoi(MCD_2PCSZ(xml.GetData()));
            if (userIdFromFile == idOfLoggedUser)
            {
                income = getIncomeFromFile();
                incomes.push_back(income);
            }
            xml.OutOfElem();
        }
        else
        {
            break;
        }
    }

    return incomes;
}

int FileWithIncomes::getIdOfLastIncome()
{
    return lastIncomeId;
}