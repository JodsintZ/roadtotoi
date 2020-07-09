#include <bits/stdc++.h>

using namespace std;

const int N = 303;
int t, v[N][N], val[N][N], n, m;

//just make everygrid worst case possible like add until it can't (greedy)
//like this for example 3 x 4 
//  2 3 3 2
//  3 4 4 3
//  2 3 3 2

void solve() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        for(int j = 0, tmp; j < m; j++) {
            scanf("%d", &v[i][j]);
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if( (i == 0 and j == 0) or (i == 0 and j == m-1) or (i == n-1 and j == 0) or (i == n-1 and j == m-1) ) {
                val[i][j] = 2;
                continue;
            }
            if((i == 0 or i == n-1) and (j != 0 and j != m-1) ) {
                val[i][j] = 3;
                continue;
            }
            if( (j == 0 or j == m-1) and (i != 0 and i != n-1) ) {
                val[i][j] = 3;
                continue;
            }
            else val[i][j] = 4;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            //printf("%d ",val[i][j]);
            if(v[i][j] > val[i][j]) {
                printf("NO\n");
                return;
            }
        }
    }
    printf("YES\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ",val[i][j]);
        }
        printf("\n");
    }
}

int main() {
    //ios_base::sync_with_stdio(0), cin.tie(0);
    scanf("%d", &t);
    while(t--) {
        solve();
    }
    return 0;
}