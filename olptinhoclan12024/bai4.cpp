#include<bits/stdc++.h>
using namespace std;

int main(){
    int dx[]={-1,-1,-1,0,0,1,1,1};
    int dy[]={-1,0,1,-1,1,-1,0,1};

    int n, m;
    if (!(cin >> n >> m)) return 0;

    int x[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> x[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (x[i][j] == -1) {
                cout << -1;
            }
            else {
                int check = 0 ;
                for (int k = 0; k < 8; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        if (x[ni][nj] == -1) {
                            check++;
                        }
                    }
                }
                cout << check ;
            }
            if (j < m - 1) cout << " ";
        }
        cout << "\n";
    }
}
