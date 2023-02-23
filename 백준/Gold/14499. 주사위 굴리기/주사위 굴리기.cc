#include<iostream>
#include<vector>
using namespace std;

int n,m,x,y,k;
int map[21][21] = {0,};
int dice[7] = {0,};
int dir_x[4] = {0,0,-1,1};
int dir_y[4] = {1,-1,0,0};

void dice_move(int dir){
  if(dir == 0){
    int temp = dice[1];
    dice[1] = dice[4];
    dice[4] = dice[6];
    dice[6] = dice[3];
    dice[3] = temp;
  }
  else if(dir == 1){
    int temp = dice[1];
    dice[1] = dice[3];
    dice[3] = dice[6];
    dice[6] = dice[4];
    dice[4] = temp;
  }
  else if(dir == 2){
    int temp = dice[1];
    dice[1] = dice[5];
    dice[5] = dice[6];
    dice[6] = dice[2];
    dice[2] = temp;
  }
  else if(dir == 3){
    int temp = dice[1];
    dice[1] = dice[2];
    dice[2] = dice[6];
    dice[6] = dice[5];
    dice[5] = temp;
  }
}

int main(){

  cin >> n >> m >> x >> y >> k;
  for(int i=0; i<n ;i++){
    for(int j=0; j<m; j++){
      cin >> map[i][j];
    }
  }
  int dir;
  for(int i=0 ; i<k; i++){
    cin >> dir;
    dir -= 1;
    int nx = x + dir_x[dir];
    int ny = y + dir_y[dir];
    
    if(nx < 0 || nx >= n || ny < 0 || ny >= m){
      continue;
    }
    dice_move(dir);
    if(map[nx][ny] == 0){
      map[nx][ny] = dice[6];
    }
    else{
      dice[6] = map[nx][ny];
      map[nx][ny] = 0;
    }
    x = nx;
    y = ny;
    cout << dice[1] << endl; 


  }
  
}