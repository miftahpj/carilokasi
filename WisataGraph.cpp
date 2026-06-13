#include "WisataGraph.h"
#include <cstddef>

WisataGraph::WisataGraph(int max_titik) {
    total_titik = max_titik;
    daftar_destinasi = new Destinasi*[total_titik + 1];
    for(int i = 0; i <= total_titik; i++) {
        daftar_destinasi[i] = NULL;
    }
}

WisataGraph::~WisataGraph() {
    for(int i = 0; i <= total_titik; i++) {
        if(daftar_destinasi[i] != NULL) {
            Jalur* current = daftar_destinasi[i]->head_jalur;
            while(current != NULL) {
                Jalur* temp = current;
                current = current->next;
                delete temp;
            }
            delete daftar_destinasi[i];
        }
    }
    delete[] daftar_destinasi;
}

void WisataGraph::tambahDestinasi(int id, std::string nama) {
    Destinasi* nodeBaru = new Destinasi;
    nodeBaru->id = id;
    nodeBaru->nama_tempat = nama;
    nodeBaru->head_jalur = NULL;
    daftar_destinasi[id] = nodeBaru;
}

void WisataGraph::tambahRute(int asal, int tujuan, int jarak) {
    Jalur* jalur1 = new Jalur{tujuan, jarak, daftar_destinasi[asal]->head_jalur};
    daftar_destinasi[asal]->head_jalur = jalur1;

    Jalur* jalur2 = new Jalur{asal, jarak, daftar_destinasi[tujuan]->head_jalur};
    daftar_destinasi[tujuan]->head_jalur = jalur2;
}

Destinasi* WisataGraph::getDestinasi(int id) {
    return daftar_destinasi[id];
}

int WisataGraph::getTotalTitik() {
    return total_titik;
}
