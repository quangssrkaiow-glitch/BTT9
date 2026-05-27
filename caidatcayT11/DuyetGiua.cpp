#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char val) {
        data = val;
        left = right = NULL;
    }
};

//Duyệt cây
void InOrder(Node* root) {
    if (root != NULL) {
        if (root->left || root->right) cout << "(";

        InOrder(root->left);
        cout << root->data << " ";
        InOrder(root->right);

        if (root->left || root->right) cout << ")";
    }
}

//Xây cây biểu thức
Node* buildTree() {
    // (a*b + c)
    Node* a = new Node('a');
    Node* b = new Node('b');
    Node* c = new Node('c');
    Node* mul1 = new Node('*');
    mul1->left = a;
    mul1->right = b;

    Node* plus = new Node('+');
    plus->left = mul1;
    plus->right = c;

    // (a*b + c) / d
    Node* d = new Node('d');
    Node* div = new Node('/');
    div->left = plus;
    div->right = d;

    // (e*f - h)
    Node* e = new Node('e');
    Node* f = new Node('f');
    Node* h = new Node('h');

    Node* mul2 = new Node('*');
    mul2->left = e;
    mul2->right = f;

    Node* minus = new Node('-');
    minus->left = mul2;
    minus->right = h;

    // (e*f - h)^g
    Node* g = new Node('g');
    Node* power = new Node('^');
    power->left = minus;
    power->right = g;

    // FINAL: ((a*b + c)/d) - ((e*f - h)^g)
    Node* root = new Node('-');
    root->left = div;
    root->right = power;

    return root;
}

//Main
int main() {
    Node* root = buildTree();
    cout << "Duyet giua : ";
    InOrder(root);
    cout << endl;
    return 0;
}