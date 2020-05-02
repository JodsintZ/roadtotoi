#include <bits/stdc++.h>

using namespace std;

int N, A;
int x[51];
long long dp[51][5005];

int main() {
    scanf("%d %d", &N, &A);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &x[i]);
        x[i] -= A;
    }
    dp[0][2500] = 1;
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < 5000; j++){
            dp[i][j] = dp[i-1][j];
            if(j-x[i] >= 0) dp[i][j] += dp[i-1][j-x[i]];
        }
    }
    printf("%lld", dp[N][2500] - 1);

}
