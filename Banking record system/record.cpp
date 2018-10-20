#include "record.h"

unsigned int Bank::counter = 0;
void Bank::AddRecord()
{
    int n;
    string fn, ln;
    double b;
    if(counter > 0)
    {
        BankAccount temp[counter];
        for(int i = 0; i < counter; i++)
        {
            temp[i].account_number = tab[i].account_number;
            temp[i].first_name = tab[i].first_name;
            temp[i].last_name = tab[i].last_name;
            temp[i].balance = tab[i].balance;
        }

        delete [] tab;

        tab = new BankAccount[counter + 1];

        for(int i = 0; i < counter; i++)
        {
            tab[i].account_number = temp[i].account_number;
            tab[i].first_name = temp[i].first_name;
            tab[i].last_name = temp[i].last_name;
            tab[i].balance = temp[i].balance;
        }

        //delete [] temp;
        //cout << " aaaaaaaaaa";
    }
    else
    {
        tab = new BankAccount[counter + 1];
    }
    //cout << counter_a;
    cout << "Enter account number: ";
    while(!(cin >> n))
    {
        cin.clear();
        while(cin.get() != '\n')
        {
            continue;
        }
        cout << "Wrong! Enter appropriate account number: ";
    }
    tab[counter].account_number = n;
    cout << "Enter first name: ";
    cin >> fn;
    cout << "Enter last name: ";
    cin >> ln;
    cout << "Enter balance: ";
    while(!(cin >> b))
    {
        cin.clear();
        while(cin.get() != '\n')
        {
            continue;
        }
        cout << "Wrong! Enter appropriate balance: ";
    }
    tab[counter].balance = b;
    tab[counter].first_name = fn;
    //cout << "sadsda";
    tab[counter].last_name = ln;
    counter++;

}
void Bank::Show(int n) const
{
    bool flag = 0;
    for(int i = 0; i < counter; i++)
        if(n == tab[i].account_number)
        {
            //cout << "Account number: " << account_number << endl;
            cout << "First name: " << tab[i].first_name << endl;
            cout << "Last name: " << tab[i].last_name << endl;
            cout << "Current balance: " << tab[i].balance << endl;
            flag++;
        }
    if(!flag)
        cout << "Bank account with such number does not exist" << endl;

}
void Bank::ShowData() const
{
    if(counter > 0)
    {
        for(int i = 0; i < counter; i++)
        {
            cout << "\t " << i + 1 << endl;
            cout << "Account number: " << tab[i].account_number << endl;
            cout << "First name: " << tab[i].first_name << endl;
            cout << "Last name: " << tab[i].last_name << endl;
            cout << "Current balance: " << tab[i].balance << endl;
            cout << endl;
        }
    }
    else
        cout << "There are not any bank accounts" << endl;
}
void Bank::SearchRecord()
{
    int record_number;
    RecordNumbers();
    cout << "Enter record number that you want to see or q if you want to come back to main menu: ";
    if(cin >> record_number)
        Show(record_number);
    //cin.ignore(INT_MAX);
    cin.clear();
    while(cin.get() != '\n')
    {
        continue;
    }

}
void Bank::EditRecord(int n)
{
    int an;
    string fn, ln;
    double b;
    bool flag = 0;
    for(int i = 0; i < counter; i++)
        if(n == tab[i].account_number)
        {
            cout << "Record number " << n << " has the following data\n";
            Show(n);
            cout << endl;
            cout << "Enter data to modify:\n";
            cout << "Enter account number: ";
            cin >> an;
            cout << "Enter first name: ";
            cin >> fn;
            cout << "Enter last name: ";
            cin >> ln;
            cout << "Enter balance: ";
            cin >> b;

            tab[i].account_number = an;

            tab[i].first_name = fn;
            //cout << "sadsda";
            tab[i].last_name = ln;
            tab[i].balance = b;
            flag++;
        }
        if(!flag)
            cout << "Record with such number does not exist" << endl;
}
void Bank::RecordNumbers()
{
    cout << "Recently there are " << GetCounter() << " records" << endl;
    cout << "All records numbers below: " << endl;
    for(int i = 0; i < counter; i++)
        cout << tab[i].account_number << endl;
}
void Bank::DeleteRecord(int n)
{
    bool flag = 0;
    if(counter > 0)
    {
        for(int i = 0; i < counter; i++)
        {
            if(n == tab[i].account_number)
            {
                BankAccount temp[counter];
                for(int i = 0; i < counter - 1; i++)
                {
                    temp[i].account_number = tab[i].account_number;
                    temp[i].first_name = tab[i].first_name;
                    temp[i].last_name = tab[i].last_name;
                    temp[i].balance = tab[i].balance;
                }

                delete [] tab;
                counter--;
                tab = new BankAccount[counter];

                for(int i = 0; i < counter; i++)
                {
                    tab[i].account_number = temp[i].account_number;
                    tab[i].first_name = temp[i].first_name;
                    tab[i].last_name = temp[i].last_name;
                    tab[i].balance = temp[i].balance;
                }
                flag++;
            }
        }
    }
    else
    {
        cout << "There are not any bank accounts" << endl;
        flag++;
    }
    if(!flag)
        cout << "Bank account with such number does not exist" << endl;
}
Bank:: Bank()
{
    tab = new BankAccount[counter];
}

