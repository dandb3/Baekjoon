#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
using ll = long long;

int arr[500001], lastNum[500001];
vector<int> minNum;

int main() {
	FASTIO;

	int N, dep, des;
	cin >> N;

	arr[0] = 1000000;
	for (int i = 0; i < N; i++) {
		cin >> dep >> des;
		arr[dep] = des;
	}

	minNum.push_back(-1);
	for (int i = 1; i <= 500000; i++) {
		if (arr[i] == 0)
			continue;
		auto it = lower_bound(minNum.begin(), minNum.end(), arr[i]);
		if (it == minNum.end()) {
			minNum.push_back(arr[i]);
			lastNum[i] = minNum.size() - 1;
		}
		else {
			*it = arr[i];
			lastNum[i] = it - minNum.begin();
		}
	}

	vector<int> lis = { 0 }, result;
	int length = minNum.size() - 1;
	for (int i = 500000; i >= 1; i--) {
		if (length > 0 && lastNum[i] == length && arr[lis[lis.size() - 1]] > arr[i]) {
			lis.push_back(i);
			length--;
		}
		else if (arr[i] != 0) {
			result.push_back(i);
		}
	}

	cout << result.size() << '\n';
	for (int i = result.size() - 1; i >= 0; i--) {
		cout << result[i] << '\n';
	}

	return 0;
}