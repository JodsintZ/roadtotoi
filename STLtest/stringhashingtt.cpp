#include <bits/stdc++.h>
#define pii pair<int,int>
#define long long long 
#define x first
#define y second
using namespace std;

const int N = 1e6+5;
const int M = 98765431;

int size;
vector<pii> ans;
long n, pwr[N], hsh[N];
char ss[N];
map <long, pii> m;
//find most string occured in ss with the lenght of n
int main() {
    scanf("%d", &n);
    scanf(" %s",ss + 1);
    size = strlen(ss + 1);
    ///printf(" %c\n", ss[1]);
    printf("%d\n", size);
    pwr[0] = 1;
    for(int i = 1; i < N; i++) {
        pwr[i] = pwr[i-1] * M;
    }

    for(int i = 1; i <= size; i++) {
        hsh[i] = hsh[i-1] + ss[i] * pwr[i];
    }

    for(int i = 1; i <= size - n + 1; i++) {
        int cur = (hsh[i + n - 1] - hsh[i-1]) * pwr[size - n + 1 - i];
        m[cur].x++;
        m[cur].y = i;
    }

    for (auto v : m) {
        ans.emplace_back(v.y.x, v.y.y);
    }
    sort(ans.begin(), ans.end(), greater<pii>());
    printf("ans = %d\n", ans[0].x);
    for(int i = ans[0].y; i < ans[0].y + n; i++) {
        printf("%c",ss[i]);
    }
    
    return 0;
}