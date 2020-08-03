#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

int a[N];


void mergesort(int l, int r) {
    if(l == r) return;
    int mid = l + r >> 1;
    mergesort(l, mid), mergesort(mid + 1, r);

    vector <int> vec;
    int p1 = l, p2 = mid + 1;
    while(p1 <= mid && p2 <= r) {
        if(a[p1] < a[p2]) vec.emplace_back(a[p1++]);
        else vec.emplace_back(a[p2++]);
    }
    while(p1 <= mid) { vec.emplace_back(a[p1++]); }
    while(p2 <= r) { vec.emplace_back(a[p2++]); }
    for(int i = l; i <= r; i++) a[i] = vec[i-l];

}

int main() {
    int n;
    scanf("%d",&n);

    for(int i = 1; i <= n; ++i) {
         scanf("%d", &a[i]);
    }
       // cout << i;


    for(int i = 1; i <= n; i++)
        printf("%d ", a[i]);

    mergesort(1,n);

    for(int i = 1; i <= n; i++)
        printf("%d ", a[i]);

    return 0;
}
