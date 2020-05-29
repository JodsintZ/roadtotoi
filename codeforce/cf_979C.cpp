#include <bits/stdc++.h>
#define long long long
#define pii pair<int, int>

using namespace std;

const int N = 3e5+5;

int n, st, en, cnt, par[N], ien, ist, cnten, cntst;
vector<int> g[N], e;
long ans;
bool vis, john;

void dfs1(int u, int p) {
    for(auto l : g[u]) {
        if(l != p) {
            par[l] = u;
            dfs1(l, u);
        }
    }
}

void dfs2(int u, int p) {
    for(auto l : g[u]) {
        if(l != p) {
            cntst++;
            dfs2(l, u);
        }
    }
}

void dfs3(int u, int p) {
    for(auto l : g[u]) {
        if(l != p) {
            cnten++;
            dfs3(l, u);
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &st, &en);
    for(int i = 1; i <= n; i++) par[i] = i;
    for(int i = 1, a, b; i < n; i++) {
        scanf("%d %d", &a, &b);
        g[a].emplace_back(b); 
        g[b].emplace_back(a);
    }

    ans = n > 2 ? 1ll * n * (n-1) : 2;

    dfs1(st, st);
   /* for(int i = 1; i <= n; i++) {
        printf("%d ", par[i]);

    }
    printf("%lld\n\n", ans);
   */
    for(int i = en; i != st; i = par[i]) {
        e.emplace_back(i);
    }
    e.emplace_back(st);
   // dfs2(st);
  // for(auto itr : e) printf("%d ", itr);
   e.size() > 2 ? ien = e[1], ist = e[e.size()-2] : john = true;
   cnten++, cntst++;
   if(john) {
       dfs2(en, st);
       dfs3(st, en);
       ans -= 1ll * cnten * cntst;
   }
   else {
       dfs2(en, ien);
       dfs3(st, ist);
       ans -= 1ll * cnten * cntst;
   }
 //  printf("%d %d ", cnten, cntst);

    printf("%lld\n", ans);
    return 0;
}