#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int M = 1e9 + 7;
// const int N = 1e5 + 10;
// long long A[N];

int main(){
  string beginWord;
  cin >> beginWord;
  string lastWord;
  cin >> lastWord;
  int n;
  cin >> n;
  vector<string> wordList(n);
  wordList.push_back(beginWord);
  n++;
  for(int i=0; i<n; i++){
    cin >> wordList[i];
  }
  vector<vector<int>> adj(n);
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      int diff = 0;
      for(int k=0; k<wordList[i].size(); k++){
        if(wordList[i][k] != wordList[j][k]){
          diff++;
        }
      }
      if(diff == 1){
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }
  }

  return 0;
}
