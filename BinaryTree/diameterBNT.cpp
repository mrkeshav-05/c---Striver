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
int height(TreeNode* root, int& diameter){
  if(root == NULL) return 0;
  int lh = height(root->left, diameter);
  int rh = height(root->right, diameter);
  diameter = max(diameter, lh+rh);
  return 1+max(lh, rh);
}
int diameterOfBinaryTree(TreeNode* root){
  int diameter = 0;
  height(root, diameter);
  return diameter;
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
  cout << diameterOfBinaryTree(root) << endl;

  return 0;
}

/**
 *            1
 *       2         3
 *    4     5    6     7
 *  8   9 10 11
 * 
 */