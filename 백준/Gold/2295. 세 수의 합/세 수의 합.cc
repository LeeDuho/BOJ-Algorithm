#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int U[1001];
int sum[1000001];


int main(){
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> U[i];
  }
  sort(U, U+N);
  int k=0;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      sum[k] = U[i] + U[j];
      k++;
    }
  }
  sort(sum, sum+k);
  
  for(int i=N-1; i>=0; i--){
    for(int j=N-1; j>=0; j--){
      int target = U[i] - U[j];
      if(binary_search(sum, sum+k, target)){  // binary search의 형식은 binary_search(시작주소, 끝주소, 찾을값)
        cout << U[i];
        return 0;
      }
    }
  }

  
}