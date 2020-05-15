#include <bits/stdc++.h>

using namespace std;

int q;

int main() {
    scanf("%d", &q);
    while(q--) {
        int a, b;
        scanf("%d %d", &a, &b);
        int ans = a;
        if(a % 2 == 1) {
           // printf("YES");
            for(int i = 2; i <= a; i++) {
                if (a % i == 0) {
                    ans += i;
                    break;
                }
            }
            b--;
            ans += (2 * b);
            printf("%d\n", ans);
            continue;
            b++;
            a *= 2;
            break;
            //in case overflow
        }
        else {
            ans += (2*b);
            printf("%d\n", ans);
        }
    }
    return 0;
}