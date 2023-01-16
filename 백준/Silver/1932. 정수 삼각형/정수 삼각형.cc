#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
int triangle[501][501];
int dp[501][501];


int MaxPath(int y, int x){
  int &ret = dp[y][x];
  if(y == n-1){
    return triangle[y][x];
  }
  if(ret != -1){
    return ret;
  }
  return ret = triangle[y][x] + max(MaxPath(y+1, x), MaxPath(y+1, x+1));

}

int main(){
  memset(dp, -1, sizeof(dp));
  cin >> n;
  for(int i=0; i<n; i++){
    for(int j=0; j<=i; j++){
      cin >> triangle[i][j];
    }
  }

  cout << MaxPath(0, 0);

  return 0;
}