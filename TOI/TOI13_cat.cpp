#include <bits/stdc++.h>

#define long long long
#define tii tuple<int,int,int>
#define pii pair<int,int>
#define x first
#define y second

using namespace std;

const int N = 2e6+5;

int n, mc, ans, mid;
vector<int> v;

int main() {
    scanf("%d", &n);
    for(int i = 0, t; i < n; i++) {
        scanf("%d", &t);
        v.emplace_back(t);
        mc = max(t, mc);
    }
    long l = 0, r = mc;
    while(l <= r) {
        bool chk = true;
        mid = (l + r) >> 1;
       // ans = mid;
       // printf("%d ", mid);
        vector<int> c;
        for(int i = 0; i < n; i++) {
           // vector<int> c;
                if(v[i] > mid) {
                c.emplace_back(v[i]);
              //  printf("%d ", c.size());
                if(c.size() == 2) {
                    if(c[0] == c[1]) c.clear();
                    else {
                        chk = false;
                        break;
                    }
                }
            }
        }
        if(chk == false) l = mid + 1;
        else {
            r = mid - 1;
            ans = mid;
        }
    }
    printf("%d\n", ans);
    return 0;
}
