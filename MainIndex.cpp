#include <iostream>

using namespace std;

// void  function decalrations

void payroll();
void staff();
void customer_Account_Menu();
void admin_Menu();
void deposit();
void withdraw_FH();
void deposit_FH(int);
void create_Customer_Account(int, int, string, int);
void create_Staff_Account(int, string, string, int);
void view_Customer_Account(int);
void view_Staff_Account(int);
void view_All_Customer_Account();
void view_All_Staff_Account();

// Next Header files declaration
#include "staff.h"
#include "deposit.h"
#include "payroll.h"
#include "login.h"
#include "menu.h"
#include "fileHandler.h"


int main()
{
  login();

  // statements
  // home();
  // payroll();
  // staff();
  // customer_Account_Menu();
  // customer_Menu();
  // account_Menu();
  // admin_Menu();
  // deposit();
  // withdraw();
  // withdraw_FH(int cid,int amount);
  // deposit(int cid,int amount);
  // create_Customer_Account(int customer_id,int account_Number, string customer_Name, int Balance);
  // create_Staff_Account(int staff_Id,string name,string staff_Address,int number);
  // view_Customer_Account(int customer);
  // view_Staff_Account(int staff_id);
  // view_All_Customer_Account();
  // view_All_Staff_Account();
}

// definition
