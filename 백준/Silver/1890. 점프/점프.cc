#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

int n;
int map[101][101];
long long dp[101][101];
int cnt=0;

long long findPath(int x,int y){
  if(x == n - 1 && y == n - 1){
    return 1;
  }
  if(dp[x][y] != -1){
    return dp[x][y];
  }
  dp[x][y] = 0;
  if(x + map[x][y] < n){
    dp[x][y] += findPath(x + map[x][y], y);
  }
  if(y + map[x][y] < n){
    dp[x][y] += findPath(x, y + map[x][y]);
  }
  return dp[x][y];

}

int main(){
  memset(dp, -1, sizeof(dp));
  cin >> n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> map[i][j];
    }
  }

  cout << findPath(0, 0);

  return 0;
}