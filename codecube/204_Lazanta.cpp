#include <bits/stdc++.h>

#define iii tuple<int, int, int>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

/*
notmal bitmask dijkstra with 4 state ( remember it's 1 << 4)
- written by pep

*/
const int N = 5e4 + 5;
const char xmas[10] = "XMAS";

int get(char x) {
    for(int i = 0; i < 4; i++) if(x == xmas[i])
        return i;
    return -1;
}

int n, m, bit;
int dp[N][1 << 4];
char S[10], A[N];
vector<pii> g[N];

int main() {
    fill_n(dp[0], N * (1 << 4), 1e9);

    scanf("%d %d %s %s", &n, &m, S, A + 2);
    for(int i = 0; i < 4; i++) if(S[i] != '_')
        bit |= (1 << i);

    for(int i = 1, a, b, c; i <= m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }

    priority_queue<iii, vector<iii>, greater<iii> > Q;
    Q.emplace(dp[n][bit] = 0, n, bit); 
    while(!Q.empty()) {
        iii now = Q.top(); Q.pop();
        int dist, u, b; tie(dist, u, b) = now;

        if(dp[u][b] != dist) continue;

        int nex = b;
        if(get(A[u]) != -1) nex |= (1 << get(A[u]));
        for(pii v : g[u]) if(dist + v.y < dp[v.x][nex]) {
            dp[v.x][nex] = dist + v.y;
            Q.emplace(dp[v.x][nex], v.x, nex);
        }
    }

    printf("%d\n", dp[1][(1 << 4) - 1]);

    return 0;
}