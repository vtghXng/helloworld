#include<bits/stdc++.h>
using namespace std;

class PhuongTien
{
    protected:
        string mapt ;
        double kg ;
    public:
        PhuongTien(string mapt1 , double kg1) 
        {
            mapt = mapt1 ;
            kg = kg1 ;
        }
        virtual ~PhuongTien(){};

        virtual void nhap()
        {
            cout << "Nhap ma phuong tien : " << endl ;
            cin >> mapt ; 
            cin.ignore(); 
            cout << "Nhap Tai trong toi da" << endl ;
            cin >> kg ; 
            cin.ignore();
        }

        virtual void xuat()
        {
            cout << mapt << " || " << kg ; 
        }

        double getKg() 
        {
            return kg; 
        }

        virtual double getChiPhi(double km , double kg) const = 0 ;
};

class KienHang 
{
    private:
        string MaKien;
        double KhoiLuongThuc ;
        double TheTich ;
    public : 
    KienHang(string ma , double m , double v) : MaKien(ma) , KhoiLuongThuc(m) , TheTich(v) {}
        double KhLgTinhCuoc() const
        {
            return max(KhoiLuongThuc ,TheTich*250) ;
        }
};

class ChuyenHang 
{
    protected:
        string maChuyen ;
        double quangDuong ;
        vector<KienHang> DanhSachKien ;
        PhuongTien* phuongtien ;
    public:
        ChuyenHang(string ma , double km , PhuongTien*pt) 
            : maChuyen(ma ) , quangDuong(km) , phuongtien(pt) {}
        
        // yeu cau 1 

        double tongKhoiLuong() const
        {
            double tong = 0 ;
            for( int i = 0 ; i < DanhSachKien.size() ; i++)
            {
                tong += DanhSachKien[i].KhLgTinhCuoc();
            }
            return tong ;
        }

        // yeu cau 2

        bool ThemKienHang(const KienHang &k)
        {
            if(phuongtien == nullptr ) return false ;

            double KhoiLuongSau = tongKhoiLuong() + k.KhLgTinhCuoc();
            if( KhoiLuongSau <= phuongtien->getKg())
            {
                DanhSachKien.push_back(k);
                return true ;
            }
            return false ;
        }

        // yeu cau 3 

        PhuongTien* chonReNhat( const vector<PhuongTien*> ds , double km , double kg )
        {
            PhuongTien* thapNhat = nullptr ;
            double minChiPhi = -1 ; 

            for( int i = 0 ; i < ds.size() ; i++)
            {
                if( ds[i]->getKg() >= kg )
                {
                    double chiPhiPhu = ds[i]->getChiPhi(km,kg) ;
                    if( minChiPhi == -1 || chiPhiPhu < minChiPhi )
                    {
                        minChiPhi = chiPhiPhu ;
                        thapNhat = ds[i] ;
                    }
                }
            }
            return thapNhat;
        }  
        
        // yeu cau 4 
        // Xe tai : 5000 kg >= 2000 kg => chiphi = 300 * 12000 + 2000 * 1500 = 6600000 
        // tau hoa : 2 toa 
        // tai trong : 2 * 30000 = 60000
        // => chiphi = 2000000 + 300 * 2000 * 3 = 3800000 
        // May bay : 10000 kg >= 2000kg 
        // => chi Phi = 2000 * 40000 = 80000000

        // => ham chontrenhat chi toi tau hoa 
};


class XeTai : public PhuongTien
{
    public:
        XeTai(string ma , double kg ) : PhuongTien(ma , kg) {}

        double getChiPhi(double km , double kg) const override 
        {
            return 12000 * km +  1500 * kg;
        }
};

class TauHoa : public PhuongTien
{
    private:
        int soToa ;
    public:
        TauHoa(string ma , int toa) : PhuongTien(ma , toa*30000) , soToa(toa) {}

        double getChiPhi( double km , double kg) const override
        {
            return 2000000 + km * kg * 3;
        }
};

int main()
{
    return 0 ;
}