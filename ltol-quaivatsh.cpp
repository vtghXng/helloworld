#include <iostream>

using namespace std;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    for (int i = 0; i <= 100; ++i) {
        int t = b + i * a; 
        
        if (t >= d && (t - d) % c == 0) {
            cout << t << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}