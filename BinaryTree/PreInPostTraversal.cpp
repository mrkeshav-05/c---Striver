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

vector<int> preInPostTraversal(TreeNode* root){
  vector<int> pre, in, post;
  stack<pair<TreeNode*, int>>st;
  st.push({root, 1});
  while(!st.empty()){
    auto it = st.top();
    st.pop();

    // this is the part of pre
    // increament 1 to 2
    // push the left side of the tree
    if(it.second == 1){
      pre.push_back(it.first->data);
      it.second++;
      st.push(it);
      if(it.first->left != NULL){
        st.push({it.first->left, 1});
      }
    }

    // this is the part of in
    // increament 2 to 3
    // push the right side of the tree
    else if(it.second == 2){
      in.push_back(it.first->data);
      it.second++;
      st.push(it);
      if(it.first->right != NULL){
        st.push({it.first->right, 1});
      }
    }
    // don't push it back again
    else{
      post.push_back(it.first->data);
    }
  }
  return pre;
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
  vector<int> pre = preInPostTraversal(root);
  for(int i = 0; i < pre.size(); i++) {
    cout << pre[i] << " ";
  }
  cout << endl;
  return 0;
}