#include <bits/stdc++.h>

#define tii tuple<int,int,int>
#define long long long;
#define pii pair<int,int>
#define x first
#define y second

using namespace std;

const int N = 2505;

int n, m, st, en, p, dp[N];
vector<pii> mst[N];
vector<tii> g ; //max spanning tree
int par[N];
queue<pii> q;

int find(int x) { return par[x] = par[x] == x ? x : find(par[x]); }

int main() {
    for(int i = 0; i < N; i++) par[i] = i;//initial parent
    scanf("%d %d", &n, &m);
    for(int i = 0, a, b, c; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        g.emplace_back(--c, a, b);
    }
    scanf("%d %d %d", &st, &en, &p);
    sort(g.begin(), g.end(), greater<tii>());

    for(tii now : g) {
        int a = get<1>(now) , b = get<2>(now), c = get<0>(now);
        int pa = find(a), pb = find(b);
        if(pa != pb) {
            par[pa] = pb;
            mst.emplace_back(a, b, c);
           // mst[a].emplace_back(b, c);
           // mst[b].emplace_back(a, c);
        }
        //cout << a << b << c;
    } // st en p
    //traversal through m s t




    return 0;
}
