#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> alpha(26, 0);

int main(){
  int n;
  cin >> n;
  string s;
  int cnt = 0;
  for(int i=0; i<n; i++){
    alpha.assign(26, 0);
    cin >> s;
    for(int j=0; j<s.size(); j++){
      if(alpha[s[j]-'a'] == 0){
        alpha[s[j]-'a']++;
      }else if(alpha[s[j]-'a'] == 1 && s[j-1] != s[j]){
        cnt++;
        break;
      }
    }
  }
  cout << n-cnt << endl;
  return 0;
}