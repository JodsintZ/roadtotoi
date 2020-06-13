#include <bits/stdc++.h>
#define tii tuple<int, int, int, int>

using namespace std;

const int N = 505;
const int M = 2e9;

int n, m, dp[N][N][1 << 3], ptr, ans;
int stx, sty, enx, eny;
char d[N][N];
string s[N];
queue<tii> q;

int main() {
    ans = M;
    ios_base::sync_with_stdio(0), cin.tie(0);;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        for(int j = 0; j < m; j++) {
            if(s[i][j] == 'S') {
                s[i][j] = '.';
                stx = i, sty = j;
            }
            if(s[i][j] == 'E') {
                s[i][j] = '.';
                enx = i, eny = j;
            }
        }
    }
    //jusst normal queue emplace ;
    //check bit (x) >> (0, 1, 2) & 1
    //emp bit (x) |= (1, 2, 4);
    for(int i = 0; i < i << 3; i++) {
        ans = min(ans, dp[enx][eny][i]);
    }
    printf("%d\n", ans);


    return 0;
}