#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int M = 1e9 + 7;
// const int N = 1e5 + 10;
// long long A[N];

// Breadth-First Search or Level-First Search
// vector<int> &adj[] this is array of vectors
// Time cpmplexity O(N + 2*E) = O(N + E)
// Space complexity O(N) + O(N) + O(N) = O(N)
// If adj is given 
void dfs(int node, vector<int> adj[], vector<int> &vis){
  vis[node] = 1;
  for(auto it : adj[node]){
    if(!vis[it]){
      dfs(it, adj, vis);
    }
  }
}
// If matrix is given 
void dfs(int node, vector<vector<int>> &adj, vector<int> &vis){
  vis[node] = 1;
  for(int i = 0; i < adj[node].size(); i++){
    if(!vis[i] && adj[node][i] != 0){
      dfs(i, adj, vis);
    }
  }
}
void bfs(int node, vector<vector<int>> &adj, vector<int> &vis){
  queue<int> q;
  q.push(node);
  vis[node] = 1;
  while(!q.empty()){
    int node = q.front();
    q.pop();
    for(int i = 0; i < adj[node].size(); i++){
      if(!vis[i] && adj[node][i] != 0){
        vis[i] = 1;
        q.push(i);
      }
    }
  }
}

int numProviences(int n, vector<int> adj[]){
  vector<int> vis(n, 0);
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    if(!vis[i]){
      cnt++;
      dfs(i, adj, vis);
      // or
      // bfs(i, adj, vis);
    }
  }
  return cnt;
}

int main(){
int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    vector<int> adj[n];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // vector<int> bfs = bfsTraversal(n, adj);
    // vector<int> dfs = dfsOfGraph(n, adj);
    // for (auto it : dfs) {
    //     cout << it << " ";
    // }
    cout << endl;

    return 0;
}