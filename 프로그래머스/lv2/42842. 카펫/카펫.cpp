#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    // vector<int> answer;
    // return answer;

    int garo = 2;
    int saero = 2;
    while(garo*2 <= brown - 2){
      
      saero = (brown - (garo*2))/2 + 2;
      if((garo-2)*(saero-2) == yellow) break;
      garo++;
    }
    if(garo < saero) swap(garo, saero);
    vector<int> answer = {garo, saero};
    return answer;

}