#include <bits/stdc++.h>

#define long long long
#define pii pair<int, int>
#define tii tuple<int, int, int>
#define tiii tuple<int, int, int, int>
#define x first
#define y second

using namespace std;

const int N = 1e5+5;

long ans;
int n, m, k;
int ta, tb, tc; //temp
int par[N];
vector<int> ansa, ansb;
vector<tii> G, br, B;
vector<tiii> E, A;

int find(int x) { return x = par[x] == x ? x : find(par[x]);  }

int main() {
    for(int i = 1; i <= n; i++) par[i] = i;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= m; i++) {
        scanf("%d %d %d", &ta, &tb, &tc);
        E.emplace_back(tc, ta, tb, i);
    }
    sort(E.begin(), E.end() );
    for(int i = 1; i <= k; i++) {
        scanf("%d %d", &ta, &tb);
        br.emplace_back(tb, ta, i);
    }
    sort(br.begin(), br.end());
    for(auto ato : E) {
        int a, b, c, d;
        tie(c, a, b, d) = ato; // val u v index
        int pa = find(a), pb = find(b);
        if(pa != pb) {
            pa = find(pb);
            A.emplace_back(c, a, b, d);
        }
    }
    sort(A.begin(), A.end(), greater<tiii>());
    for(int i = 0; i < n; i++) {
        int a, b, c, d;
        tie(c, a, b, d) = A[i];
        int b1, b2, b3;
        if(A[i] > br[i]) {
            ans += br[i];
            ansb.emplace_back(c, a, b, d);
    
        }
    }



    return 0;
}

