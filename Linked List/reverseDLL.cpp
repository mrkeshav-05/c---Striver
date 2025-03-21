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
Node* reverseDLL(Node* head){
  Node* temp = head;
  stack<int> st;
  while(temp!=NULL){
    st.push(temp->data);
    temp = temp->next;
  }
  temp = head;
  while(temp!=NULL){
    temp->data = st.top();
    st.pop();
    temp = temp->next;
  }
  return head;
}
Node* reverseDLLwithLessTime(Node* head){
  if(head == NULL || head->next == NULL) return head;
  Node* curr = head;
  Node* last = NULL;
  while(curr != NULL){
    last  = curr->prev;
    curr->prev = curr->next;
    curr->next = last;
    curr = curr->prev;
  }
  return last->prev;
}

int main(){
  vector<int> arr = {1,2,3,4,5};
  Node* head = convertArrtoDLL(arr);
  traverseDLL(head);
  cout<<endl;
  // head = reverseDLL(head);
  head = reverseDLLwithLessTime(head);
  traverseDLL(head);

  return 0;
}