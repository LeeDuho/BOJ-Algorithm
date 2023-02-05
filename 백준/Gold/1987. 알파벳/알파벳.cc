#include<iostream>
#include<vector>

using namespace std;

int R, C;
vector<bool> alphabet;
vector<vector<char>> map;
int max_cnt = 0;

void horse_can_move(int x, int y, int cnt);

int main() {
	alphabet.assign(26, false);
	cin >> R >> C;
	map.assign(R, vector<char>(C));
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}
	alphabet[map[0][0] - 'A'] = true;
	horse_can_move(0, 0, 1);
	cout << max_cnt;
	return 0;
}

void horse_can_move(int x,int y,int cnt) {
	int move_x[] = { -1,0,1,0 };
	int move_y[] = { 0,1,0,-1 };
	if (cnt > max_cnt)
		max_cnt = cnt;
	for (int i = 0; i < 4; i++) {
		if (x + move_x[i] >= 0 && x + move_x[i] < R
			&& y + move_y[i] >= 0 && y + move_y[i] < C
			&& alphabet[map[x + move_x[i]][y + move_y[i]] - 'A'] == false) {
			alphabet[map[x + move_x[i]][y + move_y[i]] - 'A'] = true;
			horse_can_move(x + move_x[i], y + move_y[i], cnt +1);
			alphabet[map[x + move_x[i]][y + move_y[i]] - 'A'] = false;
		}
	}
}