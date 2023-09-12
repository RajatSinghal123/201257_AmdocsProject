#include<bits/stdc++.h>
using namespace std;
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
        cout<<"Name: "<<adhar<<endl;
        cout<<"Name: "<<mobile_no<<endl;

    }
};
