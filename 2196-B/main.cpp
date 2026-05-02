#include <bits/stdc++.h>
using namespace std; 

#define num long long int
#define v vector 
#define vi v<num>

static num t, n, i, j, k, ans; 
vi a; 
int main() {
    cin >> t; 
    while (t--) {
        cin >> n;
        a.assign(n, 0);
        for (i=0; i<n; i++) cin >> a[i];

        // square root decomposition 
        double b = sqrt(n); 
        ans = 0; 
        for (i=0; i<n; i++) {
            if (a[i] < b) {
                for (k=1; k<b; k++) {
                    j = i + k * a[i]; 
                    if (j >= n) break;
                    if (a[i] * a[j] == j - i) ++ans; 
                }
            }
            else {
                for (j=i+a[i]; j<n; j+=a[i]) {
                    if (a[i] * a[j] == j - i) ++ans; 
                }
                for (j=i-a[i]; j>=0; j-=a[i]) {
                    if (a[i] * a[j] == i - j) ++ans; 
                }
            }
        }
        cout << ans << endl; 
    }
    return 0;
}