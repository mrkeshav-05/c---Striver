// #include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
// using namespace std;

// struct Node{
//   public:
//   int data;
//   Node* next;
  
//   public:
//   Node(int data1, Node* next1){
//     data = data1;
//     next = next1;
//   }
// };
// int main(){
//   int arr[] = {1,2,3,4};
//   Node y = Node(arr[0],nullptr);
//   cout<< y->data;
// return 0;
// }


#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node{
  public:
  int val;
  Node* next;
  public:
  Node(int data){
    val = data;
    next = NULL;
  }
  public:
  Node(int data, Node* next){
    val = data;
    next = next;
  }
};

int main(){
  Node x = Node(2, nullptr);
  // This create a stack-allocated object
  // Life time is scope of main
  // acessed directly by x.val

  Node* y = new Node(3, nullptr);
  // This create a heap-allocated object
  // Life time is until deleted
  // acessed by y->val
  Node* z = &x;
  // This create a pointer z that refers to the memory address of the stack allocated object x
  // Accessing z->val is equivalent to accessing x.val.
  Node* w = y;
  cout<< w->val;
  cout<< x.val;
  cout<< y->val;
  cout<< z->val;
return 0;
}


// 1. Stack Memory: 
// Definition: A region of memory used for managing the execution of functions. Variables with automatic storage duration (local variables, function parameters) are allocated here.
// Characteristics:
// Automatically managed: memory is allocated when the function is called and deallocated when the function exits.
// Fast access due to Last-In-First-Out (LIFO) organization.
// Limited size: determined by the operating system.
// Use Cases: Local variables, function calls, and function return addresses.


// 2. Heap Memory
// Definition: A region of memory used for dynamic memory allocation. It is managed explicitly by the programmer using new/delete (in C++) or malloc/free (in C).
// Characteristics:
// Flexible size and lifetime: memory remains allocated until explicitly freed.
// Slower than stack memory due to the need for manual management and potential fragmentation.
// Large size compared to stack memory.
// Use Cases: Objects or data structures requiring a variable or extended lifetime.