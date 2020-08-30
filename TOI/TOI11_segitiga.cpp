#include <bits/stdc++.h>

using namespace std;

const int N = 257;

int n, tc;
string s;
bool dp[N][N][3], vis[N][N][3];

int solve(int l,int r, int x) {
    if(vis[l][r][x]) return dp[l][r][x];
    vis[l][r][x] = true;

    if(l == r) {
        if(s[l] == x) dp[l][r][x] = true; 
        return dp[l][r][x];
    }

    for(int i = l + 1; i <= r; i++) {
        if(x == 0) {
            if(solve(l, i-1, 0) && solve(i, r, 2)) { 
                dp[l][r][x] = true;
                break; 
            }
        }
        if(x == 1) {
            if(solve(l, i-1, 0) && solve(i, r, 1)) { 
                dp[l][r][x] = true;
                break; 
            }
            if(solve(l, i-1, 1) && solve(i, r, 1)) { 
                dp[l][r][x] = true;
                break; 
            }
            if(solve(l, i-1, 1) && solve(i, r, 2)) { 
                dp[l][r][x] = true;
                break; 
            }
            if(solve(l, i-1, 2) && solve(i, r, 0)) { 
                dp[l][r][x] = true;
                break; 
            }
            if(solve(l, i-1, 2) && solve(i, r, 2)) { 
                dp[l][r][x] = true;
                break; 
            }
        }
        if(x == 2) {
            if(solve(l, i-1, 0) && solve(i, r, 0)) { 
                dp[l][r][x] = true;
                break; 
            }
            if(solve(l, i-1, 1) && solve(i, r, 0)) { 
                dp[l][r][x] = true;
                break; 
            }
            if(solve(l, i-1, 2) && solve(i, r, 1)) { 
                dp[l][r][x] = true;
                break; 
            }
        }
    }
    return dp[l][r][x];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    tc = 20;
    while(tc--) {
        s.clear();
        cin >> n >> s;
        for(int i = 0; i < n; i++) s[i] -= '0'; 
        fill_n(dp[0][0], N*N*3, false );
        fill_n(vis[0][0], N*N*3, false );
        if(solve(0, n-1, 0)) cout << "yes" << "\n";
        else cout << "no" << "\n";
    }

    return 0;
}