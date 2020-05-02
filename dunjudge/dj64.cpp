#include <bits/stdc++.h>

using namespace std;

int main() {
    int A;
    scanf("%d", &A);
    int t = sqrt(A);
    if( t*t == A ) {
        printf("yes");
    }
    else printf("no");
    return 0;
}
