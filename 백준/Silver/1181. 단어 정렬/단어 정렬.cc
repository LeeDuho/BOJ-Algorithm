#include<iostream>
#include<string>
#include<algorithm>
#include<vector>


using namespace std;

int main(){
  int n;
  cin >> n;
  vector<string> v;
  for(int i=0; i<n; i++){
    string s;
    cin >> s;
    v.push_back(s);
  }
  //길이가 짧은 것부터, 길이가 같으면 사전 순으로, 같은 단어는 한 번만 출력
  sort(v.begin(), v.end(), [](string a, string b){
    if(a.length() == b.length()){
      return a < b;
    }
    return a.length() < b.length();
  });
  v.erase(unique(v.begin(), v.end()), v.end());
  for(auto i : v){
    cout << i << endl;
  }
  

  return 0;
}