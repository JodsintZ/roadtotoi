
long modpow(long a, long b) {
    long ret = 1;
    for( ; b; b >>= 1) {
        if(b & 1) ret = ret * a % M;
        a = a * a % M;
    }
    return ret;
}
// basically, just change b into binary number
// then if the j th bit is 1, then you need to multiply a ^ (2^j)
// so I keep square a and see if the bit is 1 or not