#include <bits/stdc++.h>

using namespace std;

int n, m;
int dp[105][105][1005];

int main() {
	memset(dp, -1, sizeof dp);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) {
		int a, p2 = 0, p3 = 0;
		scanf("%d", &a);
		for( ; a % 2 == 0; a /= 2) p2++;
		for( ; a % 3 == 0; a /= 3) p3++;
		if(i == 1 && j == 1) dp[i][j][p3] = p2;
		else for(int k = p3; k <= 1000; k++) {
			if(dp[i-1][j][k-p3] != -1) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-p3] + p2);
			if(dp[i][j-1][k-p3] != -1) dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-p3] + p2);
		}
	}

	int ans = 0;
	for(int i = 0; i <= 1000; i++) ans = max(ans, min(i, dp[n][m][i]));
	printf("%d\n", ans);

	return 0;
}
/*
const int N = 103;
int a[N][N];
int dp[N][N][1200];

int main() {
    fill_n(dp[0], N*N*1200, -1);
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
           scanf("%d", &a[i][j]);
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int k = 0; k < 1200; k++) {
                int temp = a[i][j], t2 = 0, t3 = 0;
                while (a[i][j] % 2 == 0) {
                    a[i][j] /= 2;
                    t2++;
                }
                while (temp % 3 == 0) {
                    temp /= 3;
                    t3++;
                }
                if(i == 1 && j == 1 ) {
                    dp[i][j][t3] = t2;
                }
                else {
                    if (dp[i-1][j][k - t3] != -1) {
                        dp[i][j][k] = t2 + dp[i-1][j][t3];
                    }
                    else if (dp[i][j-1][k-t3] != -1) {
                        dp[i][j][k] = t2 + 1;
                    }
                }

            }
        }
    }
    return 0;
}*/

