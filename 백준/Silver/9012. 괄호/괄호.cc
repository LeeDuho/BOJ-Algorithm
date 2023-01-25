#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main(){
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    string s;
    cin >> s;
    stack<char> st;
    bool is_valid = true;
    for(int j=0; j<s.size(); j++){
      if(s[j] == '('){
        st.push(s[j]);
      }
      else{
        if(st.empty()){
          is_valid = false;
          break;
        }
        else{
          st.pop();
        }
      }
    }
    if(!st.empty()){
      is_valid = false;
    }
    if(is_valid){
      cout << "YES" << endl;
    }
    else{
      cout << "NO" << endl;
    }
  }

  return 0;
}