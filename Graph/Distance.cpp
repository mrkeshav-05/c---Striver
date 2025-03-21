#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int M = 1e9 + 7;
// const int N = 1e5 + 10;
// long long A[N];

// Distance of nearest cell having 1 in a binary matrix
vector<vector<int>> nearestCell(vector<vector<int>> matrix){
  int m = matrix.size();
  int n = matrix[0].size();
  vector<vector<int>> dist(m, vector<int> (n, INT_MAX));
  queue<pair<int, int>> q;
  for(int i = 0; i < m; ++i){
    for(int j = 0; j < n; ++j){
      if(matrix[i][j] == 1){
        dist[i][j] = 0;
        q.push({i, j});
      }
    }
  }
  vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for(auto [dx, dy] : dirs){
      int nx = x + dx;
      int ny = y + dy;
      if(nx >= 0 && nx < m && ny >= 0 && ny < n && dist[nx][ny] > dist[x][y] + 1){
        dist[nx][ny] = dist[x][y] + 1;
        q.push({nx, ny});
      }
    }
  }
  return dist;
}

int main() {
    int n, m;
    // cout << "Enter number of rows and columns";
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int> (n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    vector<vector<int>> result = nearestCell(matrix);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}