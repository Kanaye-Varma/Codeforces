#include <bits/stdc++.h>
using namespace std;

#define num long long int
#define v vector
#define vi v<num> 
static const num inf = 1e18; 

// constructing the segment tree 
vi st, a; 

void build(num i, num l, num r) {
    if (l == r) {
        st[i] = a[l]; 
        return; 
    }

    num m = (l + r) >> 1; 
    build(2*i, l, m); 
    build(2*i+1, m+1, r); 

    st[i] = st[2*i] ^ st[2*i+1]; 
}

void init(num n) {
    num N = 1 << n; 
    a.assign(N, 0); 
    for (num i=0; i<N; i++) cin >> a[i]; 
    st.assign(2*N, 0);
    build(1, 0, N-1); 
}

void upd(num i, num d) {
    // set a[i] = d; 
    num j = a.size() + i; 
    st[j] = d; 
    while (j > 1) {
        j >>= 1; 
        st[j] = st[2*j] ^ st[2*j+1]; 
    }
}

num solve(num i) {
    num j = a.size() + i; 
    num sz = 0, ans = 0; 
    num loc = j % 2; 
    while (j > 1) {
        j >>= 1; 
        sz = sz ? sz << 1 : sz + 1; 
        if (st[2*j + loc] < st[2*j + (1-loc)]) {
            // cow is in losing stack 
            ans += sz; 
        }
        if (st[2*j + loc] == st[2*j + (1-loc)]) {
            // cow loses if it is on the right but not on the left 
            ans += sz * loc; 
        }
        loc = j % 2; 
    }
    return ans; 
}

int main() {
    num t; cin >> t; 
    while (t--) {
        num n, q; 
        cin >> n >> q; 
        init(n);
        while (q--) {
            num b, c; cin >> b >> c; 
            --b; 
            upd(b, c); 
            // for (num i=0; i < 2 * a.size(); i++) cout << st[i] << ' '; 
            cout << solve(b) << endl; 
            upd(b, a[b]); 
        }
    }
    return 0; 
}