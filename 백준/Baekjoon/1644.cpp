#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
using ll = long long;

bool notPrime[4000001];
vector<int> prime;

int main() {
	FASTIO;

	int N;
	cin >> N;
	if (N == 1) {
		cout << 0 << '\n';
		return 0;
	}
	if (N == 2) {
		cout << 1 << '\n';
		return 0;
	}
	for (int i = 2; i <= N; i++) {
		if (notPrime[i])
			continue;
		for (int j = i * 2; j <= N; j += i) {
			notPrime[j] = true;
		}
	}

	for (int i = 2; i <= N; i++) {
		if (!notPrime[i]) {
			prime.push_back(i);
		}
	}

	int startIdx = 0, endIdx = 0, cnt = 0;
	int sum = prime[0];
	bool flag = false;
	while (true) {
		while (sum < N) {
			endIdx++;
			if (endIdx >= prime.size()) {
				flag = true;
				break;
			}
			sum += prime[endIdx];
		}
		if (flag)
			break;
		if (sum == N)
			cnt++;
		while (sum >= N) {
			sum -= prime[startIdx++];
			if (startIdx > endIdx) {
				flag = true;
				break;
			}
			if (sum == N)
				cnt++;
		}
		if (flag)
			break;
	}

	cout << cnt << '\n';

	return 0;
}