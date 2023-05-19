#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> visited;

bool compare(vector<int> a, vector<int> b) {
  return a[0] < b[0];
}

void dfs(int k, vector<vector<int>> dungeons, int& answer, int depth) {
  if(depth > answer) answer = depth;
  for(int i=0; i<dungeons.size(); i++) {
    if(!visited[i]) {
      if(k >= dungeons[i][0]) {
        visited[i] = true;
        dfs(k-dungeons[i][1], dungeons, answer, depth+1);
        visited[i] = false;
      }
    }
  }
}

int solution(int k, vector<vector<int>> dungeons) {
  int answer = 0;
  visited.resize(dungeons.size(), false);
  sort(dungeons.begin(), dungeons.end(), compare);
  dfs(k, dungeons, answer, 0);
  return answer;
}