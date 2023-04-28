#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
  //pair<요청시점, 소요시간>에서 소요시간 기준으로 오름차순 정렬하려면 
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  
  vector<pair<int, int>> v;
  for(int i=0; i<jobs.size(); i++) {
    v.push_back(make_pair(jobs[i][0], jobs[i][1]));
  }
  sort(v.begin(), v.end());

  
  int time =0;
  int index = 0;
  int result =0;
  while(index < v.size() || !pq.empty()) {
    if(index < v.size() && time >= v[index].first) {
      pq.push(make_pair(v[index].second, v[index].first));
      index++;
      continue;
    }
    if(!pq.empty()) {
      time += pq.top().first;
      result += time - pq.top().second;
      pq.pop();
    }
    else {
      time = v[index].first;
    }
  }
  return result/jobs.size();
  


}
