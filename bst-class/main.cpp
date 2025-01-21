#include <iostream>
using namespace std;

// Definition of a Binary Search Tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = nullptr;
        right= nullptr;
    }
};

int kthsmallest(Node* root, int k)
{
    int left,right;
    static int ct=0;
    if(root == NULL)
        return 0;
    left = kthsmallest(root->left,k);
    if(left)
        return left;

    ct++;
    if(ct == k)
        return root->data;

    right = kthsmallest(root->right,k);
    if(right)
        return right;
}

int kthlargest(Node* root, int k)
{
    int left,right;
    static int ct=0;
    if(root == NULL)
        return 0;
    right = kthlargest(root->right,k);
    if(right)
        return right;

    ct++;
    if(ct == k)
        return root->data;

    left = kthlargest(root->left,k);
    if(left)
        return left;
}
// Function to insert a new node into the BST
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

// Function to find the minimum value node in a BST
Node* findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Function to delete a node with a given key from the BST
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) {
        return root;
    }
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to perform in-order traversal
void inOrder(Node* root) {
    if (root == nullptr) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// Function to perform pre-order traversal
void preOrder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// Function to perform post-order traversal
void postOrder(Node* root) {
    if (root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = nullptr;

    int n;
    cin >> n;

    cout << "";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    cout << "";
    inOrder(root);
    cout << endl;

    cout << "";
    preOrder(root);
    cout << endl;

    cout << "";
    postOrder(root);
    cout << endl;

    /*
    // Delete 6 and perform in-order traversal
    root = deleteNode(root, 6);
    cout << "";
    inOrder(root);
    cout << endl;

    // Insert 8 and perform in-order traversal
    root = insert(root, 8);
    cout << "";
    inOrder(root);
    cout << endl;

    // Delete 5 and perform in-order traversal
    root = deleteNode(root, 5);
    cout << "";
    inOrder(root);
    cout << endl;

    */
    int x;
    x = kthsmallest(root, 4);
    cout<<"\n2nd smallest : "<<x;

    int y = kthlargest(root,2);
    cout<<"\n2nd largest : "<<y;


    return 0;
}
