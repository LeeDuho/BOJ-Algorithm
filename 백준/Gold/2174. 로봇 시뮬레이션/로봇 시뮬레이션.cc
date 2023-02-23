#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int a,b;
int n,m;
int map[101][101] = {0,};

typedef struct robot{
  int x;
  int y;
  char dir;
}robot;

int dir_x[4] = {0,1,0,-1};
int dir_y[4] = {1,0,-1,0};

vector<robot> robots;

int main(){
  cin >> a >> b;
  cin >> n >> m;
  
  int robot_x, robot_y;
  char robot_dir;
  for(int i=0; i<n; i++){
    cin >> robot_x >> robot_y >> robot_dir;
    robots.push_back({robot_x, robot_y, robot_dir});
    map[robot_x][robot_y] = i+1;
  }

  char order;
  int order_robot, order_repeat;
  for(int i=0; i<m; i++){
    cin >> order_robot >> order >> order_repeat;
    if(order == 'F'){
      int dir;
      if(robots[order_robot-1].dir == 'N'){
        dir = 0;
      }else if(robots[order_robot-1].dir == 'E'){
        dir = 1;
      }else if(robots[order_robot-1].dir == 'S'){
        dir = 2;
      }else if(robots[order_robot-1].dir == 'W'){
        dir = 3;
      }
      
      map[robots[order_robot-1].x][robots[order_robot-1].y] = 0;
      int x = robots[order_robot-1].x;
      int y = robots[order_robot-1].y;

      for(int j=0; j<order_repeat; j++){
        x += dir_x[dir];
        y += dir_y[dir];
        if(x < 1 || x > a || y < 1 || y > b){
          cout << "Robot " << order_robot << " crashes into the wall";
          return 0;
        }
        if(map[x][y] != 0){
          cout << "Robot " << order_robot << " crashes into robot " << map[x][y];
          return 0;
        }
      }
      robots[order_robot-1].x = x;
      robots[order_robot-1].y = y;
      map[x][y] = order_robot;
    }
    else if(order == 'L'){
      for(int j=0; j<order_repeat; j++){
        if(robots[order_robot-1].dir == 'N'){
          robots[order_robot-1].dir = 'W';
        }else if(robots[order_robot-1].dir == 'E'){
          robots[order_robot-1].dir = 'N';
        }else if(robots[order_robot-1].dir == 'S'){
          robots[order_robot-1].dir = 'E';
        }else if(robots[order_robot-1].dir == 'W'){
          robots[order_robot-1].dir = 'S';
        }
      }
    }
    else if(order == 'R'){
      for(int j=0; j<order_repeat; j++){
        if(robots[order_robot-1].dir == 'N'){
          robots[order_robot-1].dir = 'E';
        }else if(robots[order_robot-1].dir == 'E'){
          robots[order_robot-1].dir = 'S';
        }else if(robots[order_robot-1].dir == 'S'){
          robots[order_robot-1].dir = 'W';
        }else if(robots[order_robot-1].dir == 'W'){
          robots[order_robot-1].dir = 'N';
        }
      }
    }

  }
  cout << "OK";

}