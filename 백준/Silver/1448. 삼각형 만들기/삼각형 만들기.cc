#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int> straw;

int main(){
  cin >> n;
  straw.assign(n,0);
  for(int i=0; i<n; i++){
    cin >> straw[i];
  }
  sort(straw.begin(), straw.end(), greater<int>());
  for(int i=0; i<n-2; i++){
    if(straw[i] < straw[i+1] + straw[i+2]){
      cout << straw[i] + straw[i+1] + straw[i+2];
      return 0;
    }
  }
  cout << -1;

}