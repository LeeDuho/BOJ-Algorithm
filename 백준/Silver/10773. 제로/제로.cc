#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

int K;
stack<int> s;

int main(){
  cin >> K;
  int input;
  for(int i=0; i<K;i++){
    cin >> input;
    if(input !=0){
      // 0이 아니면 스택에 넣는다.
      s.push(input);
    }
    else if(input == 0){
      // 0이면 스택에서 빼낸다.
      s.pop();
    }
  }
  int sum = 0;
  while(!s.empty()){
    sum += s.top();
    s.pop();
  }
  cout << sum << "\n";
  return 0;
}