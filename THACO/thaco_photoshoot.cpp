#include <bits/stdc++.h>

#define long long long
#define pii pair<int,int>
#define x first
#define y second
#define tii tuple<int,int,int>

using namespace std;

const int N = 505;

int n, k, a[N], nbl[N], nbr[N], ta, tb, ans[N];
int pr, pl, prog; // prog = progress

int main() {
    scanf("%d %d", &n, &k);
    pr = n, pl = 1, prog = 1;
    for(int i = 0; i < k; i++) {
        scanf("%d %d", &ta, &tb);
        int cnt, c = tb-ta+1;
        for(int j = ta; j <= tb; j++) {
            if(cnt != c-1) nbr[j]++;
            if(!cnt) nbl[j]++;
            a[j]++;
            cnt++;
        }
    }
    /*
    for(int i = k; i > 0; i--) {
        for(int j = 1; j <= n; j++) {
            if(i == a[j]) {
                if(prog%2) {
                    ans[j] = pl;
                    pl++;
                }
                else {
                    ans[j] = pr;
                    pr--;
                }
                prog++;
            }
        }
    }
    
    for(int i = 1+250, tmp; i <= n+250; i++) {
        if(i > n) tmp = i%n+1;
        else tmp = i;
        if(tmp%2) {
            ans[tmp] = pr;
            pr--;
        }
        else {
            ans[tmp] = pl;
            pl++;
        }
    }
*/
    for(int i = 1; i <= n;i ++) {
        int v = i*2-1;
        if(v > n) {
            if(n%2) {
                v-=n;
            }
            else 
            v -= (n-1);
            ans[v] = i;
        }
        else ans[v] = i;
    }

    for(int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }

    return 0;
}