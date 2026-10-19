#include<bits/stdc++.h>
using namespace std ; 

class hocsinh 
{
    protected: 
        string ten ; 
        int tuoi ;
        string lop ;
    public: 
        hocsinh()
        {
            ten = "" ; 
            tuoi = 0 ; 
            lop = "" ;
        }

        hocsinh ( string ten1 , int tuoi1 , string lop1 )
        {
            ten = ten1 ;
            tuoi = tuoi1 ; 
            lop = lop1 ; 
        }

        friend istream&operator>>(istream &is , hocsinh &p) 
        {
            // is >> p.ten ; is.ignore() ;
            getline(is >> ws , p.ten);
            is >> p.tuoi ; 
            is >> p.lop ; is.ignore() ;
            return is ; 
        }

        friend ostream&operator<<(ostream &os , const hocsinh &p)
        {
            os << p.ten << " || " << p.tuoi << " || " << p.lop ;
            return os ; 
        }

        virtual float gettientieu() const { 
            return 0; 
        }
};

class hocsinhc3 : public hocsinh
{
    protected:
        float tientieu ; 
    public:
        friend istream&operator>>(istream &is , hocsinhc3 &p)
        {
            is >> static_cast<hocsinh&>(p) ;
            is >> p.tientieu ; 
            return is ;
        }

        friend ostream& operator<<(ostream& os, const hocsinhc3& p) {
            os << static_cast<const hocsinh&>(p);
            
            os <<" || Tien tieu: " << p.tientieu;
            return os;
        }

        void tinhtien()
        {
            float tiendau = 0 ;
            this->tientieu += tiendau;
        }

        void congtientieu(float tienthem)
        {
            this->tientieu += tienthem ;
            cout << "So tien tieu hien tai :" << this->tientieu << endl; 
        }

        void sosanhtientieu(const hocsinhc3 &p)
        {
            if (this->tientieu > p.tientieu) {
                cout << this->ten << " co nhieu tien tieu hon." << endl;
            } else if (this->tientieu < p.tientieu) {
                cout << p.ten << " co nhieu tien tieu hon." << endl;
            } else {
                cout << "Hai ban co tien tieu bang nhau." << endl;
            }
        }

        virtual float gettientieu() const { 
            return this->tientieu; 
        }
};

class sinhvien : public hocsinhc3 
{
    protected:
        string hoatdong ;
        string msv ; 
    public:
        friend istream&operator>>(istream &is , sinhvien &p)
        {
            is >> static_cast<hocsinhc3&>(p) ; 
            is >> p.msv ; is.ignore() ;
            is >> p.hoatdong ; is.ignore() ;
            return is ;
        }

        friend ostream&operator<<(ostream &os , const sinhvien &p)
        {
            os << static_cast<const hocsinhc3&>(p);
            
            os <<" || " << p.msv << " || " << p.hoatdong;
            return os;
        }

        void tinhdrl() 
        {
            int drl = 50; 
            if (this->hoatdong != "khong" && this->hoatdong != "") {
                drl += 30; 
            }
            cout << "Diem ren luyen cua SV " << this->ten << " la: " << drl << endl;
        }
};

class giadinh {
private:
    vector<hocsinh*> ds; 
    float tongtien;

public:
    giadinh() {
        this->tongtien = 0;
    }

    giadinh& operator+=(hocsinh* thanhvien) {
        this->ds.push_back(thanhvien);
        
        this->tongtien += thanhvien->gettientieu(); 
        return *this;
    }

    void in_danhsach() {
        cout << "\nDANH SACH THANH VIEN GIA DINH" << endl;
        for (int i = 0; i < ds.size(); i++) 
        {
            cout << "- " << *ds[i] << endl; 
        }
        cout << "TONG TIEN TIEU CUA GIA DINH: " << this->tongtien << endl;
    }
};

int main()
{
    
}