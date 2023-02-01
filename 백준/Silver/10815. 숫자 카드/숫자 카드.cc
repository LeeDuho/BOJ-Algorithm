#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int n, m;
vector<int> V;

int isin(int num){
  int left = 0;
  int right = n-1;
  int mid;
  while(left <= right){
    mid = (left+right)/2;
    if(V[mid] == num){
      return 1;
    }
    else if(V[mid] > num){
      right = mid-1;
    }
    else{
      left = mid+1;
    }
  }
  return 0;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  V.resize(n);
  for(int i=0; i<n; i++){
    cin >> V[i];
  }
  sort(V.begin(), V.end());

  cin >> m;
  int num;
  for(int i=0; i<m; i++){
    cin >> num;
    cout << isin(num) << " ";
  }
}