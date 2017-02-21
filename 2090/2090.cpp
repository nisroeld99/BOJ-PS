#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <tuple>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstdlib>
#include <stack>

using namespace std;

#define INF 1987654321
#define MAX 100010
#define MOD 1000000007

int main() {
	int n;
	cin >> n;
	
	int dp[2][3] = { 0, };
	int ret[2][3] = { 0, };
	for (int i = 0; i < n; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		ret[0][0] = max(dp[0][0], dp[0][1]) + a;
		ret[0][1] = max(dp[0][0], max(dp[0][1], dp[0][2])) + b;
		ret[0][2] = max(dp[0][1], dp[0][2]) + c;

		ret[1][0] = min(dp[1][0], dp[1][1]) + a;
		ret[1][1] = min(dp[1][0], min(dp[1][1], dp[1][2])) + b;
		ret[1][2] = min(dp[1][1], dp[1][2]) + c;

		dp[0][0] = ret[0][0];
		dp[0][1] = ret[0][1];
		dp[0][2] = ret[0][2];
		dp[1][0] = ret[1][0];
		dp[1][1] = ret[1][1];
		dp[1][2] = ret[1][2];
	}
	cout << max(dp[0][0], max(dp[0][1], dp[0][2])) << " ";
	cout << min(dp[1][0], min(dp[1][1], dp[1][2])) << endl;

	return 0;
}
