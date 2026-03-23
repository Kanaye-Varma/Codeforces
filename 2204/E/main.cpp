#include <bits/stdc++.h>
using namespace std; 

#define num long long int
#define v vector
#define vi v<num> 

int to_int(char c) {
    return c - '0'; 
}

num digits_sum(string s) {
    num ans = 0; 
    for (char x : s) ans += to_int(x); 
    return ans; 
}

string get_suffix(string s) {
    string ans = s, cur = s; 
    while (cur.size() > 1) {
        cur = to_string(digits_sum(cur));
        ans += cur; 
    }
    return ans; 
}

int main() {

    num t; cin >> t;
    while (t--) {
        string s; cin >> s; 
        if (s.size() == 1) {
            cout << s << endl;
            continue; 
        }
        vi occ(10, 0); num tot = 0; 
        for (char x : s) {
            ++occ[to_int(x)];
            tot += to_int(x); 
        }
         
        for (num start = 1; start < 9*s.size(); start++) {
            string suffix = get_suffix(to_string(start));
            vi occ_suff(10, 0); num tot_suff = 0;
            bool ok = true;  
            for (char x : suffix) {
                ++occ_suff[to_int(x)];
                tot_suff += to_int(x); 
                if (occ_suff[to_int(x)] > occ[to_int(x)]) {
                    ok = false; 
                    break; 
                }
            }
            if (!ok) continue; 
            if (tot - tot_suff == start) {
                // found answer!
                string ans = ""; string zeros = ""; 
                for (char x : s) {
                    if (occ[to_int(x)] > occ_suff[to_int(x)]) {
                        if (x == '0') zeros += x; 
                        else ans += x; 
                        --occ[to_int(x)];
                    }
                }  
                cout << ans << zeros << suffix << endl; 
                break;
            }
            
        }
    }

    return 0; 
}