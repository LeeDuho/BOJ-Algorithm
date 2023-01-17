#include <iostream>
#include <algorithm>
using namespace std;

int arr[10][10];
int paper[6];
const int INF = 987654321;

bool color(int y, int x, int val, int size)
{
	int ny = y + size - 1;
	int nx = x + size - 1;
	if (ny < 0 || nx < 0 || ny >= 10 || nx >= 10)
		return false;
	for (int i = y; i < y + size; i++)
		for (int j = x; j < x + size; j++) 
			if (val == -1 && arr[i][j] == 0 ) 
				return false;

	for (int i = y; i < y + size; i++)
		for (int j = x; j < x + size; j++)
			arr[i][j] += val;
	return true;
}

int solve(int n) {
	int y = -1, x = -1;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (arr[i][j] == 1) {
				y = i, x = j;
				break;
			}
		}
		if (y != -1) break;
	}
	if (y == -1) return n;

	int ret = INF;
	for (int i = 5; i > 0; i--) {
		if (paper[i] != 0) {
			if (color(y, x, -1, i)) {
				paper[i]--;
				ret = min(ret, solve(n + 1));
				color(y, x, 1, i);
				paper[i]++;
			}
		}
	}
	return ret;
}

int main() {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			cin >> arr[i][j];
	for (int i = 1; i <= 5; i++) 
		paper[i] = 5;

	int ans = solve(0);
	if (ans == INF) cout << -1 << endl;
	else cout << ans << endl;
	
	return 0;
}