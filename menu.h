#include <iostream>

using namespace std;

void customer_Account_Menu()
{
    system("cls");

customer:
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "\tWelcome to Archer Bank" << endl;
    cout << "\tCustomer Account Menu" << endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << endl;
    int s;
    cout << "******* | Select your Role |*******" << endl;
    cout << "\t1. Create Customer" << endl;
    cout << "\t2. View Customer" << endl; // #change
    cout << "\t3. Customer Report" << endl;
    cout << "\t4. Back" << endl;
    cout << endl;
    cout << "Please Select One ...... : ";
    cin >> s;

    switch (s)
    {
    case 1:
        // jathu
        create_Customer_Account();
        break;
    case 2:
        // thasna
        view_Customer_Account();
        break;
    case 3:
        // ad
        view_All_Customer_Account();
        break;
    case 4:
        admin_Menu();
        break;

    default:
        system("cls");
        cout << "enter valid " << endl;
        goto customer;
        break;
    };
}

void staff_Account_Menu()
{
    system("cls");
staff:
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "\tWelcome to Archer Bank" << endl;
    cout << "\tStaff Menu" << endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << endl;
    int s;
    cout << "******* | Select your Role |*******" << endl;
    cout << "\t1. Create Staff" << endl;
    cout << "\t2. View Staff" << endl; // #change
    cout << "\t3. Staff Report" << endl;
    cout << "\t4. Back" << endl;
    cout << endl;
    cout << "Please Select One ...... : ";
    cin >> s;

    switch (s)
    {
    case 1:
        // jd
        create_Staff_Account();
        break;
    case 2:
        // thasna
        view_Staff_Account();
        break;
    case 3:
        // ad, sheba
        view_All_Staff_Account();
        break;
    case 4:
        admin_Menu();
        break;
    default:
        system("cls");
        cout << "enter valid " << endl;
        goto staff;
        break;
    };
}

void admin_Menu()
{
    int admin_Selection;
    system("cls");
start:
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "\tWelcome to Archer Bank" << endl;
    cout << "\tMain Menu" << endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;

    cout << "\t1. Customer Account" << endl;
    cout << "\t2. Staff Account" << endl;
    cout << "\t3. Withdraw" << endl;
    cout << "\t4. Deposit" << endl;
    cout << "\t5. Payroll" << endl;
    cout << "\t6. Logout" << endl;
    cout << "\t7. Exit" << endl;
    cout << endl;
    cout << "Please Select One ...... : ";
    cin >> admin_Selection;

    switch (admin_Selection)
    {
    case 1:
        customer_Account_Menu();
        break;
    case 2:
        staff_Account_Menu();
        break;
    case 3:
        withdraw_FH();
        break;
    case 4:
        deposit_FH();
        break;
    case 5:
        payroll();
        break;
    case 6:
        login();
        break;
    case 7:
        exit(0);
        break;
    default:
        system("cls");
        cout << "\tInvalid option......" << endl;
        goto start;
        break;
    };
}
