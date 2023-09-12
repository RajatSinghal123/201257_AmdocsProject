#include<bits/stdc++.h>
using namespace std;

class validation
{
public:
    bool check_name(string name)
    {
        if(name[0]<65 || name[0]>90)
        {
            return 0;
        }
        for(int i=1; i<name.length(); i++)
        {
            if(name[i]<97 || name[i]>122)
            {
                return 0;
            }
        }
        return 1;
    }
    bool check_mobile(string mb)
    {
        if(mb.length()!=10)
        {
            return 0;
        }
        for(auto &c:mb)
        {
            if(c<48 || c>57)
            {
                return 0;
            }
        }
        return 1;
    }
    bool check_Aadhar(string adh)
    {
        if(adh.length()!=12)
        {
            return 0;
        }
        for(auto &c:adh)
        {
            if(c<48 || c>57)
            {
                return 0;
            }
        }
        return 1;
    }
    bool check_pan(string pan)
    {
        string s1 = pan.substr(0,5);
        string s2 = pan.substr(5,4);

        for(auto &c:s1)
        {
            if(c<65 || c>90)
            {
                return 0;
            }
        }
        for(auto &c:s2)
        {
            if(c<48 || c>57)
            {
                return 0;
            }
        }
        if(pan[pan.length()-1]<65 || pan[pan.length()-1]>90)
        {
            return 0;
        }
        return 1;
    }
};


class BankAccount
{
protected:
    string Account_Numbers;
    string fname,lname,pan,adhar,mobile_no;
public:
    validation v;
    BankAccount(string AC_NO)
    {
        Account_Numbers = AC_NO;
        cout<<endl;
        while(1)
        {
            cout<<"Enter your first name: ";
            cin>>fname;
            if(v.check_name(fname)==1)
            {
                break;
            }
            else
            {
                cout<<"Wrong name !!!"<<endl;
            }
        }
        cout<<endl;

        while(1)
        {
            cout<<"Enter your last name: ";
            cin>>lname;
            if(v.check_name(lname)==1)
            {
                break;
            }
            else
            {
                cout<<"Wrong name !!!"<<endl;
            }
        }
        cout<<endl;

        while(1)
        {
            cout<<"Enter your PAN Card Number: ";
            cin>>pan;
            if(v.check_pan(pan)==1)
            {
                break;
            }
            else
            {
                cout<<"Wrong PAN Number !!!"<<endl;
            }
        }
        cout<<endl;

        while(1)
        {
            cout<<"Enter Your Aadhar Card Number: ";
            cin>>adhar;
            if(v.check_Aadhar(adhar)==1)
            {
                break;
            }
            else
            {
                cout<<"Wrong Aadhar Number !!!"<<endl;
            }
        }
        cout<<endl;

        while(1)
        {
            cout<<"Enter Your Mobile Number: ";
            cin>>mobile_no;
            if(v.check_mobile(mobile_no)==1)
            {
                break;
            }
            else
            {
                cout<<"Wrong Aadhar Number !!!"<<endl;
            }
        }
        cout<<endl<<endl;
        cout<<"Name: "<<fname<<" "<<lname<<endl;
        cout<<"PAN: "<<pan<<endl;
        cout<<"Aadhar No: "<<adhar<<endl;
        cout<<"Mobile No: "<<mobile_no<<endl;

    }
};

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


