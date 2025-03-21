#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int M = 1e9 + 7;
// const int N = 1e5 + 10;
// long long A[N];

struct TreeNode{
  int data;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int val){
    data = val;
    left = right = NULL;
  }
};

bool checkForIdenticalTrees(TreeNode* root1, TreeNode* root2){
  if(root1 == NULL || root2 == NULL) return (root1 == root2);
  return (root1->data == root2->data) && checkForIdenticalTrees(root1->left, root2->left) && checkForIdenticalTrees(root1->right, root2->right);
}

int maxPath(TreeNode* root) {
        if(root == NULL) return INT_MIN;
        int leftsum = maxPath(root->left);
        int rightsum = maxPath(root->right);
        if (leftsum == INT_MIN && rightsum == INT_MIN) {
            return root->data;
        }
        return max(max(leftsum+root->data, rightsum+root->data), leftsum+rightsum+root->data);
    }

int main(){
  vector<int> arr = {-10, 9, 20, NULL, NULL, 15, 7};
  TreeNode* root = new TreeNode(arr[0]);
  root->left = new TreeNode(arr[1]);
  root->right = new TreeNode(arr[2]);
  // root->left->left = new TreeNode(arr[3]);
  // root->left->right = new TreeNode(arr[4]);
  root->right->left = new TreeNode(arr[5]);
  root->right->right = new TreeNode(arr[6]);

  cout << maxPath(root) << endl;
  // cout << checkForIdenticalTrees(root, root) << endl;

  return 0;
}
/**
 *           -10
 *       9         20
 *              15     7
 * 
 */