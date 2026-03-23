#include <bits/stdc++.h>
using namespace std; 

#define num int
#define v vector
#define vi v<num>
#define pii pair<num, num> 

int main() {
    num t; cin >> t; 
    while (t--) {
        num n, m; cin >> n >> m; 
        v<vi> AL(n); 
        for (num i=0; i<m; i++) {
            num u, w; cin >> u >> w; 
            --u; --w; 
            AL[u].push_back(w);
            AL[w].push_back(u); 
        }
        num ans = 0; 
        vi clr(n, -1); 
        for (num i=0; i<n; i++) if (clr[i] == -1) {
            vi cnt(2, 0);
            queue<num> q; q.push(i); 
            clr[i] = 0; ++cnt[0]; 
            bool ok = true; 
            while (!q.empty()) {
                num u = q.front(); q.pop(); 
                for (num nb : AL[u]) {
                    if (clr[nb] == clr[u]) {
                        ok = false; 
                    }
                    if (clr[nb] == -1) {
                        clr[nb] = 1 - clr[u]; 
                        ++cnt[clr[nb]]; 
                        q.push(nb); 
                    }
                }
            }
            if (ok) ans += max(cnt[0], cnt[1]);
        }
        cout << ans << endl;
    }   

    return 0;
}