int main()
{
    cout<<"Hello, Welcome to MyBank"<<endl;
    SavingAccount sa1("SA101",5000);
    //SavingAccount sa2("SA102",5000);
    //SavingAccount sa3("SA103",5000);
    //SavingAccount sa4("SA104",5000);
    //SavingAccount sa5("SA105",5000);


    CurrentAccount ca1("CA101",0);
    //CurrentAccount ca2("CA102",0);
    //CurrentAccount ca3("CA103",0);
    //CurrentAccount ca4("CA104",0);
    ///*CurrentAccount ca5("CA105",0);

    map<string,int> mp1;
    vector<SavingAccount> v1;

    v1.push_back(sa1);
    /*v1.push_back(sa2);
    v1.push_back(sa3);
    v1.push_back(sa4);
    v1.push_back(sa5);*/

    mp1["SA101"] = 0;
    /*mp1["SA102"] = 1;
    mp1["SA103"] = 2;
    mp1["SA104"] = 3;
    mp1["SA105"] = 4;*/




    map<string,int> mp2;
    vector<CurrentAccount> v2;
    v2.push_back(ca1);
    /*v2.push_back(ca2);
    v2.push_back(ca3);
    v2.push_back(ca4);
    v2.push_back(ca5);*/
    mp2["CA101"] = 0;
    /*mp2["CA102"] = 1;
    mp2["CA103"] = 2;
    mp2["CA104"] = 3;
    mp2["CA105"] = 04;*/


    string acn;
    cout<<"Enter Your Account Number: "<<endl;
    cin>>acn;
    if(mp1.find(acn)==mp1.end() && mp2.find(acn)==mp2.end())
    {
        cout<<"You are not resigtered with us"<<endl;
        return 0;
    }

    while(1)
    {
        cout<<endl<<endl;
        cout<<"Enter 1 for Withdrawl"<<endl;
        cout<<"Enter 2 for Deposit"<<endl;
        cout<<"Enter 3 for balance enquiry"<<endl;
        cout<<"Enter 4 for Money transfer"<<endl;
        cout<<"Enter 0 for exit"<<endl;


        if(mp1.find(acn)!=mp1.end())
        {
            int f;
            cin>>f;

            if(f==0)
            {
                break;
            }
            if(f==1)
            {
                cout<<"Enter Money for Withdrawl: ";
                int m;
                cin>>m;
                v1[mp1[acn]].withdrawl(m);
            }
            if(f==2)
            {
                cout<<"Enter money for deposit: ";
                int m;
                cin>>m;
                v1[mp1[acn]].deposite(m);
            }
            if(f==3)
            {
                cout<<"Your Current balance is: "<<v1[mp1[acn]].BalanceInquiry();
            }
            if(f==4)
            {
                int m;
                string s;
                while(1)
                {
                    cout<<"Please Enter Money and Bank account number and enter -1 as money for exit."<<endl;
                    cin>>m;
                    cin>>s;
                    if(m==-1)
                    {
                        break;
                    }
                    if(mp1.find(s)==mp1.end() && mp2.find(s)==mp2.end())
                    {
                        cout<<"Wrong Account Number!!!"<<endl;
                    }
                    else
                    {
                        if(mp1.find(s)!=mp1.end())
                        {
                            int r = v1[mp1[acn]].withdrawl(m);
                            if (r==1)
                            {
                                v1[mp1[s]].deposite(m);
                            }
                        }
                        else
                        {
                            int r = v1[mp1[acn]].withdrawl(m);
                            if(r==1)
                            {
                                v2[mp2[s]].deposite(m);
                            }
                        }
                        break;
                    }
                }
            }
        }
        else
        {
            int f;
            cin>>f;

            if(f==0)
            {
                break;
            }
            if(f==1)
            {
                cout<<"Enter Money for Withdrawl: ";
                int m;
                cin>>m;
                v2[mp2[acn]].withdrawl(m);
            }
            if(f==2)
            {
                cout<<"Enter money for deposit: ";
                int m;
                cin>>m;
                v2[mp2[acn]].deposite(m);
            }
            if(f==3)
            {
                cout<<"Your Current balance is: "<<v1[mp1[acn]].BalanceInquiry();
            }
            if(f==4)
            {
                int m;
                string s;
                while(1)
                {
                    cout<<"Please Enter Money and Bank account number and enter -1 as money for exit."<<endl;
                    cin>>m;
                    cin>>s;
                    if(m==-1)
                    {
                        break;
                    }
                    if(mp1.find(s)==mp1.end() && mp2.find(s)==mp2.end())
                    {
                        cout<<"Wrong Account Number!!!"<<endl;
                    }
                    else
                    {
                        if(mp1.find(s)!=mp1.end())
                        {
                            int r = v2[mp1[acn]].withdrawl(m);
                            if(r==1)
                            {
                                v1[mp1[s]].deposite(m);
                            }
                        }
                        else
                        {
                            int r = v2[mp2[acn]].withdrawl(m);
                            if(r==1)
                            {
                                v2[mp2[s]].deposite(m);
                            }
                        }
                        break;
                    }
                }
            }
        }
        //system("cls");
    }

}
