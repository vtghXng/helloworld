#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s1 , s2 ,s3 ;
    while( cin >> s1 )
    {
        if(s1 == "END" ) break;
        cin >> s2 ;
        cin >> s3 ; 

        int n = 0;
        while (n < s1.size() && (s1[n] == '0' || s1[n] == '1')) {
            n++;
        }

        int dem0 = 0 , dem1 = 0 , dem2 =0 , dem3 = 0 ;
        int dem12 = 0 , dem13 = 0 , dem23 =0 , dem123 = 0;

        for (int i = 0; i < n; i++)
        {
            if (s1[i] == '1' && s2[i] == '0' && s3[i] == '0') dem1++;
            else if (s1[i] == '0' && s2[i] == '1' && s3[i] == '0') dem2++;
            else if (s1[i] == '0' && s2[i] == '0' && s3[i] == '1') dem3++;
            else if (s1[i] == '1' && s2[i] == '1' && s3[i] == '0') dem12++;
            else if (s1[i] == '1' && s2[i] == '0' && s3[i] == '1') dem13++;
            else if (s1[i] == '0' && s2[i] == '1' && s3[i] == '1') dem23++;
            else if (s1[i] == '1' && s2[i] == '1' && s3[i] == '1') dem123++;
            else dem0++; 
        }

        int has1 = dem1 + dem12 + dem13 + dem123;
        int has2 = dem2 + dem12 + dem23 + dem123;
        int has3 = dem3 + dem13 + dem23 + dem123;

        if (dem0 > 0) {
            cout << "NO\n"; 
        } 
        else if (n < 3) {
            cout << "NO\n"; 
        } 
        else if (has1 == 0 || has2 == 0 || has3 == 0) {
            cout << "NO\n"; 
        } 
        else if (dem1 > n - 2 || dem2 > n - 2 || dem3 > n - 2) {
            cout << "NO\n";
        } 
        else {
            cout << "YES\n";
        }
    }
    return 0 ;
}