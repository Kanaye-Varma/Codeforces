#include <bits/stdc++.h>
using namespace std;

#define num long long int
#define v vector
#define vi v<num> 
#define inf 1e9

num t, n; 
vi cnt; v<vi> AL;
vi ans; num ret; 
int main() {
    cin >> t; 
    for (num _=0; _<t;_++) {
        cin >> n; 
        cnt.assign(n, 0);
        AL.assign(n, {});
        for (num i = 0; i < n-1; i++) {
            num a, b; cin >> a >> b; 
            --a; --b; 
            ++cnt[a]; ++cnt[b];
            AL[a].push_back(b);
            AL[b].push_back(a);
        }
        num roots = 0; 
        for (num c : cnt) if (c == 1) ++roots; 
        ans.assign(n, inf); ret = inf; 
        for (num i=0; i<n; i++) {
            // ans: num roots - num root neighbours (including self)
            ans[i] = roots;
            for (num nb : AL[i]) if (cnt[nb] == 1) --ans[i];
            if (cnt[i] == 1) --ans[i];
            ret = min(ans[i], ret);
        }
        cout << ret << endl;
    }

    return 0;
}