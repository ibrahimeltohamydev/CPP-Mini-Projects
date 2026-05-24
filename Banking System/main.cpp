#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;

struct BankAccount
{
  string name;
  int accountNumber;
  double balance;
};

void CreateAccount(vector<BankAccount> &accounts);
void ViewAccount(vector<BankAccount> &accounts);
void LoadAccounts(vector<BankAccount>& accounts);





int main()
{
    
    vector<BankAccount> accounts;
    LoadAccounts(accounts);
    cout <<"Welcome to Bank system"<<endl;

int choice;

do
{
cout <<"Menu System: "<<endl;
    cout <<"1. Create Account\n";
    cout <<"2. View Accounts\n";
    cout <<"0. Exit\n";
    
    
    cout <<"Enter the choice: \n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        CreateAccount(accounts);
        break;
    case 2:
        ViewAccount(accounts);
        break;
    case 0:
        cout <<"Exited";
        break;

    default:
          cout<<"Invalid choice\n";
        break;
    }

}while(choice != 0);

    

    return 0;
}

void CreateAccount(vector<BankAccount> &accounts)
{

    ofstream addAccount("Bank_Accounts.txt", ios::app);  //Writing
    BankAccount Bc;
    cout <<"Enter your name: \n";
    cin.ignore();
    getline(cin, Bc.name);
    cout <<"Enter account number: \n";
    cin>>Bc.accountNumber;
    cout <<"Enter initial balance: \n";
    cin>>Bc.balance;

    addAccount << Bc.name << " " << Bc.accountNumber << " " << Bc.balance << endl;
    addAccount.close();

    accounts.push_back(Bc);
}

void LoadAccounts(vector<BankAccount> &accounts)
{
   ifstream readAccount("Bank_Accounts.txt");
   BankAccount Bc;
   readAccount >> Bc.name >> Bc.accountNumber >> Bc.balance;
   readAccount.close();
}
void ViewAccount(vector<BankAccount> &accounts)
{
   if(accounts.empty())
   {
    cout <<"No accounts found.\n";
   }

for(int i = 0; i < accounts.size(); i++)
{       
        cout << "Account# " << i + 1 << endl;
        cout << "Name: "<< accounts[i].name << endl;
        cout << "Account Number: " << accounts[i].accountNumber <<endl;
        cout << "Balance: " << accounts[i].balance << endl;
        cout<<"*****************\n";
        
}

}