#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
  sort(people.begin(), people.end());
  int answer = 0;
  int i = 0, j = people.size()-1;
  while(i <= j) {
    if(people[i] + people[j] <= limit) {
      i++;
      j--;
    }
    else j--;
    answer++;
  }
  return answer;
}