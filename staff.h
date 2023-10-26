
#include <string>

using namespace std;

void staff () {
    int choice;

    while (true) {
        cout << "<<<<<<<<<< Employee Management System >>>>>>>>>>\n\n";
        cout << "1. New Account\n";
        cout << "2. Deposit Amount\n";
        cout << "3. Withdraw Amount\n";
        cout << "4. Customer Management\n";
        cout << "5. Staff Management\n";
        cout << "6. Reporting\n";
        cout << "7. File Handling\n";
        cout << "8. Payroll\n";
        cout << "0. To Exit\n";
        cout << "Enter your choice (0-8, 0 to exit): ";
        cin >> choice;

        if (choice == 0) {
            break;
        }

        if (choice == 5) {
            int employeeID;
            string name;
            string title;

            cout << "Please enter below details\n";
            cout << "Enter Employee ID: ";
            cin >> employeeID;
            cin.ignore(); // Clear newline character from buffer

            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter Title: ";
            getline(cin, title);

            cout << "\nEmployee Details:" << endl;
            cout << "Employee ID: " << employeeID << endl;
            cout << "Name: " << name << endl;
            cout << "Title: " << title << endl;

            char continueOption;
            cout << "Do you want to continue? (y/n): ";
            cin >> continueOption;

            if (continueOption != 'y' && continueOption != 'Y') {
                break; // Exit the loop if the user chooses not to continue
            }
        }
    }


}
