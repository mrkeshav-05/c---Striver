#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int M = 1e9 + 7;
// const int N = 1e5 + 10;
// long long A[N];


vector<int> findTopologicalOrder(int n, vector<vector<pair<int, int>>> &adj){
  vector<int> indegree(n, 0);
  for(int i=0; i<n; i++){
    for(auto &x: adj[i]){
      indegree[x.first]++;
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
    int u = q.front();
    q.pop();
    topo.push_back(u);
    for(auto &x: adj[u]){
      indegree[x.first]--;
      if(indegree[x.first] == 0){
        q.push(x.first);
      }
    }
  }
  return topo;
}
vector<int> shortestPathInDirectedGraph(int n, vector<vector<pair<int, int>>> &adj){
  vector<int> topo = findTopologicalOrder(n, adj);
  vector<int> dist(n, INT_MAX);
  dist[0] = 0;
  for(auto &node: topo){
    if(dist[node] != INT_MAX){
      for(auto &adjacentNode : adj[node]){
        dist[adjacentNode.first] = min(dist[adjacentNode.first], dist[node] + adjacentNode.second);
      }
    }
  }
  return dist;
}
vector<int> shortestPathInUndirectedGraph(int n, vector<vector<pair<int, int>>> &adj){
  vector<int> dist(n, INT_MAX);
  dist[0] = 0;
  queue<int> q;
  q.push(0);
  vectot<int> dist(n, INT_MAX);
  dist[0] = 0;// or dist[src] = 0;
  while(!q.empty()){
    int node = q.front();
    q.pop();
    for(auto adjacentNode : adj[node]){
      if(dist[adjacentNode.first] > dist[node] + adjacentNode.second){
        dist[adjacentNode.first] = dist[node] + adjacentNode.second;
        q.push(adjacentNode.first);
      }
    }
  }
  return dist;
}
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v, x;
    cin >> u >> v >> x;
    adj[u].push_back({v, x});
  }
  // vector<int> temp = shortestPathInDirectedGraph(n, adj);
  vector<int> temp = shortestPathInUndirectedGraph(n, adj);
  for(auto &x: temp){
    cout << x << " ";
  }
  cout << endl;
  return 0;
}