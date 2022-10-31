#include <iostream>
using namespace std;

int sum = 0;

struct TreeNode{

    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

TreeNode *insert(TreeNode *root, int x){
    if(!root){
        TreeNode *newNode = new TreeNode(x);
        return newNode;
    }
    if(x > root->val) root->right = insert(root->right, x);
    if(x < root->val) root->left = insert(root->left, x);

    return root;
}

void preOrder(TreeNode *root, int level){
    if(!root) return;
    sum += root->val - level;
    preOrder(root->left, level + 1);
    preOrder(root->right, level + 1);
}

int main(){

    int n, x; cin >> n;
    TreeNode *root = NULL;

    for(int i = 0; i < n; i++){
        cin >> x;
        root = insert(root, x);
    }

    preOrder(root, 0);
    cout << sum;
}