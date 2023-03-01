#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
// #include<priority_queue>
using namespace std;

int n;
vector<vector<int>> input_v;


//pq의 저장은 vector<pair<int a, int b>>이다. a가 큰 순서대로 pq에 저장 
//priority_queue의 형식은 priority_queue<자료형, vector<자료형>, 비교연산자>이다.
//priority_queue에서 vector<pair<int, int>> 뒤의 int만 비교하려면
//greater 반대는 less

priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> n;
  input_v.assign(n, vector<int>(n, 0));
  for(int i=0; i<n-1; i++){
    for(int j=0; j<n; j++){
      cin >> input_v[j][i];
    }
  }
  for(int i=0; i<n; i++){
    cin >> input_v[i][n-1];
    pq.push(make_pair(input_v[i][n-1], i));
  }
  
  int a,b;
  for(int i=0; i<n; i++){
    a = pq.top().first;
    b = pq.top().second;
    pq.pop();
    input_v[b].pop_back();
    int temp = input_v[b].size();
    pq.push(make_pair(input_v[b][temp-1], b));
  }
  cout << a << endl;


}


