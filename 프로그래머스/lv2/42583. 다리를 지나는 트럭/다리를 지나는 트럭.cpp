#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
  queue<int> bridge_q;
  int time = 0;
  int weight_sum = 0;

  int idx = 0;
  while(1) {
    time++;
    if(bridge_q.size() == bridge_length) {
      weight_sum -= bridge_q.front();
      bridge_q.pop();
    }
    if(weight_sum + truck_weights[idx] <= weight) {
      if(idx == truck_weights.size()-1) {
        time += bridge_length;
        break;
      }
      bridge_q.push(truck_weights[idx]);
      weight_sum += truck_weights[idx];
      idx++;
    } else {
      bridge_q.push(0);
    }
  }
  return time;
  

}