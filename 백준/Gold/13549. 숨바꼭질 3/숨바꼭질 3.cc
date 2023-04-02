#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int visited[100001] = {0,};

void bfs(int subin, int dongsaeng) {
  //pair<int, int> first는 시간, second는 위치
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //pair의 first가 작은 순서대로 정렬
  pq.push(make_pair(0, subin));
  visited[subin] = 1;
  while(!pq.empty()){
    
    int time = pq.top().first;
    int location = pq.top().second;
    pq.pop();

    if(location == dongsaeng){
      cout << time << endl;
      return;
    }
    if(location*2 <= 100000 && visited[location*2] == 0){
      pq.push(make_pair(time, location*2));
      visited[location*2] = 1;
    }
    if(location-1 >= 0 && visited[location-1] == 0){
      pq.push(make_pair(time+1, location-1));
      visited[location-1] = 1;
    }
    if(location+1 <= 100000 && visited[location+1] == 0){
      pq.push(make_pair(time+1, location+1));
      visited[location+1] = 1;
    }
  }
}

int main(){

  int subin, dongsaeng;

  cin >> subin >> dongsaeng;

  bfs(subin, dongsaeng);

}