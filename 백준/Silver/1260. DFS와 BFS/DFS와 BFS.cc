#include<iostream>
#include<vector>

using namespace std;

int n,m,v;
vector<vector<int>> adj;

void DFS(int here, vector<bool> &visited){
  visited[here] = true;
  cout << here << " ";
  for(int i=1; i<=n; i++){
    if(adj[here][i] == 1 && !visited[i]){
      DFS(i, visited);
    }
  }
}

void BFS(int here, vector<bool> &visited){
  vector<int> q;
  q.push_back(here);
  visited[here] = true;
  while(!q.empty()){
    int cur = q.front();
    q.erase(q.begin());
    cout << cur << " ";
    for(int i=1; i<=n; i++){
      if(adj[cur][i] == 1 && !visited[i]){
        q.push_back(i);
        visited[i] = true;
      }
    }
  }
}

int main(){
  cin >> n >> m >> v;
  adj = vector<vector<int>>(n+1, vector<int>(n+1, 0));
  for(int i=0; i<m; i++){
    int a,b;
    cin >> a >> b;
    adj[a][b] = 1;
    adj[b][a] = 1;
  }

  vector<bool> visited(n+1, false);
  DFS(v, visited);
  cout << endl;
  visited = vector<bool>(n+1, false);
  BFS(v, visited);


  return 0;
}