#include<bits/stdc++.h>
using namespace std;

const int MAX = 1005; 
int a[MAX][MAX];
int dist[MAX][MAX];

int dx[] = {-1,1,0,0} ;
int dy[] = {0,0,1,-1} ;

int main()
{
    int n , m ; 
    cin >> n >> m ;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dist[i][j] = -1;
        }
    }

    queue<pair<int, int>> q;
    q.push({sx,sy});
    dist[sx][sy] = 0 ;

    while(!q.empty())
    {
        int x = q.front().first ;
        int y = q.front().second ;
        q.pop();

        if (x == ex && y == ey) 
        {
            cout << dist[x][y] << "\n";
            return 0;
        }

        for (int i = 0; i < 4; i++) 
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) 
            {
                if (a[nx][ny] == 0 && dist[nx][ny] == -1) 
                {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }
    }

    cout << -1 << endl;
    return 0 ;
}