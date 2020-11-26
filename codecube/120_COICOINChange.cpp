#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int M = 1e7;

int q, p, m, k, c[15], fin[15],finn[15], dp[N], pre[N]; // c < 10
int ansl, ans, ansr, temp;
int ransr, lansl;
map<int,int> v;

int main () {
    scanf("%d %d %d", &p, &m, &k);
    for(int i = 0; i < k; i++) {
        scanf("%d", &temp);
        c[i] = temp;
        v.emplace(temp,i);
    }
    for(int i = 0; i <= m; i++) {
        dp[i] = M;
    }
    dp[0] = 0;
    for(int j = 0; j < k; j++) { //for(int i = 1; i <= m ; i++) swap with lower loop
        for(int i = 1; i <= m ; i++) { //for(int j = 0; j < k; j++)
            if (i >= c[j]) { //dp[i] = min (dp[i], dp[i-c[j]] + 1);
                if(dp[i] > dp[i-c[j]] + 1) {
                    dp[i] = dp[i-c[j]] + 1;
                    pre[i] = c[j];
                }
            }
        }
    }

    ans = INT_MAX;
    for(int i = p,temp; i <= m; i++) {
        temp = dp[i] + dp[i-p];
        if(temp < ans) {
            ans = temp;
            ansr = dp[i];
            ansl = dp[i-p];
            ransr = i;
            lansl = i-p;
        }
    }
    printf("%d %d \n", ansr, ansl);
    //ansr input
    int i = ransr;
    while( i != 0) {
        fin[v[pre[i]]]++;
        i -= pre[i];
    }
    for(int i = 0; i < k; i++) {
        cout << fin[i] << " ";
    }
    cout <<endl;
    //return lansl
    int q = lansl;
    while( q != 0) {
        finn[v[pre[q]]]++;
        q -= pre[q];
    }
    for(int q = 0; q < k; q++) {
        cout << finn[q]<< " ";
    }
    return 0;
}
