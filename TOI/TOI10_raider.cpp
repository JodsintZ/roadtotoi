#include <bits/stdc++.h>
#define long long long 
#define tii tuple<int,int,int>

using namespace std;

const int N = 103;
const int M = 1e9;

//it bugged what the fuck

int n, m, A[N][N];
queue<tii> q;

int main() {
    scanf("%d %d", &m, &n);
    for(int i = 0; i < m; i++) { // row
        for(int j = 0; j < n; j++) { //column
            scanf("%d", &A[m][n]);  
        }
    }
    q.emplace(1, (m-1)/2 + 1, 0);
    q.emplace(1, (m-1)/2, 0);
    q.emplace(1, (m-1)/2 - 1, 0);

    while(!q.empty()) {
        tii now = q.front(); q.pop();
        int a = get<0>(now), b = get<1>(now), c = get<2>(now);
        if(b<0 || b >=m || c < 0 || c >=n) continue;
        if(b == (m-1)/2 && c == n-1) return !printf("%d\n", a);
        if(a % A[b][c] == 0) {
            ++a;
            if(b % 2) {
                q.emplace(a, m - 1, n);
                q.emplace(a, m - 1, n - 1);
                q.emplace(a, m , n - 1);
                q.emplace(a, m , n + 1);
                q.emplace(a, m + 1, n);
                q.emplace(a, m + 1, n - 1);
            }
            else {
                q.emplace(a, m - 1, n);
                q.emplace(a, m - 1, n + 1);
                q.emplace(a, m , n - 1);
                q.emplace(a, m , n + 1);
                q.emplace(a, m + 1, n);
                q.emplace(a, m + 1, n + 1);
            }
        }
    }
    printf("boi");
    return 0;
}