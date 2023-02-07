#include<iostream>

using namespace std;

int main(){

  int n;
  int num;
  cin >> n;
  int min = 987654321;
  int max = -987654321;
  for(int i=0; i<n; i++){
    cin >> num;
    if(num < min) 
      min = num;
    if(num > max) 
      max = num;
  }
  cout << min << " " << max;

}