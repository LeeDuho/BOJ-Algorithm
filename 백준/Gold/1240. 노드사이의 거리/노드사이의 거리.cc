#include<iostream>
#include<vector>
#include<map>
#include<list>

using namespace std;

int n,m;
vector<int> visited(1001,0);

vector<pair<int,long long int>> v[1001];

long long int dfs(int start, int end){
  if(start == end){
    return 0;
  }
  for(int i=0; i<v[start].size(); i++){
    if(visited[v[start][i].first] == 0){
      visited[v[start][i].first] = 1;
      long long int temp = dfs(v[start][i].first, end);
      if(temp != -1){
        return temp + v[start][i].second;
      }
    }
  }
  return -1;
}

int main(){
  cin >> n >> m;
  int a,b;
  long long int w;
  for(int i=0; i<n-1; i++){
    cin >> a >> b >> w;
    v[a].push_back(make_pair(b,w));
    v[b].push_back(make_pair(a,w));
  }
  for(int i=0; i<m; i++){
    cin >> a >> b;
    visited.assign(1001,0);
    visited[a] = 1;
    cout << dfs(a,b) << "\n";
  }
}
