#include <bits/stdc++.h>

#define iii tuple<long, int, int, int>
#define long long long
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

int n, m, F, st, en;
long cost[105], dist[105][105][2];
vector<pii> g[105];
priority_queue<iii, vector<iii>, greater<iii> > Q;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%lld", cost+i);
    scanf("%d %d %d %d", &st, &en, &F, &m);
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    fill_n(dist[0][0], 105*105*2, 1e12);
    dist[st][0][0] = 0;
    Q.emplace(dist[st][0][0], st, 0, 0);
    while(!Q.empty()) {
        iii now = Q.top();
        Q.pop();
        int u = get<1>(now), f = get<2>(now), k = get<3>(now);
        if(get<0>(now) != dist[u][f][k]) continue; // don't forget this
        //Go to next node
        for(pii vw : g[u]) {
            int v = vw.x, w = vw.y;
            if(f >= w && dist[u][f][k] < dist[v][f-w][k]) {
                dist[v][f-w][k] = dist[u][f][k];
                Q.emplace(dist[v][f-w][k], v, f-w, k);
            }
        }
        //Use the free fuel
        if(k == 0 && dist[u][F][1] > dist[u][f][0]) {
            dist[u][F][1] = dist[u][f][0];
            Q.emplace(dist[u][F][1], u, F, 1);
        }
        //Decide to spend money to get 1 unit of fuel
        if(f < F && dist[u][f][k] + cost[u] < dist[u][f+1][k]) {
            dist[u][f+1][k] = dist[u][f][k] + cost[u];
            Q.emplace(dist[u][f+1][k], u, f+1, k);
        }
    }
    printf("%lld\n", dist[en][F][1]);
    return 0;
}
