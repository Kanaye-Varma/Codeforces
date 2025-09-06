#include <bits/stdc++.h>
using namespace std;

#define num long long int
#define v vector 
#define vi v<num> 
#define INF 1e9

num t, n, k;
/*
Minimise number of deals 

- Find max x such that 3^x <= N
- N -= 3^x 
- Repeat 
*/
vi pow_3, coins_for_deal;

int main() {
    pow_3.assign(22, 0); // buffer space jic
    coins_for_deal.assign(22, 0);
    pow_3[0] = 1; coins_for_deal[0] = 3;
    for (int i=1; i<pow_3.size(); i++) {
        pow_3[i] = 3 * pow_3[i-1];
        coins_for_deal[i] = 3*pow_3[i] + i*pow_3[i-1];
    }

    cin >> t;
    for (int _=0; _<t; _++) {
        cin >> n >> k;
        // max  n = 10^9 ~ 3^18
        int x = 19;
        num coins = 0, num_deals = 0; 
        vi deals; deals.assign(22, 0);
        while (n) {
            if (pow_3[x] <= n) {
                // take the deal 
                ++deals[x]; ++num_deals;
                n -= pow_3[x];
                coins += coins_for_deal[x];
            }
            else --x;
        }
        if (num_deals > k) {
            cout << -1 << endl;
            continue;
        }
        if (k - num_deals < 2) {
            cout << coins << endl;
            continue;
        }
        for (x=21; x > 0; x--) {
            /*
            If deals[x] = 0: move on
            find max z such that
                num_deals + 2z <= k
                :. z <= (k-num_deals)/2
            
            coins -= 3^(x-1)z
            num_deals += 2z
            */
           if (deals[x] == 0) continue;
           num z = min(deals[x], (k-num_deals)/2);
           if (z <= 0) break;
           coins -= pow_3[x-1]*z;
           num_deals += 2*z;
           deals[x] -= z;
           deals[x-1] += 3*z;
        }
        
        cout << coins << endl;
    }
    return 0; 
}