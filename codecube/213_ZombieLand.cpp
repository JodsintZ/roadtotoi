#include <bits/stdc++.h>

#define long long long
#define pii pair<long,long>
#define x first
#define y second

using namespace std;

const long N = 2e5+5;
const long M = 2e16+5;

int n, m, s, e, q, t[N];
long dp[N], dp2[N], dp3[N];
vector<pii> g[N];
priority_queue<pii, vector<pii>, greater<pii> > p;

int main() {
    scanf("%d %d %d %d", &n, &m, &s, &e);
    for(int i = 1, u, v; i <= m; i++) {
        long w;
        scanf("%d %d %lld", &u, &v, &w);
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    fill_n(dp, N, M);
    fill_n(dp2, N, M);
    fill_n(dp3, N, M);

    dp[s] = 0;
    p.emplace(dp[s], s);
    while(!p.empty()) {
        pii now = p.top();
        p.pop();
        long u = now.y;
        long dist = now.x;
        if(dist != dp[u]) continue;
        for(pii v : g[u]) {
            if(dist + v.y < dp[v.x]) {
                dp[v.x] = dist + v.y;
                p.emplace(dp[v.x], v.x);
            }
        }
    }

    dp2[e] = 0;
    p.emplace(dp2[e], e);
    while(!p.empty()) {
        pii now = p.top();
        p.pop();
        long u = now.y;
        long dist = now.x;
        if(dist != dp2[u]) continue;
        for(pii v : g[u]) {
            if(dist + v.y < dp2[v.x]) {
                dp2[v.x] = dist + v.y;
                p.emplace(dp2[v.x], v.x);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if(dp[i] + dp2[i] == dp[e]) {
            dp3[i] = 0;
            p.emplace(dp3[i], i);
           // printf("%d ", i);
        }
    }

    while(!p.empty()) {
        pii now = p.top();
        p.pop();
        long u = now.y;
        long dist = now.x;
        if(dist != dp3[u]) continue;
        for(pii v : g[u]) {
            if(dist + v.y < dp3[v.x]) {
                dp3[v.x] = dist + v.y;
                p.emplace(dp3[v.x], v.x);
            }
        }
    }

    scanf("%d ", &q);
    for(int i = 1; i <= q; i++) {
        scanf("%d ", t + i);
    }
    for(int i = 1; i <= q; i++) {
        printf("%lld \n", dp3[t[i]]);
    }

    return 0;
}
