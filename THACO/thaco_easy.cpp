#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
//still can;t show the output if A.size() != B.size()
string A, B, C;
bool jhn;
int s, i, e, temp, val;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> A >> B;
    for(int i = 0; i < A.size(); i++) A[i] -= '0';
    for(int i = 0; i < B.size(); i++) B[i] -= '0';
    if(B.size() <= A.size()) swap(A,B);
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    //cout << A << " " << B;
    s = min(A.size(), B.size());
    e = max(A.size(), B.size());
    jhn = true; i = 0;
    while(jhn) {
        if(i == s) {
            break;
        }
        jhn = false;
        val = A[i] + B[i] + temp;
        temp = 0;
        while(val >= 10) val -= 10, jhn = true, temp++;
        if(i < s-1) jhn = true;
        i++;
        C += val + '0';
    }
    if(s == e) {
        if(temp) C += temp + '0';
        reverse(C.begin(), C.end()); 
        cout << C;
        return 0;
    }

    while(i < e) {
        if( i == s) C += B[i] + '0' + temp;
        else {
            C += B[i] + '0';
        }
    }
    reverse(C.begin(), C.end()); 
    cout << C;
    return 0;
}