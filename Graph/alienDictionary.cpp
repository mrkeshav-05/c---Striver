#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int M = 1e9 + 7;
// const int N = 1e5 + 10;
// long long A[N];


string findOrderOfAlphabet(vector<string> &dict, int n, int k){
  vector<vector<int>> adj(k);
  for(int i = 0; i < n-1; i++){
    string s1 = dict[i];
    string s2 = dict[i+1];
    int len = min(s1.length(), s2.length());
    for(int j = 0; j < len; j++){
      if(s1[j] != s2[j]){
        adj[s1[j] - 'a'].push_back(s2[j] - 'a');
        break;
      }
    }
  }
  vector<int> indegree(k, 0);
  for(int i = 0; i < k; i++){
    for(auto it : adj[i]){
      indegree[it]++;
    }
  }
  queue<int> q;
  for(int i = 0; i < k; i++){
    if(indegree[i] == 0){
      q.push(i);
    }
  }
  string ans = "";
  while(!q.empty()){
    int node = q.front();
    q.pop();
    ans += (node + 'a');
    for(auto it : adj[node]){
      indegree[it]--;
      if(indegree[it] == 0){
        q.push(it);
      }
    }
  }
  return ans;
}

int main(){
  int n, k;
    cin >> n >> k;
    vector<string> dict(n);
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        dict.push_back(s);
    }
    string s = findOrderOfAlphabet(dict, n, k);
    cout << s << endl;
  return 0;
}