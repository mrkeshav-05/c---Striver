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

// Node* oddEvenSeperator(Node* head){
//   if(head == NULL || head->next == NULL){
//     return head;
//   }
//   Node* temp = head;
//   Node* resultHead = new Node(0);
//   while(temp != NULL || temp->next != NULL){
//     Node* newNode = new Node(temp->data);
//     resultHead->next = newNode;
//     resultHead = resultHead->next;
//     temp = temp->next->next;
//   }
//   if(temp->next == NULL){
//     Node* newNode = new Node(temp->data);
//     resultHead->next = newNode;
//   }
//   temp = head->next;
//   while(temp != NULL || temp->next != NULL){
//     Node* newNode = new Node(temp->data);
//     resultHead->next = newNode;
//     resultHead = resultHead->next;
//     temp = temp->next->next;
//   }
//   if(temp->next == NULL){
//     Node* newNode = new Node(temp->data);
//     resultHead->next = newNode;
//   }
//   return resultHead;
// }
Node* oddEvenSeperator(Node* head){
  if(head == NULL || head->next == NULL){
    return head;
  }

  Node* oddDummy = new Node(0);
  Node* evenDummy = new Node(0);
  Node* odd = oddDummy;
  Node* even = evenDummy;
  Node* temp = head;
  bool isOdd = true;

  while(temp != NULL){
    if(isOdd){
      odd->next = new Node(temp->data);
      odd = odd->next;
    } else {
      even->next = new Node(temp->data);
      even = even->next;
    }
    temp = temp->next;
    isOdd = !isOdd;
  }

  odd->next = evenDummy->next;
  return oddDummy->next;
}
int main(){
  vector<int> arr1 = {1,2,3,4,5};
  Node* head = convertArrtoLL(arr1);
  traverseLL(head);
  cout<<endl;
  Node* resultHead = oddEvenSeperator(head);
  traverseLL(resultHead);
  return 0;
}