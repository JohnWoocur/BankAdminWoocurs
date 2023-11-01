#include <iostream>

using namespace std;

// void  function decalrations

void payroll();
void staff();
void customer_Account_Menu();
void admin_Menu();
void staffs();
void withdraw_FH();
void deposit_FH();
void create_Customer_Account(int, int, string, int);
void create_Staff_Account(int, string, string, int);
void view_Customer_Account();
void view_Staff_Account();
void view_All_Customer_Account();
void view_All_Staff_Account();

// Next Header files declaration


#include "payroll.h"
#include "login.h"
#include "menu.h"
#include "fileHandler.h"
#include "staffs.h"
#include "staffadd.h"




int main()
{
  login();
}

// definition
