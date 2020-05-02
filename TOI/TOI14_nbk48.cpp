#include <bits/stdc++.h>

#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 1e5+5;
const int M = 2e9+9;

int n, q, pref, ptr, ans[N];
vector<pii> v, pre;

int main() {
    scanf("%d %d", &n, &q);
    for(int i = 1, t; i <= n; i++) {
        scanf("%d", &t);
        pref += t;
        if(v.empty()) {
            v.emplace_back(pref, i);
            continue;
        }
        while(pref <= v.back().x && !v.empty()) {
            v.pop_back();
        }
        v.emplace_back(pref, i);
    }
    v.emplace_back(INT_MAX, n+1);
   // for(int i = 0; i < v.size(); i++) printf("%d %d\n", v[i].x, v[i].y);
    for(int j = 0, t; j < q; j++) {
        scanf("%d", &t);
        pre.emplace_back(t, j);
    }
    sort(pre.begin(), pre.end());

    for(int i = 0; i < q; i++) {
        while(pre[i].x > v[ptr].x) ptr++;
        if(pre[i].x < v[ptr].x) ans[pre[i].y] = v[ptr].y - 1;
        else ans[pre[i].y] = v[ptr].y;
    }

    for(int i = 0; i < q; i++) {
        printf("%d \n", ans[i]);
    }

    return 0;
}
