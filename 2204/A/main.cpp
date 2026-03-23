#include <bits/stdc++.h>
using namespace std;

#define num long long int
#define v vector
#define vi v<num> 

num inf = 1e9; 
num zero = 0; 

int main() {
    num t; cin >> t; 
    while (t--) {
        num n; cin >> n; 
        num ans = 0, d = 1; 
        for (num i=0; i<n; i++) {
            char x; cin >> x; 
            ans += d; 
            if (x == 'L') d = 0;
        }
        cout << ans << endl;
    }
    return 0; 
}