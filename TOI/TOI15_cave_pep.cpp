#include <bits/stdc++.h>

#define long long long
#define iii tuple<long, long, long>
#define pii pair<long, long>
#define x first
#define y second

using namespace std;

const int N = 2e3+5;
const int M = 1e4+5;
const int K = 5e5+5;

int n, s, e, m, q;
long dp[N][M], ans[K];
vector<pii> g[N];

bool bad(pii a, pii b, pii c) {
    return (c.y - a.y) * (a.x - b.x) <= (b.y - a.y) * (a.x - c.x);
}

long f(pii l, long x) {
    return l.x * x + l.y;
}

int main() {
    fill_n(dp[0], N * M, 1e18);

    scanf("%d %d %d %d", &n, &s, &e, &m);
    for(int i = 1, a, b, c; i <= m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        g[a].emplace_back(b, c);
    }

    priority_queue<iii, vector<iii>, greater<iii> > Q;
    Q.emplace(dp[s][0] = 0, s, 0);
    while(!Q.empty()) {
        iii now = Q.top(); Q.pop();
        long dist, u, cnt; tie(dist, u, cnt) = now;

        if(dist != dp[u][cnt] || cnt + 1 > m) continue;
        for(pii v : g[u]) if(dist + v.y < dp[v.x][cnt + 1])
            Q.emplace(dp[v.x][cnt + 1] = dist + v.y, v.x, cnt + 1);
    }

    vector<pii> stk;
    for(int i = m; i; i--) {
        if(dp[e][i] == 1e18) continue;
        while(stk.size() > 1 && bad(stk[stk.size() - 2], stk.back(), pii(i - 1, dp[e][i])))
            stk.pop_back();
        stk.emplace_back(i - 1, dp[e][i]);
    }

    scanf("%d", &q);
    vector<pii> ask;
    for(int i = 0, a; i < q; i++) {
        scanf("%d", &a);
        ask.emplace_back(a, i);
    }
    sort(ask.begin(), ask.end());
    int ptr = 0;
    for(int i = 0; i < q; i++) {
        while(ptr < stk.size() - 1 && f(stk[ptr + 1], ask[i].x) <= f(stk[ptr], ask[i].x))
            ++ptr;
        ans[ask[i].y] = f(stk[ptr], ask[i].x);
    }
    for(int i = 0; i < q; i++) printf("%lld ", ans[i]);
    printf("\n");
    
    return 0;
}
