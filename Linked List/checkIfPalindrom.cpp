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
// Time Complexity O(2*N) and space Complexity O(N)
bool checkIfPalindrom(Node* head){
  Node* temp = head;
  stack<int> st;
  while(temp != NULL){
    st.push(temp->data);
    temp = temp->next;
  }
  temp = head;
  while(temp != NULL){
    if(temp->data != st.top()){
      return false;
    }
    st.pop();
    temp = temp->next;
  }
  return true;
}
Node* reverseLL(Node* head){
  if(head == NULL || head->next == NULL) return head;
  Node* newNode = reverseLL(head->next);
  head->next->next = head;
  head->next = NULL;
  return newNode;
}
bool checkIfPalindromWithLessTime(Node* head){
  Node* slow = head;
  Node* fast = head;
  while(fast->next != NULL && fast->next->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
  }
  Node* newNode = reverseLL(slow->next);
  Node* first = head;
  Node* second = newNode;
  while(second != NULL){
    if(first->data != second->data){
      return false;
    }
    first = first->next;
    second = second->next;
  }
  return true;
}
int main(){
  vector<int> arr = {1,2,2,1};
  Node* head = convertArrtoLL(arr);
  traverseLL(head);
  cout << endl;
  cout << checkIfPalindromWithLessTime(head);
  return 0;
}
