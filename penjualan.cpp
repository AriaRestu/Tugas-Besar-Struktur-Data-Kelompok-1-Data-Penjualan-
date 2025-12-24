#include "penjualan.h"

adrToko createToko(int id, string nama, string alamat) {
    adrToko T = new Toko{id, nama, alamat, NULL, NULL};
    return T;
}

adrBarang createBarang(int id, string nama, float harga) {
    adrBarang B = new Barang{id, nama, harga, NULL};
    return B;
}

adrRelasi createRelasi(adrBarang B) {
    adrRelasi R = new Relasi{B, NULL};
    return R;
}

void insertFirstToko(adrToko &first, adrToko T) {
    T->next = first;
    first = T;
}

void insertLastBarang(adrBarang &first, adrBarang B) {
    if (!first) first = B;
    else {
        adrBarang p = first;
        while (p->next) p = p->next;
        p->next = B;
    }
}

void deleteTokoBesertaRelasi(adrToko &first, int id) {
    adrToko p = first, prev = NULL;
    while (p && p->idToko != id) {
        prev = p;
        p = p->next;
    }
    if (!p) return;

    while (p->firstRelasi) {
        adrRelasi r = p->firstRelasi;
        p->firstRelasi = r->next;
        delete r;
    }

    if (!prev) first = p->next;
    else prev->next = p->next;

    delete p;
}

void deleteFirstBarang(adrBarang &first) {
    if (!first) return;
    adrBarang p = first;
    first = p->next;
    delete p;
}

adrToko findToko(adrToko first, int id) {
    while (first) {
        if (first->idToko == id) return first;
        first = first->next;
    }
    return NULL;
}

adrBarang findBarang(adrBarang first, int id) {
    while (first) {
        if (first->idBarang == id) return first;
        first = first->next;
    }
    return NULL;
}

void connectTokoBarang(adrToko T, adrBarang B) {
    if (!T || !B) return;
    adrRelasi R = createRelasi(B);
    R->next = T->firstRelasi;
    T->firstRelasi = R;
}

void deleteRelasiBarang(adrToko T, int idBarang) {
    adrRelasi p = T->firstRelasi, prev = NULL;
    while (p && p->ptrBarang->idBarang != idBarang) {
        prev = p;
        p = p->next;
    }
    if (!p) return;
    if (!prev) T->firstRelasi = p->next;
    else prev->next = p->next;
    delete p;
}

void showAllToko(adrToko first) {
    while (first) {
        cout << first->idToko << " - " << first->namaToko << endl;
        first = first->next;
    }
}

void showAllBarang(adrBarang first) {
    while (first) {
        cout << first->idBarang << " - " << first->namaBarang << endl;
        first = first->next;
    }
}

void showTokoWithBarang(adrToko first) {
    while (first) {
        cout << "\nToko: " << first->namaToko << endl;
        adrRelasi r = first->firstRelasi;
        while (r) {
            cout << "- " << r->ptrBarang->namaBarang << endl;
            r = r->next;
        }
        first = first->next;
    }
}

void showBarangTokoTertentu(adrToko T) {
    adrRelasi r = T->firstRelasi;
    while (r) {
        cout << r->ptrBarang->namaBarang << endl;
        r = r->next;
    }
}

void showTokoMenjualBarang(adrToko first, int idBarang) {
    while (first) {
        adrRelasi r = first->firstRelasi;
        while (r) {
            if (r->ptrBarang->idBarang == idBarang) {
                cout << first->namaToko << endl;
                break;
            }
            r = r->next;
        }
        first = first->next;
    }
}

int countBarangToko(adrToko T) {
    int count = 0;
    adrRelasi r = T->firstRelasi;
    while (r) {
        count++;
        r = r->next;
    }
    return count;
}

void showTokoTerbanyakTersedikit(adrToko first) {
    adrToko max = first, min = first;
    while (first) {
        if (countBarangToko(first) > countBarangToko(max)) max = first;
        if (countBarangToko(first) < countBarangToko(min)) min = first;
        first = first->next;
    }
    cout << "Terbanyak: " << max->namaToko << endl;
    cout << "Tersedikit: " << min->namaToko << endl;
}