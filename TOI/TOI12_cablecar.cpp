#include <bits/stdc++.h>

#define tii tuple<int,int,int>
#define long long long;
#define pii pair<int,int>
#define x first
#define y second

using namespace std;

//too ez to compliment
//down below using mst with dp 
//another solution(haven't tried yet) is b-search all max ans and normal dfs
//can;t read old code lmao rip

const int N = 2505;
const int M = 2e9;

int n, m, st, en, p, dp[N], low, ans;
vector<tii> mst;
vector<tii> g ; //max spanning tree
int par[N];
queue<pii> q;

void dfs(int x, int pp) {
    par[x] = pp;
    for(auto ato : )
}

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
    for(auto now : mst) {
        int a = get<1>(now) , b = get<2>(now), c = get<0>(now);
        mm[a].emplace_back(b, c);
        mm[b].emplace_back(a, c);
    }

    for(int i = 0; i < N; i++) par[i] = i;//initial parent
    low = M;
    dfs(st, -1);

    ans = p / low;
    if(p%low) ans++;
    printf("%d\n", ans);



    return 0;
}
