#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<deque>

using namespace std;


int main() {
  string input;
  string bomb;

  // stack<char> s;
  deque<char> s;
  
  cin >> input >> bomb;

  for(int i=0; i<input.size(); i++) {
    s.push_back(input[i]);

    if(s.back() == bomb[bomb.size()-1]) {
      stack<char> tmp;
      bool flag = true;
      for(int j=bomb.size()-1; j>=0; j--) {
        if(s.empty() || (s.back() != bomb[j])) {
          flag = false;
          break;
        }
        tmp.push(s.back());
        s.pop_back();
      }
      if(!flag) {
        while(!tmp.empty()) {
          s.push_back(tmp.top());
          tmp.pop();
        }
      }
    }
  }

  if(s.empty()) {
    cout << "FRULA" ;
  }
  else {
    while(!s.empty()) {
      cout << s.front();
      s.pop_front();
    }
  }

  return 0;
}