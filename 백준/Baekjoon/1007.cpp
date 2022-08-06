#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
using ll = long long;

int N;
bool checked[21];
ll result;
void combination(int cnt, int idx, vector<pair<int, int>>& point);

int main() {
	FASTIO;

	int test;
	cin >> test;
	cout << fixed;
	cout.precision(8);
	while (test--) {
		result = 1e18;
		cin >> N;
		vector<pair<int, int>> point(N + 1);
		for (int i = 1; i <= N; i++) {
			cin >> point[i].first >> point[i].second;
		}

		combination(0, 0, point);
		cout << sqrt(static_cast<double>(result)) << '\n';
	}

	return 0;
}

void combination(int cnt, int idx, vector<pair<int, int>>& point) {
	if (cnt == N / 2) {
		pair<ll, ll> ret;
		for (int i = 1; i <= N; i++) {
			if (checked[i]) {
				ret.first += point[i].first;
				ret.second += point[i].second;
			}
			else {
				ret.first -= point[i].first;
				ret.second -= point[i].second;
			}
		}
		result = min(ret.first * ret.first + ret.second * ret.second, result);
		return;
	}

	for (int i = idx + 1; i <= N; i++) {
		if (N - i + 1 < N / 2 - cnt)
			break;
		checked[i] = true;
		combination(cnt + 1, i, point);
		checked[i] = false;
	}
}