#include<bits/stdc++.h>
using namespace std;
class CurrentAccount : public BankAccount
{
    int current_account_balance;
public:
    CurrentAccount(string acn,int cab):BankAccount(acn)
    {
        current_account_balance = 0;
    }
    int withdrawl(int amount)
    {
        if(amount<=0)
        {
            cout<<"Amount can not be negative!!!"<<endl;
            return 0;
        }
        if(amount>current_account_balance)
        {
            cout<<"You can not Withdrawl"<<endl;
            return 0;
        }
        current_account_balance = current_account_balance - amount;
        cout<<"You have withdrawl "<<amount<<endl;
        cout<<"Now Your Current Account balance is - "<<current_account_balance<<endl;
        return 1;
    }
    void deposite(int amount)
    {
        if(amount<=0)
        {
            cout<<"Amount can not be negative!!!"<<endl;
            return ;
        }
        current_account_balance = current_account_balance + amount;
        cout<<"You have depositted "<<amount<<endl;
        cout<<"Now Your Current Account balance is - "<<current_account_balance<<endl;
    }
    int BalanceInquiry()
    {
        return current_account_balance;
    }
};
