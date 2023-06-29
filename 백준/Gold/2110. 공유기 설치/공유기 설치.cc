#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c;
vector<int> house;

bool isPossible(int dist) {
    int cnt = 1;
    int prev = house[0];
    for (int i = 1; i < n; i++) {
        if (house[i] - prev >= dist) {
            cnt++;
            prev = house[i];
        }
    }
    return cnt >= c;
}

int main() {
    cin >> n >> c; //n 집 개수, c 공유기 개수, 공유기 사이 거리 최대
    house.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> house[i];
    }
    sort(house.begin(), house.end());

    int left = 1; // 가능한 최소 거리
    int right = house[n - 1] - house[0]; // 가능한 최대 거리
    int answer = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (isPossible(mid)) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << answer << endl;

    return 0;
}
