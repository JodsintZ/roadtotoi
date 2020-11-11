#include <bits/stdc++.h>

using namespace std;

const int N = 4e5+5;
//somehow wrong
int n, m, pl, pr, ans, tmp, chng, ans1, val[N], ttl;
vector<int> va, v;

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        va.emplace_back(tmp);
    }
    for(int i = 0; i < m; i++) {
        scanf("%d", &tmp);
        v.emplace_back(tmp);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++) v.emplace_back(va[i]);

    for(auto a : v) cout << a << " "; cout << "\n";
    //initial
    pr = m+n-1; 
    ans1 += m * (m-1);
    ans1 /= 2;
    cout << "ans = " << ans1 << " " ;
    for(int i = 0; i < m; i++) {
        while(pr != m-1 && v[pr] < v[i]) {
            pr--;
        }
        if(pr == m-1) {
            break;
        }
        ttl += (pr - m + 1);
        val[i] = pr - m + 1;
        cout << val[i] << " ";
    }
    cout << " \n" << ttl << "   " ;
    
    tmp = ttl;
    for(int i = m-1; i >= 0; i--) {
        int x = n - val[i];
        tmp -= val[i];
        tmp += x;
        ans = max(ans, tmp);
        
    }
    printf("%d\n", ans + ttl);

    return 0;
}