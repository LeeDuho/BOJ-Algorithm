#include<iostream>
#include<vector>
#include<list>
using namespace std;

int N;
int adj[1001][1001] = {0,};
bool check[1001] = {false,};
list<int> V[1001];

void euler(int here){
  while(!V[here].empty()){
    int there = V[here].back();
    if(adj[here][there] > 0){
      if(adj[here][there] == 1){
        V[here].pop_back();
      }
      
      adj[here][there]--;
      adj[there][here]--;
      euler(there);
    }
    else{
      V[here].pop_back();
    }
  }

  cout << here << " ";

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  int check =0;
  for(int i=1;i<=N;i++){
    check = 0;
    for(int j=1; j<=N;j++){
      cin >> adj[i][j];
      
      if(adj[i][j] > 0){
        V[i].push_back(j);
        V[j].push_back(i);
      }
      check += adj[i][j];
    }
    if(check%2 == 1){
      cout << -1;
      return 0;
    }
  }

  euler(1);

  return 0;
}