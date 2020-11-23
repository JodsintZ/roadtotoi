#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+5;
int sum, l, r, mid, a[N], n, k, ans;

int main () {
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", a + i);
        sum += a[i];
    }
  //  cout << sum << "\n";
    r = sum ;

    while(l <= r) {
        bool john = false;
        mid = (l + r + 1) >> 1;
      //  cout << mid;
        int cnt_k = 1, temp = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] > mid) john = true;
            else if(temp + a[i] > mid) {
                cnt_k++, temp = a[i];
            }
            else temp += a[i];

            if(cnt_k > k) john = true;

            if(john) break;
        }

        if(john) l = mid + 1;

        else {
            ans = mid;
            r = mid - 1;
        }

    }
    printf("%d", ans);
    return 0;
}
