#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int M = 1e9 + 7;
// const int N = 1e5 + 10;
// long long A[N];


// Topological Sorting :  is the liners ordering of vertices such that for every directed edge u->v, vertex u comes before v in the ordering.
// there should not be any cycle in the graph.
void dfs(int node, vector<int> &vis, stack<int> &st, vector<vector<int>> &adj){
  vis[node] = 1;
  for(auto it : adj[node]){
    if(!vis[it]){
      dfs(it, vis, st, adj);
    }
  }
  st.push(node);
}
vector<int> topoSortUsingDfs(int n, vector<vector<int>> &adj){
  vector<int> vis(n, 0);
  stack<int> st;
  for(int i=0; i<n; i++){
    if(!vis[i]){
      dfs(i, vis, st, adj);
    }
  }
  vector<int> topo;
  while(!st.empty()){
    topo.push_back(st.top());
    st.pop();
  }
  return topo;
}

vector<int> topoSortUsingBfs(int n, vector<vector<int>> &adj){
  vector<int> indegree(n, 0);
  for(int i=0; i<n; i++){
    for(auto it : adj[i]){
      indegree[it]++;
    }
  }
  queue<int> q;
  for(int i=0; i<n; i++){
    if(indegree[i] == 0){
      q.push(i);
    }
  }
  vector<int> topo;
  while(!q.empty()){
    int node = q.front();
    q.pop();
    topo.push_back(node);
    for(auto it : adj[node]){
      indegree[it]--;
      if(indegree[it] == 0){
        q.push(it);
      }
    }
  }
  return topo;
}

int main(){
  int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    // vector<int> v = topoSortUsingDfs(n, adj);
    vector<int> v = topoSortUsingBfs(n, adj);
    for(auto i : v){
      cout << i << " ";
    }
    cout << endl;
  return 0;
}