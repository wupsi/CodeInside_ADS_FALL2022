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
    int sz;

    BinarySearchTree(){
        root = NULL;
        sz = 0;
    }

    Node *insert(Node *current, int x){
        if(!current){
            current = new Node(x);
            sz++;
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

    int height(Node *current){
        if(!current) return 0;
        int leftH = height(current->left);
        int rightH = height(current->right);
        return max(leftH, rightH) + 1;
    }
};

int main(){

    BinarySearchTree BST;
    int x;

    while(true){
        cin >> x;
        if(x == 0) break;
        BST.root = BST.insert(BST.root, x);
    }

    cout << BST.height(BST.root);
}
