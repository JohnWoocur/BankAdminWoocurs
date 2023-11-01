// #include <windows.h>
#include <fstream>
#include <string>
using namespace std;

void login()
{
    // sifran
    string username, password;

    system("cls");
    cout << endl
         << "\t\t\t\t\t\t----------------------------" << endl;
    cout << endl
         << "\t\t\t\t\t\t        Admin Login   " << endl;
    cout << endl
         << "\t\t\t\t\t\t----------------------------" << endl;

    cout << "\t\t\t plese enter the username and password  " << endl;
    cout<<endl;
    cout << "\t\t\t USERNAME : ";
    cin >> username;
    cout<<endl;
    cout << "\t\t\t PASSWORD : ";
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
                admin_Menu();
            }
            else
            {
                cout << "Login Failed" << endl;
                // loop when login failed
            }
        }
    }
    reader.close();
}

