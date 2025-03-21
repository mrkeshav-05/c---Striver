#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int M = 1e9 + 7;
// const int N = 1e5 + 10;
// long long A[N];

bool detect(int src, vector<int> adj[], vector<int> &vis){
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto adjacentNode : adj[node]){
            if(!vis[adjacentNode]){
                vis[adjacentNode] = 1;
                q.push({adjacentNode, node});
            }else if(parent != adjacentNode){
                return true;
            }
        }
    }
}

bool detectCycleUsingBFS(vector<int> adj[], int n){
    vector<int> vis(n, 0);
    queue<pair<int, int>> q;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            if(detect(i, adj, vis)) return true;
        }
    }
    return false;
}

bool dfs(int node, int parent, vector<int> adj[], vector<int> &vis){
    vis[node] = 1;
    for(auto adjacentNode : adj[node]){
        if(!vis[adjacentNode]){
            if(dfs(adjacentNode, node, adj, vis)) return true;
        }
        // visited and not parent visited
        else if(parent != adjacentNode){
            return true;
        }
    }
    return false;
}

bool detectCycleUsingDFS(vector<int> adj[], int n){
    vector<int> vis(n, 0);
    for(int i=0; i<n; i++){
        if(!vis[i]){
            if(dfs(i, -1, adj, vis)) return true;
        }
    }
    return false;
}
bool dfsCheck(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathvis){
    vis[node] = 1;
    pathvis[node] = 1;
    for(auto adjacentNode : adj[node]){
        if(!vis[adjacentNode]){
            if(dfsCheck(adjacentNode, adj, vis, pathvis)) return true;
        }else if(pathvis[adjacentNode]){
            return true;
        }
    }
    pathvis[node] = 0;
    return false;
}
bool detectCycleUsingDFSIndirectedGraph(vector<int> adj[], int n){
    vector<int> vis(n, 0);
    vector<int> pathvis(n, 0);
    for(int i=0; i<n; i++){
        if(!vis[i]){
            if(dfsCheck(i, adj, vis, pathvis)) return true;
        }
    }
    return false;
}

bool bfsCheck(int node, vector<int> adj[], vector<int> vis){

}

bool detectCycleUsingBFSIndirectedGraph(vector<int> adj[], int n){
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
    int cnt = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cnt++;

        for(auto it : adj[node]){
            indegree[it]--;
        if(indegree[it] == 0){
            q.push(it);
        }
        }
    }
    // It mean that the graph is linear and does not have cycle
    if(cnt == n) return false;
    return true;
}

int main() {
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
    // cout << detectCycleUsingBFS(adj, n);
    // cout << detectCycleUsingDFS(adj, n);
    // cout << detectCycleUsingDFSIndirectedGraph(adj, n) << endl;
    cout << detectCycleUsingBFSIndirectedGraph(adj, n) << endl;
    return 0;
}