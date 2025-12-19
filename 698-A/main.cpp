#include <bits/stdc++.h>
using namespace std;

#define num long long int
#define v vector 
#define vi v<num>
#define inf 1e9

int main() {
    num n; cin >> n; 
    vi a(n+1, 0);
    for (num i = 1; i <= n; i++) cin >> a[i]; 

    v<vi> dp; // dp[i][s]
    dp.assign(n+1, vi(3, inf));
    for (num s = 0; s < 3; s++) dp[0][s] = 0; 
    for (num i = 1; i <= n; i++) {
        for (num s = 0; s < 3; s++) dp[i][0] = min(dp[i][0], dp[i-1][s] + 1);
        if (a[i] & 1) dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
        if (a[i] & 2) dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
    }
    num ans = inf; 
    for (num s = 0; s < 3; s++) ans = min(ans, dp[n][s]);
    cout << ans << endl;

    return 0;
}