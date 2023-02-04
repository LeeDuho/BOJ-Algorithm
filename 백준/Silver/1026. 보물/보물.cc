#include <iostream>
#include <algorithm>
using namespace std;

bool DESC(int a, int b) {
	return a > b;
}
int N;
int A[101];
int B[101];

int main() {
	
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}

	sort(A, A + N);	
	sort(B, B + N, DESC);
    
    int result = 0;
	for (int i = 0; i < N; i++) {
		result += (A[i] * B[i]);
	}

	cout << result;
    
}