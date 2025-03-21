#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int M = 1e9 + 7;
// const int N = 1e5 + 10;
// long long A[N];

// Breadth-First Search or Level-First Search
void dfs(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &vis){
  int m = matrix.size();
  int n = matrix[0].size();
  if(i < 0 || i >= m || j < 0 || j >= n || vis[i][j] || matrix[i][j] == 0){
    return;
  }
  vis[i][j] = 1;
  dfs(i+1, j, matrix, vis);
  dfs(i-1, j, matrix, vis);
  dfs(i, j+1, matrix, vis);
  dfs(i, j-1, matrix, vis);
}
int numberOfIslandsUsingDfs(vector<vector<int>> matrix){
  int m = matrix.size();
  int n = matrix[0].size();
  vector<vector<int>> vis(m, vector<int> (n, 0));
  int cnt = 0;
  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      if(!vis[i][j] && matrix[i][j] == 1){
        cnt++;
        dfs(i, j, matrix, vis);
      }
    }
  }
}
int numberOfIslandsUsingBFS(vector<vector<int>> matrix){
  int m = matrix.size();
  int n = matrix[0].size();
  vector<vector<int>> vis(m, vector<int> (n, 0));
  int cnt = 0;
  for(int i = 0; i < m; ++i){
    for(int j = 0; j < n; ++j){
      if(!vis[i][j] && matrix[i][j] == 1){
        cnt++;
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;
        while(!q.empty()){
          int x = q.front().first;
          int y = q.front().second;
          q.pop();
          if(x+1 < m && !vis[x+1][y] && matrix[x+1][y] == 1){
            q.push({x+1, y});
            vis[x+1][y] = 1;
          }
          if(x-1 >= 0 && !vis[x-1][y] && matrix[x-1][y] == 1){
            q.push({x-1, y});
            vis[x-1][y] = 1;
          }
          if(y+1 < n && !vis[x][y+1] && matrix[x][y+1] == 1){
            q.push({x, y+1});
            vis[x][y+1] = 1;
          }
          if(y-1 >= 0 && !vis[x][y-1] && matrix[x][y-1] == 1){
            q.push({x, y-1});
            vis[x][y-1] = 1;
          }
        }
      }
    }
  }
  return cnt;
}

void runningDfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int, int>> &island, int i0, int j0){
  int n = grid.size();
  int m = grid[0].size();
  vis[i][j] = 1;
  island.push_back({i-i0, j-j0});
  vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  for(auto [dx, dy] : direction){
    int nx= i+dx;
    int ny= j+dy;
    if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny]==1){
      runningDfs(nx, ny, grid, vis, island, i0, j0);
    }
  }
}

int numberOfDistictsIslands(vector<vector<int>> &grid){
  int n = grid.size();
  int m = grid[0].size();
  vector<vector<int>> vis(n, vector<int> (m, 0));
  set<vector<pair<int, int>>> islands;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(!vis[i][j] && grid[i][j] == 1){
        vector<pair<int, int>> island;
        runningDfs(i, j, grid, vis, island, i, j);
        sort(island.begin(), island.end());
        islands.insert(island);
      }
    }
  }
  return islands.size();
}


int main(){
    int n, m;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int> (n, 0));
    for(int i=0; i<m; i++){
      for(int j=0; j<n; j++){
        cin >> matrix[i][j];
      }
    }
    cout << numberOfIslandsUsingBFS(matrix) << endl;
    // vector<vector<int>> island = numberOfDistictsIslands(matrix);
    // for(int i=0; i<m; i++) {
    //   for(int j=0; j<n; j++){
    //     cout << island[i][j] << " ";
    //   }
    //   cout << endl;
    // }

    return 0;
}