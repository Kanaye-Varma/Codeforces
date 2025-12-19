#include <bits/stdc++.h>
using namespace std;

#define num long long int
#define v vector
#define vi v<num>
#define inf 1e9

num N; vi a, t; 
vi A, ft, ps;

num LSOne(num i) {return (i & (-i));}

// fenwick tree 
void build() {
    ps.assign(N+1, 0);
    ft.assign(N+1, 0);
    ps[1] = A[1]; ft[1] = ps[1];
    for (num i = 2; i <= N; i++) {
        ps[i] = A[i] + ps[i-1];
        ft[i] = ps[i] - ps[i-LSOne(i)];
    }
}

num rsq(num j) {
    num ans = 0; 
    for (; j; j -= LSOne(j)) ans += ft[j];
    return ans;
}

void update(num j, num d) {
    A[j] += d;
    for (; j <= N; j += LSOne(j)) ft[j] += d; 
}

map<num, num> cnt; 
int main() {
    ios::sync_with_stdio(false);
    
    cin >> N;
    a.assign(N+1, 0);
    for (num i = 1; i <= N; i++) {
        cin >> a[i];
        cnt[a[i]] = 0; 
    }
    
    // calculate f and g respectively 
    vi f, g;
    
    f.assign(N+1, 0);
    A.assign(N+1, 0);
    g.assign(N+1, 0);
    for (num i = 1; i <= N; i++) {
        f[i] = ++cnt[a[i]];
    }
    for (num j = 1; j <= N; j++) {
        g[j] = cnt[a[j]] + 1 - f[j];
        ++A[g[j]];
    }
    build();
    
    num ans = 0; 
    for (num i = 1; i <= N; i++) {
        // for i < j; find f(i) > g(j)
        update(g[i], -1);
        ans += rsq(f[i]-1);
    }
    cout << ans << endl;
    return 0;
}