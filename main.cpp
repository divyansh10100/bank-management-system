#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
using namespace std;

class account
{
    int pin;
    float balance;
    public:
    float amount;
    float getbal();
    int getpin();
    float deposit();
    float withdraw();
    void pinchange();
}acc;

float account::getbal()
{
    ifstream fin("balance.txt");
    if(!fin)
    {
        cout<<"file unable to open.";
        getch();
        exit(0);
    }
    fin>>balance;
    fin.close();
    return balance;
}

int account::getpin()
{
    ifstream fi("pincode.txt");
    if(!fi)
    {
        cout<<"file unable to open";
        getch();
        exit(0);
    }
    fi>>pin;
    fi.close();
    return pin;
}

float account::deposit()
{
    int newbal=acc.getbal()+acc.amount;
    ofstream fout("balance.txt");
    fout<<newbal;
    fout.close();
    return newbal;
}

float account::withdraw()
{
    float newbal=acc.getbal()-acc.amount;
    ofstream fout("balance.txt");
    fout<<newbal;
    fout.close();
    return newbal;
}

void account::pinchange()
{
    int ch,npin;
    cout<<"enter recent pin\n";
    cin>>ch;
    if(ch==acc.getpin())
    {
        cout<<"enternew pin\n";
        cin>>npin;
        cout<<"re-enter your pin\n";
        cin>>ch;
        if(ch==npin)
        {
            cout<<"your pin is changed\nyour new pin is,-\n"<<npin;
            ofstream fo("pincode.txt");
            fo.put(npin);
            fo.close();
        }
        else
        {
            cout<<"pin doesn't match\n";
            exit(0);
        }
    }
    else
    cout<<"invalid pin";
}

int main()
{
    start:
    int pinch,choice;
    cout<<"\n\tWELCOME TO OUR ACCOUNT MANAGEMENT SERVICE\n";
    cout<<"\nplease enter your pin\n\n";
    cin>>pinch;
    if(pinch==acc.getpin())
    {
        cout<<"enter your choice\n\n";
        cout<<"1. Withdraw\n";
        cout<<"2. Deposit\n";
        cout<<"3. check balance\n";
        cout<<"4. Change pin\n";
        cout<<"5. Exit\n\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"enter the amount to be withdrawn\n";
            cin>>acc.amount;
            acc.withdraw();
            cout<<"your current balance="<<acc.getbal();
            break;
            case 2:
            cout<<"enter the amount to be deposited\n";
            cin>>acc.amount;
            acc.deposit();
            cout<<"your current balance="<<acc.getbal();
            break;
            case 3:
            cout<<"your current balance="<<acc.getbal();
            break;
            case 4:
            acc.pinchange();
            break;
            case 5:
            cout<<"THANK YOU TO USE OUR SERVICE";
            getch();
            exit(0);
            default:
            cout<<"invalid choice";
        }
        cout<<"\n\ndo you want to continue\n";
        cout<<"enter 1 to continue and 2 to exit\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
            goto start;
            case 2:
            cout<<"THANK YOU TO USE OUR SERVICE\n";
            getch();
            exit(0);
            default:
            cout<<"invalid choice\n";
            break;
        }
    }
    else
    cout<<"the pin you entered is incorrect\n";
    getch();
}
