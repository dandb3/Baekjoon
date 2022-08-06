#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
using ll = long long;

int dp[1000001];

int goDown(int cur);
void output(int cur);

int main() {
	FASTIO;
	memset(dp, -1, sizeof(dp));

	int N;
	cin >> N;

	cout << goDown(N) << '\n';
	output(N);

	return 0;
}

int goDown(int cur) {
	int& ret = dp[cur];
	if (ret != -1) {
		return ret;
	}
	if (cur == 1)
		return ret = 0;
	ret = goDown(cur - 1);
	if (cur % 3 == 0) {
		ret = min(ret, goDown(cur / 3));
	}
	if (cur % 2 == 0) {
		ret = min(ret, goDown(cur / 2));
	}
	ret++;
	return ret;
}

void output(int cur) {
	cout << cur;
	if (cur == 1) {
		cout << '\n';
		return;
	}
	else {
		cout << ' ';
	}

	if (cur % 3 == 0) {
		if (dp[cur] == 1 + dp[cur / 3]) {
			output(cur / 3);
			return;
		}
	}
	if (cur % 2 == 0) {
		if (dp[cur] == 1 + dp[cur / 2]) {
			output(cur / 2);
			return;
		}
	}
	output(cur - 1);
}