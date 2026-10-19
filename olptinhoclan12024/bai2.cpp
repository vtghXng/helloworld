#include<bits/stdc++.h>
using namespace std ;

int main(){
    string ten1 , ten2 ;

    cin >> ten1 >> ten2 ;

    if( ten1 == "Moc" || ten1 == "Thuy" || ten1 == "Tho" || ten1 == "Kim" || ten1 == "Hoa" ){
        if( ten1 == "Kim" && ten2 =="Thuy" ) cout << ten1 << " sinh " << ten2 ;
            else if( ten1 == "Kim" && ten2 == "Tho") cout << ten2 << " sinh " << ten1 ; 
                else if( ten1 == "Moc" && ten2 == "Thuy" ) cout << ten2 << " sinh " << ten1 ;
                    else if( ten1 == "Hoa" && ten2 == "Tho" ) cout << ten1 << " sinh " << ten2 ;
                        else if( ten1 == "Moc" && ten2 == "Hoa" ) cout << ten1 << " sinh " << ten2 ;
    }

    if( ten2 == "Moc" || ten2 == "Thuy" || ten2 == "Tho" || ten2 == "Kim" || ten2 == "Hoa" ){
        if( ten2 == "Kim" && ten1 =="Thuy" ) cout << ten2 << " sinh " << ten1 ;
            else if( ten2 == "Kim" && ten1 == "Tho") cout << ten1 << " sinh " << ten2 ; 
                else if( ten2 == "Moc" && ten1 == "Thuy" ) cout << ten1 << " sinh " << ten2 ;
                    else if( ten2 == "Hoa" && ten1 == "Tho" ) cout << ten2 << " sinh " << ten1 ;
                        else if( ten2 == "Moc" && ten1 == "Hoa" ) cout << ten2 << " sinh " << ten1 ;
    }

    if( ten1 == "Moc" || ten1 == "Thuy" || ten1 == "Tho" || ten1 == "Kim" || ten1 == "Hoa" ){
        if( ten1 == "Kim" && ten2 =="Moc" ) cout << ten1 << " khac " << ten2 ;
            else if( ten1 == "Kim" && ten2 == "Hoa") cout << ten2 << " khac " << ten1 ; 
                else if( ten1 == "Moc" && ten2 == "Tho" ) cout << ten1 << " khac " << ten2 ;
                    else if( ten1 == "Hoa" && ten2 == "Thuy" ) cout << ten2 << " khac " << ten1 ;
                        else if( ten1 == "Tho" && ten2 == "Thuy" ) cout << ten1 << " khac " << ten2 ;
    }

    if( ten2 == "Moc" || ten2 == "Thuy" || ten2 == "Tho" || ten2 == "Kim" || ten2 == "Hoa" ){
        if( ten2 == "Kim" && ten1 =="Moc" ) cout << ten2 << " khac " << ten1 ;
            else if( ten2 == "Kim" && ten1 == "Hoa") cout << ten1 << " khac " << ten2 ; 
                else if( ten2 == "Moc" && ten1 == "Tho" ) cout << ten2 << " khac " << ten1 ;
                    else if( ten2 == "Hoa" && ten1 == "Thuy" ) cout << ten1 << " khac " << ten2 ;
                        else if( ten2 == "Tho" && ten1 == "Thuy" ) cout << ten2 << " khac " << ten1 ;
    }
 
}