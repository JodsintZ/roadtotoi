#include <bits/stdc++.h>

using namespace std;

int n;
vector <int> v, a, b; //a first b second(swap)
//stack<int> b;
const int inf = 1e8 +5;

int main(){
    int ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < 2*n; i++) {
        int temp;
        scanf("%d", &temp);
        v.emplace_back(temp);
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++) {
        if ( i&0 == 0) {
            a.emplace_back(v[i]);
        }
        else {
            b.emplace_back(v[i]);
        }
    }
    //printf("%d",a.size());
   /* for(int i = 0; i < a.size(); i++) {
        cout << a[i];
        printf(" ");
    } */
    sort(b.begin(), b.end(), greater<int>());
    for(int i = 0 ; i < n; i++) {
        ans = ans + a[i] * b[i];
    }

    printf("%d",ans);
    return 0;
}
