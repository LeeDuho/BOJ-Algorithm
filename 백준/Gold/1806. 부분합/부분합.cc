#include <iostream>
#include <vector>

using namespace std;

int n, s;
vector<int> sum_v;

int main() {
  cin >> n >> s;
  sum_v.assign(n+1, 0);

  int tmp;
  for(int i=1; i<=n; i++) {
    cin >> tmp;
    sum_v[i] = sum_v[i-1] + tmp;
  }


  int ans = 987654321;
  int left = 0; 
  int right = 1;
  while(left <= right && right <= n) {
    if(sum_v[right] - sum_v[left] >= s) {
      if(ans > right - left) {
        ans = right - left;
      }
      left++;
    }
    else {
      right++;
    }
  }

  if(ans == 987654321) {
    cout << 0 << endl;
  }
  else {
    cout << ans << endl;
  }

  return 0;

}
