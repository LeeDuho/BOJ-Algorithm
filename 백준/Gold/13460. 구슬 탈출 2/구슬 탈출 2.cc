#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// rx,ry ,bx,by를 저장하는 구조체
typedef struct balls {
  int rx,ry,bx,by;
}balls;

int main() {
  int n,m;
  cin >> n >> m;

  char map[11][11];
  int rx,ry,bx,by;

  for(int i= 0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin >> map[i][j];
      if(map[i][j] == 'R') {
        rx = i;
        ry = j;
      }
      else if(map[i][j] == 'B') {
        bx = i;
        by = j;
      }
    }
  }

  balls b;
  b.rx = rx;
  b.ry = ry;
  b.bx = bx;
  b.by = by;

  queue<pair<int,balls>> q;
  q.push(make_pair(0,b));

  int dx[4] = {0,0,-1,1};
  int dy[4] = {-1,1,0,0};

  int visited[11][11][11][11] = {0,};

  visited[rx][ry][bx][by] = 1;

  while(!q.empty()) {
    int cnt = q.front().first;
    balls cur_balls = q.front().second;
    q.pop();

    if(cnt >= 10) {
      cout << -1 << "\n";
      return 0;
    }

    for(int i=0; i<4; i++) {
      int nrx = cur_balls.rx;
      int nry = cur_balls.ry;
      int nbx = cur_balls.bx;
      int nby = cur_balls.by;
      while(1) {
        nrx += dx[i];
        nry += dy[i];
        if(map[nrx][nry] == '#') {
          nrx -= dx[i];
          nry -= dy[i];
          break;
        }
        if(map[nrx][nry] == 'O') {
          break;
        }

      }
      while(1) {
        nbx += dx[i];
        nby += dy[i];
        if(map[nbx][nby] == '#') {
          nbx -= dx[i];
          nby -= dy[i];
          break;
        }
        if(map[nbx][nby] == 'O') {
          break;
        }
      }
      if(map[nbx][nby] == 'O') {
        continue;
      }
      if(map[nrx][nry] == 'O') {
        cout << cnt+1 << "\n";
        return 0;
      }
      if(nrx == nbx && nry == nby) { 
        if(abs(nrx - cur_balls.rx) + abs(nry - cur_balls.ry) > abs(nbx - cur_balls.bx) + abs(nby - cur_balls.by)) {
          nrx -= dx[i];
          nry -= dy[i];
        }
        else {
          nbx -= dx[i];
          nby -= dy[i];
        }
      }
      if(visited[nrx][nry][nbx][nby] == 0) {
        visited[nrx][nry][nbx][nby] = 1;
        balls next_balls;
        next_balls.rx = nrx;
        next_balls.ry = nry;
        next_balls.bx = nbx;
        next_balls.by = nby;
        q.push(make_pair(cnt+1,next_balls));
      }

    }
  }
  cout << -1 << "\n";
}