#include <bits/stdc++.h>

#define long long long
#define tii tuple<long, int, int, int>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 103;
const long M = 5e18;

int n, m, S, D, F, P[N];
long dp[N][N][2], ans; // station, fuel, ticket : 1 is not used 0 is used; 
vector<pii> g[N];
priority_queue<tii, vector<tii>, greater<tii> > pq;

int main() {
    fill_n(dp[0][0], N * N * 2, M);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &P[i]);
    scanf("%d %d %d", &S, &D, &F);
    scanf("%d", &m);
    for(int i = 0, a, b, w; i < m; i++) {
        scanf("%d %d %d", &a, &b, &w);
        g[a].emplace_back(b, w);
        g[b].emplace_back(a, w);
    }
    dp[S][0][1] = 0;
    pq.emplace(0, S, 0, 1); // station, fuel, ticket : 1 is not used 0 is used; 
    while(!pq.empty()) {
        tii now = pq.top(); pq.pop();
        long dist; int u, f, t; tie (dist, u, f, t) = now;

        if(dist != dp[u][f][t]) continue;
        //if ans then break
        if(u == D && f == F) {
            ans = dist;
            break;
        }
        //go next node
        for(auto vw : g[u]) {
            int v = vw.x, w = vw.y;
            if(f >= w && dp[]) {
                
            }
            pq.emplace(dp[v][f-w][t] = dist, v, f-w, t);
        }
        //use free ticket
        if(t) {
            pq.emplace(dp[u][F][0] = dist, u , F, 0);
        }
        //add 1 fuel
        if(f != F) {
           pq.emplace(dp[u][f+1][t] = dist+P[u], u, f+1, t); 
        }
        
    }

    printf("%lld", ans);
    return 0;
}