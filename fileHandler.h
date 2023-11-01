#include <iostream>
#include <fstream>
using namespace std;
void withdraw_FH()
{
    // linthu
restart:
    int cid;
    cout << "Enter Customer id : ";
    cin >> cid;

    string accNumber, id, name, Balance;
    string file = "customer/" + to_string(cid) + ".txt";
start:
    ifstream readFile(file);
    if (readFile.is_open())
    {
        readFile >> accNumber >> id >> name >> Balance;
        readFile.close();
        int amount;
        cout << "\nAccount Balance of " + name + " is : " + Balance + " Rs" << endl;
        cout << "Enter Withdrawal amount : ";
        cin >> amount;

        int bal = stoi(Balance);
        if (bal >= amount)
        {
            bal = bal - amount;
            ofstream writeFile(file);
            writeFile << accNumber << " " << id << " " << name << " " << bal;
            writeFile.close();
            cout << "\nWithdrawal success..." << endl;
            cout<<endl;
            cout << "Balance Amount is : " << bal << " Rs" << endl;

            int input;
        endMenu:
            cout << endl;
            cout << "1.  Another Withdraw ?." << endl;
            cout << "2.  Go to Main Menu" << endl;
            cout << "\nChoose Option : ";

            cin >> input;
            switch (input)
            {
            case 1:
                goto start;
                break;
            case 2:
                admin_Menu();
                break;
            default:
                goto endMenu;
                break;
            }
        }
        else
        {
            cout << "Withdrawal Failed... enter availabe amount.." << endl;
            goto start;
        }
    }
    else
    {
        cout << "Account Not Found !!!";
        goto restart;
    }
}

void deposit_FH()
{
    labelrestart:
    int cid;
    cout << "Enter Customer id : ";
    cin >> cid;
    labeldeposit:

    string accNumber, id, name, Balance;
    string file = "customer/" + to_string(cid) + ".txt";
    ifstream myFile(file);
    if (myFile.is_open())
    {
        myFile >> accNumber >> id >> name >> Balance;
        cout<<"account balance is :"<< Balance;
        cout<<endl;
        int amount;
        cout << "Enter Deposit amount : ";
        cin >> amount;

            int bal = stoi(Balance);
            bal = bal + amount;
            myFile.close();
            ofstream myFile2(file);
            myFile2 << accNumber << " " << id << " " << name << " " << bal;
            myFile2.close();
            cout << " Deposit success.." << endl;
            cout<<endl;
            cout<<"now balance is :"<< bal;
            cout<<endl;
         int input;
        endMenu:
            cout << endl;
            cout << "1.  Another Deposit ?." << endl;
            cout << "2.  Go to Main Menu" << endl;
            cout << "\nChoose Option : ";

            cin >> input;
            switch (input)
            {
            case 1:
                goto labeldeposit;
                break;
            case 2:
                admin_Menu();
                break;
            default:
                goto endMenu;
                break;
            }

    }
    else
    {
        cout << "account not found";
        goto labelrestart;
    }
}

void create_Customer_Account(int customer_id, int account_Number, string customer_Name, int Balance)
{

    string file = "customer/" + to_string(customer_id) + ".txt";
    ofstream myFile(file);
    if (myFile.is_open())
    {
        myFile << account_Number << " " << customer_id << " " << customer_Name << " " << Balance;
        cout << "Account details saved successfully" << endl;
        myFile.close();
    }
    else
    {
        cout << "unable to open" << endl;
    }
}



void view_Customer_Account()
{


    start:

    int acc,accNumber;
    string  id, name, Balance;

    cout << "\nEnter the Account ID : "<< endl;
    cin >> acc;
    cout << endl;

    string file;
    file = "customer/" + to_string(acc) + ".txt";


    ifstream myFile(file);
    if (myFile.is_open())
    {
        myFile >> accNumber >> id >> name >> Balance;

                cout << "Account Number : " << accNumber << endl;
                cout << "Name : " << name << endl;
                cout << "Id : " << id << endl;
                cout << "Account Balance : " << Balance << endl;

        myFile.close();

    endMenu:
         int input;

            cout << endl;
            cout << "1) View another customer." << endl;
            cout << "2) Back" << endl;
            cout << "3) Go to Main Menu" << endl;
            cout << "\nChoose Option : ";

            cin >> input;
            switch (input)
            {
            case 1:
                goto start;
                break;
            case 2:
                customer_Account_Menu();
                break;
            case 3:
                admin_Menu();
                break;
            default:
                goto endMenu;
                break;

        // loop to view another customer or return to previous menu

            }
    }
    else
    {
        cout << "The Customer File isn't Found " << endl;
        goto start;
    }
}

void view_Staff_Account()
{
    start:

    int sid;
    string name, id, address, number;

    cout << "\nEnter the Staff ID : "<< endl;
    cin >> sid;

    string file = "staff/" + to_string(sid) + ".txt";
    ifstream myFile(file);
    if (myFile.is_open())
    {
        myFile >> name >> id >> address >> number;
        {
            cout << "Staff Id : " << name << endl;
            cout << "Staff Name: " << id << endl;
            cout << "Staff Address : " << address << endl;
            cout << "Staff Contact Number : " << number << endl;
        }
        myFile.close();

    endMenu:
         int opt;

            cout << endl;
            cout << "1) View another Staff." << endl;
            cout << "2) Back" << endl;
            cout << "3) Go to Main Menu" << endl;
            cout << "\nChoose Option : ";
            cin >> opt;

            switch (opt)
            {
            case 1:
                goto start;
                break;
            case 2:
                staff_Account_Menu();
                break;
            case 3:
                admin_Menu();
                break;
            default:
                goto endMenu;
                break;

        // loop to view another staff or return to previeous menu
            }
    }
    else
    {
        cout << "The Staff File isn't Found" << endl;
        goto start;
    }
}

void view_All_Customer_Account()
{

    cout << "All Customer account" << endl;
    // back to previeous menu
}

void view_All_Staff_Account()
{

    cout << "All staff account" << endl;
    // back to previeous menu
}
