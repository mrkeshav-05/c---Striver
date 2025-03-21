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
  Node(int data1, Node* next){
    data = data1;
    next = next;
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

Node* insertAtKthelem(Node* head, int k, int data){
  if(head == NULL){
    head->data = data;
    head->next = NULL;
    return head;
  }
  if(k == 1){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
    return head;
  }
  Node* mover = head;
  int cnt = 0;
  while(head != NULL){
    cnt++;
    if(cnt == k-1){
      Node* temp = new Node(data);
      temp->next = mover->next;
      mover->next = temp;
      return head;
    }else{
      mover = mover->next;
    }
  }
  return head;
};



int main(){
  vector<int> arr = {1,2,3,4,5};
  Node* head = convertArrtoLL(arr);
  traverseLL(head);
  head = insertAtKthelem(head, 3, 10);
  cout << endl;
  traverseLL(head);

  return 0;
}