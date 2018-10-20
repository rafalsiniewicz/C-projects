#ifndef RECORD_H
#define RECORD_H
#include<iostream>
#include<string>
#include<windows.h>
#include<stdio.h>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::copy;

class Bank;
class BankAccount
{
friend class Bank;
private:

    int account_number;
    string first_name;
    string last_name;
    double balance;
public:
    BankAccount(int n = 0, string fn = "no first name" , string ln = "no last name" , double b = 0.0);

};
class Bank
{
//friend class BankAccount;
private:
    static unsigned int counter;
    BankAccount* tab;
public:
    void AddRecord();
    void Show(const int n) const;
    void ShowData() const;
    void SearchRecord();
    void EditRecord(const int n);
    void DeleteRecord(const int n);
    void RecordNumbers();
    static int GetCounter()
    {
        return counter;
    }
    Bank();
    ~Bank();
};
class Menu
{
private:
public:
    void Show() const;
    void ClearScreen() const
    {
        getchar();
        system("cls");
    }
    void Background() const;
};


#endif // RECORD_H
