#include "penjualan.h"

int main() {
    adrToko listToko = NULL;
    adrBarang listBarang = NULL;

    int pilihan = -1;

    while (pilihan != 0) {
        cout << "\n===== MENU DATA PENJUALAN =====\n";
        cout << "1. Tambah Data Toko\n";
        cout << "2. Tambah Data Barang\n";
        cout << "3. Hubungkan Toko dengan Barang\n";
        cout << "4. Tampilkan Semua Toko & Barang\n";
        cout << "5. Tampilkan Barang dari Toko Tertentu\n";
        cout << "6. Tampilkan Toko yang Menjual Barang Tertentu\n";
        cout << "7. Hapus Data Toko\n";
        cout << "8. Hapus Relasi Barang pada Toko\n";
        cout << "9. Toko dengan Barang Terbanyak & Tersedikit\n";
        cout << "0. Keluar\n";
        cout << "Pilih Menu: ";
        cin >> pilihan;

        switch (pilihan) {

        case 1: {
            int id;
            string nama, alamat;
            cout << "ID Toko   : "; cin >> id;
            cout << "Nama Toko : "; cin >> nama;
            cout << "Alamat    : "; cin >> alamat;
            insertFirstToko(listToko, createToko(id, nama, alamat));
            break;
        }

        case 2: {
            int id;
            string nama;
            float harga;
            cout << "ID Barang   : "; cin >> id;
            cout << "Nama Barang : "; cin >> nama;
            cout << "Harga       : "; cin >> harga;
            insertLastBarang(listBarang, createBarang(id, nama, harga));
            break;
        }

        case 3: {
            int idToko, idBarang;
            cout << "ID Toko   : "; cin >> idToko;
            cout << "ID Barang : "; cin >> idBarang;

            adrToko T = findToko(listToko, idToko);
            adrBarang B = findBarang(listBarang, idBarang);

            if (T != NULL && B != NULL) {
                connectTokoBarang(T, B);
                cout << "Relasi berhasil ditambahkan\n";
            } else {
                cout << "Toko atau Barang tidak ditemukan\n";
            }
            break;
        }

        case 4:
            showTokoWithBarang(listToko);
            break;

        case 5: {
            int id;
            cout << "ID Toko: ";
            cin >> id;
            adrToko T = findToko(listToko, id);
            if (T != NULL)
                showBarangTokoTertentu(T);
            else
                cout << "Toko tidak ditemukan\n";
            break;
        }

        case 6: {
            int id;
            cout << "ID Barang: ";
            cin >> id;
            showTokoMenjualBarang(listToko, id);
            break;
        }

        case 7: {
            int id;
            cout << "ID Toko yang dihapus: ";
            cin >> id;
            deleteTokoBesertaRelasi(listToko, id);
            break;
        }

        case 8: {
            int idToko, idBarang;
            cout << "ID Toko   : "; cin >> idToko;
            cout << "ID Barang : "; cin >> idBarang;
            adrToko T = findToko(listToko, idToko);
            if (T != NULL)
                deleteRelasiBarang(T, idBarang);
            else
                cout << "Toko tidak ditemukan\n";
            break;
        }

        case 9:
            showTokoTerbanyakTersedikit(listToko);
            break;

        case 0:
            cout << "Program selesai.\n";
            break;

        default:
            cout << "Menu tidak valid!\n";
        }
    }

    return 0;
}