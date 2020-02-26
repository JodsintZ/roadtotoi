#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
bool a[N];
int ans;

int main(){
    int n, b;
    scanf("%d %d", &n, &b);
    int k = sqrt(n);
    for(int i = 2; i <= k; i ++) {
        if (a[i] == false) {
            int temp = i;
            while(temp <= n) {
                a[temp] = true;
                temp += i;
            }
            ans++;
        }
    }

    for(int i = 2; i <= n; i++){
        if ( a[i] == false) ans++;
    }
    ans = ans - b;
    if(ans <= 0) ans = 0;
    printf("%d", ans);
    return 0;
}
