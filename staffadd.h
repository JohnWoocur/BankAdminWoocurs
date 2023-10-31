
using namespace std;

void create_Staff_Account(int staff_Id, string name, string staff_Address, int phone_number)
{

start:
            cout << "Enter Staff ID: ";
            cin >> staff_Id;

            cout << "Enter Name: ";
            cin >> name;

            cout << "Enter Staff Address: ";
            cin >>staff_Address;

            cout << "Enter Phone Number: ";
            cin >> phone_number;

    string file = "staff/" + to_string(staff_Id) + ".txt";
    ofstream myFile(file);
    if (myFile.is_open())
    {
        myFile << name << " " << staff_Id << " " << staff_Address << " " << phone_number;
        cout << "Account details saved successfully" << endl;
        myFile.close();
        // loop to view another customer or return to previeous menu

        endLoop:
        cout << "\n1) Create another staff ?." << endl;
        cout << "2) Back" << endl;
        cout << "3) Logout" << endl;
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

