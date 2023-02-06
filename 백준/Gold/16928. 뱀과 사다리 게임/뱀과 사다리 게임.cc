#include<iostream>
#include<queue>
#include<vector>


using namespace std;

int ladder, snake;
// vector<pair<int,int>> ladderMap;
// vector<pair<int,int>> snakeMap;
int mapping[101] = {0,};
queue<pair<int,int>> q;
int visited[101] = {0,};

int main(){
  cin >> ladder >> snake;
  for(int i=0;i<ladder;i++){
    int a,b;
    cin >> a >> b;
    // ladderMap.push_back(make_pair(a,b));
    mapping[a]=b;
  }
  for(int i=0;i<snake;i++){
    int a,b;
    cin >> a >> b;
    // snakeMap.push_back(make_pair(a,b));
    mapping[a]=b;
  }

  q.push(make_pair(1,0)); // now, cnt
  visited[1]=1;
  
  while(1){
    int now = q.front().first;
    int cnt = q.front().second;
    q.pop();

    if(now==100){
      cout << cnt;
      return 0;
    }

    for(int i=1;i<=6;i++){
      if(now+i<=100 && visited[now+i]==0){
        visited[now+i]=1;
        if(mapping[now+i]!=0){
          q.push(make_pair(mapping[now+i],cnt+1));
          visited[mapping[now+i]]=1;
        }
        else{
          q.push(make_pair(now+i,cnt+1));
        }
      }
    }
      
  }
}