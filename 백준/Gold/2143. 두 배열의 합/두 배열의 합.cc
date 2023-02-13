#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int t;
int n,m;
int a[1001];
int b[1001];
vector<long long int> a_sum;
vector<long long int> b_sum;


int main(){
  cin >> t;

  cin >> n;
  for(int i=0; i<n; i++){
    cin >> a[i];
  }
  cin >> m;
  for(int i=0; i<m; i++){
    cin >> b[i];
  }

  long long int sum = 0;
  for(int i=0; i<n; i++){
    sum = 0;
    for(int j=i; j<n; j++){
      sum += a[j];
      a_sum.push_back(sum);
    }
  }
  for(int i=0; i<m; i++){
    sum = 0;
    for(int j=i; j<m; j++){
      sum += b[j];
      b_sum.push_back(sum);
    }
  }
  long long int cnt = 0;
  sort(b_sum.begin(), b_sum.end());
  for(int i=0 ;i<a_sum.size(); i++){
    long long int target = t - a_sum[i];
    auto upper = upper_bound(b_sum.begin(), b_sum.end(), target);
    auto lower = lower_bound(b_sum.begin(), b_sum.end(), target);
    cnt += (upper - lower);

  }
  cout << cnt;
}

long long int upper_bound(long long int target){
  int start = 0;
  int end = b_sum.size()-1;
  int mid;
  while(start < end){
    mid = (start + end) / 2;
    if(b_sum[mid] <= target){
      start = mid + 1;
    }
    else{
      end = mid;
    }
  }
  return end;
}

long long int lower_bound(long long int target){
  int start = 0;
  int end = b_sum.size()-1;
  int mid;
  while(start < end){
    mid = (start + end) / 2;
    if(b_sum[mid] < target){
      start = mid + 1;
    }
    else{
      end = mid;
    }
  }
  return end;
}