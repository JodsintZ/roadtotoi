#include <bits/stdc++.h>

#define pii pair<int,int>
#define x first
#define y second

using namespace std;

vector<pii> v; // .x number .y position
int n;
vector<int> temp, ans;
//bool john;

int main () {
    scanf("%d", &n);
    for(int i = 0, t; i < n; i++) {
        scanf("%d", &t);
        v.emplace_back(t, i);
    }
    sort(v.begin(),v.end());
    ans.emplace_back(0);

    //base case start with 1 (pick the first one)

    for(int i = 0; i < n-1; i++) {
        if(v[i].y > v[i+1].y) {
            if(temp.size() > ans.size()) {
                ans.clear();
                for(int i = 0; i < temp.size(); i++) {
                    ans.emplace_back(temp[i]);
                }
            }
            temp.clear();
        }
        if((v[i].y < v[i+1].y) && (v[i].x  == (v[i+1].x - 1) ) ) {
           // john = true;
            if(temp.empty()) temp.emplace_back(v[i].y);
            temp.emplace_back(v[i+1].y);
        }

        if (i == n-2) {
            if(temp.size() > ans.size()) {
                ans.clear();
                for(int i = 0; i < temp.size(); i++) {
                    ans.emplace_back(temp[i]);
                }
                temp.clear();
            }
        }

    }
    //if(!john) return !printf("1\n1\n"); //base case
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++) printf("%d ", ans[i]+1);
    return 0;
}
