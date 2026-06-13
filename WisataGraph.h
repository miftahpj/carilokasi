#ifndef WISATAGRAPH_H
#define WISATAGRAPH_H
#include <string>

struct Jalur {
    int id_tujuan;
    int jarak_meter;
    Jalur* next;
};

struct Destinasi {
    int id;
    std::string nama_tempat;
    Jalur* head_jalur; 
};

class WisataGraph {
private:
    Destinasi** daftar_destinasi; 
    int total_titik;

public:
    WisataGraph(int max_titik);
    ~WisataGraph();
    void tambahDestinasi(int id, std::string nama);
    void tambahRute(int asal, int tujuan, int jarak);
    Destinasi* getDestinasi(int id);
    int getTotalTitik();
};

#endif
