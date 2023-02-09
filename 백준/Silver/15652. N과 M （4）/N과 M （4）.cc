#include<iostream>
#include<vector>

using namespace std;

int n,m;

void dfs(int selected_num, vector<int> selected_v, int selected_before){
  if(selected_num == m){
    for(int i=0; i< m; i++){
      cout << selected_v[i] << " ";
    }
    cout << "\n";
    return;
  }
  for(int i=selected_before; i<=n; i++){
    selected_v.push_back(i);
    dfs(selected_num + 1, selected_v, i);
    selected_v.pop_back();
  }
  return;
}

int main(){
  cin >> n >> m;
  dfs(0, vector<int>(), 1);
}