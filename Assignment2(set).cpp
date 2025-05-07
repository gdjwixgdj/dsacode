#include<iostream>
using namespace std;

class Set {
    int count, a[20];
public:
    Set() {
        count = 0;
    }

    // Insert elements with duplicate prevention
    void insert() {
        cout << "How many elements you want to insert?: ";
        int t, element;
        cin >> t;

        for (int i = 0; i < t; i++) {
            cout << "Enter element " << (i + 1) << ": ";
            cin >> element;

            // Check for duplicates before inserting
            if (search(element) != -1) {
                cout << "Duplicate element. Not inserted.\n";
            } else {
                if (count >= 20) {
                    cout << "Set is full! Cannot insert more elements.\n";
                    break;
                }
                a[count++] = element;
            }
        }
    }

    void display() {
        if (count == 0) {
            cout << "Set is empty.\n";
            return;
        }
        for (int i = 0; i < count; i++)
            cout << a[i] << " ";
        cout << endl;
    }

    void displaySize() {
        cout << "Size of set: " << count << endl;
    }

    int search(int key) {
        for (int i = 0; i < count; i++) {
            if (a[i] == key)
                return i;
        }
        return -1;
    }

    void Delete() {
        int index, key;
        cout << "Enter element you want to delete: ";
        cin >> key;
        index = search(key);
        if (index == -1)
            cout << "Element not found!!\n";
        else {
            for (int i = index; i < count - 1; i++)
                a[i] = a[i + 1];
            count--;
            cout << "Element " << key << " is deleted!\n";
        }
    }

    void union1(Set A, Set B) {
        count = 0;
        for (int i = 0; i < A.count; i++)
            a[count++] = A.a[i];

        for (int i = 0; i < B.count; i++) {
            if (A.search(B.a[i]) == -1)
                a[count++] = B.a[i];
        }
    }

    void intersection(Set A, Set B) {
        count = 0;
        for (int i = 0; i < B.count; i++) {
            if (A.search(B.a[i]) != -1)
                a[count++] = B.a[i];
        }
    }

    void minus(Set A, Set B) {
        count = 0;
        for (int i = 0; i < A.count; i++) {
            if (B.search(A.a[i]) == -1)
                a[count++] = A.a[i];
        }
    }
};

int main() {
    Set obj, A, B, C;
    int flag = 1, num, ch;

    do {
        cout << "-----------MENU------------\n";
        cout << "1. Insert elements into main set\n";
        cout << "2. Display set\n";
        cout << "3. Display size\n";
        cout << "4. Search element\n";
        cout << "5. Delete an element\n";
        cout << "6. Union\n";
        cout << "7. Intersection\n";
        cout << "8. Difference (A - B)\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                obj.insert();
                break;
            case 2:
                obj.display();
                break;
            case 3:
                obj.displaySize();
                break;
            case 4:
                cout << "Enter the key you want to search: ";
                cin >> num;
                num = obj.search(num);
                if (num != -1)
                    cout << "Key found at index " << num << endl;
                else
                    cout << "Key not found.\n";
                break;
            case 5:
                obj.Delete();
                break;
            case 6:
                cout << "Enter 1st set elements:\n";
                A.insert();
                cout << "Enter 2nd set elements:\n";
                B.insert();
                C.union1(A, B);
                cout << "--------After union-----\n";
                C.display();
                break;
            case 7:
                cout << "Enter 1st set elements:\n";
                A.insert();
                cout << "Enter 2nd set elements:\n";
                B.insert();
                C.intersection(A, B);
                cout << "--------After intersection-----\n";
                C.display();
                break;
            case 8:
                cout << "Enter 1st set elements:\n";
                A.insert();
                cout << "Enter 2nd set elements:\n";
                B.insert();
                C.minus(A, B);
                cout << "--------After difference (A - B)-----\n";
                C.display();
                break;
            case 9:
                flag = 0;
                break;
            default:
                cout << "Wrong choice!\n";
        }
        cout << endl;
    } while (flag);

    return 0;
}
