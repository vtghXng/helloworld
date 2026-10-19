#include<bits/stdc++.h>
using namespace std ;

class tk 
{
    protected:
        string matk;
        string tentk;
        int sodu;
    public:
        tk( string matk1 = "" , string tentk1 = "" , int sodu1 = 0 )
        {
            matk1 = matk ; 
            tentk1 = tentk ; 
            sodu = sodu1 ;
        }

        virtual ~tk(){};

        virtual void nhap()
        {
            cout << "Nhap Ma Tk" << endl ;
            getline(cin,matk);cin.ignore();
            cout << "Nhap Ten TK" << endl;
            getline(cin,tentk);cin.ignore();
            cout << "Nhap so du" <<endl;   
        }

        virtual void naptien(double sotien)
        {
            if( sotien > 0 )
            {
                sodu += sotien ;
                    cout << "Da nap " << sotien << " vao tai khoan. So du hien tai: " << sodu << endl;
            } 
            else 
            {
                cout << "So tien nap phai lon hon 0!" << endl;
            }
        }

        virtual void ruttien(double soTien) = 0;

        virtual void xuat() {
            cout << "Ma TK: " << matk << " | Chu TK: " << tentk << " | So du: " << sodu << endl;
        }
    
        double getsodu() 
        {
            return sodu;
        }

        string getmatk()\
        {
            return matk;
        }
};

class tkthuong : public tk 
{
    protected:
        int phitn ;
    public:
        tkthuong( string matk1 = "" , string tentk1 = "" , int sodu1 = 0 , int ptn1 = 0 ):tk(matk1,tentk1,sodu1)
        {
            phitn = ptn1;
        }

        void nhap() override {
            tk::nhap();
            cout << "Nhap Phi thuong nien: ";
            cin >> phitn;
        }

        void ruttien(double sotien) override 
        {
            if( sotien <= 0 ) 
            {
                cout << "Khong the rut tien" ;
                return ;
            }

            if (sodu >= sotien) 
            {
                sodu -= sotien;
                cout << "Rut thanh cong " << sotien << " (TK Thuong). So du moi: " << sodu << endl;
            } 
            else 
            {
                cout << "Giao dich that bai! So du khong du de rut " << sotien << "." << endl;
            }
        };

        void xuat() override 
        {
            tk::xuat();
            cout << "Phi TN" << phitn << endl; 
        };
};

class tkvip : public tkthuong
{
    protected:
        int hanmuc ; 
    public:
        tkvip( string matk1 = "" , string tentk1 = "" , int sodu1 = 0 , int ptn1 = 0 , int hanmuc1 = 0 ):tkthuong(matk1,tentk1,sodu1,ptn1)
        {
            hanmuc = hanmuc1 ;
        }

        void nhap() override {
            tkthuong::nhap();
            cout << "Nhap Han muc thau chi: ";
            cin >> hanmuc;
        }

        void ruttien(double sotien) override
        {
            if (sotien <= 0) {
                cout << "So tien rut phai lon hon 0!" << endl;
                return;
            }

            if ((sodu + hanmuc) >= sotien) {
                sodu -= sotien; 
                cout << "Rut thanh cong " << sotien << " (TK VIP). So du moi: " << sodu << endl;
            } 
            else 
            {
                cout << "Giao dich that bai! Vuot qua han muc thau chi cho phep." << endl;
            }
        };

        void xuat() override
        {
            tkthuong::xuat();
            cout << "Han muc thau chi" << hanmuc << endl ;
        }

};

int main()
{
    vector<tk*> dstk;
    int n;

    cout << "--- NHAP DANH SACH TAI KHOAN ---" << endl;
    cout << "Nhap so luong tai khoan: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int loai;
        cout << "\nTai khoan thu " << i + 1 << ":" << endl;
        cout << "Chon loai (1 - TK Thuong, 2 - TK VIP): ";
        cin >> loai;
        
        cin.ignore(); 

        tk* tk1 = NULL;
        if (loai == 1) {
            tk1 = new tkthuong();
        } else {
            tk1 = new tkvip();
        }
        
        tk1->nhap(); 
        dstk.push_back(tk1);
    }

    cout << "\n=== DANH SACH TAI KHOAN VUA NHAP ===" << endl;
    for (int i = 0; i < dstk.size(); i++) {
        dstk[i]->xuat();
    }

    cout << "\n--- GIAO DICH RUT TIEN ---" << endl;
    string maTimKiem;
    double tienRut;
    bool timThay = false;

    cout << "Nhap Ma TK muon rut tien: ";
    cin >> ws; 
    getline(cin, maTimKiem);

    for (int i = 0; i < dstk.size(); i++) {
        if (dstk[i]->getmatk() == maTimKiem) {
            cout << "Tai khoan hien tai: "; 
            dstk[i]->xuat();
            cout << "Nhap so tien can rut: ";
            cin >> tienRut;
            
            
            dstk[i]->ruttien(tienRut); 
            
            timThay = true;
            break;
        }
    }
    if (!timThay) {
        cout << "Khong tim thay tai khoan co ma: " << maTimKiem << endl;
    }

    cout << "\n--- TAI KHOAN CO SO DU DUOI 5 TRIEU ---" << endl;
    bool coTKKem = false;
    for (int i = 0; i < dstk.size(); i++) {
        if (dstk[i]->getsodu() < 5000000) {
            dstk[i]->xuat();
            coTKKem = true;
        }
    }
    if (!coTKKem) {
        cout << "Khong co tai khoan nao so du duoi 5 trieu." << endl;
    }

    for (int i = 0; i < dstk.size(); i++) {
        delete dstk[i];
    }
    dstk.clear();

    return 0;
}