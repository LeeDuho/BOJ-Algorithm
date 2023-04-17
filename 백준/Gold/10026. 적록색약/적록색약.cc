#include<iostream>
#include<string>
#include<vector>

using namespace std;

int n;
string image[101];
bool normal_visited[101][101] = {false,};
bool SM_visited[101][101] = {false,};


void normal_find_close_color(int x,int y) {
  normal_visited[x][y] = true;
  char color = image[x][y];
  if(x-1 >= 0 && normal_visited[x-1][y] == false && image[x-1][y] == color) {
    normal_find_close_color(x-1,y);
  }
  if(x+1 < n && normal_visited[x+1][y] == false && image[x+1][y] == color) {
    normal_find_close_color(x+1,y);
  }
  if(y-1 >= 0 && normal_visited[x][y-1] == false && image[x][y-1] == color) {
    normal_find_close_color(x,y-1);
  }
  if(y+1 < n && normal_visited[x][y+1] == false && image[x][y+1] == color) {
    normal_find_close_color(x,y+1);
  }
}

void SM_find_close_color(int x,int y) {
  SM_visited[x][y] = true;
  char color = image[x][y];
  if(color == 'B') {
    if(x-1 >= 0 && SM_visited[x-1][y] == false && image[x-1][y] == color) {
      SM_find_close_color(x-1,y);
    }
    if(x+1 < n && SM_visited[x+1][y] == false && image[x+1][y] == color) {
      SM_find_close_color(x+1,y);
    }
    if(y-1 >= 0 && SM_visited[x][y-1] == false && image[x][y-1] == color) {
      SM_find_close_color(x,y-1);
    }
    if(y+1 < n && SM_visited[x][y+1] == false && image[x][y+1] == color) {
      SM_find_close_color(x,y+1);
    }
  } else {
    if(x-1 >= 0 && SM_visited[x-1][y] == false && (image[x-1][y] != 'B')) {
      SM_find_close_color(x-1,y);
    }
    if(x+1 < n && SM_visited[x+1][y] == false && (image[x+1][y] != 'B')) {
      SM_find_close_color(x+1,y);
    }
    if(y-1 >= 0 && SM_visited[x][y-1] == false && (image[x][y-1] != 'B')) {
      SM_find_close_color(x,y-1);
    }
    if(y+1 < n && SM_visited[x][y+1] == false && (image[x][y+1] != 'B')) {
      SM_find_close_color(x,y+1);
    }

  }
}

int normal_count() {
  int count = 0;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(normal_visited[i][j] == false) {
        count++;
        normal_find_close_color(i,j);
      }
    }
  } 
  return count;
}

int SM_count() {
  int count = 0;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(SM_visited[i][j] == false) {
        count++;
        SM_find_close_color(i,j);
      }
    }
  } 
  return count;
}

int main() {
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> image[i];
  }
  cout << normal_count() << " " << SM_count();
}


