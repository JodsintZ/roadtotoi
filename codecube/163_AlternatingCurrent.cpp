#include <bits/stdc++.h>

#define long long long
using namespace std;

int n, k;
long int presum;
vector<int> v;

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i ++) {
        int temp;
        scanf("%d", &temp);
        v.emplace_back(temp);
        presum += temp;
    }
    presum /= n;
    sort(v.begin(),v.end());
  //  cout << presum << endl;
    int l = presum - (k/2);
    int r = presum + (k/2);
    if(k % 2 == 1 ) r++;
   // cout << l <<" " <<  r;
    long ansl=0 ,ans = 1e10+5 ,ansr=0;
    for(int i = 0; i <= k/2; i++) {
        for(int j = 0 ; v[j] < l; j++) {
            ansl += l - v[j];
        }
       // cout << ansl << endl;
        l++;
        for(int k = n-1; v[k] > r; k-- ) {
            ansr += v[k] - r;
        }
       // cout << ansr << endl;
        r++;
        long tt = max(ansr,ansl);
        ans = min(ans,tt );
        ansr = 0, ansl = 0;
    }
    cout << ans;
    return 0;
}
