#include <iostream>
#include <vector>

using namespace std;
struct Account
{
    string username;
    string password;
    string site;
};

void Add_Account(vector<Account> &accounts);
void View_Account(vector<Account> &accounts);
void Search_Account(vector<Account> &accounts);
void Search_By_Username(vector<Account> &accounts);
void Search_By_Site(vector<Account> &accounts);

int main()
{
    cout << "🔐 Welcome to Password Manager 🔐" << endl;

    vector<Account> accounts;

    int choice;

    do
    {
        cout << "⚙️ Menu System: " << endl;
        cout << "Enter ➡️ 1: Add Account" << endl;
        cout << "Enter ➡️ 2: view Account" << endl;
        cout << "Enter ➡️ 3: Search Account" << endl;
        cout << "Enter ➡️ 0: Exit" << endl;
        cout << "Enter an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Add_Account(accounts);
            cout << "✅Account added successfully.\n";

            break;
        case 2:
            View_Account(accounts);
            break;
        case 3:
            Search_Account(accounts);
            break;
        case 0:
            cout << "Exit";
            break;
        default:
            cout << "Invalid choice";
        }

    } while (choice != 0);

    return 0;
}

void Add_Account(vector<Account> &accounts) // Function To Add Account
{
    Account acc;

    cout << "Enter site: ";
    cin >> acc.site;

    cout << "Enter username: ";
    cin >> acc.username;

    cout << "Enter password: ";
    cin >> acc.password;

    accounts.push_back(acc);
}

void View_Account(vector<Account> &accounts) // Function To view Account
{
    if (accounts.empty())
    {
        cout << "No accounts found\n";
    }

    for (int i = 0; i < accounts.size(); i++)
    {
        cout << "Account #" << i + 1 << endl;
        cout << "Site: " << accounts[i].site << endl;
        cout << "Username: " << accounts[i].username << endl;
        cout << "Password: " << accounts[i].password << endl;
        cout << "-------------------------" << endl;
    }
}

void Search_Account(vector<Account> &accounts) // Function To Search Account
{

    cout << "Welecome to Search Menu: " << endl;
    cout << "Enter 1 to serch username\n";
    cout << "Enter 2 to serch site\n";
    cout << "============================\n";

    int choice_search;
    cin >> choice_search;

    switch (choice_search)
    {
    case 1:
        Search_By_Username(accounts);
        break;
    case 2:
        Search_By_Site(accounts);
        break;
    default:
        cout << "Invalid choice! \n";
    }
}

void Search_By_Username(vector<Account> &accounts)
{
    string Username;
    cout << "Enter the Username to search:\n";
    cin >> Username;

    bool found = false;
    for (int i = 0; i < accounts.size(); i++)
    {
        if (accounts[i].username == Username)
        {
            cout << "\nAccount Found: \n";
            cout << "Site: " << accounts[i].site << endl;
            cout << "Username: " << accounts[i].username << endl;
            cout << "Password: " << accounts[i].password << endl;
            cout << "-------------------------" << endl;

            found = true;
        }
    }

    if (!found)
    {
        cout << "No account found with this username.\n";
    }
}
void Search_By_Site(vector<Account> &accounts)
{
    string Site;
    cout << "Enter the Site to search:\n";
    cin >> Site;

    bool found = false;
    for (int i = 0; i < accounts.size(); i++)
    {
        if (accounts[i].site == Site)
        {
            cout << "\nAccount Found: \n";
            cout << "Site: " << accounts[i].site << endl;
            cout << "Username: " << accounts[i].username << endl;
            cout << "Password: " << accounts[i].password << endl;
            cout << "-------------------------" << endl;

            found = true;
        }
    }

    if (!found)
    {
        cout << "No account found with this site.\n";
    }
}
