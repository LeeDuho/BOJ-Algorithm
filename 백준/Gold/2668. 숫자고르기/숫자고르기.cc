#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int> arr;
vector<bool> visited;
vector<int> ans;

void dfs(int start, int now) {
  if(visited[arr[now]] == false) {
    if(start == arr[now]) {
      ans.push_back(start);
      return ;
    }
    visited[arr[now]] = true;

    dfs(start, arr[now]);
  }

}

int main() {
  cin >> n;
  arr.assign(n+1, 0);
  visited.assign(n+1, false);
  for(int i=1; i<=n; i++) {
    cin >> arr[i];
  }
  for(int i=1; i<=n; i++) {
    visited.assign(n+1, false);
    dfs(i, i);
  }
  vector<int> result;
  for(int i=0; i<ans.size(); i++) {
    if(result.size() == 0) {
      result.push_back(ans[i]);
    } else {
      bool flag = false;
      for(int j=0; j<result.size(); j++) {
        if(result[j] == ans[i]) {
          flag = true;
          break;
        }
      }
      if(flag == false) {
        result.push_back(ans[i]);
      }
    }
  }

  //result 오름차순 정렬
  sort(result.begin(), result.end());

  cout << result.size() << endl;
  for(int i=0; i<result.size(); i++) {
    cout << result[i] << endl;
  }




  return 0;
}