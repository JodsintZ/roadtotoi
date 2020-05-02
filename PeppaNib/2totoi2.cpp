#include <bits/stdc++.h>

#define iii tuple<int, int, int>
//Minimum Spanning Tree Kruskal;
using namespace std;

const int N = 1e5+5;

struct UnionFind {
    int par[N];

    void init() {
        for(int i = 1; i < N; i++) par[i] = i;
    }

    int find(int x) {
        return par[x] = x == par[x] ? x : find(par[x]);
    }

    void unite(int a, int b) {
        int pa = find(a), pb = find(b);
        par[pa] = pb;
    }
} dsu;

int n, m, ans; //n = number of vertices, m = number of edges
vector<iii> E;

int main() {
    dsu.init(); //Reset DSU

    scanf("%d %d", &n, &m);
    for(int i = 1, a, b, c; i <= m; i++) {
        scanf("%d %d %d", &a, &b, &c); //a, b = vertices, c = weight
        E.emplace_back(c, a, b);
    }
    sort(E.begin(), E.end()); //Sort edges

    for(iii e : E) { //Loop each edge
        int a, b, c;
        tie(c, a, b) = e;
        if(dsu.find(a) != dsu.find(b)) { //Not in the same components
            ans += c;
            dsu.unite(a, b);
        }
    }

    printf("%d\n", ans);

    return 0;
}
