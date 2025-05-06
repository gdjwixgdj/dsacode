#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    bool lThread;
    bool rThread;

    Node(int val) {
        data = val;
        left = right = NULL;
        lThread = rThread = false;
    }
};

class PreorderTBT {
private:
    Node* root;

public:
    PreorderTBT() {
        root = NULL;
    }

    Node* insert(Node* root, int val) {
        if (root == NULL)
            return new Node(val);

        if (val < root->data)
            root->left = insert(root->left, val);
        else if (val > root->data)
            root->right = insert(root->right, val);

        return root;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    void createPreorderThread(Node* node, Node*& prev) {
        if (node == NULL)
            return;

        if (node->left == NULL) {
            node->left = prev;
            node->lThread = true;
        }

        if (prev != NULL && prev->right == NULL) {
            prev->right = node;
            prev->rThread = true;
        }

        prev = node;

        if (node->lThread == false)
            createPreorderThread(node->left, prev);

        if (node->rThread == false)
            createPreorderThread(node->right, prev);
    }

    void createPreorderThread() {
        Node* prev = NULL;
        createPreorderThread(root, prev);
    }

    void preorderTraversal() {
        if (root == NULL) {
            cout << "Tree is empty!" << endl;
            return;
        }

        Node* curr = root;
        cout << "Preorder Traversal using Threads: ";
        while (curr != NULL) {
            cout << curr->data << " ";

            if (curr->lThread == false)
                curr = curr->left;
            else
                curr = curr->right;
        }
        cout << endl;
    }
};

int main() {
    PreorderTBT tbt;
    int choice, val;
    bool done = false;

    while (!done) {
        cout << "\n--- Preorder Threaded Binary Tree Menu ---" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Create Preorder Threads" << endl;
        cout << "3. Preorder Traversal (Threaded)" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                tbt.insert(val);
                cout << "Node inserted." << endl;
                break;

            case 2:
                cout << "Creating Preorder Threads..." << endl;
                tbt.createPreorderThread();
                cout << "Threads created." << endl;
                break;

            case 3:
                tbt.preorderTraversal();
                break;

            case 4:
                cout << "Exiting program." << endl;
                done = true;
                break;

            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}

