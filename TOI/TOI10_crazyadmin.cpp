#include <bits/stdc++.h>

using namespace std;

int m, o, temp, sum, group, ans, mid, tans;
int a[105];

int main() {
    scanf("%d %d", &m, &o);
    for(int i = 0; i < o; i++) {
        scanf("%d", a + i);
        sum += a[i];
    }

    int l = 0, r = sum;
    while(l <= r) {
        mid = (l + r) >> 1;
        group = 1;
        temp = 0;
        for(int i = 0; i < o; i++) {
            if(a[i] > mid) {
                group = 2000;
                break;
            }
            if(temp + a[i] > mid) {
                group++;
                temp = 0;
            }
            temp += a[i];
        }
        if(group <= m) {
            r = mid - 1;
            ans = mid;
        }
        else l = mid + 1;
    }
    printf("%d", ans);
    return 0;
}
