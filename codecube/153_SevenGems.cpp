#include <bits/stdc++.h>
#define tii tuple<int, int, int, int, int>

using namespace std;

const int M = 2e9;

string s[205];
int X[5] = {0, 0, 0, -1, 1}, Y[5] = {0, 1, -1, 0 , 0}; // up down l r
int n, m, dp[205][205][8][1<<7], ptr;
// still wrong cuz too lazy to edit the 1 << 7 but the concept is just right
// recommend to not put tii as 5 just as 4 and don't input dp in there cuz it isn't necessary
queue<tii> pq;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    fill_n(dp[0][0][0], 205 * 205 * 8 * 1<<7, M);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(s[i][j] == 'S') {
                s[i][j] = '.';
                dp[i][j][0][1] = 1;
                pq.emplace(1, i, j, 0, 1);
            }
            if(s[i][j] == 'G') {
                s[i][j] = 'A' + ptr;
                ptr++;
            }
        }
    }
    while(!pq.empty()) {
        tii now = pq.top();
        pq.pop();
        int dist = get<0>(now), x = get<1>(now), y = get<2>(now), e = get<3>(now), d = get<4>(now);
        if(e == 7) return! printf("%d\n", dist);
        if(dist != dp[x][y][e][d]) continue;
        for(int i = 0; i < 5; i++) {
            dist = get<0>(now), x = get<1>(now), y = get<2>(now), e = get<3>(now), d = get<4>(now);
            x += X[i], y += Y[i], dist++, d++;
            if(d == 7) d = 1;
            if(x < 0 || x >= m || y < 0 || y >= n) continue;
            if(s[x][y] == '#') continue;
            if(s[x][y] == '.' || s[x][y] - '0' <= d) {
                dp[x][y][e][d] = dist;
                pq.emplace(dist, x, y, e, d);
                continue;
            }
            if(s[x][y] >= 'A' && s[x][y] <= 'Z') {
                e |= pow(2, s[x][y]-'A');
                dp[x][y][e+1][d] = dist;
                pq.emplace(dist, x, y, e+1, d);
                continue;
            }
        }
    }
    printf("-1\n");
    return 0;
}