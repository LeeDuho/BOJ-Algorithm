#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int V,E;
vector<pair<int, pair<int,int>>> edge;
int parent[10001];

int findParent(int x){
  if(parent[x] == x) return x;
  return findParent(parent[x]);
}
void unionParent(int a, int b){
  a = findParent(a);
  b = findParent(b);
  if(a < b) parent[b] = a;
  else parent[a] = b;
}

void kruskal(){
  sort(edge.begin(), edge.end(), less<pair<int, pair<int,int>>>());
  
  for(int i=1; i<=V; i++){
    parent[i] = i;
  }

  int cnt = 0;
  int sum = 0;
  for(int i=0; i<E; i++){
    int e1 = edge[i].second.first; //edge는 pair<int, pair<int,int>>로 구성되어있다.
    int e2 = edge[i].second.second;
    int cost = edge[i].first;
    if(findParent(e1) != findParent(e2)){
      unionParent(e1,e2);
      sum += cost;
      cnt++;
    }
    if(cnt == V-1) 
      break;
  }
  cout << sum;
}

int main(){
  cin >> V >> E;
  for(int i=0; i<E; i++){
    int a,b,c;
    cin >> a >> b >> c;
    edge.push_back(make_pair(c, make_pair(a,b)));
  }
  kruskal();
}

