#include <iostream>
#include <string>

using namespace std;

struct Node {
    int key;
    Node *left, *right, *parent;
    Node(int k) : key(k), left(nullptr), right(nullptr), parent(nullptr) {}
};

class BST {
public:
    Node* root;
    BST() : root(nullptr) {}

    // TREE-INSERT (CLRS 12.3)
    void insert(int k) {
        Node* z = new Node(k);
        Node* y = nullptr;
        Node* x = root;
        while (x != nullptr) {
            y = x;
            if (z->key < x->key) x = x->left;
            else x = x->right;
        }
        z->parent = y;
        if (y == nullptr) root = z;
        else if (z->key < y->key) y->left = z;
        else y->right = z;
    }

    Node* search(Node* x, int k) {
        while (x != nullptr && k != x->key) {
            if (k < x->key) x = x->left;
            else x = x->right;
        }
        return x;
    }

    Node* minimum(Node* x) {
        while (x->left != nullptr) x = x->left;
        return x;
    }

    // TRANSPLANT (CLRS 12.3) - Critical for correct structure
    void transplant(Node* u, Node* v) {
        if (u->parent == nullptr) root = v;
        else if (u == u->parent->left) u->parent->left = v;
        else u->parent->right = v;
        if (v != nullptr) v->parent = u->parent;
    }

    // TREE-DELETE (CLRS 12.3)
    void deleteNode(int k) {
        Node* z = search(root, k);
        if (z == nullptr) return;

        if (z->left == nullptr) {
            transplant(z, z->right);
        } else if (z->right == nullptr) {
            transplant(z, z->left);
        } else {
            Node* y = minimum(z->right); // Successor
            if (y->parent != z) {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
        }
        delete z;
    }

    void inorder(Node* x) {
        if (x != nullptr) {
            inorder(x->left);
            cout << x->key << endl;
            inorder(x->right);
        }
    }

    void preorder(Node* x) {
        if (x != nullptr) {
            cout << x->key << endl;
            preorder(x->left);
            preorder(x->right);
        }
    }

    void postorder(Node* x) {
        if (x != nullptr) {
            postorder(x->left);
            postorder(x->right);
            cout << x->key << endl;
        }
    }
};

int main() {
    BST tree;
    string cmd;
    // Input format: oin, opre, opost or commands like i13, d7
    while (cin >> cmd && cmd != "e") {
        if (cmd == "oin") tree.inorder(tree.root);
        else if (cmd == "opre") tree.preorder(tree.root);
        else if (cmd == "opost") tree.postorder(tree.root);
        else {
            char type = cmd[0];
            int val = stoi(cmd.substr(1));
            if (type == 'i') tree.insert(val);
            else if (type == 'd') tree.deleteNode(val);
        }
    }
    return 0;
}