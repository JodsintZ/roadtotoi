#include <bits/stdc++.h>

#define long long long
#define tii tuple<long, int, int>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 2e3+5;
const int M = 1e4+5;
const int B = 5e5+5;

int n, p, u, e, l, en, ptr;
vector<pii> g[N], vl;
long dp[M][N], tem1, tem2, ans[B];
priority_queue<tii, vector<tii>, greater<tii>> Q;
vector<pair<long, long>> pre;

int main () {
    scanf("%d %d %d %d", &n, &p, &en, &e); // p start(no effect) en end
    for(int i = 0, a, b, c; i < e; i++) {
        scanf("%d %d %d", &a, &b, &c);
        g[a].emplace_back(b, c);
    }
    scanf("%d", &l);
    for(int i = 0, t; i < l; i++) {
        scanf("%d", &t);
        vl.emplace_back(t, i);
    }
    sort (vl.begin(), vl.end());
    fill_n(dp[0], M*N,1e18); // EDGE NODE
    //end of input
    dp[0][p] = 0;
    Q.emplace(dp[0][p], 0, p); // dp, edge visited , current node
    while(!Q.empty()) {
        tii now = Q.top();
        Q.pop();
        long dist = get<0>(now);
        int b = get<1>(now), u = get<2>(now);
        if(dist != dp[b][u] || b + 1 > e) continue;
        for(pii v : g[u]) {
            if(dist +  1ll*v.y < dp[b+1][v.x] ) {
                dp[b+1][v.x] = dist + 1ll* v.y;
                Q.emplace(dp[b+1][v.x], b+1, v.x);
            }
        }
    }
    for(int i = 0; i <= e; i++) {
        //printf("%lld ", dp[i][en]);
        if(dp[i][en] == 1e18) continue;
        if(pre.empty()) {
            pre.emplace_back(dp[i][en], i);
            continue;
        }
        else if(pre.back().x > dp[i][en]) pre.emplace_back(dp[i][en], i);

    }
    reverse(pre.begin(), pre.end());
    //for(int i = 0; i < pre.size(); i++) printf("%lld %d  ",pre[i].x, pre[i].y);
    // 12 4  14 3  29 2
    //check vl with pre
    int ptr = 0;
    for(int i = 0; i < l; i++) {
        while( (ptr != pre.size()) && (pre[ptr].x + (pre[ptr].y - 1) * vl[i].x > pre[ptr+1].x + (pre[ptr+1].y - 1) * vl[i].x) ) ptr++;
        ans[vl[i].y] = pre[ptr].x + (pre[ptr].y - 1) * vl[i].x;
    }
    for(int i = 0; i < l; i++) {
        printf("%lld ", ans[i]);
    }

    return 0;
}
/*

8 0 7 14
0 1 10
0 3 14
0 4 8
1 2 2
2 7 2
2 3 4
3 7 15
3 4 9
5 3 7
5 7 2
4 5 5
4 6 1
6 5 1
6 4 3
4
0 10 2 30

expected : 12 34 18 59
*/
