#include<iostream>
#include<fstream>
using namespace std;

// Define a structure to store student information
struct Student {
    int roll;        // Roll number of student
    char name[20];   // Name of student
    char div;        // Division of student
    char addr[20];   // Address of student
};

// Function to create and write student records to file
void create() {
    ofstream fout("stud.dat", ios::binary);  // Open file in binary write mode
    Student s;
    char more;
    do {
        cout << "Enter Roll, Name, Div, Address: ";
        cin >> s.roll >> s.name >> s.div >> s.addr;
        fout.write((char*)&s, sizeof(s));    // Write struct data to file
        cout << "Add more? (y/n): ";
        cin >> more;
    } while (more == 'y');                   // Repeat if user wants to add more
    fout.close();                            // Close the file
}

// Function to display all student records
void display() {
    ifstream fin("stud.dat", ios::binary);   // Open file in binary read mode
    Student s;
    cout << "\nRoll\tName\tDiv\tAddr\n";
    while (fin.read((char*)&s, sizeof(s))) { // Read each record from file
        cout << s.roll << "\t" << s.name << "\t" << s.div << "\t" << s.addr << "\n";
    }
    fin.close();                             // Close the file
}

// Function to search for a specific student by roll number
void search() {
    ifstream fin("stud.dat", ios::binary);   // Open file in binary read mode
    Student s;
    int r, found = 0;
    cout << "Enter roll to search: ";
    cin >> r;
    while (fin.read((char*)&s, sizeof(s))) { // Read each record and check roll
        if (s.roll == r) {
            cout << "Found: " << s.name << " " << s.div << " " << s.addr << "\n";
            found = 1;
            break;
        }
    }
    if (!found) cout << "Record not found.\n";  // Message if record not found
    fin.close();                                 // Close the file
}

// Main function with menu-driven program
int main() {
    int ch;
    do {
        cout << "\n1.Create 2.Display 3.Search 4.Exit: ";
        cin >> ch;
        if (ch == 1)
            create();    // Call create function
        else if (ch == 2)
            display();   // Call display function
        else if (ch == 3)
            search();    // Call search function
    } while (ch != 4);   // Repeat until user chooses to exit
    return 0;
}
