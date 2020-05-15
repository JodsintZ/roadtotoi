#include <bits/stdc++.h>
#define long long long

using namespace std;

const int N = 2e5+5;

int n;
vector<int> vl, vr;
long ans;

int main() {
    scanf("%d", &n);
    for(int i = 1, t; i <= n; i++) {
        scanf("%d", &t);
        vl.emplace_back(i + t);
        vr.emplace_back(i - t);
    }
    sort(vl.begin(), vl.end());
    sort(vr.begin(), vr.end());
    for(int i = 0; i < n; i++) {
        int cr = lower_bound(vr.begin(), vr.end(), vl[i]) - vr.begin();
        int cru = upper_bound(vr.begin(), vr.end(), vl[i]) - vr.begin();
    //    printf("%d ", cr);
        if(vr[cr] == vl[i]) {
            ans += (cru - cr);
        }
        
    }
    printf("%lld\n", ans);

    return 0;
}