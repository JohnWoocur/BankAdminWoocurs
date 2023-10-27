#include <iostream>
using namespace std;
void withdraw_FH(int cid, int amount)
{
    string accNumber, id, name, Balance;
    string file = to_string(cid) + ".txt";
    ifstream myFile(file);
    if (myFile.is_open())
    {
        while (myFile >> accNumber >> id >> name >> Balance)
        {
            int bal = stoi(Balance);
            if (bal >= amount)
            {
                bal = bal - amount;
                myFile.close();
                ofstream myFile(file);
                myFile << accNumber << " " << id << " " << name << " " << bal;
                myFile.close();
                cout << " Withdrawal success.." << endl;
            }
            else
            {
                cout << " Withdrawal Failed... enter availabe amount.." << endl;
            }
        }
        myFile.close();
    }
    else
    {
        cout << "unable to open";
    }
}

void deposit(int cid, int amount)
{
    string accNumber, id, name, Balance;
    string file = to_string(cid) + ".txt";
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

    string file = to_string(customer_id) + ".txt";
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

void create_Staff_Account(int staff_Id, string name, string staff_Address, int number)
{
    string file = to_string(staff_Id) + ".txt";
    ofstream myFile(file);
    if (myFile.is_open())
    {
        myFile << name << " " << staff_Id << " " << staff_Address << " " << number;
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
    string file = to_string(customer) + ".txt";
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
    }
    else
    {
        cout << "unable to open " << endl;
    }
}

void view_Staff_Account(int staff_id)
{
    string name, id, address, number;
    string file = to_string(staff_id) + ".txt";
    ifstream myFile(file);
    if (myFile.is_open())
    {
        while (myFile >> name >> id >> address >> number)
        {
            cout << "Staff Name : " << name << endl;
            cout << "Staff Id: " << id << endl;
            cout << "Staff Address : " << address << endl;
            cout << "Staff Contact Number : " << number << endl;
        }
    }
    else
    {
        cout << "unable to open " << endl;
    }
}

void view_All_Customer_Account()
{
    // issue4
    cout << "All Customer account" << endl;
}

void view_All_Staff_Account()
{
    // issue5
    cout << "All staff account" << endl;
}