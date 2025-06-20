#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        ll N;
        cin >> N;
        // We look for m >= 1 s.t. numerator = N - m*(m-1)/2 is positive and divisible by m.
        // Then t = numerator / m >= 1 and string length t + 2*m <= 100000.
        bool found = false;
        ll maxm = (ll)(sqrt(2.0 * N) + 2);
        maxm = min(maxm, 100000LL);
        for (ll m = 1; m <= maxm; ++m) {
            ll tri = m * (m - 1) / 2;
            if (tri > N) break;
            ll num = N - tri;
            if (num % m != 0) continue;
            ll t = num / m;
            if (t < 1) continue;
            if (t + 2 * m > 100000) continue;
            // build string: t 'u', then m times 'w','u'
            string s;
            s.reserve(t + 2 * m);
            s.append(t, 'u');
            for (ll i = 0; i < m; ++i) {
                s.push_back('w');
                s.push_back('u');
            }
            cout << s;
            found = true;
            break;
        }
        // guarantee existence
        if (!found) {
            // fallback: alternating uw until pairs reach N (triangular approx)
            ll m = (ll)(sqrt(2.0 * N) + 1);
            ll t = 1;
            string s;
            s.reserve(m * 2);
            s.push_back('u');
            for (ll i = 1; i <= m; ++i) {
                s.push_back('w');
                s.push_back('u');
                if (i * t + i * (i - 1) / 2 >= N) break;
            }
            cout << s;
        }
        cout << '\n';
    }
    return 0;
}