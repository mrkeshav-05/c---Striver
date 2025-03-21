#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int M = 1e9 + 7;
// const int N = 1e5 + 10;
// long long A[N];

int memoization(int n, vector<int> &dp){
  if( n <= 1 ) return n;
  if( dp[n] != -1 ) return dp[n];
  return dp[n] = memoization(n-1, dp) + memoization(n-2, dp);
}
int tabulation(int n){
  vector<int> dp(n+1, -1);
  dp[0] = 0;
  dp[1] = 1;
  for(int i = 2; i <= n; i++){
    dp[i] = dp[i-1] + dp[i-2];
  }
  return dp[n];
}
int frogJump(vector<int> heigth){ // This is by using tabulation
  int n = height.size();
  vector<int> dp(n, 0);
  dp[0] = 0;
  dp[1] = abs(height[1] - height[0]);
  for(int i = 2; i < n; i++){
    dp[i] = min(dp[i-1] + abs(height[i] - height[i-1]), dp[i-2] + abs(height[i] - height[i-2]));
  }
  return dp[n-1];
}
int frogJump(vector<int> heigth){ // This is by using tabulation by spaceOptimization
  int n = height.size();
  int prev2 = 0;
  int prev1 = 0;
  for(int i = 1; i < n; i++){
    int first = prev1 + abs(height[i]-height[i-1]);
    int second = prev2 + abs(height[i]-height[i-2]);
    int curr = min(first, second);
    prev2 = prev1;
    prev1 = curr;
  }
  return prev1;
}
int frogJump(vector<int> heigth){ // this is by using memoization
  int n = height.size();
  vector<int> dp(n, -1);
  // this is a lembda function
  function<int(int)> dfs = [&](int i){
    if( i == 0 ) return 0;
    if( i == 1 ) return abs(height[1] - height[0]);
    if( dp[i] != -1 ) return dp[i];
    return dp[i] = min(dfs(i-1) + abs(height[i] - height[i-1]), dfs(i-2) + abs(height[i] - height[i-2]));
  };
}


int main(){
  int n;
  vector<int> dp(n+1, -1);
  cout << memoization(n, dp) << endl;
  cout << tabulation(n) << endl;
  return 0;
}