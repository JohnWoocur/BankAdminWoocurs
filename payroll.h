#include <iostream>
#include <fstream>

using namespace std;
void login();
void payroll()
{

   // variable to store information

   double hourlyrate = 0;
   double overtimepay = 0;
   double regularpay = 0;
   double overallpay = 0;
   string month;
   int staff_Id;
   int hoursworked = 0;
   int overtimehours = 0;

payroll:
   cout << endl
        << endl;
   cout << "\t\t============= | PAYROLL | =============" << endl;
   cout << endl;

   // add staff id and month input from user
   cout << "Enter the staff ID              :";
   cin >> staff_Id;
   cout << "Enter the month                 :";
   cin >> month;
   // get hourswork and hourlyrate
   cout << "Please Enter Your Hours Worked  :";
   cin >> hoursworked;
   cout << "Please Enter Your Hourly Rate   :";
   cin >> hourlyrate;
   // Calculate overtime
   if (hoursworked > 208)
   {
      overtimehours = hoursworked - 208;
      hoursworked = 208; // regular hours
      overtimepay = overtimehours * hourlyrate;
   }
   // calculate pay for regular hours
   regularpay = hoursworked * hourlyrate;

   // Overall Pay
   overallpay = regularpay + overtimepay;

   // Display Pay
   double allowances, grosssal;

   // calculate the allowances
   float medical, transport, food, telephone;
   cout << "Enter the Medical Allowances    :";
   cin >> medical;
   cout << "Enter the Transport Allowances  :";
   cin >> transport;
   cout << "Enter the Food Allowances       :";
   cin >> food;
   cout << "Enter the Telephone Allowances  :";
   cin >> telephone;
   allowances = medical + transport + food + telephone;
   float netsal, dedac;
   cout << "Enter the Deduction             :";
   cin >> dedac;

   // input the overall pay and allowances
   cout << endl;
   string file = "payroll/" + to_string(staff_Id) + ".txt";
   ofstream myFile(file, ios::app);

   myFile << "Staff id | Your allowances | Hours Worked | Hourly Rate | Regular Pay | OverTime Pay | Over ALL Pay | Gross Salary | Your Net Salary" << endl;;

   cout << "Staff id                        :" << staff_Id << endl;
   myFile << staff_Id << " ";

   cout << "Your allowances                 :" << allowances << endl;
   myFile << allowances << " ";

   cout << "Hours Worked                    :" << hoursworked << endl;
   myFile << hoursworked << " ";

   cout << "Hourly Rate                     :" << hourlyrate << endl;
   myFile << hourlyrate << " ";

   cout << "Regular Pay                     :" << regularpay << endl;
   myFile << regularpay << " ";

   cout << "OverTime Pay                    :" << overtimepay << endl;
   myFile << overtimepay << " ";

   cout << "Over ALL Pay                    :" << overallpay << endl;
   myFile << overallpay << " ";

   // calculate the GrossPay
   grosssal = overallpay + allowances;
   cout << "Your Gross Salary               :" << grosssal << endl;
   myFile << grosssal << " ";

   // calculate the net salary

   netsal = grosssal - dedac;
   cout << "Your Net Salary                 :" << netsal << endl;
   myFile << netsal << endl;

   myFile.close();
   cout << "Account details saved successfully" << endl;

endPayroll:

   // loop to another payroll or return to previeous menu
   cout << endl
        << endl;
   cout << "\n1) Add another staff ID ?." << endl;
   cout << "2) Back" << endl;
   cout << "3) Logout" << endl;
   cout << "Choose Option : ";
   int input;
   cin >> input;

   switch (input)
   {
   case 1:
      goto payroll;
      break;
   case 2:
      admin_Menu();
      break;
   case 3:
      login();
      break;

   default:
      goto endPayroll;
      break;
   }
}
// save all data in single file for each staff id
// save it in payroll folder file name as staff id

/*void save_Staff_Id(int staff_Id, string month,int hoursworked ,double hourlyrate ,float Medical_Allowances ,float Transport_Allowances ,float Food_Allowances ,float Telephone_Allowances ,double Your_allowances ,double Regular_Pay ,int OverTime_Pay ,double Over_ALL_Pay ,double grosssal ,float dedac ,float netsal)
{
      string file = "PAY/" + to_string(staff_Id) + ".txt";
      ofstream myFile(file);
         if (myFile.is_open())
        {
        myFile << staff_Id ,month ,hoursworked ,hourlyrate ,Medical_Allowances ,Transport_Allowances ,Food_Allowances ,Telephone_Allowances ,Your_allowances ,Regular_Pay ,OverTime_Pay ,Over_ALL_Pay ,grosssal ,Deduction ,netsal;
        cout << "Account details saved successfully" << endl;
        myFile.close();
        }
}*/
