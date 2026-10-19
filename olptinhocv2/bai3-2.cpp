#include <iostream>
#include <map>

using namespace std;

void solve() {
    int n;
    cin >> n;

    map<long long, long long> cnt;
    bool invalid = false;

    for (int i = 0; i < n; i++) {
        long long a, M;
        cin >> a >> M; 

        if (M <= 0 || (M & (M - 1)) != 0) {
            invalid = true; 
            continue;
        }

        long long k = 0;
        long long temp = M;
        while (temp > 1) {
            temp /= 2;
            k++;
        }

        // 3. Phân tích các bit 1 của Tử số a
        for (int bit = 0; bit < 62; bit++) {
            if ((a >> bit) & 1) {
                cnt[k - bit]++;
            }
        }
    }

    if (invalid) {
        cout << "NO\n";
        return;
    }

    for (auto it = cnt.rbegin(); it != cnt.rend(); ++it) {
        long long k = it->first;
        long long count = it->second;

        if (k <= 0) continue;

        if (count >= 2) {
            cnt[k - 1] += count / 2;
            it->second = count % 2;
        }
    }

    if (cnt[0] != 1) {
        cout << "NO\n";
        return;
    }

    for (auto p : cnt) {
        if (p.first != 0 && p.second > 0) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    // Tối ưu I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}