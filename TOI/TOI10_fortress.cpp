#include <bits/stdc++.h>

using namespace std;

int m, n, ans;

int main() {
    for(int i = 0; i < 20; i++) {
        scanf("%d %d", &m, &n);
        if(m / 2 < n ) {
            printf("0\n");
            continue;
        }
        n *= 4;
        ans = (n - m) / 2 + 1;
        if(ans < 0) ans = 0;
        printf("%d\n",ans);
    }
    return 0;
}
