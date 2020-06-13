#include <bits/stdc++.h>

using namespace std;

int n, k, ans;
vector<int> v;

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0, t; i < n; i++) {
        scanf("%d", &t);
        v.emplace_back(t);
    }
    sort(v.begin(), v.end(), greater<int>());
    for(int i = 0; i < n;) {
        ans += v[i];
        i += k;
    }
    for(auto ato : v) printf("%d ",ato);
    printf("%d\n", ans);
    return 0;
}