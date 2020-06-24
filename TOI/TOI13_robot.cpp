#include <bits/stdc++.h>

#define tii tuple<int, int, int>

using namespace std;

const int N = 2e3+5;
const int M = 2e9+5;

//just do normal dijkstra (bfs) 
//if found mark 2 thing ans1++ and ans2 += ddist * 2;
//too lazy to do this 

int n, m;
string s[N];
int vis[N][N], dp[N][N];
queue<tii> p;
int x[4] = {1, 0, 0, -1}, y[4] = {0, 1, 1, 0};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
fill_n(dp[0], N * N, M);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
      /*  for(int j = 0; j < m; j++) {
            if(s[i][j] == 'X') {
                p.emplace(0, i, j);
                dp[i][j] = 0;
            }
        } */
    }
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
        if(s[i][j] == 'X') {
                p.emplace(0, i, j);
                dp[i][j] = 0;
                vis[i][j] = true;
            }
    }
    while(!p.empty()) {
        tii now = p.front(); 
        p.pop();
        

    }
    
    
    return 0;
}