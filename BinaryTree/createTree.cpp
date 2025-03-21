#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int M = 1e9 + 7;
// const int N = 1e5 + 10;
// long long A[N];

struct Node{
  int data;
  Node* left;
  Node* right;

  Node(int val){
    data = val;
    left = right = NULL;
  }
};

Node* convertArrToTree(vector<int> arr){
  Node* root = new Node(arr[0]);
  return root;
}

int main(){
  vector<int> arr = {1,2,3,4,5,6,7,8};
  Node* root = convertArrToTree(arr);
  cout << root->data << endl;
  return 0;
}
/**
 * Types of binary tree(0, 1, 2)
 * 1. Full binary tree:
 *                    -) either 0 or 2 nodes in the tree
 * 2. Complete binary tree: 
 *                    -) all the nodes are completely filled except the last level
 *                    -) the last nodes has all nodes as left as possible
 * 3. Perfact binary tree:
 *                    -) all leaf nodes are at same level
 * 4. Balanced binary tree
 *                    -) height of the tree is max log(N: number of nodes)
 * 5. Degenerated binary tree
 *                    -) when every node has a single children
 * 
 */