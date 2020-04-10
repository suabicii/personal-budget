#include "FileWithExpenses.h"

void FileWithExpenses::saveExpenseToFile(Expense expense)
{
    CMarkup xml;

    if (isFileEmpty(getFileName()))
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("expenses");
        xml.IntoElem();
    }
    else
    {
        xml.Load(MCD_2PCSZ(getFileName()));
        xml.FindElem();
        xml.IntoElem();
    }

    xml.AddElem("expense");
    xml.IntoElem();
    xml.AddElem("expenseId", expense.getId());
    xml.AddElem("userId", expense.getUserId());
    xml.AddElem("date", AuxiliaryMethods::convertDateInIntToString(expense.getDate()));
    xml.AddElem("item", expense.getItem());
    xml.AddElem("amount", expense.getAmount());

    xml.Save(MCD_2PCSZ(getFileName()));
}

Expense FileWithExpenses::getExpenseFromFile()
{
    CMarkup xml;
    Expense expense;

    xml.Load(MCD_2PCSZ(getFileName()));

    xml.FindElem();
    xml.IntoElem();

    for (int i = 0; i < lastExpenseId; i++)
    {
        xml.FindElem("expense");
    }

    xml.IntoElem();

    xml.FindElem("expenseId");
    expense.setId(atoi(MCD_2PCSZ(xml.GetData())));
    xml.FindElem("userId");
    expense.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
    xml.FindElem("date");
    expense.setDate(AuxiliaryMethods::convertDateInStringToInt(MCD_2PCSZ(xml.GetData())));
    xml.FindElem("item");
    expense.setItem(MCD_2PCSZ(xml.GetData()));
    xml.FindElem("amount");
    expense.setAmount(atof(MCD_2PCSZ(xml.GetData())));

    return expense;
}

vector<Expense> FileWithExpenses::loadExpensesFromFile(int idOfLoggedUser)
{
    CMarkup xml;
    Expense expense;
    vector<Expense> expenses;
    int userIdFromFile;

    lastExpenseId = 0;

    xml.Load(MCD_2PCSZ(getFileName()));

    xml.FindElem();
    xml.IntoElem();

    while (true)
    {
        if (xml.FindElem("expense"))
        {
            xml.IntoElem();
            xml.FindElem("expenseId");
            lastExpenseId = atoi(MCD_2PCSZ(xml.GetData()));
            xml.FindElem("userId");
            userIdFromFile = atoi(MCD_2PCSZ(xml.GetData()));
            if (idOfLoggedUser == userIdFromFile)
            {
                expense = getExpenseFromFile();
                expenses.push_back(expense);
            }
            xml.OutOfElem();
        }
        else
        {
            break;
        }
    }

    return expenses;
}

int FileWithExpenses::getIdOfLastExpense()
{
    return lastExpenseId;
}