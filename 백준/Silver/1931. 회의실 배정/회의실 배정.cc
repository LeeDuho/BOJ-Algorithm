#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<pair<int, int>> v;

int max_num_of_meeting(){
  int num = 0;
  int last = -1;
  for(int i=0;i<n;i++){
    if(last <= v[i].first){
      last = v[i].second;
      num++;
    }
  }
  return num;
}

int main(){
  cin >> n;
  for(int i=0;i<n;i++){
    int a, b;
    cin >> a >> b;
    v.push_back(make_pair(a, b));
  }
  //v의 두번째 인자를 기준으로 오름차순 정렬
  sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b){
    if(a.second == b.second){
      return a.first < b.first;
    }
    return a.second < b.second;
  });

  cout << max_num_of_meeting();
  
  return 0;
}