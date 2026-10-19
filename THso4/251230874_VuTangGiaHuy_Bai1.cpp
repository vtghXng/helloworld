#include<bits/stdc++.h>
using namespace std ;

class thongtin 
{
    protected:
        string ht ;
        int ns ;
    public:
        virtual void nhap()
        {   
            cout << "Nhap ho va ten : " << endl ;
            getline(cin,ht);
            cout << "Nhap nam sinh : " << endl ;
            cin >> ns ; 
        };
        virtual void xuat()
        {
            cout << "Danh sach ban dau : " ;
            cout << ht << setw(9) << ns << endl; 
        };
};

class thisinh : public thongtin
{
    private:
        string sbd ; 
        double toan,ly,hoa;
    public:
        void nhap() override 
        {
            thongtin::nhap();
            cin.ignore();
            cout << "Nhap so bao danh :";
            getline(cin,sbd);
            cout << "Nhap diem toan ly hoa :" ; 
            cin >> toan >> ly >> hoa ;
            cin.ignore();
        };

        void xuat() override 
        {
            cout << "Danh sach thi sinh la : " ;
            cout << sbd << setw(8) << ht << setw(8) << ns << setw(8) << toan << setw(4) << ly << setw(4) << hoa;
        };

        double tong() 
        {
            return (toan + ly + hoa) ;
        }

        string getsbd()
        {
            return sbd;
        }

        bool yc()
        {
            return (toan >= 5 && ly >= 5 && hoa >= 5);
        }
};

// •	Nhập vào một danh sách có n thí sinh
// •	Hiển thị danh sách thí sinh có tổng điểm ba môn tăng dần;
// •	Tìm một thí sinh khi biết Số báo danh.
// •	Thống kê xem có bao nhiêu phần trăm thí sinh đạt yêu cầu (cả ba môn có điểm lớn hơn hoặc bằng 5).

int main()
{
    vector<thongtin*> ds ;
    int n ;
    cout << "Nhap so thi sinh :" ; 
    cin >> n ; cin.ignore();

    int i ; 
    for( i = 0 ; i < n ; i++) 
    {
        cout << "Nhap thong tin ts so " << i + 1 << endl ;
        thongtin* ts = new thisinh() ; 
        ts->nhap();
        ds.push_back(ts);
        cout << endl ;
    }

    cout << "Xuat thong tin thi sinh " << endl;
    for( i = 0 ; i < ds.size() ; i++)
    {
        ds[i]->xuat();
        cout << endl ;
    }

    cout << "Danh sach thi sinh co tong diem tang dan:" << endl;
    for (int i = 0; i < ds.size() - 1; i++) {
        for (int j = i + 1; j < ds.size(); j++) {
            thisinh* ts_i = (thisinh*)ds[i];
            thisinh* ts_j = (thisinh*)ds[j];
            
            if (ts_i->tong() > ts_j->tong()) {
                thongtin* temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
    
    for(int i = 0; i < ds.size(); i++) {
        ds[i]->xuat();
        thisinh* ts = (thisinh*)ds[i]; 
        cout << setw(8) << " | Tong: " << ts->tong() << endl;
    }

    cout << "Nhap sbd can tim :" << endl ; 
    string tk ; 
    cin >> tk ;

    bool kq = false ; 
    for( i = 0 ; i < ds.size() ; i++)
    {
        thisinh* ts = (thisinh*)ds[i]; 
        if (ts != NULL && ts->getsbd() == tk) {
            cout << "Da tim thay: \n";
            ts->xuat();
            cout << endl;
            kq = true;
            break; 
        }
    }

    if (!kq) {
        cout << "Khong tim thay thi sinh co SBD: " << tk << endl;
    }

    cout << "Danh sach dat du dieu kien cac mon tren 5 la :" << endl ; 
    int dem = 0 ; 
    for(int i = 0; i < ds.size(); i++) {
        thisinh* ts = (thisinh*)ds[i]; 
        if (ts != NULL && ts->yc()) {
            dem++;
        }
    }
    
    if (ds.size() > 0) {
        double phanTram = (double)dem / ds.size() * 100;
        cout << "Ty le thi sinh dat yeu cau (3 mon >= 5): " << phanTram << "%" << endl;
    }

    for(int i = 0; i < ds.size(); i++)
    {
        delete ds[i];
    }
    ds.clear();
    
    return 0;

}