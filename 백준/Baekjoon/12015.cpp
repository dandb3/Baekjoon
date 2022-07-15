#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
using ll = long long;

int seq[1000001];

int main() {
	FASTIO;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> seq[i];
	}

	vector<int> lis;
	lis.push_back(seq[0]);

	for (int i = 1; i < N; i++) {
		auto it = lower_bound(lis.begin(), lis.end(), seq[i]);
		if (it == lis.end())
			lis.push_back(seq[i]);
		else if (*it > seq[i])
			*it = seq[i];
	}

	cout << lis.size() << '\n';

	return 0;
}