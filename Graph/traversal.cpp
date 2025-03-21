// #include <bits/stdc++.h>
// #include <iostream>
// using namespace std;
// const int M = 1e9 + 7;
// // const int N = 1e5 + 10;
// // long long A[N];

// // Breadth-First Search or Level-First Search
// // vector<int> &adj[] this is array of vectors
// // Time cpmplexity O(N + 2*E) = O(N + E)
// // Space complexity O(N) + O(N) + O(N) = O(N)
// vector<int> bfsTraversal(int n, vector<int> adj[]){
//   vector<int> vis(n, 0);
//   vis[0] = 1;
//   vector<int> bfs;
//   queue<int> q;
//   q.push(0);
//   while(!q.empty()){
//     int node = q.front();
//     q.pop();
//     bfs.push_back(node);
//     for(auto it : adj[node]){
//       if(!vis[it]){
//         vis[it] = 1;
//         q.push(it);
//       }
//     }
//   }
//   return bfs;
// }

// // Depth-First Search or Pre-Order Traversal
// // vector<int> &adj[] this is array of vectors
// // Time cpmplexity O(N + 2*E) = O(N + E)
// // Space complexity O(N) + O(N) + O(N) = O(N)
// vector<int> dfsTraversal(int n, vector<int> adj[]){
//   vector<int> vis(n, 0);
//   vis[0] = 1;
//   vector<int> dfs;
//   stack<int> st;
//   st.push(0);
//   while(!st.empty()){
//     int node = st.top();
//     st.pop();
//     dfs.push_back(node);
//     for(auto it : adj[node]){
//       if(!vis[it]){
//         vis[it] = 1;
//         st.push(it);
//       }
//     }
//   }
//   return dfs;
// }
// int main(){
//   int n, m;
//   cout << "Enter the number of nodes and edges: ";
//   cin >> n >> m;
//   vector<int> adj[n];
//   for(int i = 0; i < m; i++){
//     int u, v;
//     cin >> u >> v;
//     adj[u].push_back(v);
//     adj[v].push_back(u);
//   }
//   vector<int> bfs = bfsTraversal(n, adj);
//   for(auto it : bfs){
//     cout << it << " ";
//   }
//   cout << endl;
//   return 0;
// }

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

const int M = 1e9 + 7;

// Breadth-First Search (BFS)
vector<int> bfsTraversal(int n, vector<int> adj[]) {
    vector<int> vis(n, 0); // Use vector for dynamic size
    vis[0] = 1;
    vector<int> bfs;
    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for (auto it : adj[node]) {
            if (!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

// Depth-First Search (DFS)
vector<int> dfsTraversal(int n, vector<int> adj[]) {
    vector<int> vis(n, 0); // Use vector for dynamic size
    vis[0] = 1;
    vector<int> dfs;
    stack<int> st;
    st.push(0);
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        dfs.push_back(node);
        for (auto it : adj[node]) {
            if (!vis[it]) {
                vis[it] = 1;
                st.push(it);
            }
        }
    }
    return dfs;
}
void dfsTraversalUsingRecursion(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfs) {
    dfs.push_back(node);
    vis[node] = 1;
    // traverse all the adjacent nodes of the current node
    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfsTraversalUsingRecursion(it, adj, vis, dfs);
        }
    }
}
vector<int> dfsOfGraph(int n, vector<int> adj[]) {
    vector<int> vis(n, 0);
    int start = 0;
    vector<int> dfs;
    dfsTraversalUsingRecursion(start, adj, vis, dfs);
    return dfs;
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

    // vector<int> bfs = bfsTraversal(n, adj);
    vector<int> dfs = dfsOfGraph(n, adj);
    for (auto it : dfs) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
