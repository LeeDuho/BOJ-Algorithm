#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int n;
vector<int> tower;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> n;

  tower.assign(n, 0);
  stack<pair<int,int>> s;
  for(int i=0; i<n; i++) {
    cin >> tower[i];
    while(!s.empty() && s.top().first < tower[i]) {
      s.pop();
    }
    if(s.empty()) {
      cout << 0 << " ";
    }
    else {
      cout << s.top().second + 1 << " ";
    }
    s.push(make_pair(tower[i], i));
  }

  return 0;
}