#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class account_query {
private:
    char account_number[20];
    char firstName[10];
    char lastName[10];
    float total_Balance;

public:
    void read_data();
    void show_data();
    void write_rec();
    void read_rec();
    void search_rec();
    void edit_rec();
    void delete_rec();
};

void account_query::read_data() {
    cout << "Enter Account Number: ";
    cin >> account_number;
    cout << "Enter First Name: ";
    cin >> firstName;
    cout << "Enter Last Name: ";
    cin >> lastName;
    cout << "Enter Balance: ";
    cin >> total_Balance;
    cout << endl;
}

void account_query::show_data() {
    cout << "Account Number: " << account_number << endl;
    cout << "First Name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;
    cout << "Current Balance: Rs. " << total_Balance << endl;
    cout << "-------------------------------" << endl;
}

void account_query::write_rec() {
    ofstream outfile;
    outfile.open("record.txt", ios::binary | ios::app);
    read_data();
    outfile.write(reinterpret_cast<char*>(this), sizeof(*this));
    outfile.close();
}

void account_query::read_rec() {
    ifstream infile;
    infile.open("record.txt", ios::binary);
    if (!infile) {
        cout << "Error in Opening! File Not Found!!" << endl;
        return;
    }
    cout << "****Data from file****" << endl;
    while (infile.read(reinterpret_cast<char*>(this), sizeof(*this))) {
        show_data();
    }
    infile.close();
}

void account_query::search_rec() {
    int n;
    ifstream infile;
    infile.open("record.txt", ios::binary);
    if (!infile) {
        cout << "Error in opening! File Not Found!!" << endl;
        return;
    }
    infile.seekg(0, ios::end);
    int count = infile.tellg() / sizeof(*this);
    cout << "There are " << count << " records in the file" << endl;
    cout << "Enter Record Number to Search: ";
    cin >> n;
    infile.seekg((n - 1) * sizeof(*this));
    if (infile.read(reinterpret_cast<char*>(this), sizeof(*this))) {
        show_data();
    } else {
        cout << "Record not found." << endl;
    }
    infile.close();
}

void account_query::edit_rec() {
    int n;
    fstream iofile;
    iofile.open("record.txt", ios::in | ios::out | ios::binary);
    if (!iofile) {
        cout << "Error in opening! File Not Found!!" << endl;
        return;
    }
    iofile.seekg(0, ios::end);
    int count = iofile.tellg() / sizeof(*this);
    cout << "There are " << count << " records in the file" << endl;
    cout << "Enter Record Number to edit: ";
    cin >> n;
    if (n < 1 || n > count) {
        cout << "Invalid record number." << endl;
        return;
    }
    iofile.seekg((n - 1) * sizeof(*this));
    if (iofile.read(reinterpret_cast<char*>(this), sizeof(*this))) {
        cout << "Record " << n << " has the following data" << endl;
        show_data();
        cout << "Enter new data to modify" << endl;
        read_data();
        iofile.seekp((n - 1) * sizeof(*this));
        iofile.write(reinterpret_cast<char*>(this), sizeof(*this));
        cout << "Record modified successfully." << endl;
    } else {
        cout << "Record not found." << endl;
    }
    iofile.close();
}




    void account_query::delete_rec() {
    int n;
    ifstream infile;
    infile.open("record.txt", ios::binary);
    if (!infile) {
        cout << "Error in opening! File Not Found!!" << endl;
        return;
    }
    infile.seekg(0, ios::end);
    int count = infile.tellg() / sizeof(*this);
    cout << "There are " << count << " records in the file" << endl;
    cout << "Enter Record Number to Delete: ";
    cin >> n;
    if (n < 1 || n > count) {
        cout << "Invalid record number." << endl;
        return;
    }

    fstream tmpfile;
    tmpfile.open("tmpfile.txt", ios::out | ios::binary);

    infile.open("record.txt", ios::binary);
    infile.seekg(0);
    for (int i = 0; i < count; i++) {
        infile.read(reinterpret_cast<char*>(this), sizeof(*this));
        if (i != (n - 1)) {
            tmpfile.write(reinterpret_cast<char*>(this), sizeof(*this));
        }
    }

    infile.close();
    tmpfile.close();

    remove("record.txt");
    rename("tmpfile.txt", "record.txt");
    cout << "Record deleted successfully." << endl;
}


