#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    bool lthread, rthread;

    Node(int val) {
        data = val;
        left = right = NULL;
        lthread = rthread = true;
    }
};

class TBT {
    Node *root;

public:
    TBT() {
        root = NULL;
    }

    void insert(int val) {
        Node *newNode = new Node(val);

        if (root == NULL) {
            root = newNode;
            return;
        }

        Node *curr = root, *parent = NULL;
        while (curr != NULL) {
            parent = curr;
            if (val < curr->data) {
                if (!curr->lthread)
                    curr = curr->left;
                else
                    break;
            } else if (val > curr->data) {
                if (!curr->rthread)
                    curr = curr->right;
                else
                    break;
            } else {
                cout << "Duplicate value not allowed!\n";
                return;
            }
        }

        if (val < parent->data) {
            newNode->left = parent->left;
            newNode->right = parent;
            parent->lthread = false;
            parent->left = newNode;
        } else {
            newNode->left = parent;
            newNode->right = parent->right;
            parent->rthread = false;
            parent->right = newNode;
        }
    }

    void inorder() {
        if (root == NULL) {
            cout << "Tree is empty.\n";
            return;
        }

        Node *curr = root;
        // Go to the leftmost node
        while (!curr->lthread)
            curr = curr->left;

        while (curr != NULL) {
            cout << curr->data << " ";
            if (curr->rthread)
                curr = curr->right;
            else {
                curr = curr->right;
                while (curr != NULL && !curr->lthread)
                    curr = curr->left;
            }
        }
        cout << endl;
    }
};

int main() {
    TBT tree;
    int choice, val;

    do {
        cout << "\n---MENU---\n1. Insert\n2. Display Inorder\n3. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                tree.insert(val);
                break;
            case 2:
                cout << "Inorder Traversal: ";
                tree.inorder();
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}
