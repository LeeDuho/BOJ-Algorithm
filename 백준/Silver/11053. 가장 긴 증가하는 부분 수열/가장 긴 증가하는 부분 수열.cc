#include<iostream>

using namespace std;

int n;
int A[1001];
int dp[1001];

int longest_increasing_subsequence(int start){
  if(dp[start] != -1) return dp[start];
  int ret = 1;
  for(int i=start+1;i<n;i++){
    if(A[start] < A[i]){
      ret = max(ret, longest_increasing_subsequence(i)+1);
    }
  }
  return dp[start] = ret;
}



int main(){
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> A[i];
  }
  for(int i=0;i<n;i++){
    dp[i] = -1;
  }
  int maxLen = 0;
  for(int i=0;i<n;i++){
    maxLen = max(maxLen, longest_increasing_subsequence(i));
  }
  cout << maxLen;
  //cout << longest_increasing_subsequence(0);
  return 0;
}