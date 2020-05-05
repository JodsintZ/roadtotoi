#include <bits/stdc++.h>

#define long long long

using namespace std;

vector<int> v, d;
int n, k, ans;

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0, t; i < n; i++) {
        scanf("%d", &t);
        v.emplace_back(t);
    }
    for(int i = 1; i < n; i++) {
        d.emplace_back(v[i] - v[i-1] - 1);
    }
    sort(d.begin(), d.end(), greater<int>());
    ans = v.back() - v[0] + 1;
    for(int i = 0; i < k-1; i++) {
        ans -= d[i];
    }
    printf("%d\n", ans);
    return 0;
}