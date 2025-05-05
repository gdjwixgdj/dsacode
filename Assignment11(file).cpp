// Assignment No 11 - File Handling with Basic Syntax

#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

struct stud {
    int roll;
    char name[10];
    char div;
    char add[10];
} rec;

class student {
public:
    void create();
    void display();
    int search();
    void Delete();
};

void student::create() {
    char ans;
    ofstream fout;
    fout.open("stud.dat", ios::out | ios::binary);
    if (!fout) {
        cout << "\nError opening file for writing.";
        return;
    }
    do {
        cout << "\n\tEnter Roll No of Student: ";
        cin >> rec.roll;
        cout << "\n\tEnter Name of Student: ";
        cin >> rec.name;
        cout << "\n\tEnter Division of Student: ";
        cin >> rec.div;
        cout << "\n\tEnter Address of Student: ";
        cin >> rec.add;
        fout.write((char*)&rec, sizeof(stud));
        cout << "\n\tDo you want to add more records? (y/n): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    fout.close();
}

void student::display() {
    ifstream fin;
    fin.open("stud.dat", ios::in | ios::binary);
    if (!fin) {
        cout << "\nError opening file for reading.";
        return;
    }
    cout << "\n\tThe Content of File are:\n";
    cout << "\n\tRoll\tName\tDiv\tAddress";
    while (fin.read((char*)&rec, sizeof(stud))) {
        if (rec.roll != -1) {
            cout << "\n\t" << rec.roll << "\t" << rec.name << "\t" << rec.div << "\t" << rec.add;
        }
    }
    fin.close();
}

int student::search() {
    int r, i = 0;
    ifstream fin;
    fin.open("stud.dat", ios::in | ios::binary);
    if (!fin) {
        cout << "\nError opening file for searching.";
        return -1;
    }
    cout << "\n\tEnter Roll No to Search: ";
    cin >> r;
    while (fin.read((char*)&rec, sizeof(stud))) {
        if (rec.roll == r) {
            cout << "\n\tRecord Found...\n";
            cout << "\n\tRoll\tName\tDiv\tAddress";
            cout << "\n\t" << rec.roll << "\t" << rec.name << "\t" << rec.div << "\t" << rec.add;
            fin.close();
            return i;  // position of record
        }
        i++;
    }
    fin.close();
    return -1;  // Not found
}

void student::Delete() {
    int pos = search();
    if (pos == -1) {
        cout << "\n\tRecord Not Found.";
        return;
    }
    fstream f;
    f.open("stud.dat", ios::in | ios::out | ios::binary);
    if (!f) {
        cout << "\nError opening file for deletion.";
        return;
    }
    int offset = pos * sizeof(stud);
    f.seekp(offset);
    rec.roll = -1;
    strcpy(rec.name, "NULL");
    rec.div = 'N';
    strcpy(rec.add, "NULL");
    f.write((char*)&rec, sizeof(stud));
    f.close();
    cout << "\n\tRecord Deleted.";
}

int main() {
    student obj;
    int ch;
    char ans;
    do {
        cout << "\n\n\t***** Student Information *****";
        cout << "\n\t1. Create\n\t2. Display\n\t3. Delete\n\t4. Search\n\t5. Exit";
        cout << "\n\t..... Enter Your Choice: ";
        cin >> ch;
        switch (ch) {
            case 1: obj.create(); break;
            case 2: obj.display(); break;
            case 3: obj.Delete(); break;
            case 4: obj.search(); break;
            case 5: cout << "\n\tExiting program."; break;
            default: cout << "\n\tInvalid Choice!"; break;
        }
        if (ch != 5) {
            cout << "\n\t..... Do you want to continue in Main Menu? (y/n): ";
            cin >> ans;
        } else {
            ans = 'n';
        }
    } while (ans == 'y' || ans == 'Y');

    return 0;
}
