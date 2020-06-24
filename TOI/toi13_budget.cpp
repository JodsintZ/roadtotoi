#include <bits/stdc++.h>

#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 1e4 + 5;
const int M = 2e9;

int n, m, st, en, z, dp[N], dp2[N];
pii ans = {-1, -1};
vector<pii> g[N];
priority_queue<pii, vector<pii>, greater<pii> > pq;

int main() {
    scanf("%d %d %d %d %d", &n, &m, &st, &en, &z);
    for(int i = 0, u, v, di; i < m; i++) {
        scanf("%d %d %d", &u, &v, &di);
        g[u].emplace_back(v, di);
        g[v].emplace_back(u, di);
    }

    fill_n(dp, N, M);
    dp[st] = 0;
    pq.emplace(dp[st], st);
    while(!pq.empty()) {
        pii now = pq.top();
        pq.pop();
        int dist = now.x, u = now.y;
        if(dist != dp[u]) continue;
        for(auto vw : g[u]) {
            int v = vw.x, w = vw.y;
            if(dist + w < dp[v]) {
                dp[v] = w + dist;
                pq.emplace(dp[v], v);
            }
        }
    }

    fill_n(dp2, N, M);
    dp2[en] = 0;
    pq.emplace(dp2[en], en);
    while(!pq.empty()) {
        pii now = pq.top();
        pq.pop();
        int dist = now.x, u = now.y;
        if(dist != dp2[u]) continue;
        for(auto vw : g[u]) {
            int v = vw.x, w = vw.y;
            if(dist + w < dp2[v]) {
                dp2[v] = w + dist;
                pq.emplace(dp2[v], v);
            }
        } 
    }

    int d2 = M, pos;
    for(int i = 0; i < n; i++) {
        if(dp2[i] < d2 && dp[i] <= z) {
            d2 = dp2[i];
            pos = i;
        }
    }
    printf("%d %d %d\n", pos, dp[pos], d2);
    return 0;
}