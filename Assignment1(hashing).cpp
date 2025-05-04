#include <iostream>
using namespace std;

class HashTable {
    int table[10];

public:
    HashTable() {
        for (int i = 0; i < 10; i++)
            table[i] = -1;
    }

    void display() {
        cout << "Hash Table:\n";
        for (int i = 0; i < 10; i++)
            cout << i << " --> " << table[i] << endl;
    }

    void insert(int key, int method) {
        int pos = key % 10;

        if (table[pos] == -1) {
            table[pos] = key;
        } else {
            cout << "Collision at position " << pos << endl;
            if (method == 1)
                linearProbing(key, pos);
            else
                quadraticProbing(key, pos);
        }
    }

private:
    void linearProbing(int key, int pos) {
        for (int i = 1; i < 10; i++) {
            int newPos = (pos + i) % 10;
            if (table[newPos] == -1) {
                table[newPos] = key;
                return;
            }
        }
        cout << "Hash table is full (Linear Probing failed)\n";
    }

    void quadraticProbing(int key, int pos) {
        for (int i = 1; i < 10; i++) {
            int newPos = (pos + i * i) % 10;
            if (table[newPos] == -1) {
                table[newPos] = key;
                return;
            }
        }
        cout << "Hash table is full (Quadratic Probing failed)\n";
    }
};

int main() {
    HashTable ht;
    int choice;

    do {
        cout << "\nMenu:\n1. Insert\n2. Display\n3. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            int key, method;
            cout << "Enter key to insert: ";
            cin >> key;
            cout << "Probing method: 1. Linear  2. Quadratic: ";
            cin >> method;
            ht.insert(key, method);
        } else if (choice == 2) {
            ht.display();
        } else if (choice == 3) {
            cout << "Exiting...\n";
        } else {
            cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}
