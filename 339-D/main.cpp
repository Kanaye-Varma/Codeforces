#include <bits/stdc++.h>
using namespace std;

#define num long long int
#define v vector
#define vi v<num> 
#define inf 1e9

vi a;
vi st, L, R, f; 


void build(num p, num l, num r) {
    L[p] = l;
    R[p] = r; 
    if (l==r) {
        st[p] = a[l];
        f[p] = 0; 
    }
    else {
        num m = (l+r)/2; 
        build(2*p, l, m);
        build(2*p+1, m+1, r);
        f[p] = 1 - f[2*p];
        if (f[p]) st[p] = (st[2*p] | st[2*p+1]);
        else st[p] = (st[2*p] ^ st[2*p+1]);
    }
}

void update(num p, num x, num b) {
    // update a[x] to b
    if ((x < L[p]) || (R[p] < x)) return;
    if ((L[p] == R[p])) {
        st[p] = b;
        return; 
    }
    update(2*p, x, b);
    update(2*p+1, x, b);
    if (f[p]) st[p] = (st[2*p] | st[2*p+1]);
    else st[p] = (st[2*p] ^ st[2*p+1]);
}

int main() {
    num n, m; cin >> n >> m;
    num N = (1<<n);
    a.assign(N+1,0);
    for (int i = 1; i <= N; i++) cin >> a[i]; 

    st.assign(2*N+1, 0);
    L.assign(2*N+1, 0);
    R.assign(2*N+1, 0);
    f.assign(2*N+1, -1);

    build(1, 1, N);
    
    for (num _ = 0; _ < m; _++) {
        num p, b; cin >> p >> b; 
        update(1, p, b);
        cout << st[1] << endl;
    }

    return 0;
}