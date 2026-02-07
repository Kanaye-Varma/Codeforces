#include <bits/stdc++.h>
using namespace std;

#define num long long int
#define v vector 
#define vi v<num>
#define inf 1e9 

num zero = 0; 
num n, t; 
vi a, p, t1, t2; 
num i, j, k;
v<vi> adj; 

void setParents(num u) {
    for (num w : adj[u]) {
        if (!p[w]) {
            p[w] = u; 
            setParents(w);
        }
    }
}

void dfs(num u) {
    if (u != 1) {
        t1[u] = a[u] - min(zero, t2[p[u]]);
        t2[u] = a[u] - max(zero, t1[p[u]]);
    }
    for (num w : adj[u]) {
        if (w != p[u]) dfs(w);
    }
}
int main() {
    cin >> t; 
    while (t--) {
        cin >> n;
        a.assign(n+1, 0);
        for (i=1; i<=n; i++) cin >> a[i]; 
        adj.assign(n+1, {});
        for (i=0; i<n-1; i++) {
            num u, _v; cin >> u >> _v; 
            adj[u].push_back(_v);
            adj[_v].push_back(u);
        }
        p.assign(n+1, 0);
        p[1] = 1; 
        setParents(1);
        t1.assign(n+1, 0); t1[1] = a[1];
        t2.assign(n+1, 0); t2[1] = a[1];
        dfs(1);
        for (i=1; i<=n; i++) cout << t1[i] << ' ';
        cout << endl;
    }

    return 0;
}