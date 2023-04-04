#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N;

priority_queue<int, vector<int>, greater<int>> pq;


int main() {
  int num;
  cin >> N;
  for(int i=0; i<N; i++) {
    cin >> num;
    pq.push(num);    
  }
  int result = 0;
  int compare_a, compare_b;
  while(!pq.empty()) {
    compare_a = pq.top();
    pq.pop();
    if(pq.empty()) {
      
      break;
    }
    compare_b = pq.top();
    pq.pop();
    result += compare_a + compare_b;
    pq.push(compare_a + compare_b);
  }
  cout << result << endl;

}