#include <fstream>
#include <iostream>

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
            cout << endl;
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
        cout << "account balance is :" << Balance;
        cout << endl;
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
        cout << endl;
        cout << "now balance is :" << bal;
        cout << endl;
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

void create_Customer_Account()
{
    start:
    int account_no;
    string name;
    string Address;
    int phone_number;

    cout << "Enter account_No : ";
    cin >> account_no;

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Address: ";
    cin >> Address;

    cout << "Enter Phone Number: ";
    cin >> phone_number;

    string file = "customer/" + to_string(account_no) + ".txt";
    ofstream myFile(file);
    ofstream customers("customers.txt",ios::app);
    if (myFile.is_open())
    {
        myFile << name << " " << account_no << " " << Address << " " << phone_number;
        customers << account_no << endl;
        cout << "Account details saved successfully" << endl;
        myFile.close();
        customers.close();
        // loop to view another customer or return to previeous menu

    endLoop:
        cout << "\n1.  Create another Account ?." << endl;
        cout << "2.  Back" << endl;
        cout << "3.  Logout" << endl;
        cout << "Choose Option : ";
        int input;
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
            login();
            break;

        default:
            goto endLoop;
            break;
        }
    }
    else
    {
        cout << "unable to open" << endl;
    }
}

void create_Staff_Account()
{

start:
    int staff_Id;
    string name;
    string staff_Address;
    int phone_number;

    cout << "Enter Staff ID: ";
    cin >> staff_Id;

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Staff Address: ";
    cin >> staff_Address;

    cout << "Enter Phone Number: ";
    cin >> phone_number;

    string file = "staff/" + to_string(staff_Id) + ".txt";
    ofstream myFile(file);
    ofstream staffs("staffs.txt", ios::app);
    if (myFile.is_open())
    {
        myFile << name << " " << staff_Id << " " << staff_Address << " " << phone_number;
        staffs << staff_Id << endl;
        cout << "Account details saved successfully" << endl;
        myFile.close();
        staffs.close();
        // loop to view another customer or return to previeous menu

    endLoop:
        cout << "\n1.  Create another staff ?." << endl;
        cout << "2.  Back" << endl;
        cout << "3.  Logout" << endl;
        cout << "Choose Option : ";
        int input;
        cin >> input;

        switch (input)
        {
        case 1:
            goto start;
            break;
        case 2:
            staff_Account_Menu();
            break;
        case 3:
            login();
            break;

        default:
            goto endLoop;
            break;
        }
    }
    else
    {
        cout << "unable to open" << endl;
    }
}

void view_Customer_Account()
{

start:

    int acc, accNumber;
    string id, name, Balance;

    cout << "\nEnter the Account ID : " << endl;
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

    cout << "\nEnter the Staff ID : " << endl;
    cin >> sid;

    string file = "staff/" + to_string(sid) + ".txt";
    ifstream myFile(file);
    if (myFile.is_open())
    {
        myFile >> name >> id >> address >> number;
        {
            cout << "Staff Id : " << id << endl;
            cout << "Staff Name: " << name << endl;
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
    cout << endl;
start:
    int cid;
    int count = 0;
    int activeAccount = 0;

    string name, id, acc, balance;
    ifstream customersFile("customers.txt");
    cout << "Account No\tID\tName\t\tBalance" << endl;
    cout << "________________________________________________" << endl;
    while (customersFile >> cid)
    {
        string file = "customer/" + to_string(cid) + ".txt";
        ifstream singleCustomer(file);
        if (singleCustomer.is_open())
        {
            singleCustomer >> acc >> id >> name >> balance;
            {
                cout << acc << "\t\t" << id << "\t" << name << "\t\t" << balance << endl;
            }
            singleCustomer.close();
            if(stoi(balance) >= 500){
                ++activeAccount;
            }
            ++count;
        }
        else
        {
            cout << "Customer ID : " + to_string(cid) + "Not Found" << endl;
            goto start;
        }
    }

    cout << "\nTotal customers count is \t\t: " << count << endl;
    cout << "Total active customers count is \t: " << activeAccount << endl;

endMenu:
    int opt;

    cout << endl;
    cout << "1) Back" << endl;
    cout << "2) Go to Main Menu" << endl;
    cout << "\nChoose Option : ";
    cin >> opt;

    switch (opt)
    {
    case 1:
        staff_Account_Menu();
        break;
    case 2:
        admin_Menu();
        break;
    default:
        goto endMenu;
        break;
    }
}

void view_All_Staff_Account()
{

    fstream staffsFile,readStaffs;
    string txtOut;
    string staff_id, name , address , contact_no;

    staffsFile.open("staffs.txt");
    cout << " staff_id         name         address         contact_no " << endl;
    while(getline(staffsFile,txtOut))
    {
        readStaffs.open("staff/" + txtOut+".txt");
        readStaffs >> staff_id >> name >> address >> contact_no ;
        cout << staff_id + "     " + name + "        " + address + "         " + contact_no  << endl;
        readStaffs.close();
    }
    staffsFile.close();
        cout << endl;
        cout << endl;
        cout << "1) Back to Staff Menu" << endl;
        cout << "2) Logout" << endl;
        cout << "Choose Option : ";
        int input;
        cin >> input;

        switch (input)
        {
        case 1:
            staff_Account_Menu();
            break;
        case 2:
            login();
            break;

        default:
            exit(0);
            break;
        }
}
