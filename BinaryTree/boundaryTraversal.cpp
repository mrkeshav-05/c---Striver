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

vector<int> boundaryTraversal(TreeNode* root){
  vector<int> boundary;
  if(root == NULL) return boundary;
  return boundary;
}

int main(){
  vector<int> arr = {1,2,3,4,5,6,7,8};
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(7);
  root->left->left = new TreeNode(3);
  // root->left->right = new TreeNode(5);
  // root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(8);
  // root->left->left->left = new TreeNode(8);
  root->left->left->right = new TreeNode(4);
  root->right->right->left = new TreeNode(9);
  root->left->left->right->left = new TreeNode(5);
  root->left->left->right->right = new TreeNode(6);
  root->right->right->left->left = new TreeNode(10);
  root->right->right->left->right = new TreeNode(11);

  vector<int> boundary = boundaryTraversal(root);
  for(int i = 0; i<boundary.size(); i++){
    cout << boundary[i] << " ";
  }
  cout << endl;
  return 0;
}
/**
 *            1
 *       2         3
 *    4     5    6     7
 *  8   9 10 11
 * 
 */