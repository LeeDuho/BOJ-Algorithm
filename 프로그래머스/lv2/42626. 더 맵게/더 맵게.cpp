#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
  //min heap
  priority_queue<int, vector<int>, greater<int>> pq;

  for(int i=0; i<scoville.size(); i++){
    pq.push(scoville[i]);
  }

  int count = 0;
  while(pq.empty() == false){
    int first = pq.top();
    pq.pop();
    if(first >= K) return count;
    if(pq.empty()) return -1;
    int second = pq.top();
    pq.pop();
    pq.push(first + second * 2);
    count++;
  }
}