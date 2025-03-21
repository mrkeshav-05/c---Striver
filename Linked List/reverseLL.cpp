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
Node* reverseLLWithStack(Node* head){
  Node* temp = head;
  stack<int> st;
  while(temp != NULL){
    st.push(temp->data);
    temp = temp->next;
  }
  temp = head;
  while(temp != NULL){
    temp->data = st.top();
    st.pop();
    temp = temp->next;
  }
  return head;
}
// THis is iterativer approach with time O(N) and space O(1)
Node* reverseLLWithoutUsingExtraDataStructure(Node* head){
  Node* prev = NULL;
  Node* curr = head;
  Node* next = NULL;
  while(curr != NULL){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  head = prev;
  return head;
}
// This is recursive approach with time O(N) and space O(N)
Node* reverseLLWithRecursive(Node* head){
  if(head == NULL || head->next == NULL) return head;
  Node* newNode = reverseLLWithRecursive(head->next);
  head->next->next = head;
  head->next = NULL;
  return newNode;
}
Node* reverseKGroup(Node* head, int k) {
        // if head is NULL
        if(head == NULL) return head;
        Node* curr = head;
        for(int i=0; i<=k; i++){
            if(curr == NULL) return head;
            curr = curr->next;
        }
        Node* prev = NULL;
        Node* next = NULL;
        Node* temp = head;
        curr = head;
        for(int i=0; i<k; i++){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        temp->next = reverseKGroup(curr, k);
        
        return head;
    }
int main(){
  vector<int> arr = {1,2,3,4,5};
  Node* head = convertArrtoLL(arr);
  traverseLL(head);
  cout << endl;
  head = reverseKGroup(head, 2);
  traverseLL(head);
  return 0;
}
