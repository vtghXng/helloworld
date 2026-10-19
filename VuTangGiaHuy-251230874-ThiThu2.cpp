#include<bits/stdc++.h>
using namespace std;

class DiaChiIP 
{
    private:
        int o[4] ;
    public:
        DiaChiIP()
        {
            o[0]=o[1]=o[2]=o[3]=0;
        }

        explicit DiaChiIP(const string& s)
        {
            string chuoiTam = "" ; 
            int dem = 0; 
            for( int i =0 ; i < s.length() ; i++ )
            {
                if( i == s.length() || s[i] == '.' )
                {
                    if( dem >= 4 ) cout << "Nhieu hon 4 octet" ;
                    if( chuoiTam == "") cout << "Octet bi trong" ;

                    int giatri = stoi(chuoiTam);
                    if( giatri < 0 || giatri > 255 )  cout << "Octet nam ngoai 0 -> 255" ;

                    o[dem] = giatri ;
                    dem++;
                    chuoiTam = "";
                }
                else 
                {
                    chuoiTam += s[i] ;
                }
            }

            if(dem < 4 )
            {
                cout << "Chuoi khong du 4 octet" ; 
            }
        }
};

template <class T>
class DanhSach {
        T* data;
        int n, cap;
    public:
        DanhSach(int capacity = 4) : n(0) , cap(capacity)
        {
            data = new T[cap] ;
        };

        DanhSach(const DanhSach& other) : n(other.n) , cap(other.cap)
        {
            data = new T[cap] ;
            for( int i =0 ; i < n ; i++)
            {
                data[i] = other.data[i] ;
            }
        };

        DanhSach& operator=(const DanhSach& other)
        {
            if( this != &other )
            {
                delete[] data ;
                n = other.n ;
                cap = other.cap ;
                data = new T[cap] ;
                for( int i = 0 ; i < n ;i++)
                {
                    data[i] = other.data[i];
                }
            }
            return this* ;
        };

        ~DanhSach()
        {
            delete[] data ;
        };
        
        void them(const T& x)  // tự tăng gấp đôi cap khi đầy
        {
            if( n == cap )
            {
                cap *= 2 ;
                T* newDaTa = new T[cap] ;
                for( int i =0  ; i < n ; i++)
                {
                    newDaTa[i] = data[i] ;
                }
                delete[] data ;
                data = newDaTa ;
            }

            data[n] = x ;
            n++ ;
        }; 

        T& operator[](int i)// ném out_of_range nếu i sai
        {
            if( i < 0 || i >= n)
            {
                cout << "Chi so nam ngoai trup cap he thong " ;
            }
            return data[i];
        };  
                   
        int kichThuoc() const { return n; }
};

int main()
{
    DanhSach<DiaChiIP> dsIP; 
    int n; 

    cout << "Nhap so luong dia chi IP :" ;
    cin >> n ;
    cin.ignore() ;

    for(int i = 0 ; i <  n; i ++) 
    {
        string chuoiIP ;
    }
    return 0;
}