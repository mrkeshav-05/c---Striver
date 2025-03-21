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

// LL one = 1->2->3->4->5->X
// LL two = 6->7->8->X
// LL sum = 7->9->1->5->5->X

Node* sum(Node* head1, Node* head2){
  Node* resultHead = new Node(0);
  Node* mover1 = head1;
  Node* mover2 = head2;
  Node* mover3 = resultHead;
  int carry = 0;
  while(mover1 != NULL || mover2 != NULL){
    int sum = carry;
    if(mover1 != NULL){
      sum += mover1->data;
      mover1 = mover1->next;
    }
    if(mover2 != NULL){
      sum += mover2->data;
      mover2 = mover2->next;
    }
    carry = sum/10;
    sum = sum%10;
    Node* temp = new Node(sum);
    mover3->next = temp;
    mover3 = mover3->next;
  }
  if(carry > 0){
    Node* temp = new Node(carry);
    mover3->next = temp;
  }
  return resultHead->next;
}
int main(){
  vector<int> arr1 = {1,2,3,4,5};
  vector<int> arr2 = {6,7,8};
  Node* head1 = convertArrtoLL(arr1);
  Node* head2 = convertArrtoLL(arr2);
  // traverseLL(head);
  Node* resultHead = sum(head1, head2);
  traverseLL(resultHead);
  return 0;
}