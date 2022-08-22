#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

struct BinarySearchTree{

    Node *root;

    BinarySearchTree(){
        root = NULL;
    }

    Node *insert(Node *current, int x){
        if(!current){
            current = new Node(x);
            return current;
        }
        if(x > current->data) current->right = insert(current->right, x);
        else if(x < current->data) current->left = insert(current->left, x);

        return current;
    }

    Node *find(Node *current, int x){
        if(!current) return NULL;

        if(x > current->data) return find(current->right, x);
        else if(x < current->data) return find(current->left, x);
        else return current;
    }

    Node *findMin(Node *current){
        if(current->left == NULL) return current;
        return findMin(current->left);
    }

    Node *findMax(Node *current){
        if(current->right == NULL) return current;
        return findMax(current->right);
    }

    Node *remove(Node *current, int x){
        if(current == NULL) return NULL;
        
        if(x > current->data) current->right = remove(current->right, x);
        else if(x < current->data) current->left = remove(current->left, x);
        else{
            if(current->left == NULL and current->right == NULL) current = NULL;
            else if(current->right == NULL) current = current->left;
            else if(current->left == NULL) current = current->right;
            else{
                Node *minRight = findMin(current->right);
                current->data = minRight->data;
                current->right = remove(current->right, minRight->data);
            }
        }
        return current;
    }

    void preOrder(Node *current){
        if(!current) return;
        cout << current->data << " ";
        preOrder(current->left);
        preOrder(current->right);
    }

    void inOrder(Node *current){
        if(!current) return;
        inOrder(current->left);
        cout << current->data << " ";
        inOrder(current->right);
    }

    void postOrder(Node *current){
        if(!current) return;
        postOrder(current->left);
        postOrder(current->right);
        cout << current->data << " ";
    }
};

int main(){

    BinarySearchTree BST;
    int n = 8;
    int arr[n] = {56, 30, 70, 40, 22, 11, 3, 16};
    
    for(int i = 0; i < n; i++)
        BST.root = BST.insert(BST.root, arr[i]);
    
    BST.preOrder(BST.root);
    cout << endl;
    BST.inOrder(BST.root);
    cout << endl;
    BST.postOrder(BST.root);
}

// PreOrder
// ---------------------------------------------------------------------
// preOrder(BST.root) -> 56 -> cout << 56 << " " -> preOrder(56->left);
// preOrder(current) -> 30 -> cout << 30 << " " -> preOrder(30->left);
// preOrder(current) -> 22 -> cout << 22 << " " -> preOrder(22->left);
// preOrder(current) -> 11 -> cout << 11 << " " -> preOrder(11->left);
// preOrder(current) -> 3 -> cout << 3 << " " -> preOrder(3->left);
// preOrder(current) -> NULL -> return;
// preOrder(current) -> 3 -> preOrder(3->right);
// preOrder(current) -> NULL -> return;
// preOrder(current) -> 11 -> preOrder(11->right);
// preOrder(current) -> 16 -> cout << 16 << " " << -> preOrder(16->left);
// preOrder(current) -> NULL -> return;
// preOrder(current) -> 22 -> preOrder(22->right);
// preOrder(current) -> NULL -> return;
// preOrder(current) -> 30 -> preOrder(30->right);
// preOrder(current) -> 40 -> cout << 40 << " " -> preOrder(40->left);
// preOrder(current) -> NULL -> return;
// ...
// ----------------------------------------------------------------------
