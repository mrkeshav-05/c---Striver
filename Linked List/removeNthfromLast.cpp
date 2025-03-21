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

Node* removeNthfromLast(Node* head, int n){
  Node* dummy = new Node(0);
  dummy->next = head;
  Node* first = dummy;
  Node* second = dummy;
  for(int i = 1; i <= n+1; i++){
    first = first->next;
  }
  while(first != NULL){
    first = first->next;
    second = second->next;
  }
  second->next = second->next->next;
  return dummy->next;
}
Node* reverseLL(Node* head){
  Node* prev = NULL;
  Node* curr = head;
  Node* next = NULL;
  while(curr != NULL){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}
Node* removeNthfromFirstUsingReverseLL(Node* head, int n){
  head = reverseLL(head);
  Node* temp = head;
  if(n == 1){
    head = head->next;
    return reverseLL(head);
  }
  for(int i = 1; i < n-1; i++){
    temp = temp->next;
  }
  temp->next = temp->next->next;
  head = reverseLL(head);
  return head;
}

int main(){
  vector<int> arr = {1,2,3,4,5};
  Node* head = convertArrtoLL(arr);
  // traverseLL(head);
  head = removeNthfromFirstUsingReverseLL(head, 1);
  traverseLL(head);
  return 0;
}