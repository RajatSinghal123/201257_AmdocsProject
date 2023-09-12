#include<bits/stdc++.h>
#include "Validation.h"
#include "BankAccount.h"
#include "SavingAccount.h"
#include "CurrentAccount.h"
using namespace std;

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
