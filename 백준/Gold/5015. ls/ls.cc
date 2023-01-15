#include<iostream>
#include<string>
#include<vector>
#include<cstring>

using namespace std;

string P;
int N;
string S;
int dp[101][101];

bool wildcard(int Ppos,int Spos){
  int& ret = dp[Ppos][Spos];
  if(ret != -1){
    return ret;
  }
  while(Ppos < P.size() && Spos < S.size() && P[Ppos] == S[Spos]){
    Ppos++;
    Spos++;
  }
  if(Ppos == P.size()){
    if(Spos == S.size()){
      return ret = true;
    }
    else{
      return ret = false;
    }
  }
  if(P[Ppos] == '*'){
    for(int skip=0; Spos+skip <= S.size(); skip++){
      if(wildcard(Ppos+1, Spos+skip)){
        return ret = true;
      }
    }
  }
  return ret = false;
}

int main(){
  cin >> P >> N;
  for(int i=0; i<N; i++){
    memset(dp, -1, sizeof(dp));
    cin >> S;
    if(wildcard(0, 0)){
      cout << S << endl;
    }
  }

  return 0;
}