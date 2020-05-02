#include <bits/stdc++.h>

#define long long long
#define tii tuple<long,int,int>

using namespace std;

const int N = 2e5+5;
const int M = 1e6+5;

int n, m, par[N];
priority_queue<tii> pq;
long ans;

int find(int x) { return par[x] = x == par[x] ? x : find(par[x]); }

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < N; i++) par[i] = i;
    for(int i = 0, b, a; i < m; i++) {
        long c;
        scanf("%d %d %lld", &a, &b, &c);
        pq.emplace(c-1, a, b);
    }
    while(!pq.empty()) {
        tii now = pq.top(); 
        pq.pop();
        long c = get<0>(now);
        int a = get<1>(now), b = get<2>(now);
        int pa = find(a), pb = find(b);
        if(pa != pb) {
            par[pa] = pb;
            ans += c;
        }
    }
    printf("%lld ", ans);
    return 0;
}
