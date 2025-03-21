#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int M = 1e9 + 7;
// const int N = 1e5 + 10;
// long long A[N];

struct Node{
  int data;
  Node* next;

  Node(int data1){
    data = data1;
    next = NULL;
  }
  Node(int data1, Node* next1){
    data = data1;
    next = next1;
  }
};

Node* convertArrtoLL(vector<int> arr){
  Node* head = new Node(arr[0]);
  Node* mover = head;
  for(int i = 1; i < arr.size(); i++){
    Node* temp = new Node(arr[i]);
    mover->next = temp;
    mover = mover->next;
  }
  return head;
}
Node* traverseLL(Node* head){
  Node* mover = head;
  while(mover != NULL){
    cout<< mover->data << " ";
    mover = mover->next;
  }
  return head;
}

int lengthLL(Node* head){
  Node* mover = head;
  int count = 0;
  while(mover != NULL){
    count++;
    mover = mover->next;
  }
  return count;
}

int main(){
  vector<int> arr = {1,2,3,4,5};
  Node* head = convertArrtoLL(arr);
  traverseLL(head);
  cout<<lengthLL(head);
  return 0;
}