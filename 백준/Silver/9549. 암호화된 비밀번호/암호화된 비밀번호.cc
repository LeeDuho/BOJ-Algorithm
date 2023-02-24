#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int t;
string origin, encrypted;
vector<int> alpha1(26, 0);
vector<int> alpha2(26, 0);

bool compare(){
  for(int i=0; i<26; i++){
    if(alpha1[i] != alpha2[i]){
      return false;
    }
  }
  return true;
}

int main(){
  cin >> t;
  for(int i=0 ; i<t; i++){
    cin >> encrypted >> origin;
    int encrypted_len = encrypted.length();
    int origin_len = origin.length();
    int diff = encrypted_len - origin_len;

    alpha1.assign(26, 0);
    alpha2.assign(26, 0);
    for(int i=0; i<origin.length(); i++){
      alpha1[origin[i] - 'a']++;
    }
    for(int i=0; i<origin.length(); i++){
      alpha2[encrypted[i] - 'a']++;
    }
    if(compare()){
      cout << "YES" << endl;
      continue;
    }
    
    bool flag = false;
    for(int j=0; j<diff; j++){
      alpha2[encrypted[j] - 'a']--;
      alpha2[encrypted[j+origin_len] - 'a']++;
      if(compare()){
        cout << "YES" << endl;
        flag = true;
        break;
      }
    }
    if(!flag){
      cout << "NO" << endl;
    }
  }
}