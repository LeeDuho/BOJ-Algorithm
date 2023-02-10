#include <iostream>
#include <vector>
 
using namespace std;
 
int main(void){
    int n, x, y;

    cin >> n;
    vector<pair<int, int> > v; 
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        v.push_back(pair<int, int>(x, y));
    }
     int ans;
    for(int j = 0; j < n; j++){
        ans = 1;
        for(int k = 0; k < n; k++){
            if(v[j].first < v[k].first && v[j].second < v[k].second){
                ans++;
            }
        }
        cout << ans << endl;
    }
}
 
 