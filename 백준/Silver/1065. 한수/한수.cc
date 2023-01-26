#include<iostream>

using namespace std;

int hansu(int n){
  int count = 0;
  for(int i=1; i<=n; i++){
    if(i < 100){
      count++;
    }
    else{
      int a = i / 100;
      int b = (i % 100) / 10;
      int c = i % 10;
      if((a - b) == (b - c)){
        count++;
      }
    }
  }
  return count;
}

int main(){
  int n;
  cin >> n;
  cout << hansu(n);

  return 0;
}