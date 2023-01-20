#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int n;
int A[1001];
int dp_left[1001];
int dp_right[1001];

int left_start(int start){
  int &ret = dp_left[start];
  if(ret != -1){
    return ret;
  }
  ret = 1;
  for(int i=start+1; i<n; i++){
    if(A[start] > A[i]){
      ret = max(ret, left_start(i) + 1);
    }
  }
  return ret;
}

int right_start(int start){
  int &ret = dp_right[start];
  if(ret != -1){
    return ret;
  }
  ret = 1;
  for(int i=start-1; i>=0; i--){
    if(A[start] > A[i]){
      ret = max(ret, right_start(i) + 1);
    }
  }
  return ret;
}

int main(){
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> A[i];
  }
  memset(dp_left, -1, sizeof(dp_left));
  memset(dp_right, -1, sizeof(dp_right));
  for(int i=0; i<n; i++){
    left_start(i);
    right_start(i);
  }
  int ans = 0;
  for(int i=0; i<n; i++){
    ans = max(ans, dp_left[i] + dp_right[i] - 1);
  }
  cout << ans;


  return 0;
}