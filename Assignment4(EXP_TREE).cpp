#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Node {
public:
    char data;
    Node *left, *right;
    Node(char val) {
        data = val;
        left = right = NULL;
    }
};

class ExpressionTree {
    Node* root;

public:
    ExpressionTree() {
        root = NULL;
    }

    void createFromPrefix(string expr) {
        stack<Node*> s;
        // Scan from right to left
        for (int i = expr.size() - 1; i >= 0; i--) {
            char ch = expr[i];
            Node* newNode = new Node(ch);
            if (isOperator(ch)) {
                // Pop two operands
                newNode->left = s.top(); s.pop();
                newNode->right = s.top(); s.pop();
            }
            s.push(newNode);
        }
        root = s.top();
    }

    void inorder() {
        cout << "Inorder Traversal: ";
        inorderHelper(root);
        cout << endl;
    }

private:
    bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
    }

    void inorderHelper(Node* node) {
        if (node != NULL) {
            inorderHelper(node->left);
            cout << node->data;
            inorderHelper(node->right);
        }
    }
};

int main() {
    ExpressionTree tree;
    string expr;
    cout << "Enter a prefix expression: ";
    cin >> expr;
    tree.createFromPrefix(expr);
    tree.inorder();
    return 0;
}
