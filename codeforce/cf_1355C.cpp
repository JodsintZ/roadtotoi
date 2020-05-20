#include <bits/stdc++.h>

using namespace std;

int a, b, c, d, mn, ans;

int main() {
    scanf("%d %d %d %d", &a, &b, &c, &d);
    mn = min(b-a, c-b);
    mn++;
    printf("%d ",mn);
    if(a + c > d) {
        mn -= (a + c - d);
        for(int i = 0; i <= (d-b); i++) {
            ans += mn;
            mn--;
        }
    }
    if(a + c < d) {
        int k = mn;
        for(int i = d; i >= c; i--) {
            ans += mn;
            mn--;
        }
        for(int i = a + c + 1; i <= d; i++) {
            ans += k;
            k--;
        }
    }
    if(a + c == d) {
        for(int i = d; i >= c; i--) {
            ans += mn;
            mn--;
        }
    }
    printf("%d\n", ans);
    return 0;
}