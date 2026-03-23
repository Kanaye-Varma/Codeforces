#include <bits/stdc++.h>
using namespace std;

#define num long long int
#define v vector
#define vi v<num> 
#define pii pair<num, num> 

num inf = 1e9; 
num zero = 0; 

int main() {
    num t; cin >> t; 
    while (t--) {
        num n; cin >> n;
        v<pii> a;
        for (num i=0; i<n; i++) {
            num x; cin >> x; 
            a.push_back(pii(x, i));
        }
        sort(a.begin(), a.end()); 
        num len = n, ans = 0; 
        for (num i=n-1; i >= 0; i--) {
            num x = a[i].first, pos = a[i].second; 
            if (pos >= len) continue;
            len = pos; 
            ++ans; 
        }
        cout << ans << endl;
    }
    return 0; 
}