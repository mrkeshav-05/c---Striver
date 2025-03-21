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

Node* deleteHead(Node* head){
  if(head == NULL) return head;
  Node* temp = head;
  head = head->next;
  delete temp;
  return head;
}

Node* deleteTail(Node* head){
  if(head == NULL) return head;
  if(head->next == NULL){
    delete head;
    return NULL;
  }
  Node* mover = head;
  while(mover->next->next != NULL){
    mover = mover->next;
  }
  delete mover->next;
  mover->next = NULL;
  return head;
}


Node* deleteKthelem(Node* head, int k){
  if(head == NULL) return head;
  if(k == 1){
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
  }
  int cnt = 0;
  Node* mover = head;
  while(mover != NULL){
    cnt++;
    if(cnt == k-1){
      Node* temp = mover->next;
      mover->next = mover->next->next;
      delete temp;
      return head;
      break;
    }
    else{
      mover = mover->next;
    }
  }
  return head;
}

int main(){
  vector<int> arr = {1,2,3,4,5};
  Node* head = convertArrtoLL(arr);
  // head = deleteHead(head);
  // head = deleteTail(head);
  head = deleteKthelem(head, 5);
  traverseLL(head);

  return 0;
}