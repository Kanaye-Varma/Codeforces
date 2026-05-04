#include <bits/stdc++.h>
using namespace std; 

#define num long long int
#define v   vector
#define vi  v<num>
#define inf 1e18

num t, n; 
vi a; 

vi par, depth;

num get_depth(num i) {
    if (!depth[i])
        depth[i] = par[i] < 0 ? 1 : 1 + get_depth(par[i]); 
    return depth[i]; 
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n; 
        a.assign(n, 0); 
        for (num i=0; i<n; i++) cin >> a[i]; 
        
        par.assign(n, -1); 
        stack<num> s; 
        for (num i=0; i<n; i++) {
            num last = -1; 
            while (!s.empty() && a[s.top()] <= a[i]) {
                last = s.top(); 
                s.pop(); 
            }
            if (!s.empty()) {
                par[i] = s.top(); 
            }
            if (last != -1) {
                par[last] = i; 
            }
            s.push(i); 
        }

        depth.assign(n, 0); 
        num dmax = 0;
        for (num i=0; i<n; i++) dmax = max(dmax, get_depth(i)); 
        cout << n - dmax << endl;
    }
    return 0; 
}
