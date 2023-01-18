#include<iostream>
#include<algorithm>

using namespace std;

int histogram[100001];

long long find_max_square(int left, int right){
  if(left == right) return histogram[left];

  int mid = (left + right) / 2;
  long long ret = max(find_max_square(left,mid), find_max_square(mid+1, right));
  
  int le = mid, ri = mid+1;
  int h = min(histogram[le], histogram[ri]);
  while(left <= le && ri <= right){
    ret = max(ret, (long long)h * (ri - le + 1));
    if(ri < right && (le == left || histogram[le-1] < histogram[ri+1])){
      ri++;
      h = min(h, histogram[ri]);
    }
    else{
      le--;
      if(le < left) break;
      h = min(h, histogram[le]);
    }
  }
  return ret;
}

int main(){
  while(1){
    int n;
    
    cin >> n;
    if(n == 0) break;

    for(int i=0; i<n; i++){
      cin >> histogram[i];
    }

    cout << find_max_square(0, n-1) <<"\n";
  }

  return 0;
}