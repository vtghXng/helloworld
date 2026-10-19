#include<bits/stdc++.h>
using namespace std ;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n ; 
    cin >> n ; 

    long long temp = n ; 
    vector<int> e ; 

    for( long long i = 2 ; i * i <= temp ; i++)
    {
        if( temp % i == 0 )
        {
            int dem = 0 ; 
            while( temp % i == 0 )
            {
                dem++ ; 
                temp /= i ; 
            }
            e.push_back(dem);
        }
    }

    if( temp > 1 ) e.push_back(1) ;

    if (e.size() == 1) {
        if (e[0] > 1) cout << 0 << "\n"; 
        else cout << 1 << "\n";
        return 0;
    }

    int max_e = 0;
    int sum_e = 0;
    for (int dem : e) {
        max_e = max(max_e, dem);
        sum_e += dem;
    }

    int min_kq = 1e9;

    for (int i = 0; i < e.size(); i++) {
        if (e[i] > 1) {
            min_kq = min(min_kq, sum_e - e[i]);
        }
    }

    for (int g = 2; g <= max_e + 1; g++) {
        int buoc = 0;
        for (int dem : e) {
            buoc += min(abs(dem - g), dem);
        }
        min_kq = min(min_kq, buoc);
    }

    cout << min_kq << "\n";
    

}