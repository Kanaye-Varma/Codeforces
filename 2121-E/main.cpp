#include <bits/stdc++.h>
using namespace std;

#define num long long int
#define v vector 
#define vi v<num> 

num inf = 1e11; 
num zero = 0; 


int to_int(char x) {
    
    return x - '0'; 
}

void solve(string l, string r) {
    num n = l.size(); 
    
    v<vi> dp(n, vi(3, inf));

    num ans = 0; 
    num i = 0; 
    while (l[i] == r[i] && i < n) {
        ans += 2; 
        ++i; 
    }
    if (i == n || r[i] - l[i] >= 2) {
        cout << ans << endl;
        return;
    }
    ans += 1; 
    dp[i][1] = ans; // lower bound only 
    dp[i][2] = ans; // upper bound only
    for (i += 1; i < n; i++) {
        dp[i][0] = dp[i-1][0];
        if (dp[i-1][1] < inf) { // lower bound only 
            dp[i][1] = dp[i-1][1] + 1 + (r[i] == l[i] ? 1 : 0);
            if (to_int(l[i]) < 8 || (l[i] == '8' && r[i] != '9')) {
                // break out of the lower bound entirely
                dp[i][0] = min(dp[i][0], dp[i-1][1]);
            } 
        }
        if (dp[i-1][2] < inf) { // upper bound only 
            dp[i][2] = dp[i-1][2] + 1 + (l[i] == r[i] ? 1 : 0);
            if (to_int(r[i]) > 1 || (r[i] == '1' && l[i] != '0')) {
                dp[i][0] = min(dp[i][0], dp[i-1][2]);
            }
        }
    }
    ans = inf; 
    for (num j=0; j<3; j++) ans = min(ans, dp[n-1][j]);
    cout << ans << endl;
}

int main() {
    num t; cin >> t;
    while (t--) {
        num a, b; cin >> a >> b;
        string l = to_string(a), r = to_string(b); 
        solve(l, r);
    }
    return 0; 
}