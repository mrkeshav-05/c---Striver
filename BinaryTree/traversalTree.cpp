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

TreeNode* convertArrToTree(vector<int> arr){
  TreeNode* root = new TreeNode(arr[0]);
  // using bfs


  return root;
}
void preorderTraversal(TreeNode* root){
  if(root == NULL) return;
  cout << root->data << " ";
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}
void inorderTraversal(TreeNode* root){
  if(root == NULL) return;
  inorderTraversal(root->left);
  cout << root->data << " ";
  inorderTraversal(root->right);
}
void postorderTraversal(TreeNode* root){
  if(root == NULL) return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  cout << root->data << " ";
}
// This is of BFS as levelwise traversal
// Implementation by queue
// Time Complexity is O(N: number of nodes) and Space Complexity is O(N)
vector<vector<int>> levelorderTraversal(TreeNode* root){
  vector<vector<int>> levelorder;
  if(root == NULL) return levelorder;
  queue<TreeNode*> q;
  q.push(root);
  while(!q.empty()){
    int size = q.size();
    vector<int> level;
    for(int i = 0; i < size; i++){
      TreeNode* node = q.front();
      q.pop();
      if(node->left != NULL) q.push(node->left);
      if(node->right != NULL) q.push(node->right);
      level.push_back(node->data);
    }
    levelorder.push_back(level);
  }
  return levelorder;
}
// Iterative traversal of preOrder
// root left right
// Implemented by using one stack
// time complexity O(N) space complexity O(N) 
vector<int> preorderIterativeTraversal(TreeNode* root){
  vector<int> preorder;
  if(root == NULL) return preorder;
  stack<TreeNode*> st;
  st.push(root);
  while(!st.empty()){
    TreeNode* node = st.top();
    st.pop();
    preorder.push_back(node->data);
    if(node->right != NULL) st.push(node->right);
    if(node->left != NULL) st.push(node->left);
  }
  return preorder;
}

// Iterative traversal of inorder
// left root right
// Implemented by using one stack
// time complexity O(N) space complexity O(N) 

vector<int> inorderIterativeTraversal(TreeNode* root){
  vector<int> inorder;
  stack<TreeNode*> st;
  TreeNode* node = root;
  while(true){
    if(node != NULL){
      st.push(node);
      node = node->left;
    }
    else{
      if(st.empty() == true) break;
      node = st.top();
      st.pop();
      inorder.push_back(node->data);
      node = node->right;
    }
  }
  return inorder;
}

// Iterative traversal of postOrder
// left right root
// Implemented by using one stack
// time complexity O(2*N) space complexity O(N) 
vector<int> postorderIterativeTraversal(TreeNode* root){
  vector<int> postorder;
  stack<TreeNode*> st;
  TreeNode* node = root;
  while(node != NULL || !st.empty()){
    if(node != NULL){
      st.push(node);
      node = node->left;
    }else{
      TreeNode* temp = st.top()->right;
      if(temp == NULL){
        temp = st.top();
        st.pop();
        postorder.push_back(temp->data);
        while(!st.empty() && temp == st.top()->right){
          temp = st.top();
          st.pop();
          postorder.push_back(temp->data);
        }
      }else{
        node = temp;
      }
    }
  }
  return postorder;
}

// Iterative traversal of postOrder
// left right root
// Implemented by using two stack
// Here second stack is used to reverse the nodes only
vector<int> postorderIterativeTraversalUsingTwoStacks(TreeNode* root){
  vector<int> postorder;
  if(root == NULL) return postorder;
  stack<TreeNode*> st1, st2;
  st1.push(root);
  while(!st1.empty()){
    root = st1.top();
    st1.pop();
    st2.push(root);
    if(root->left != NULL) st1.push(root->left);
    if(root->right != NULL) st1.push(root->right);
  }
  while(!st2.empty()){
    postorder.push_back(st2.top()->data);
    st2.pop();
  }
  return postorder;
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

  vector<int> preorderItr = preorderIterativeTraversal(root);
  cout << "preorder: ";
  for(int i = 0; i<preorderItr.size(); i++){
    cout << preorderItr[i] << " ";
  }
  cout << endl;
  vector<int> inorderItr = inorderIterativeTraversal(root);
  cout << "inorder: ";
  for(int i = 0; i<inorderItr.size(); i++){
    cout << inorderItr[i] << " ";
  }
  cout << endl;
  vector<int> postorderItr = postorderIterativeTraversal(root);
  cout << "postorder: ";
  for(int i = 0; i<postorderItr.size(); i++){
    cout << postorderItr[i] << " ";
  }
  cout << endl;

  // vector<vector<int>> pt = levelorderTraversal(
  // cout << "height: " << levelorderTraversal(root).size() << endl;

  return 0;
}
/**
 *            1
 *       2         3
 *    4     5    6     7
 *  8   9 10 11
 * 
 */
