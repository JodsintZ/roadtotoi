#include <bits/stdc++.h>

#define long long long
#define pii pair<int,int>
#define x first
#define y second

using namespace std;

const int N = 5e5 + 5;

int n, m, tmp, cntg, cntr;
vector<int> g[N], G[N], R[N];
string order = "";
bool jhn, jhng;
// g first r second
int main() {   
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        string S;
        cin >> S;
        for(int j = 0; j < m; j++) {
            g[i].emplace_back(S[j]);
            G[i].emplace_back(0);
            R[i].emplace_back(0);
        }
    }
    for(int j = 0; j < m; j++) {
        int i = 0;
        if(!j) {
            if(g[i][j] == 'G') G[i][j] = 1;
            else R[i][j] = 1;
        } 
        else {
            if(g[i][j] == 'G') G[i][j]++;
            else R[i][j]++;
            G[i][j] += G[i][j-1];
            R[i][j] += R[i][j-1];
        }
    }
    for(int i = 1; i < n; i++) {
        int j = 0;
        if(g[i][j] == 'G') G[i][j]++;
        else R[i][j]++;
        G[i][j] += G[i-1][j];
        R[i][j] += R[i-1][j];
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            G[i][j] = max(G[i-1][j], G[i][j-1]);
            R[i][j] = max(R[i-1][j], R[i][j-1]);
            if(g[i][j] == 'G') G[i][j]++;
            else R[i][j]++;
        }
    }
    int ans;
    ans = min(G[n-1][m-1], R[n-1][m-1]);
    if(G[n-1][m-1] > R[n-1][m-1]) jhng = true;
    if(ans > (m + n - 1) / 2) ans = (m+n-1) / 2, jhn = true;
    printf("%d\n", ans << 1);
    //printf(" Y R Y R Y\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ", R[i][j]);
        }
        printf("\n");
    }
    
    //initial ( the last one )
    if(ans) {
        if(g[n-1][m-1] == 'G') cntg++; 
        else cntr++; 
        order = order + "Y";
    }
    if(!ans) order += "N";
    int i = n-1, j = m-1;
    
    if(jhng) {
        while(i || j) {
            if(G[i-1][j] < G[i][j-1]) {
                order+="D";
                if(cntg != ans) {
                    cntg++;
                    order = order + "Y";
                }
                else order = order + "N";
                i--;
            }
            else if(G[i-1][j] > G[i][j-1]) {
                order+="R";
                if(cntg != ans) {
                    cntg++;
                    order = order + "Y";
                }
                else order = order +  "N";
                j--;
            }

            // we go B
            if(G[i-1][j] == G[i][j-1]) {
                if(R[i-1][j] < R[i][j-1]) {
                    order = order +  "D";
                    if(cntr != ans) {
                        cntr++;
                       order = order +  "Y";
                    }
                    else order = order +  "N";
                    i--;
                }
                else if(R[i-1][j] > R[i][j-1]) {
                    order = order + "R";
                    if(cntr != ans) {
                        cntr++;
                        order = order +  "Y";
                    }
                    else order = order + "N";
                    j--;
                }
            }
           
        }
    }
    for(int i = order.size()-1; i>=0; i--) {
        cout << order[i] << " ";
    }
    
    return 0;
}