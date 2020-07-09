#include <bits/stdc++.h>

#define pii pair<int,int>
#define tii tuple<int,int,int>
#define x first
#define y second
#define long long long

using namespace std;

const int N = 1e9 + 7;
const int M = 1e3+5;

//this one still wrong , to fix u need to do coordinate compression and use 
//some formula to calculate factorial in O(logN) and normal dp below that's it.

int dp[M][M];
int n, q, x, y;

int main() {
    scanf("%d %d", &n, &q);
   // printf("%d %d", n ,q);
    for(int i = 1; i < M; i++) {
        dp[1][i] = 1;
        dp[i][1] = 1;
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d %d", &x, &y);
      //  printf(" i \n");
        dp[x][y] = -1;
    }
    for(int j = 2; j <  M; j++) {
         for(int i = 2; i < M; i++) {
            if(dp[i][j] == -1) ;
            else if(dp[i-1][j] == -1 && dp[i][j-1] == -1) {
                dp[i][j] = 0;
            }
            else if(dp[i-1][j] == -1) {
                dp[i][j] =  dp[i][j-1];
            }
            else if(dp[i][j-1] == -1) {
                dp[i][j] =  dp[i-1][j];
            }
            else dp[i][j] =  dp[i-1][j] + dp[i][j-1];
            dp[i][j] %= N;
         }
    }
    //for(int i = 0; i <= )
   // printf("q = %d", q);
    for(int i = 1; i <= q; i++) {
        scanf("%d %d", &x, &y);
      //  printf(" ll \n");
        printf("%d \n",dp[x][y]);
    }
    return 0;
}
