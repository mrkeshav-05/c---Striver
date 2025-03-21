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
Node* reverseLL(Node* head){
  if(head == NULL && head->next == NULL) return head;
  Node* newNode = reverseLL(head->next);
  head->next->next = head;
  head->next = NULL;
  return newNode;
}
Node* addOneLL(Node* head){
  head = reverseLL(head);
  Node* temp = head;
  int carry = 1;
  while(temp != NULL){
    temp->data = temp->data + carry;
    if(temp->data < 10){
      carry = 0;
      break;
    }else{
      carry = 1;
      temp->data = 0;
    }
    temp = temp->next;
  }
  if(carry == 1){
    Node* newNode = new Node(1);
    head = reverseLL(head);
    newNode->next = head;
    return newNode;
  }
  head = reverseLL(head);
  return head;
}
int main(){
  vector<int> arr = {9,9,9};
  Node* head = convertArrtoLL(arr);
  traverseLL(head);
  cout << endl;
  head = addOneLL(head);
  traverseLL(head);
  return 0;
}