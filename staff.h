#include <string>
#include <fstream>

using namespace std;

void staff()
{
    int choice;


    while (true)
    {
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

        if (choice == 0)
        {
            break;
        }

        if (choice == 5)
        {
            int employeeID;
            fstream file;
            string name,job_position,address,email_address,phone_number,dob;

            cout << "Please enter below details\n";
            cout << "Enter Employee ID: ";
            cin >> employeeID;
            cin.ignore(); // Clear newline character from buffer

            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter Job-Position: ";
            getline(cin, job_position);

            cout <<"Enter Address: ";
            getline(cin, address);

            cout <<"Enter Email-Address: ";
            getline(cin, email_address);

            cout <<"Enter Phone-Number: ";
            getline(cin, phone_number);



            cout << "\nEmployee Details:" << endl;
            cout << "Employee ID: " << employeeID << endl;
            cout << "Name: " << name << endl;
            cout << "Job Position: " << job_position << endl;
            cout << "Email-Address: " << email_address <<endl;
            cout << "Phone-number: " << phone_number << endl;


            char continueOption;
            cout << "Do you want to continue? (y/n): ";
            cin >> continueOption;

            if (continueOption != 'y' && continueOption != 'Y')
            {
                break; // Exit the loop if the user chooses not to continue
            }
            else{
                cout << "End" << endl;
            }
            file.open("staff_record.txt" ,ios::app | ios::out);
            file<<"\t"  <<"\t" <<name <<"\t"<<job_position << "\t"<<email_address <<"\t"<< phone_number <<"" <<"\n";
            file.close();
}
        }
    }
