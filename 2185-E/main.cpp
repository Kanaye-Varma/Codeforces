#include <bits/stdc++.h>
using namespace std;

#define num long long int
#define v vector
#define vi v<num>

num INF = 1e10;

num t, n, m, k;
num i, j; // for loops

vi a, b, s, memo, R, L, d;


int main() {

    cin >> t; 
    while (t--)
    {
        cin >> n >> m >> k;
        a.assign(n, 0);
        for (i=0; i<n; i++) cin >> a[i];
        b.assign(m, 0);
        for (i=0; i<m; i++) cin >> b[i];
        s.assign(k, 0);
        for (i=0; i<k; i++) {
            char x; cin >> x; 
            if (x == 'L') --s[i];
            else ++s[i];
        }

        memo.assign(2*k+1, INF); // from 0 to 2k
        num dx = 0; 
        for (j=0; j<k; j++) {
            dx += s[j];
            memo[dx+k] = min(memo[dx+k], j);
        }

        set<num> thorns; 
        for (j=0; j<m; j++) thorns.insert(b[j]);
        
        R.assign(n, 0); L.assign(n, 0);
        for (i=0; i<n; i++) {
            auto up = thorns.upper_bound(a[i]);
            if (up == thorns.end()) R[i] = INF;
            else R[i] = *up - a[i];
            if (R[i] > k) R[i] = INF; 
            if (up == thorns.begin()) L[i] = -INF;
            else L[i] = *(--up) - a[i];
            if (L[i] < -k) L[i] = -INF;
        }

        d.assign(k, 0);        
        for (i=0; i<n; i++) {
            num TRi = R[i] == INF ? INF : memo[R[i] + k]; // T(R[i])
            num TLi = L[i] == -INF ? INF : memo[L[i] + k]; // T(L[i])
            j = min(TRi, TLi); 
            if (j != INF) d[j] += 1; 
        }

        num D = 0;
        for (j=0; j<k; j++) {
            D += d[j];
            cout << n - D << ' ';
        }
        cout << endl;

    }
    

    return 0;
}