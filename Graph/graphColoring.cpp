#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int M = 1e9 + 7;
// const int N = 1e5 + 10;
// long long A[N];

bool bfs(vector<vector<int>> &adj, int n, vector<int> &color, int node){
  queue<int> q;
  q.push(node);
  color[node] = 0;
  while(!q.empty()){
    int node = q.front();
    q.pop();
    for(auto adjacentNode  : adj[node]){
      if(color[adjacentNode] == -1){
        color[adjacentNode] = 1-color[node];
      }else if(color[adjacentNode] == color[node]){
        return false;
      }
    }
  }
  return true;
}
bool isBipartitebfs(vector<vector<int>> &adj, int n){
  vector<int> color(n, -1);
  color[0] = 1;
  for(int i = 0; i < n; i++){
    if(!color[i]){
      if(bfs(adj, n, color, i) == false){
        return false;
      }
    }
  }
  return true;
}

bool dfs(vector<vector<int>> &adj, int n, vector<int> &color, int node, int col){
  color[node] = col;
  for(auto adjacentNode : adj[node]){
    if(color[adjacentNode] == -1){
      color[adjacentNode] = 1-color[node];
      if(!dfs(adj, n, color, adjacentNode, 1-col)){
        return false;
      }
    }else if(color[adjacentNode] == color[node]){
      return false;
    }
  }
  return true;
}

bool isBipartitedfs(vector<vector<int>> &adj, int n){
  vector<int> color(n, -1);
  color[0] = 1;
  for(int i = 0; i < n; i++){
    if(color[i] == -1){
      if(dfs(adj, n, color, i, 0) == false){
        return false;
      }
    }
  }
  return true;
}

int main() {
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // cout << isBipartitebfs(adj, n) << endl;
    cout << isBipartitedfs(adj, n) << endl;
    return 0;
}