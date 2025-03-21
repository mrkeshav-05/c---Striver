#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int M = 1e9 + 7;
// const int N = 1e5 + 10;
// long long A[N];


bool dfsCheck(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis, vector<int> &check){
  vis[node] = 1;
  pathVis[node] = 1;
  for (auto adjacentNode : adj[node]) {
    if (!vis[adjacentNode]) {
      if (dfsCheck(adjacentNode, adj, vis, pathVis, check)) return true;
    } else if (pathVis[adjacentNode]) {
      return true;
    }
  }
  pathVis[node] = 0;
  check[node] = 1;
  return false;
}

vector<int> eventualSafeNodesUsingDFS(int n, vector<vector<int>> &adj){
  vector<int> vis(n, 0);
  vector<int> pathVis(n, 0);
  vector<int> check(n, 0);
  vector<int> safeNodes;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      dfsCheck(i, adj, vis, pathVis, check);
    }
  }
  for (int i = 0; i < n; i++) {
    if (check[i] == 1) safeNodes.push_back(i);
  }
  return safeNodes;
}

vector <int> eventualSafeNodesUsingBFS(int n, vector<vector<int>> &adj){
  vector<vector<int>> revadj(n);
  for (int i = 0; i < n; i++) {
    for (auto it : adj[i]) {
      // i -> it
      // it -> i
      revadj[it].push_back(i);
    }
  }
  vector<int> indegree(n, 0);
  for (int i = 0; i < n; i++) {
    for (auto it : revadj[i]) {
      indegree[it]++;
    }
  }
  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }
  vector<int> safeNodes;
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    safeNodes.push_back(node);
    for (auto it : revadj[node]) {
      indegree[it]--;
      if (indegree[it] == 0) {
        q.push(it);
      }
    }
  }
  return safeNodes;
}

// A node is called eventually safe if every possible path starting from
// that node ends in a terminal node (a node with no outgoing edges) and does not enter a cycle.
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
    // vector<int> v = eventualSafeNodesUsingDFS(n, adj);
    vector<int> v = eventualSafeNodesUsingBFS(n, adj);
    for(auto i : v){
      cout << i << " ";
    }
    cout << endl;
  return 0;
}