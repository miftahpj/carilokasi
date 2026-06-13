#include <iostream>
using namespace std;

int main(){
    string nama, alamat, karir;
    int usia;

    cout << "==== INPUT DATA ====\n";
    cout << "Masukan Nama : ";
    getline(cin, nama);

    cout << "Masukan Alamat : ";
    getline(cin, alamat);

    cout << "Masukan Karir : ";
    getline(cin, karir);

    cout << "Masukan Usia : ";
    cin >> usia;

    cin.ignore();
    
    cout << endl;

    cout << "==== TAMPIL DATA ====\n";
    cout << "Nama      : " << nama << endl;
    cout << "Alamat    : " << alamat << endl;
    cout << "Karir     : " << karir << endl;
    cout << "Usia      : " << usia << endl;
}