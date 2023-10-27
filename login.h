#include <windows.h>
#include <fstream>
#include <string>
using namespace std;

void login()
{
    string username, password;

    cout << endl
         << "\t\t\t\t\t\t----------------------------" << endl;
    cout << endl
         << "\t\t\t\t\t\t        Admin Login   " << endl;
    cout << endl
         << "\t\t\t\t\t\t----------------------------" << endl;

    cout << "\t\t\t plese enter the username and password  " << endl;
    cout << "\t\t\t USERNAME : ";
    cin >> username;
    cout << "\t\t\t PASSWORD :";
    cin >> password;

    string uname, pass;
    ifstream reader("login.txt");

    if (reader.is_open())
    {
        while (reader >> uname >> pass)
        {
            if (username == uname && password == pass)
            {
                cout << "login Successfully" << endl;
                system("cls");
            }
            else
            {
                cout << "Login Failed" << endl;
            }
        }
    }
    reader.close();
}

void admin()
{
    string username, password;

    cout << endl
         << "\t\t\t\t\t\t----------------------------" << endl;
    cout << endl
         << "\t\t\t\t\t\t      Admin Account Register   " << endl;
    cout << endl
         << "\t\t\t\t\t\t----------------------------" << endl;

    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    ofstream file("login.txt");
    if (file.is_open())
    {
        file << username << " " << password << endl;

        file.close();
        cout << "Login credentials saved successfully!" << endl;
        system("cls");
        login();
    }
    else
    {
        cout << "Unable to open file." << endl;
    }
}
void home()
{
    string username, password;
    int x;
    cout << endl
         << "\t\t\t\t\t\t----------------------------" << endl;
    cout << endl
         << "\t\t\t\t\t\t          Admin  " << endl;
    cout << endl
         << "\t\t\t\t\t\t----------------------------" << endl;

    cout << "Press 1.Create Admin Account" << endl;
    cout << "Press 2.Login Admin Account" << endl;
    cout << "Select Option:";

    cin >> x;
    switch (x)
    {
    case 1:
        system("cls");
        admin();

        break;

    case 2:
        system("cls");
        login();

        break;

    default:
        system("cls");

        cout << "\t\t\t please select from the option given above \n"
             << endl;
        home();
    }
}
