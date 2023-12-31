#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<pair<int, int>> A(N); //숫자, index

	for (int i = 0; i < N; i++) {
		cin >> A[i].first;
		A[i].second = i;
	}

	sort(A.begin(), A.end());

	int MAX = 0;
	for (int i = 0; i < N; i++) {
		if (MAX < A[i].second - i){//정렬전 index - 정렬후 index
			MAX = A[i].second - i;
		} 
	}
	cout << MAX + 1;
}