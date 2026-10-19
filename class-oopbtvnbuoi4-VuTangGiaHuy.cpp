#include <bits/stdc++.h>
using namespace std;

class NhanVien {
protected:
    string ten;
public:
    NhanVien(string tenNV) {
        ten = tenNV;
    }

    virtual ~NhanVien() {
    }

    virtual long long tinhLuong() = 0;

    virtual void xuatThongTin() {
        cout << "Ten nhan vien: " << ten << endl;
    }
};

class NhanVienFullTime : public NhanVien {
private:
    long long luongcung;
public:
    NhanVienFullTime(string tenNV, long long luongCung) : NhanVien(tenNV) {
        luongcung = luongCung;
    }

    ~NhanVienFullTime() {
    }

    long long tinhLuong() {
        return luongcung;
    }

    void xuatThongTin() {
        NhanVien::xuatThongTin();
        cout << "Loai: Full-time" << endl;
        cout << "Luong cung: " << tinhLuong() << " VND" << endl;
    }
};

class NhanVienPartTime : public NhanVien {
private:
    int giolam;
    long long luongparttime;
public:
    NhanVienPartTime(string tenNV, int soGio, long long luong1Gio) : NhanVien(tenNV) {
        giolam = soGio;
        luongparttime = luong1Gio;
    }

    ~NhanVienPartTime() {
    }

    long long tinhLuong() {
        return (long long)giolam * luongparttime;
    }

    void xuatThongTin() {
        NhanVien::xuatThongTin();
        cout << "Loai: Part-time" << endl;
        cout << "So gio lam: " << giolam << " gio" << endl;
        cout << "Tong luong: " << tinhLuong() << " VND" << endl;
    }
};

int main() {
    NhanVien* danhSach[2];

    danhSach[0] = new NhanVienFullTime("Nguyen Van A", 10000000);
    
    danhSach[1] = new NhanVienPartTime("Tran Thi B", 20, 30000);

    for (int i = 0; i < 2; i++) {
        danhSach[i]->xuatThongTin();
    }

    for (int i = 0; i < 2; i++) {
        delete danhSach[i]; 
    }

    return 0;
}