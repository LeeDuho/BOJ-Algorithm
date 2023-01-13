#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    string s1, s2;
    cin >> s1 >> s2;

    // dp[i][j] = s1[0...i]와 s2[0...j]의 LCS
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    
    for(int i = 1; i <= s1.size(); i++){
        for(int j = 1; j <= s2.size(); j++){
            if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[s1.size()][s2.size()] << endl;
  return 0;
}