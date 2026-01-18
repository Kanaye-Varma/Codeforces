#include <bits/stdc++.h>
using namespace std;

#define num long long int
#define v vector 
#define vi v<num> 
#define str string

num m, t;
str s, l, r; 

num c2num(char c) {
    return static_cast<num>(c-'0');
}


int main() {
    
    cin >> t;
    while (t--) {
        cin >> s >> m;
        vi l(m, 0); vi r(m, 0);
        for (num i=0; i<m; i++) {
            char c; cin >> c; 
            l[i] = c2num(c);
        }
        for (num i=0; i<m; i++) {
            char c; cin >> c; 
            r[i] = c2num(c);
        }
        v<set<num>> occ;
        occ.assign(10, {});
        num n = s.length();
        for (num i=0; i<n; i++) 
            occ[c2num(s[i])].insert(i);
        num idx = -1; 
        bool possible = false; 
        for (num i=0; i<m && !possible; i++) {
            // for each possible digit, find the best one
            num rightmost_index = idx; 
            for (num d=l[i]; d<=r[i] && !possible; d++) {
                set<num>::iterator first = occ[d].upper_bound(idx);
                if (first == occ[d].end()) {
                    possible = true;
                }
                else {
                    rightmost_index = max(rightmost_index, *first);
                }
            }
            idx = rightmost_index; 
        }
        if (possible) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}