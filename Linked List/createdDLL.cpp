#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int M = 1e9 + 7;
// const int N = 1e5 + 10;
// long long A[N];

struct Node{
  int data;
  Node* next;
  Node* prev;

  Node(int data1){
    data = data1;
    next = NULL;
    prev = NULL;
  }
  Node(int data1, Node* next1, Node* prev1){
    data = data1;
    next = next1;
    prev = prev1;
  }
};

Node* convertArrtoDLL(vector<int> arr){
  Node* head = new Node(arr[0]);
  Node* mover = head;
  for(int i = 1; i < arr.size(); i++){
    Node* temp = new Node(arr[i]);
    mover->next = temp;
    temp->prev = mover;
    mover = mover->next;
  }
  return head;
}
Node* traverseDLL(Node* head){
  Node* mover = head;
  while(mover != NULL){
    cout<< mover->data << " ";
    mover = mover->next;
  }
  return head;
}
Node* deleteKthelem(Node* head, int k){
  if(head == NULL) return head;
  if(k == 1){
    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
    return head;
  }
  Node* mover = head;
  int cnt = 0;
  while(mover != NULL){
    cnt++;
    if(cnt == k-1){
      Node* temp = mover->next;
      mover->next = temp->next;
      if(temp->next != NULL){
        temp->next->prev = mover;
      }
      delete temp;
      return head;
    }
  }
  return head;
}

Node* insertAtKthelem(Node* head, int k, int data){
  if(head == NULL){
    head->data = data;
    head->next = NULL;
    head->prev = NULL;
    return head;
  }
  if(k == 1){
    Node* temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;
  }
  Node* mover = head;
  int cnt = 0;
  while(mover != NULL){
    cnt++;
    if(cnt == k-1){
      Node* temp = new Node(data);
      temp->next = mover->next;
      temp->prev = mover;
      if(mover->next != NULL){
        mover->next->prev = temp;
      }
      mover->next = temp;
      return head;
    }else{
      mover = mover->next;
    }
  }
  return head;
}

int main(){
  vector<int> arr = {1,2,3,4,5};
  Node* head = convertArrtoDLL(arr);
  traverseDLL(head);
  cout<<endl;
  head = insertAtKthelem(head, 1, 10);
  traverseDLL(head);

  return 0;
}