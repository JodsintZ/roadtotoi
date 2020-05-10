#include <bits/stdc++.h>

#define long long long
#define pii pair<int,int>
#define tii tuple<long,int,int>
#define x first
#define y second

using namespace std;

const int N = 1e5+5;
const long M = 9e18;

int n, m, k ,t;
long dp[N][2], ans; //1 not use yet ,0 used
vector<pii> g[N];
priority_queue<tii, vector<tii>, greater<tii> > pq;

int main() { 
    fill_n(dp[0], N*2, M);
    scanf("%d %d %d %d", &n, &m, &k, &t);
    for(int i = 0, u, v, w; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    dp[1][1] = 0;
   // dp[1][0] = 0;
    pq.emplace(dp[1][1], 1, 1);
   // pq.emplace(dp[1][0], 1, 0);
    // node conditon
    while(!pq.empty()) {
        tii now = pq.top(); pq.pop();
        long dist = get<0>(now);
        int u = get<1>(now), c = get<2>(now);

        if(dist != dp[u][c]) continue;

        for(pii vw : g[u]) {
            int v = vw.x, w = vw.y;
            if(dist + w < dp[v][c]) {
                dp[v][c] = dist + w;
                pq.emplace(dp[v][c], v, c);
            }

            if(c && dist + k < dp[v][0]) {
                dp[v][0] = dist + k;
                pq.emplace(dist + k, v, 0);
            }
        
       }
    }
   // printf("%lld ", dp[n][1]);
    ans = min(dp[n][0], dp[n][1]);
    if(ans > t) printf("No Honey TT\n");
    else printf("Happy Winnie the Pooh :3\n%lld\n", ans);
    
    //printf("%lld", min(dp[n][0], dp[n][1]) );
    return 0;
}