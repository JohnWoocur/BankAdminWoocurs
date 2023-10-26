
using namespace std;

void payroll(){
//variable to store information
double hourlyrate =0;
double overtimepay =0;
double regularpay =0;
double overallpay =0;
int hoursworked =0;
int overtimehours =0;

// get hourswork and hourlyrate
cout<<"Please Enter Your Hours Worked :";
cin>>hoursworked;
cout<<endl;
cout<<"Please Enter Your Hourly Rate:";
cin>>hourlyrate;
cout<<endl;
 //Calculate overtime
 if(hoursworked > 208){
    overtimehours = hoursworked - 208;
    hoursworked =208; //regular hours
    overtimepay = overtimehours * hourlyrate;
 }
//calculate pay for regular hours
regularpay= hoursworked* hourlyrate;

//Overall Pay
overallpay = regularpay+overtimepay;

//Display Pay

cout<<"Hours Worked :"<<(hoursworked+ overtimehours) <<endl;
cout<<"Hourly Rate :"<<hourlyrate <<endl;
cout<<"Regular Pay :"<<regularpay <<endl;
cout<<"OverTime Pay:"<<overtimepay <<endl;
cout<<"Over ALL Pay :"<<overallpay <<endl;
cout<<endl;



double allowances,grosssal;

{
   // calculate the allowances
   float medical,transport,food,telephone;
   cout<< "Enter the Medical Allowances :";
cin>>medical;
cout<<endl;
cout<< "Enter the Transport Allowances :";
cin>>transport;
cout<<endl;
cout<< "Enter the Food Allowances :";
cin>>food;
cout<<endl;
cout<< "Enter the Telephone Allowances :";
cin>>telephone;
cout<<endl;

allowances = medical+transport+food+telephone;
}

//input the overall pay and allowances
cout<< "Enter the Over All Pay :" <<overallpay<<endl;

cout<< "Enter the allowances :"  <<allowances<<endl;

//calculate the GrossPay
grosssal= overallpay+allowances;
cout<< "Enter the Gross Salary :"  <<grosssal<<endl;
cout<<endl;
//calculate the net salary
float netsal,dedac;

cout<< "Enter the Deduction :";
cin>>dedac;

netsal=grosssal-dedac;

cout<< "Enter the Net Salary:"  <<netsal<<endl;



}


