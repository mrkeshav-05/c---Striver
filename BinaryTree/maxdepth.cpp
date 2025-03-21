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
/**
 * to find maxdepth we can use both recursiveorder || levelorder
 * recursiveorder : 
 *        takes auxiliary space O(height of BN tree)
 *        and worst case is when tree is linear 
 * levelorder : 
 *        takes space complexity O(N: number of nodes)
 *        and the worst case is when it is a perfact BN tree
 * 
 *  */ 

int maxdepth(TreeNode* root){
  if(root == NULL) return 0;
  int leftheight = maxdepth(root->left);
  int rightheight = maxdepth(root->right);
  return 1+max(leftheight,rightheight);
}
int maxdepthUsinglevelorder(TreeNode* root){
  vector<vector<int>> levelorder;
  if(root == NULL) return levelorder.size();
  queue<TreeNode*> q;
  q.push(root);
  while(!q.size()){
    int size = q.size();
    vector<int> level;
    for(int i=0;i<size;i++){
      TreeNode* node = q.front();
      q.pop();
      if(node->left != NULL) q.push(node->left);
      if(node->right != NULL) q.push(node->right);
      level.push_back(node->data);
    }
    levelorder.push_back(level);
  }
  return levelorder.size();
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

  cout << "maxdepth: " << maxdepth(root)  << endl;

  return 0;
}
/**
 *            1
 *       2         3
 *    4     5    6     7
 *  8   9 10 11
 * 
 */