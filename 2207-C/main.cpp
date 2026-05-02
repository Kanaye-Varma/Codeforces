#include <bits/stdc++.h>
using namespace std; 

#define v vector 
#define num long long int
#define vi v<num> 
#define inf 1e9 

static num t, n, h, i, j; 
vi a, cap; 
static const bool dbg = false; 

int main() {

    cin >> t; 
    while (t--) {
        cin >> n >> h;
        a.assign(n, 0); 
        for (i=0; i<n; i++) cin >> a[i]; 
        
        // cap[i]: capacity (water drained) for drain at column i
        cap.assign(n, 0); 
        for (i=0; i<n; i++) {
            num cur_max = 0; 
            // to the left first
            for (j=i; j>=0; j--) {
                cur_max = max(cur_max, a[j]); 
                cap[i] += h - cur_max; 
            }
            // to the right now 
            cur_max = a[i]; 
            for (j=i+1; j<n; j++) {
                cur_max = max(cur_max, a[j]); 
                cap[i] += h - cur_max; 
            }

        }
        if (dbg) {for (i=0; i<n; i++) cout << cap[i] << ' '; cout << endl;}

        // now we find the answer. 
        // ans(i, j) = cap[i] + cap[j] - cap[k]
        // where k = argmax[z=i...j](a[z])
        num ans = 0; 
        for (i=0; i<n; i++) {
            num cur_max = a[i], k=i; 
            for (j=i; j<n; j++) {
                if (a[j] > cur_max) {
                    cur_max = a[j]; 
                    k = j; 
                }
                ans = max(
                    ans, cap[i] + cap[j] - cap[k]
                );
            }
            if (dbg) cout << "ans is " << ans << " at i = " <<  i << endl;
        }
        cout << ans << endl;
    }

    return 0;
}