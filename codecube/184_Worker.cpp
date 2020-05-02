#include <bits/stdc++.h>
#define tii tuple<int, int, int>
#define long long long

using namespace std; //mst

const int N = 1e3+5;

int n, b, a[N], par[N]; // boss is node 0
priority_queue < tii, vector<tii>, greater<tii>> g, mst;
long ans;

int find(int x) { return par[x] = par[x] == x ? x : find(par[x]); }

void read_input() {
    scanf("%d", &n);
    for(int i = 0; i < N; i++) par[i] = i;
    for(int i = 1, t; i <= n; i++) {
        scanf("%d ", &t);
        g.emplace(t, 0, i);
    }
    for(int i = 1, t; i <= n; i++) {
        scanf("%d ", &a[i]);
    }
}

int main ( ) {
    read_input();
    for(int i = 1; i < n ; i++) {
        for(int j = i+1; j <= n; j++) {
            //printf("%d %d\n", i, j);
            g.emplace(a[j] + a[i], i, j);
        }
    }
    while(!g.empty()) {
        tii now = g.top();
        g.pop();
        int a = get<2>(now), b = get<1>(now), c = get<0>(now);
        int pa = find(a), pb = find(b);
        if(pa != pb) { //merge
            ans += c;
            par[pa] = pb;
        }
    }
    printf("%lld \n", ans);
    return 0;
}
