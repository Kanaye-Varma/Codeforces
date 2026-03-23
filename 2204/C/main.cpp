#include <bits/stdc++.h>

using namespace std; 

#define num long long int
#define v vector 
#define vi v<num> 

num ans(num a, num b, num c, num m) {
    num 
        gone = m / a, 
        shared_b = m / lcm(a, b), 
        shared_c = m / lcm(a, c), 
        all = m / lcm(lcm(a, b), c);
    return 6*gone - 3*(shared_b + shared_c) + 2*all; 
}

int main() {

    num t; cin >> t; 
    while (t--) {
        num a, b, c, m; cin >> a >> b >> c >> m;
        cout << ans(a, b, c, m) << ' '
            << ans(b, a, c, m) << ' '
            << ans(c, a, b, m) << endl;
    }
    return 0; 
}