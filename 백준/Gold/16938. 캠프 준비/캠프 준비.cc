#include<iostream>

#define MAX 987654321

using namespace std;

int N,L,R,X;
int A[16];
int ans=0;

void dfs(int idx, int sum, int min, int max){
  if(sum > R) return;
  if(idx==N){
    if(sum>=L && sum<=R && max-min>=X)
      ans++;
    return;
  }
  dfs(idx+1, sum+A[idx], min<A[idx]?min:A[idx], max>A[idx]?max:A[idx]);
  dfs(idx+1, sum, min, max);
}

int main(){
  cin >> N >> L >> R >> X;
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  dfs(0,0,MAX,-1);
  cout << ans;
}