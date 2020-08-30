#include <bits/stdc++.h>
#define pii pair<int,int>
#define x first 
#define y second

using namespace std;

const int N = 1e5;

int t, n, r, d;
vector<pii> v;

int dist(pii a, pii b) {
    return a.x * b.x + a.y * b.y;
}

int dq(int a, int b) {
    if(a == b) return INT_MAX;
    if(a == b-1) return dist(v[a], v[b]);

    int mid = (l + r) >> 1, l = dq(a, mid), r = dq(mid + 1, b), bar = v[mid]. x;


}

void solve() {
    scanf("%d %d %d", &n, &r, &d);
    v.clear();
    for(int i = 0, t1, t2; i < n; i++) {
        scanf("%d %d", &t1, &t2);
        v.emplace_back(t1, t2);
    }
    sort(v.begin(), v.end());
    int ans = dq(0, n-1);
    if(ans - 2*r< d*d) printf("Y\n");
    else printf("N\n");
}

int main() {
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}