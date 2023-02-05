#include<iostream>
#include<queue>
#include<vector>
using namespace std;

#define ripe 1
#define notRipe 0
#define nothing -1

int col,row;
int map[1001][1001];
queue<pair<int,int>> q;
int notRipeCnt=0;

int main(){
  cin >> col >> row;

  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      cin >> map[i][j];
      if(map[i][j]==ripe){
        q.push(make_pair(i,j));
      }
      else if(map[i][j]==notRipe){
        notRipeCnt++;
      }
    }
  }
  int day=0;
  int rippedCnt=0;
  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    if(x-1>=0 && map[x-1][y]==notRipe){
      map[x-1][y]=map[x][y]+1;
      q.push(make_pair(x-1,y));
      if(day<map[x-1][y]) day=map[x-1][y];
      rippedCnt++;
    }
    if(x+1<row && map[x+1][y]==notRipe){
      map[x+1][y]=map[x][y]+1;
      q.push(make_pair(x+1,y));
      if(day<map[x+1][y]) day=map[x+1][y];
      rippedCnt++;
    }
    if(y-1>=0 && map[x][y-1]==notRipe){
      map[x][y-1]=map[x][y]+1;
      q.push(make_pair(x,y-1));
      if(day<map[x][y-1]) day=map[x][y-1];
      rippedCnt++;
    }
    if(y+1<col && map[x][y+1]==notRipe){
      map[x][y+1]=map[x][y]+1;
      q.push(make_pair(x,y+1));
      if(day<map[x][y+1]) day=map[x][y+1];
      rippedCnt++;
    }

  }

  if(notRipeCnt==0) cout << 0;
  else if(rippedCnt==notRipeCnt) cout << day-1;
  else cout << -1;

}