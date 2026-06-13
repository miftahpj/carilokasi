#include <iostream>
#include "WisataGraph.h"
#include "Navigasi.h"

using namespace std;

int main() {
    WisataGraph petaTasik(5);

    petaTasik.tambahDestinasi(1, "Alun-Alun Tasikmalaya");
    petaTasik.tambahDestinasi(2, "Masjid Agung Tasikmalaya");
    petaTasik.tambahDestinasi(3, "Situ Gede");
    petaTasik.tambahDestinasi(4, "Terminal Indihiang");
    petaTasik.tambahDestinasi(5, "Sentra Kerajinan Rajapolah");

    petaTasik.tambahRute(1, 2, 500);   
    petaTasik.tambahRute(1, 3, 4500);  
    petaTasik.tambahRute(2, 4, 6000);  
    petaTasik.tambahRute(3, 4, 5000);  
    petaTasik.tambahRute(4, 5, 8000);  

    int lokasi_awal, lokasi_tujuan;
    
    cout << "=== SISTEM NAVIGASI PARIWISATA TASIKMALAYA ===\n\n";
    cout << "Daftar Destinasi & Titik Penting:\n";
    for(int i = 1; i <= petaTasik.getTotalTitik(); i++) {
        cout << "[" << i << "] " << petaTasik.getDestinasi(i)->nama_tempat << "\n";
    }
    
    cout << "\nMasukkan Angka Lokasi Anda Saat Ini : ";
    cin >> lokasi_awal;
    cout << "Masukkan Angka Destinasi Tujuan     : ";
    cin >> lokasi_tujuan;

    if(lokasi_awal < 1 || lokasi_awal > petaTasik.getTotalTitik() || 
       lokasi_tujuan < 1 || lokasi_tujuan > petaTasik.getTotalTitik()) {
        cout << "\n[!] Kode lokasi tidak dikenali program!\n";
        return 1;
    }

    cout << "\nMengkalkulasi rute terbaik untuk perjalanan Anda...";
    
    cariRuteWisata(petaTasik, lokasi_awal, lokasi_tujuan);

    return 0; 
}
