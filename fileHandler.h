#include <iostream>
#include <fstream>
using namespace std;
void withdraw_FH(int cid)
{
    // linthu
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
            // readFile.close();
            ofstream writeFile(file);
            writeFile << accNumber << " " << id << " " << name << " " << bal;
            writeFile.close();
            cout << "\nWithdrawal success..." << endl;
            cout << "Balance Amount is : " << bal << " Rs" << endl;

            int input;
        endMenu:
            cout << endl;
            cout << "1) Another Withdraw ?." << endl;
            cout << "2) Go to Main Menu" << endl;
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
        cout << "unable to open";
    }
}

void deposit_FH(int cid)
{
    int amount;
    cout << "Enter Deposit amount : ";
    cin >> amount;

    string accNumber, id, name, Balance;
    string file = "customer/" + to_string(cid) + ".txt";
    ifstream myFile(file);
    if (myFile.is_open())
    {
        while (myFile >> accNumber >> id >> name >> Balance)
        {
            int bal = stoi(Balance);
            bal = bal + amount;
            myFile.close();
            ofstream myFile(file);
            myFile << accNumber << " " << id << " " << name << " " << bal;
            myFile.close();
            cout << " Deposit success.." << endl;
        }
        myFile.close();
    }
    else
    {
        cout << "unable to open";
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



void view_Customer_Account(int customer)
{

    string accNumber, id, name, Balance;
    string file = "customer/" + to_string(customer) + ".txt";
    ifstream myFile(file);
    if (myFile.is_open())
    {
        while (myFile >> accNumber >> id >> name >> Balance)
        {
            // issue3
            cout << "Account Number : " << accNumber << endl;
            cout << "Name : " << name << endl;
            cout << "Id : " << id << endl;
            cout << "Account Balance : " << Balance << endl;
        }
        myFile.close();

        // loop to view another customer or return to previeous menu
    }
    else
    {
        cout << "unable to open " << endl;
    }
}

void view_Staff_Account(int staff_id)
{

    string name, id, address, number;
    string file = "staff/" + to_string(staff_id) + ".txt";
    ifstream myFile(file);
    if (myFile.is_open())
    {
        while (myFile >> name >> id >> address >> number)
        {
            cout << "Staff Id : " << name << endl;
            cout << "Staff Name: " << id << endl;
            cout << "Staff Address : " << address << endl;
            cout << "Staff Contact Number : " << number << endl;
        }
        myFile.close();
        // loop to view another staff or return to previeous menu
    }
    else
    {
        cout << "unable to open " << endl;
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
