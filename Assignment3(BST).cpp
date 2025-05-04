#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
};

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    Node* createNode(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    void insert(int val) {
        Node* newNode = createNode(val);
        if (root == NULL) {
            root = newNode;
            cout << "Node inserted.\n";
            return;
        }
        Node* temp = root;
        while (true) {
            if (val < temp->data) {
                if (temp->left == NULL) {
                    temp->left = newNode;
                    cout << "Node inserted.\n";
                    break;
                } else {
                    temp = temp->left;
                }
            } else if (val > temp->data) {
                if (temp->right == NULL) {
                    temp->right = newNode;
                    cout << "Node inserted.\n";
                    break;
                } else {
                    temp = temp->right;
                }
            } else {
                cout << "Value already exists.\n";
                break;
            }
        }
    }

    void inorder(Node* temp) {
        if (temp != NULL) {
            inorder(temp->left);
            cout << temp->data << " ";
            inorder(temp->right);
        }
    }

    void preorder(Node* temp) {
        if (temp != NULL) {
            cout << temp->data << " ";
            preorder(temp->left);
            preorder(temp->right);
        }
    }

    int findMin() {
        if (root == NULL) {
            return -1;
        }
        Node* temp = root;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        return temp->data;
    }

    int findMax() {
        if (root == NULL) {
            return -1;
        }
        Node* temp = root;
        while (temp->right != NULL) {
            temp = temp->right;
        }
        return temp->data;
    }

    void mirror(Node* temp) {
        if (temp != NULL) {
            Node* swapNode = temp->left;
            temp->left = temp->right;
            temp->right = swapNode;

            mirror(temp->left);
            mirror(temp->right);
        }
    }

    bool search(int key) {
        Node* temp = root;
        while (temp != NULL) {
            if (key < temp->data) {
                temp = temp->left;
            } else if (key > temp->data) {
                temp = temp->right;
            } else {
                return true;
            }
        }
        return false;
    }

    int height(Node* temp) {
        if (temp == NULL) {
            return 0;
        }
        int leftHeight = height(temp->left);
        int rightHeight = height(temp->right);
        if (leftHeight > rightHeight)
            return leftHeight + 1;
        else
            return rightHeight + 1;
    }
};

int main() {
    BST tree;
    int choice, val;
    do {
        cout << "\n1. Insert\n2. Inorder\n3. Preorder\n4. Minimum\n5. Maximum\n6. Mirror\n7. Search\n8. Height\n9. Exit\nEnter choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter value: ";
            cin >> val;
            tree.insert(val);
        } else if (choice == 2) {
            cout << "Inorder: ";
            tree.inorder(tree.root);
            cout << endl;
        } else if (choice == 3) {
            cout << "Preorder: ";
            tree.preorder(tree.root);
            cout << endl;
        } else if (choice == 4) {
            int minVal = tree.findMin();
            if (minVal == -1)
                cout << "Tree is empty.\n";
            else
                cout << "Minimum: " << minVal << endl;
        } else if (choice == 5) {
            int maxVal = tree.findMax();
            if (maxVal == -1)
                cout << "Tree is empty.\n";
            else
                cout << "Maximum: " << maxVal << endl;
        } else if (choice == 6) {
            tree.mirror(tree.root);
            cout << "Tree mirrored. Inorder: ";
            tree.inorder(tree.root);
            cout << endl;
        } else if (choice == 7) {
            cout << "Enter value to search: ";
            cin >> val;
            if (tree.search(val))
                cout << "Found.\n";
            else
                cout << "Not found.\n";
        } else if (choice == 8) {
            cout << "Height: " << tree.height(tree.root) << endl;
        }
    } while (choice != 9);

    return 0;
}
