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

int depth(TreeNode* root){
  if(root == nullptr) return 0;
  return 1+max(depth(root->left), depth(root->right));
}
// In this timecomplexity O(N^2: number of node)
bool isBalanced(TreeNode* root){
  if(root == nullptr) return true;
  int findLeftHeight = depth(root->left);
  int findRightHeight = depth(root->right);
  return (abs(findLeftHeight - findRightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right));
}

int dfsHeight(TreeNode* root){
  if(root == nullptr) return 0;
  int leftHeight = dfsHeight(root->left);
  if(leftHeight == -1) return -1;
  int rightHeight = dfsHeight(root->right);
  if(rightHeight == -1) return -1;
  if(abs(leftHeight - rightHeight) > 1) return -1;
  return max(leftHeight, rightHeight) + 1;
}
bool isBalancedWithLesstime(root){
  return dfsHeight(root) != -1;
}

int main(){
  vector<int> arr = {1,2,3,4,5,6,7,8};
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);
  root->left->left->left = new TreeNode(8);
  root->left->left->right = new TreeNode(9);
  root->left->right->left = new TreeNode(10);
  root->left->right->right = new TreeNode(11);

  cout << isBalancedWithLesstime(root) << endl;

  return 0;
}
/**
 *            1
 *       2         3
 *    4     5    6     7
 *  8   9 10 11
 * 
 */