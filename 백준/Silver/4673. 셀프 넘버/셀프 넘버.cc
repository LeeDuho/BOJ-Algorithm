#include<iostream>

using namespace std;

int nonSelfNum[10001];

int main(){
  for(int i=1; i<=10000; i++){
    int num = i;
    int sum = i;
    while(num != 0){
      sum += num % 10;
      num /= 10;
    }
    if(sum <= 10000){
      nonSelfNum[sum] = 1;
    }
  }
  for(int i=1; i<=10000; i++){
    if(nonSelfNum[i] == 0){
      cout << i << endl;
    }
  }

  return 0;
}