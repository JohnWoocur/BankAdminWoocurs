#include<iostream>
#include<fstream>
using namespace std;
#include "safna.h"

void customer_Account_Menu_Switch(char s){ 
    
    switch (s){
        case 1:
            // create_Customer_Account();
            break;
        case 2:
            // view_Customer_Account(); f
            break;
        case 3:
            // view_All_Customer_Account();
            break;
        default:
            cout << "enter valid " <<endl;
            break;
        };

}

void customer_Menu_Switch(int customer_Selection){
    
        switch (customer_Selection){
            case 1:
                cout <<"\tAccount Details"<<endl;
                break;
            case 2:
                cout <<"\tDeposit"<<endl;
                break;
            case 3:
                cout <<"\tWithdrawal"<<endl;
                break;
            case 4:
                // account_Menu();
                break;
            default:
                cout <<"\tinvalid option"<<endl;
                break;
            };
}
void account_Menu_Switch(int role){
    
    switch (role){
        case 1:
            admin_Menu();
            break;
        case 2:
            customer_Menu();
            break;
        default:
            cout<<"invalid"<<endl;
            break;
        };
}
void admin_Menu_Switch(int select){
        switch (select){
            case 1:
                // customer_Account_Menu();
                break;
            case 2:
                cout <<"\tstaff"<<endl;
                break;
            case 3:

                // withdraw();
                break;
            case 4:
                // deposit();
                break;
            case 5:
                cout <<"\tpyroll"<<endl;
                break;
            case 6:
                // account_Menu();
                break;
            default:
                cout <<"\tinvalid option"<<endl;
                break;
            };
    
}