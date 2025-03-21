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

// Time complexity is O(2*N) ans space complexity is O(1)
Node* sortLL(Node* head){
  int cnt0 = 0, cnt1 = 0, cnt2 = 0;
  Node* temp = head;
  while(temp != NULL){
    if(temp->data == 0) cnt0++;
    else if(temp->data == 1) cnt1++;
    else cnt2++;
    temp = temp->next;
  }
  temp = head;
  while(cnt0--) {
    temp->data = 0;
    temp = temp->next;
  }
  while(cnt1--) {
    temp->data = 1;
    temp = temp->next;
  }
  while(cnt2--) {
    temp->data = 2;
    temp = temp->next;
  }
  return head;
}

Node* sortLLWithOptimization(Node* head){
  Node* temp = head;
  Node* zerohead = new Node(-1);
  Node* onehead = new Node(-1);
  Node* twohead = new Node(-1);
  Node* zero = zerohead;
  Node* one = onehead;
  Node* two = twohead;
  while(temp != NULL){
    if(temp->data == 0){
      Node* newNode = new Node(0);
      zero->next = newNode;
      zero = zero->next;
    }
    else if(temp->data == 1){
      Node* newNode = new Node(1);
      one->next = newNode;
      one = one->next;
    }
    else{
      Node* newNode = new Node(2);
      two->next = newNode;
      two = two->next;
    }
    temp = temp->next;
  }
  zero->next = onehead->next;
  one->next = twohead->next;

  return zerohead->next;
}
int main(){
  vector<int> arr = {0, 0, 1, 1, 0, 2, 2, 0, 1, 0, 2, 0, 1, 0};
  Node* head = convertArrtoLL(arr);
  traverseLL(head);
  cout << endl;
  Node* resultHead = sortLLWithOptimization(head);
  traverseLL(resultHead);
  return 0;
}