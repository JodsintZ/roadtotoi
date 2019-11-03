#include <bits/stdc++.h>

using namespace std;

int a[10];
bool dup;

int main() {
    int n, k, p;
    scanf("%d %d", &n, &k);
    for (int l,i = n; i <= k; i++) {
        while ( l > 0) {
        int p = i;
        l = i;
        int temp = l % 10;
        l /= 10;
        a[temp]++;
        }
        dup = false;
        for(int j = 0 ;j < 10; j++) {
               if (a[j] > 1) dup = true;
            }               
        if (dup == true) {
            printf("%d", p);
        }
        fill(a,a+10,0);
        dup = false;
    }

    return 0;
}