#include <bits/stdc++.h>


#define tii tuple <int,int,int>
using namespace std;

const int N = 1e3+5;
const int M = 2e9;

bool a[N][N];
int dp[N][N][4], n;
queue <tii> Q;
int main () {
    scanf("%d", &n);
   //memset (dp, M, sizeof(dp)); memset only for byte
   fill_n(dp[0][0],N * N * N,M);
    printf("%d   h", dp[2][2]);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%d", a[i] + j);
        }
    }
    dp[1][1][1] = 0;
    dp[1][1][2] = 0;
    Q.emplace(1,1,1);
    Q.emplace(1,1,2);

    while(!Q.empty()) {
        auto now = Q.front();
        Q.pop();
        int x = get<0>(now);
        int y = get<1>(now);
        int p = get<2>(now);
        int d = dp[x][y][p];

        if(x == n && y == n) return !printf("%d", d);

        if(p == 0) {
           // if(!a[x-1][y]) cout << p;
        }
    }
    return 0;
}
