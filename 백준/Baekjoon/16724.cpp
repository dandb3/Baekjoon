#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
using ll = long long;

int N, M;
char board[1001][1001];
int checked[1001][1001]; // 0이면 not-Visited Node, 1 이상이면 visited Node

bool addIfTrue(int curR, int curC, int cnt);

int main() {
	FASTIO;

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
		}
	}
	int result = 0;
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (checked[i][j] >= 1)
				continue;
			if (addIfTrue(i, j, ++cnt))
				result++;
		}
	}

	cout << result << '\n';

	return 0;
}

bool addIfTrue(int curR, int curC, int cnt) {
	checked[curR][curC] = cnt;
	switch (board[curR][curC]) {
	case 'U':
		if (curR == 1)
			return true;
		if (checked[curR - 1][curC] == cnt)
			return true;
		if (checked[curR - 1][curC] >= 1)
			return false;
		return addIfTrue(curR - 1, curC, cnt);
	case 'D':
		if (curR == N)
			return true;
		if (checked[curR + 1][curC] == cnt)
			return true;
		if (checked[curR + 1][curC] >= 1)
			return false;
		return addIfTrue(curR + 1, curC, cnt);
	case 'L':
		if (curC == 1)
			return true;
		if (checked[curR][curC - 1] == cnt)
			return true;
		if (checked[curR][curC - 1] >= 1)
			return false;
		return addIfTrue(curR, curC - 1, cnt);
	case 'R':
		if (curC == M)
			return true;
		if (checked[curR][curC + 1] == cnt)
			return true;
		if (checked[curR][curC + 1] >= 1)
			return false;
		return addIfTrue(curR, curC + 1, cnt);
	}
}