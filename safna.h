#include "switch.h"
using namespace std;

void customer_Account_Menu(){
        cout <<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
        cout <<"\tWelcome to Archer Bank"<<endl;
        cout <<"\tCustomer Account Menu"<<endl;
        cout <<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
        cout <<endl;
        int s;
        cout <<"******* | Select your Role |*******"<<endl;
        cout <<"\t1. Add Customer"<<endl;
        cout <<"\t2. View Customer"<<endl;
        cout <<"\t3. View all Customer"<<endl;
        cout <<"\t4. return"<<endl;
        cout <<endl;
        cout <<"Please Select One ...... : ";
        cin >>s;


}
void customer_Menu(){
    int customer_id;
    int customer_Selection;
    cout <<"******* | Wellcome |*******"<<endl;
    cout <<"Enter your Id : ";
    cin >>customer_id;
    if (6==6){
        cout <<"\t1. Account Details"<<endl;
        cout <<"\t2. Deposit"<<endl;
        cout <<"\t3. Withdraw"<<endl;
        cout <<"\t4. Return"<<endl;
        cout <<endl;
        cout <<"Please Select One ...... : ";
        cin >>customer_Selection;
}
}

void account_Menu(){
    int role;
    cout <<"******* | Select your Role |*******"<<endl;
    cout <<"\t1. Admin"<<endl;
    cout <<"\t2. Customer"<<endl;
    cout <<endl;
    cout <<"Please Select One ...... : ";
    cin >>role;
    account_Menu_Switch(role);
 }

 void admin_Menu()
 {
        int admin_id ;
        int admin_Password;
        int admin_Selection;
        cout <<"******* | Wellcome |*******"<<endl;
        cout <<"Enter your Id : ";
        cin >>admin_id;
        cout<<endl;
        cout <<"Enter your Password : ";
        cin >>admin_Password;
        cout<<endl;
        // if(admin_id_check()){
            if(4==4){
            cout <<"\t1. Customer Account"<<endl;
            cout <<"\t2. Staff Account"<<endl;
            cout <<"\t3. Withdraw"<<endl;
            cout <<"\t4. Deposit"<<endl;
            cout <<"\t5. Payroll"<<endl;
            cout <<"\t6. Return"<<endl;
            cout <<endl;
            cout <<"Please Select One ...... : ";
            cin >>admin_Selection;
     }
}

