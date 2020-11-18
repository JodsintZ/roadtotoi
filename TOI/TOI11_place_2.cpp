#include <bits/stdc++.h>

#define tii tuple<int, int, int>
#define long long long

using namespace std;

const int N = 2e5+5 ;

int n ,m, a, b, c, par[N];
long ans;

vector<int> A;
vector<tii> E;

int find (int x) { return x = par[x] == x ? x : find(par[x]); }

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < N; i++) par[i] = i;
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        E.emplace_back(c-1, a, b);
    } 
    sort(E.begin(), E.end(), greater<tii>());
    for(auto ato : E) {
        tie(c, a, b) = ato;
        int pa = find(a) , pb = find(b);
        if(pa != pb) {
            ans += c;
            A.emplace_back(c);
            par[pa] = pb;
        }
    }
    printf("%lld\n", ans);
    for(auto ato : A) cout << ato << " ";
    return 0;
}