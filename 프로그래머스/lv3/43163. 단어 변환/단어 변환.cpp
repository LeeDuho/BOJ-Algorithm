#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<bool> visited;

int bfs(string begin, string target, vector<string> words) {
  queue<pair<string, int>> q;
  q.push(make_pair(begin, 0));
  while(!q.empty()) {
    string word = q.front().first;
    int depth = q.front().second;
    q.pop();
    if(word == target) return depth;
    for(int i=0; i<words.size(); i++) {
      if(!visited[i]) {
        int diff = 0;
        for(int j=0; j<word.size(); j++) {
          if(word[j] != words[i][j]) diff++;
        }
        if(diff == 1) {
          visited[i] = true;
          q.push(make_pair(words[i], depth+1));
        }
      }
    }
  }
  return 0;
}


int solution(string begin, string target, vector<string> words) {
  visited.resize(words.size(), false);
  int answer = bfs(begin, target, words);
  return answer;
  
}