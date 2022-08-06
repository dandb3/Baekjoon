#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
using ll = long long;

int arr[1000001];
int lastNum[1000001];
vector<int> minNum;

int main() {
	FASTIO;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	minNum.push_back(arr[0]);
	lastNum[0] = 1;
	for (int i = 1; i < N; i++) {
		auto it = lower_bound(minNum.begin(), minNum.end(), arr[i]);
		if (it == minNum.end()) {
			minNum.push_back(arr[i]);
			lastNum[i] = minNum.size();
		}
		else {
			*it = arr[i];
			lastNum[i] = it - minNum.begin() + 1;
		}
	}
	vector<int> result = { 2000000000 };
	int length = minNum.size();
	for (int i = N - 1; i >= 0; i--) {
		if (lastNum[i] == length && result[result.size() - 1] > arr[i]) {
			result.push_back(arr[i]);
			length--;
		}
		if (length == 0)
			break;
	}
	cout << result.size() - 1 << '\n';
	for (int i = result.size() - 1; i > 1; i--) {
		cout << result[i] << ' ';
	}
	cout << result[1] << '\n';
	return 0;
}