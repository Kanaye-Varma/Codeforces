#include <bits/stdc++.h>
using namespace std;

#define v vector 
#define num long long int
#define vi v<num>
#define INF 1e9

num T, N;

int main() {

    cin >> T;
    while (T--) {
        cin >> N; 
        vi nums(N, 0);
        for (num i = 0; i < N; i++) cin >> nums[i];
        vi ps(N,0); ps[0] = nums[0];
        for (num i = 1; i < N; i++) ps[i] = ps[i-1] + nums[i];
        string letters; cin >> letters;

        vi left{}, right{};
        for (num i = 0; i < N; i++) {
            if (letters[i] == 'L') left.push_back(i);
            if (letters[i] == 'R') right.push_back(i);
        }
        sort(right.begin(), right.end(), greater<num>());
        if ((left.size() == 0) || (right.size() == 0)) {
            cout << 0 << endl;
            continue;
        }
        num i = 0, ans = 0;
        while (true) {
            if (i >= min(left.size(), right.size())) break;
            if (left[i] > right[i]) break;
            ans += ps[right[i]];
            if (left[i] > 0) ans -= ps[left[i]-1];
            i++;
        }
        cout << ans << endl;
    }

    return 0;
}