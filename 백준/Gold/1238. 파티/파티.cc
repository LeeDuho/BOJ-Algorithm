#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<pair<int,int>> map[1001];
vector<int> dist;
vector<int> result;


void dijkstra(int start) {
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;  // greater를 쓰면 오름차순으로 정렬됨, pair는 first를 기준으로 정렬됨
  pq.push({0,start}); // dist, node
  dist[start] = 0;
  while(!pq.empty()) {
    int cur_dist = pq.top().first;
    int cur = pq.top().second;
    pq.pop();
    if(dist[cur] < cur_dist) continue;

    for(int i=0; i<map[cur].size(); i++) {
      int next = map[cur][i].first;
      int next_dist = map[cur][i].second + cur_dist;
      if(dist[next] > next_dist) {
        dist[next] = next_dist;
        pq.push({next_dist, next});
      }
    }
  }

}


int main() {
  int n,m,x;  // n개의 집, m개의 도로, x번 집에 파티
  cin >> n >> m >> x;
  for(int i=1; i<=m;i++) {
    int a,b,c;  // a에서 b로 가는데 c의 시간이 걸림
    cin >> a >> b >> c;
    map[a].push_back({b,c});
  }

  result.assign(n+1, 0);
  dist.assign(n+1, 987654321);
  dijkstra(x);
  for(int i=1; i<=n; i++) {
    result[i] += dist[i];
  }

  for(int i=1; i<=n; i++) {
    if(i == x) continue;
    dist.assign(n+1, 987654321);
    dijkstra(i);
    result[i] += dist[x];

  }

  int max = 0;
  for(int i=1; i<=n; i++) {
    if(max < result[i]) max = result[i];
  }

  cout << max << endl;
  


  return 0;
}