#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int M = 1e9 + 7;
// const int N = 1e5 + 10;
// long long A[N];

void reverseArr(vector<int> &A){
  if(A.size() == 0){
    return;
  }
  int temp = A.back();
  A.pop_back();
  reverseArr(A);
  A.insert(A.begin(), temp);
}
void reverseArr(vector<int> &A, int l, int r){
  if(l >= r){
    return;
  }
  swap(A[l], A[r]);
  reverseArr(A, l+1, r-1);
}
bool checkForPalindrome(string s){
  if(s.length() == 0 || s.length() == 1){
    return 1;
  }
  if(s[0] == s[s.length()-1]){
    return checkForPalindrome(s.substr(1, s.length()-2));
  }
  return 0;
}

void reverseString(string s, int l, int r){
  if(l >= r){
    return;
  }
  swap(s[l], s[r]);
  reverseString(s, l+1, r-1);
}


int main(){
  vector<int> A = {1,2,3,4,5,6,7};
  int n = A.size();
  reverseArr(A, 0, n-1);
  for(int i = 0; i < n; i++){
    cout << A[i] << " ";
  }
  cout << endl;
  string s = "abba";
  // cout << checkForPalindrome(s) << endl;
  string s2 = s;
  reverseString(s2, 0, s2.length()-1);
  if(s == s2)
    cout << "Palindrome" << endl;
  else
    cout << "Not Palindrome" << endl;
  return 0;
}