Bank:: ~Bank()
{
    delete [] tab;
}

BankAccount::BankAccount(int n, string fn, string ln, double b)
{
    account_number = n;
    first_name = fn;
    last_name = ln;
    balance = b;
    //counter_a++;
}

void Menu::Background() const
{
    cout << "\t\t\t\t\t ACCOUNT INFORMATION SYSTEM" << endl;
    cout << "\t\t\t\t Select option:" << endl;
    cout << "\t\t\t\t 1 -> Add record to file\n"
         "\t\t\t\t 2 -> Show record\n"
         "\t\t\t\t 3 -> Show all records\n"
         "\t\t\t\t 4 -> Search record from file\n"
         "\t\t\t\t 5 -> Update record \n"
         "\t\t\t\t 6 -> Delete record\n"
         "\t\t\t\t 7 -> Quit\n"
         "\t\t\t\t Enter your choice: ";
}
void Menu:: Show() const
{

    int option;
    int record_number;
    Bank bank;
    Background();
    cin >> option;
    while(option != 7)
    {
        switch(option)
        {
        case 1:
            ClearScreen();
            cout << "Recently there are " << bank.GetCounter() << " records" << endl;
            bank.AddRecord();
            getchar();
            ClearScreen();
            break;
        case 2:
            ClearScreen();
            cout << "Enter record number that you want to see: ";
            if(cin >> record_number)
                bank.Show(record_number);
            cin.clear();
            while(cin.get() != '\n')
            {
                continue;
            }
            ClearScreen();
            break;
        case 3:
            ClearScreen();
            cout << "Recently there are " << bank.GetCounter() << " records" << endl;
            bank.ShowData();
            while(cin.get() != '\n')
            {
                continue;
            }
            system("cls");
            break;
        case 4:
            ClearScreen();
            bank.SearchRecord();
            ClearScreen();
            break;
        case 5:
            ClearScreen();
            bank.RecordNumbers();
            cout << "Enter record number that you want to modify or q if you want to come back to main menu: ";
            if(cin >> record_number)
                bank.EditRecord(record_number);
            cin.clear();
            while(cin.get() != '\n')
            {
                continue;
            }
            ClearScreen();
            break;
        case 6:
            ClearScreen();
            bank.RecordNumbers();
            cout << "Enter record number that you want to delete or q if you want to come back to main menu: ";
            if(cin >> record_number)
                bank.DeleteRecord(record_number);
            cin.clear();
            while(cin.get() != '\n')
            {
                continue;
            }
            ClearScreen();
            break;
        }
        Background();
        cin >> option;
    }
}


