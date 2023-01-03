#include<iostream>

using namespace std;

char image[64][64];

void quardTree(int x, int y, int n){
  if(n==1){
    cout << image[x][y];
    return;
  }
  bool isSame = true;
  for(int i=x;i<x+n;i++){
    for(int j=y;j<y+n;j++){
      if(image[x][y] != image[i][j]){
        isSame = false;
        break;
      }
    }
    if(!isSame) break;
  }
  if(isSame){
    cout << image[x][y];
  }else{
    cout << "(";
    quardTree(x,y,n/2);
    quardTree(x,y+n/2,n/2);
    quardTree(x+n/2,y,n/2);
    quardTree(x+n/2,y+n/2,n/2);
    cout << ")";
  }
}

int main(){
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin >> image[i][j];
    }
  }
  quardTree(0,0,n);
  return 0;
}