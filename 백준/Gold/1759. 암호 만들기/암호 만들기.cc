#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L,C;
vector<char> chars;
vector<char> selected;

void dfs(int idx, int cnt, int moeum_cnt, int jaum_cnt) {
  if(cnt == L) {
    if(moeum_cnt >= 1 && jaum_cnt >= 2) {
      for(int i=0; i<selected.size(); i++) {
        cout << selected[i];
      }
      cout << endl;
    }
    return;
  }
  if(idx == C) {
    return;
  }

  selected.push_back(chars[idx]);
  if(chars[idx] == 'a' || chars[idx] == 'e' || chars[idx] == 'i' || chars[idx] == 'o' || chars[idx] == 'u') {
    dfs(idx+1, cnt+1, moeum_cnt+1, jaum_cnt);
  } else {
    dfs(idx+1, cnt+1, moeum_cnt, jaum_cnt+1);
  }
  selected.pop_back();
  dfs(idx+1, cnt, moeum_cnt, jaum_cnt);
}

int main() {
  cin >> L >> C;
  chars.assign(C, 0);
  for(int i=0; i<C; i++) {
    cin >> chars[i];
  }

  sort(chars.begin(), chars.end());

  dfs(0, 0, 0, 0);

  return 0;
}