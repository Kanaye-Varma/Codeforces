#include <bits/stdc++.h>
using namespace std;

#define num long long int
#define v vector
#define vi v<num>
#define INF 1e9

num T, N;
int main() {

    cin >> T;
    
    for (num _ = 0; _ < T; _++) {
        cin >> N;
        vi n(N+2, 0);
        for (num i = 0; i < N; i++) {
            num x; cin >> x;
            ++n[x];
        }
        bool flag = 0; 
        for (num i = 1; i <= N; i++) {
            if (n[i] == 1) {
                cout << "NO" << endl;
                flag = 1; 
                break;
            }
            if (n[i] > 2) {
                num k = n[i] - 2; 
                n[i] = 2; 
                n[i+1] += k; 
            }
        }
        if (!flag) cout << "YES" << endl;
    }
    return 0;

}
