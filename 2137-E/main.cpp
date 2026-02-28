#include <bits/stdc++.h>
using namespace std;

#define num long long int 
#define v vector 
#define vi v<num>

num inf = 1e9; 
num zero = 0;

num i, j, x;
num n, k, t; 
vi occ;  

int mex() {
    for (i=0; i<=n; i++)
        if (occ[i] == 0) return i; 
    return n+1; 
}

int sm() {
    for (i=0; i<=n; i++) 
        if (occ[i] != 1) return i; 
    return n+1; 
}


void state2(num m) {

    for (i=m+1; i<=n; i++) {
        occ[m] += occ[i];
        occ[i] = 0; 
    }
    
    if (occ[m] == 1) {
        num ans = m * (m + 1) / 2; 
        cout << ans << endl;
    }
    else {
        --k; 
        num ans = m * (m-1) / 2; 
        j = k % 2 == 0 ? m : m+1;
        ans += occ[m] * j;
        cout << ans << endl; 
    }
}

int main() {
    cin >> t; 
    while (t--) {
        cin >> n >> k;
        occ.assign(n+2, 0);
        for (i=0; i<n; i++) {
            cin >> x; ++occ[x];
        }
        
        num m = mex(); 
        num s = sm(); 

        if (m == s) {
            state2(m);
        } else {
            for (i=0; i<=n; i++) {
                if (i < m && occ[i] > 1) {
                    occ[m] += occ[i];
                    occ[i] = 0; 
                }
                if (i > m) {
                    occ[m] += occ[i]; 
                    occ[i] = 0; 
                }
            }
            --k; 
            if (k) state2(s);
            else {
                num ans = 0; 
                for (i=0; i<=m; i++) ans += occ[i] * i;
                cout << ans << endl;
            }

        }
    }
    return 0; 
}