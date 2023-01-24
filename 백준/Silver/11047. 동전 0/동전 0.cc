#include<iostream>
#include<vector>

using namespace std;

int N,K;
vector<int> coins;

void find_coin(int index, int k, int count){
  if(k==0){
    cout << count << endl;
    return;
  }
  if(index<0 || k<0){
    cout << -1;
    return;
  }
  if(k>=coins[index]){
    find_coin(index, k-coins[index], count+1);

  }
  else{
    find_coin(index-1, k, count);
  }
}

int main(){
  cin >> N >> K;

  for(int i=0; i<N; i++){
    int coin;
    cin >> coin;
    coins.push_back(coin);
  }
  find_coin(N-1, K, 0);

  return 0;
}