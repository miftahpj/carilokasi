#include "Navigasi.h"
#include <iostream>
#include <climits>
#include <cstddef>

void cariRuteWisata(WisataGraph& peta, int titik_awal, int titik_tujuan) {
    int V = peta.getTotalTitik();
    
    int* jarak = new int[V + 1];
    bool* dikunjungi = new bool[V + 1];
    int* jejak = new int[V + 1];

    for(int i = 1; i <= V; i++) {
        jarak[i] = INT_MAX;
        dikunjungi[i] = false;
        jejak[i] = -1; 
    }

    jarak[titik_awal] = 0;

    for(int i = 1; i <= V - 1; i++) {
        int min_jarak = INT_MAX, node_sekarang = -1;
        
        for(int v = 1; v <= V; v++) {
            if(!dikunjungi[v] && jarak[v] <= min_jarak) {
                min_jarak = jarak[v];
                node_sekarang = v;
            }
        }
        
        if (node_sekarang == -1) break;
        dikunjungi[node_sekarang] = true;

        Destinasi* u = peta.getDestinasi(node_sekarang);
        if(u != NULL) {
            Jalur* rute = u->head_jalur;
            while(rute != NULL) {
                int v = rute->id_tujuan;
                if(!dikunjungi[v] && jarak[node_sekarang] != INT_MAX && 
                   jarak[node_sekarang] + rute->jarak_meter < jarak[v]) {
                    jarak[v] = jarak[node_sekarang] + rute->jarak_meter;
                    jejak[v] = node_sekarang;
                }
                rute = rute->next;
            }
        }
    }

    if(jarak[titik_tujuan] == INT_MAX) {
        std::cout << "\n[!] Rute tidak dapat diakses!\n";
    } else {
        std::cout << "\n=========================================\n";
        std::cout << "Estimasi Jarak Tempuh : " << jarak[titik_tujuan] << " meter\n";
        std::cout << "Panduan Rute          : ";
        
        int posisi = titik_tujuan;
        int urutan_rute[100]; 
        int indeks = 0;
        
        while(posisi != -1) {
            urutan_rute[indeks++] = posisi;
            posisi = jejak[posisi];
        }
        
        for(int i = indeks - 1; i >= 0; i--) {
            std::cout << peta.getDestinasi(urutan_rute[i])->nama_tempat;
            if(i > 0) std::cout << " -> ";
        }
        std::cout << "\n=========================================\n";
    }

    delete[] jarak;
    delete[] dikunjungi;
    delete[] jejak;
}
