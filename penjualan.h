#ifndef PENJUALAN_H
#define PENJUALAN_H

#include <iostream>
#include <string>
using namespace std;

struct Barang {
    int idBarang;
    string namaBarang;
    float harga;
    Barang* next;
};

struct Relasi {
    Barang* ptrBarang;
    Relasi* next;
};

struct Toko {
    int idToko;
    string namaToko;
    string alamat;
    Toko* next;
    Relasi* firstRelasi;
};

typedef Toko* adrToko;
typedef Barang* adrBarang;
typedef Relasi* adrRelasi;

adrToko createToko(int, string, string);
adrBarang createBarang(int, string, float);
adrRelasi createRelasi(adrBarang);

void insertFirstToko(adrToko&, adrToko);
void insertLastBarang(adrBarang&, adrBarang);

void deleteTokoBesertaRelasi(adrToko&, int);
void deleteFirstBarang(adrBarang&);

adrToko findToko(adrToko, int);
adrBarang findBarang(adrBarang, int);

void connectTokoBarang(adrToko, adrBarang);
void deleteRelasiBarang(adrToko, int);

void showAllToko(adrToko);
void showAllBarang(adrBarang);
void showTokoWithBarang(adrToko);
void showBarangTokoTertentu(adrToko);
void showTokoMenjualBarang(adrToko, int);

int countBarangToko(adrToko);
void showTokoTerbanyakTersedikit(adrToko);

#endif