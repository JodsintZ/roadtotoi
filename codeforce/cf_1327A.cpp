#include <bits/stdc++.h>

#define long long long

using namespace std;

int q;

int main () {
    scanf("%d", &q);
    while(q--) {
        long n, m;
      //  cout << q;
      scanf("%lld %lld", &m,&n);
      if(((m%2 == 0 && n%2==0)||(m%2==1 && n%2==1)) && (m >= n*n)) printf("YES\n");
      else printf("NO\n");
    }
    return 0;
}
