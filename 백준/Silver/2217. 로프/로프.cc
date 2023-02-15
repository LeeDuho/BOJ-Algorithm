#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n, m;
	int max_value;
	int tmp_value;
	vector <int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		v.push_back(m);
	}

	sort(v.begin(), v.end());

	max_value = 0;
	for (int i = 0; i < n; i++) {
		tmp_value = v[i] * (v.size() - i);
		if (max_value < tmp_value) {
			max_value = tmp_value;
		}
	}
	cout << max_value;
}

