#include <bits/stdc++.h>
#define long long long
#define pii pair<int, int>
#define x first
#define y second
#define tii tuple<int,int,int>

using namespace std;

const int N = 1e5+5;
const int M = 2e9+5;

int n, m, s, en, ttl, mx, ans;
int dp[N][2], par[N]; // 0 not used 1 used
vector<pii> g[N];
vector<int> e;
priority_queue<tii, vector<tii>, greater<tii> > p;

int main() {
    scanf("%d %d %d %d", &n, &m, &s, &en);
    for(int i = 0; i < N; i++) par[i] = i;
    fill_n(dp[0], N*2, M);
    for(int i = 0, a, b, c; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
        ttl += c;
    }
    dp[s][0] = 0;
    p.emplace(dp[s][0], s, 0);
    while(!p.empty()) {
        tii now = p.top();
        int dist = get<0>(now), u = get<1>(now), gf = get<2>(now);
        p.pop();
        if(dp[u][gf] != dist) continue;
        for(auto vw : g[u]) {
            int v = vw.x, w = vw.y;
            if(gf) {
                if(dist + w < dp[v][gf]) {
                    dp[v][gf] = dist + w;
                    p.emplace(dp[v][gf], v, gf);
                }

            }
            else {
                if(dist + w < dp[v][gf]) {
                    dp[v][gf] = dist + w;
                    p.emplace(dp[v][gf], v, gf);
                }
                if(dist < dp[v][1]) {
                    dp[v][1] = dist;
                    p.emplace(dp[v][1], v, 1);
                }
            }
            
        }

    }
    /*
    ans = M;
    for(int i = 0; i < 1005; i++) {
        if(dp[en][i] != M) ans = min(ans, dp[en][i] - i);
    } 
    if(dp[en][1] != M ) ans
    printf("%d\n", ttl - ans);
    */
    printf("%d\n", ttl - dp[en][1]);
    /*
    for(int i = en; i != s; i = par[i]) {
        e.emplace_back(dp[i]);
    }
    e.emplace_back(0);
  //  for(auto b : e) cout << b << " ";
    ttl -= dp[en];
    for(int i = 0; i < e.size()-1; i++) {
        mx = max(mx, e[i] - e[i+1]);
    }

    //for(int i = 0; i < n; i++) printf("%d ", par[i]);
   // printf("%d\n", ttl + mx);

    */
    return 0;
}