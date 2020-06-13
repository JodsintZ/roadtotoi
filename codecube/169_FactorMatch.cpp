#include <bits/stdc++.h>
#define nl printf("\n")
#define long long long

using namespace std;

const int N = 1e6+5;
const int M = 2000002129;

int n, m, ans;
vector<int> p, A, B;
bool chkp[1005];
long mul[N], pata[N], patb[N];

void fillpat() {
    pata[1] = A[0];
    patb[1] = B[0];
    for(int i = 2; i <= n; i++) {
        pata[i] = mul[i-1] * A[i-1] + pata[i-1];
    }
    for(int i = 2; i <= m; i++) {
        patb[i] = mul[i-1] * B[i-1] + patb[i-1];
    }
}

void initg() {
    for(int i = 2; i < 1000; i++) {
        if(!chkp[i]) {
            p.emplace_back(i);
            for(int j = i; j < 1000; j += i) chkp[j] = true;
        }
    }
    mul[0] = 1;
    for(int i = 1; i < N; i++) {
        mul[i] =  M * mul[i-1];
    }
}

int ff(int x) {
    int ann = 1, t;
    for(auto ato : p) {
        if(x == 1) break;
        t = 1;
        while(x % ato == 0) {
            x /= ato;
            t++;
        }
        ann *= t;
    }
    return ann;
}

int bs(int x) {
    int l = x, r = min(n, x + m - 1), an = 0;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(pata[mid] - pata[x-1] == patb[mid - x + 1] * mul[x-1]) {
            l = mid + 1;
            an = mid - x + 1;
        }
        else r = mid - 1;
    }
    return an;
}

int main() {
    scanf("%d %d", &n, &m);
    initg();
   // for(auto ato : p) printf("%d ", ato);
    for(int i = 0, t; i < n; i++) {
        scanf("%d", &t);
        A.emplace_back(ff(t));
    }
    for(int i = 0, t; i < m; i++) {
        scanf("%d", &t);
        B.emplace_back(ff(t));
    }
    /*
    for(auto ato : A) printf("%d ", ato);
    nl;
    for(auto ato : B) printf("%d ", ato);
    nl;
    */
    fillpat();
    /*
    for(int i = 0; i <= n; i++) printf("%lld ", pata[i]);
    nl;
    for(int i = 0; i <= m; i++) printf("%lld ", patb[i]);
    */
    for(int i = 1; i <= n; i++) {
        ans = max (ans, bs(i));
    }
    printf("%d\n", ans);

    return 0;
}