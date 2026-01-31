#include <bits/stdc++.h>
using namespace std;

#define num long long int
#define v vector 
#define vi v<num>

num t, n, m;
vi a, b, c; 
num i, j, k;

int main() {
    cin >> t; 
    while (t--) {
        cin >> n >> m;
        priority_queue<num, vi, greater<num>> swords;
        for (i=0; i<n; i++) {
            num x; cin >> x; 
            swords.push(x);
        }
        b.assign(m, 0); for (i=0; i<m; i++) cin >> b[i];
        c.assign(m, 0); for (i=0; i<m; i++) cin >> c[i];

        vi stage_1, stage_2;
        for (i=0; i<m; i++) {
            if (c[i] > 0) stage_1.push_back(i);
            else stage_2.push_back(i);
        }
        sort(stage_1.begin(), stage_1.end(), [](num i, num j) {return b[i] < b[j];});
        sort(stage_2.begin(), stage_2.end(), [](num i, num j) {return b[i] < b[j];});
        priority_queue<num, vi, greater<num>> more_swords;
        num idx = 0; 
        num ans = 0; 
        // stage 1
        while (!swords.empty()) {
            num cur = swords.top(); swords.pop();
            if (idx < stage_1.size()) {
                j = stage_1[idx];
                if (cur >= b[j]) {
                    swords.push(max(cur, c[j]));
                    ++idx; ++ans;
                } else more_swords.push(cur);
            } else {
                more_swords.push(cur);
            }
        }
        // stage 2
        idx = 0; 
        while (!more_swords.empty()) {
            num cur = more_swords.top(); more_swords.pop();
            if (idx < stage_2.size()) {
                j = stage_2[idx];
                if (cur >= b[j]) {
                    ++idx; ++ans;
                }
            }
        }

        cout << ans << endl;
    }
}