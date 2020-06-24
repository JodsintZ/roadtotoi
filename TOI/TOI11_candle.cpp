#include<bits/stdc++.h>

using namespace std;

const int N = 2005;
int A[N][N];
int n, m;
bool visited[N][N];
stack<pair<int, int> > q;
int R[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int RR[8] = {-1, 0, 1, -1, 1, 0, -1, 1};
int ans;
string s;

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < m; j++){
            A[i][j] = s[j] - '0';
        }
    }
    //for(int i = 0; i < n; i++){for(int j = 0; j < m; j++)printf("%d ", A[i][j]);puts("");}
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(!visited[i][j] && A[i][j] == 1)ans++;//printf("ans = %d ij %d %d\n", ans, i, j);
            if(A[i][j] == 1)q.emplace(i, j);
            while(!q.empty()){
                int x = q.top().first, y = q.top().second;
                q.pop();
                if(visited[x][y])continue;
                for(int k = 0; k < 8; k++){
                    if(A[x + R[k]][y + RR[k]] == 1 ) //&& x + R[k] >= 0 && x + R[k] < n && y + RR[k] >= 0 && y + RR[k] < m
                    q.emplace(x + R[k], y + RR[k]);
                }
                visited[x][y] = true;
            }
        }
    printf("%d", ans);
    return 0;
}
