#include <bits/stdc++.h>

#define long long long
#define pii pair<long,long>
#define x first
#define y second

using namespace std;

int n, m, ans;
long ta, tb, tc;
vector<pii> vg;

const int N = 1e5 + 5;

int main() {
    scanf("%d %d", &m, &n);
    for(int i = 0; i < m; i++) {
        scanf("%lld %lld", &ta, &tb);
        vg.emplace_back(ta, tb);
    }
    for(int i = 0; i < n; i++) {
        scanf("%lld %lld %lld", &ta, &tb, &tc);
        int cnt = 0;
        for(int j = 0; j < m; j++) {
            if( (vg[j].x-ta)*(vg[j].x-ta) + (vg[j].y - tb)*(vg[j].y - tb) <= tc*tc ) {
                cnt++;
            }
        }
        if (cnt != m && cnt != 0) ans++;  
    }
    printf("%d\n", ans);
    return 0;
}