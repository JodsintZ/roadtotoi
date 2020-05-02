#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

int n, A[N];

void merge_sort(int l, int r) {
    if(l == r) return;
    int mid = (l + r) >> 1;
    merge_sort(l, mid), merge_sort(mid + 1, r);

    int p1 = l, p2 = mid + 1;
    vector<int> vec;
    while(p1 <= mid && p2 <= r) {
        if(A[p1] < A[p2]) vec.emplace_back(A[p1++]);
        else vec.emplace_back(A[p2++]);
    }
    while(p1 <= mid) vec.emplace_back(A[p1++]);
    while(p2 <= r) vec.emplace_back(A[p2++]);
    for(int i = l; i <= r; i++) A[i] = vec[i - l];
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", A + i);
    merge_sort(1, n);
    for(int i = 1; i <= n; i++) printf("%d ", A[i]);
    printf("\n");
    return 0;
}
