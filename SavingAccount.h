#include<bits/stdc++.h>
using namespace std;
class SavingAccount : public BankAccount
{
    int Saving_account_balance;
public:
    SavingAccount(string acn,int sab):BankAccount(acn)
    {
        Saving_account_balance = sab;
    }
    int withdrawl(int amount)
    {
        if(amount<=0)
        {
            cout<<"Amount can not be negative!!!"<<endl;
            return 0;
        }
        if(Saving_account_balance-amount<5000)
        {
            cout<<"You Can not Withdrawl"<<endl;
            return 0;
        }
        Saving_account_balance = Saving_account_balance - amount;
        cout<<"You have withdrawl "<<amount<<endl;
        cout<<"Now Your Saving Account balance is - "<<Saving_account_balance<<endl;
        return 1;
    }
    void deposite(int amount)
    {
        if(amount<=0)
        {
            cout<<"Amount can not be negative!!!"<<endl;
            return ;
        }
        Saving_account_balance = Saving_account_balance + amount;
        cout<<"You have depositted "<<amount<<endl;
        cout<<"Now Your Saving Account balance is - "<<Saving_account_balance<<endl;
    }
    int BalanceInquiry()
    {
        return Saving_account_balance;
    }
    int interest(int rate)
    {
        Saving_account_balance*=(1+rate/100);
        return Saving_account_balance;
    }
};
