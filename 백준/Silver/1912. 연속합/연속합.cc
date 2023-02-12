#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int num[100001];
long long int max_num = -987654321;
long long int dp[100001]={0,};

int main(){
  cin >> n;
  for(int i=1; i<=n;i++){
    cin >> num[i];
  }

  for(int i=1; i<=n; i++){
    dp[i] = max(dp[i-1] + num[i], (long long int)num[i]);
    max_num = max(max_num, dp[i]);
  }
  cout << max_num;

}