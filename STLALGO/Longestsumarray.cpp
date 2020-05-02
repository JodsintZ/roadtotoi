#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

struct item {
    int ans, sum, pre, suf;
    item() {}
    item(int ans, int sum, int pre, int suf) : ans(ans), sum(sum), pre(pre), suf(suf) {}

    friend item operator+(const item &a, const item &b) {
        item ret;
        ret.sum = a.sum + b.sum;
        ret.pre = max(a.pre, a.sum + b.pre);
        ret.suf = max(b.suf, a.suf + b.sum);
        ret.ans = max({a.ans, b.ans, a.suf + b.pre});
        return ret;
    }
};

int n;
int A[N];

item solve(int l, int r) {
    if(l == r) return item(A[l], A[l], A[l], A[l]);
    int mid = (l + r) >> 1;
    return solve(l, mid) + solve(mid + 1, r);
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", A + i);
    item ret = solve(1, n);

    printf("%d\n", ret.ans);

    return 0;
}
