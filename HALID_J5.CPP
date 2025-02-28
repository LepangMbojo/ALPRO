#include <iostream>
using namespace std;

int jumlah;
bool isLepas = false;
char gerbong_dilepas;

int jumlah_gerbong_dilepas = 0;
bool gerbongDilepas = false;

void header() {
    system("cls");
    cout << "  /\\_/\\   PT KAP (KERETA API PROGRAMMER)" << endl
         << " ( o.o )  PROGRAM SISTEM TIKET DAN GERBONG KERETA" << endl
         << "  > ^ <   DIBUAT OLEH PJ MODUL 5 ALPRO 2024" << endl
         << "=================================================" << endl;
}

struct Penumpang { 
    string nama; 
};

struct Gerbong {
    char id;
    string kelas;
    Penumpang penumpang[100];
    int jumlahPenumpang;
};

Gerbong gerbong_dilepas_array[100];
Gerbong kereta[100];


string dapatkanKelasGerbong(int indeks) {
    return (indeks % 6 == 1) ? "EKO" : (indeks % 6 == 2) ? "BISNIS" : "RAJA";
}

void inisialisasiGerbong(int a) {
    for (int i = 0; i <= a; ++i) {
        kereta[i].id = 'A' + i;
        kereta[i].jumlahPenumpang = 0;
        kereta[i].kelas = (i == 0) ? "mesin" : dapatkanKelasGerbong(i);
    }
}

void tampilkanGerbong() {
    header();
    for (int i = 0; i <= jumlah; ++i) {
        cout << kereta[i].id;
        if (i > 0) cout << kereta[i].jumlahPenumpang;
        if (i < jumlah) cout << "-";
    }
    if (isLepas) {
        cout << "- X --";
        for (int j = 0; j < jumlah_gerbong_dilepas; ++j) {
            cout << char(gerbong_dilepas + j);
            if (j != jumlah_gerbong_dilepas - 1) cout << "-";
        }
    }
    cout << endl;
}

void menu() {
    header();
    tampilkanGerbong();
    if (gerbongDilepas == false) {
        cout << "menu:" << endl
             << "1. Tambah Penumpang" << endl
             << "2. Hapus Penumpang"  << endl
             << "3. Info Gerbong" << endl
             << "4. Lepas Gerbong" << endl
             << "Input (1,2,3,4): ";
    }
    else {
        cout << "menu:" << endl
             << "1. Tambah Penumpang" << endl
             << "2. Hapus Penumpang"  << endl
             << "3. Info Gerbong" << endl
             << "Input (1,2,3): ";
    }
}

void tambahPenumpang() {
    tampilkanGerbong();
    string namaPenumpang, kelasGerbong;
    cout << "Masukkan nama penumpang: ";
    cin >> namaPenumpang;
    do {
        cout << "Pilih kelas tiket (EKO, BISNIS, RAJA): ";
        cin >> kelasGerbong;
    } while (kelasGerbong != "EKO" && kelasGerbong != "BISNIS" && kelasGerbong != "RAJA");

    int pilihanGerbong[100], jumlahPilihan = 0;
    for (int i = 1; i <= jumlah; ++i) {
        if (kereta[i].kelas == kelasGerbong)
            pilihanGerbong[jumlahPilihan++] = i;
    }
    while (jumlahPilihan < 1) {
        cout << "Gerbong kelas " << kelasGerbong << " yang tersedia: TIDAK ADA" << endl
             << "Harap pilih kelas lainnya!" << endl;
        cout << "Pilih kelas tiket (EKO, BISNIS, RAJA): ";
        cin >> kelasGerbong;
        jumlahPilihan = 0;
        for (int i = 1; i <= jumlah; ++i) {
        if (kereta[i].kelas == kelasGerbong)
            pilihanGerbong[jumlahPilihan++] = i;
        }
    }

    cout << "Gerbong kelas " << kelasGerbong << " yang tersedia: ";
    for (int i = 0; i < jumlahPilihan; ++i) {
        cout << kereta[pilihanGerbong[i]].id << " ";
    }
    cout << endl;

    char pilihGerbong;
    bool valid = false;
    while (!valid) {
        cout << "Pilih lokasi gerbong: ";
        cin >> pilihGerbong;
        for (int i = 0; i < jumlahPilihan; ++i) {
            if (kereta[pilihanGerbong[i]].id == pilihGerbong) {
                kereta[pilihanGerbong[i]].penumpang[kereta[pilihanGerbong[i]].jumlahPenumpang++].nama = namaPenumpang;
                valid = true;
                break;
            }
        }
        if (pilihGerbong == 'A')
            cout << "Tidak bisa memilih gerbong mesin, harap pilih gerbong lainnya" << endl;
        else if (!valid) 
            cout << "Tidak bisa memilih gerbong " << pilihGerbong << " karena kelas gerbong tersebut bukanlah " << kelasGerbong << endl;
    }
    system("pause");
}

void hapusPenumpang() {
    tampilkanGerbong();
    string namaPenumpang, kelasGerbong;
    cout << "Masukkan nama penumpang yang ingin dihapus dari daftar: ";
    cin >> namaPenumpang;
    cout << "Masukkan kelas tiket yang dimiliki (EKO, BISNIS, RAJA): ";
    cin >> kelasGerbong;

    while (kelasGerbong != "EKO" && kelasGerbong != "BISNIS" && kelasGerbong != "RAJA") {
        cout << "Harap masukkan kelas tiket EKO, BISNIS, atau RAJA" << endl
             << "Masukkan kelas tiket yang dimiliki (EKO, BISNIS, RAJA): ";
        cin >> kelasGerbong;
    }

    int posisiPenumpang[10][2], jumlahPosisi = 0;

    for (int i = 1; i <= jumlah; ++i) {
        if (kereta[i].kelas == kelasGerbong) {
            for (int j = 0; j < kereta[i].jumlahPenumpang; ++j) {
                if (kereta[i].penumpang[j].nama == namaPenumpang) {
                    posisiPenumpang[jumlahPosisi][0] = i;
                    posisiPenumpang[jumlahPosisi][1] = j;
                    jumlahPosisi++;
                }
            }
        }
    }

    if (jumlahPosisi > 0) {
        cout << "Penumpang ditemukan!" << endl;
        for (int i = 0; i < jumlahPosisi; ++i) {
            cout << i + 1 << ". " << namaPenumpang << " (" << kelasGerbong << ") di Gerbong " << kereta[posisiPenumpang[i][0]].id << endl;
        }
        int pilihanHapus;
        cout << "Ingin Menghapus penumpang nomor berapa: ";
        cin >> pilihanHapus;
        while (pilihanHapus < 1 || pilihanHapus > jumlahPosisi) {
            cout << "Pilihan tidak valid!" << endl
                 << "Ingin Menghapus penumpang nomor berapa: ";
            cin >> pilihanHapus;
        }

        int gerbongIndex = posisiPenumpang[pilihanHapus - 1][0];
        int penumpangIndex = posisiPenumpang[pilihanHapus - 1][1];
        for (int i = penumpangIndex; i < kereta[gerbongIndex].jumlahPenumpang - 1; ++i) {
            kereta[gerbongIndex].penumpang[i] = kereta[gerbongIndex].penumpang[i + 1];
        }
        kereta[gerbongIndex].jumlahPenumpang--;
        cout << "Penumpang berhasil dihapus!" << endl;
    }
    else
        cout << "Tidak ditemukan penumpang dengan nama " << namaPenumpang << " di kelas " << kelasGerbong << endl
             << "Coba cari lagi dengan data lain!" << endl;
    system("pause");
}

void infoGerbong() {
    header();
    tampilkanGerbong();
    int jumlahEko = 0, jumlahBisnis = 0, jumlahRaja = 0;
    for (int i = 1; i <= jumlah; ++i) {
        if (kereta[i].kelas == "EKO") jumlahEko += kereta[i].jumlahPenumpang;
        else if (kereta[i].kelas == "BISNIS") jumlahBisnis += kereta[i].jumlahPenumpang;
        else if (kereta[i].kelas == "RAJA") jumlahRaja += kereta[i].jumlahPenumpang;
    }
    cout << "Jumlah penumpang EKO: " << jumlahEko << " BISNIS: " << jumlahBisnis << " RAJA: " << jumlahRaja << endl;

    for (int i = 1; i <= jumlah; ++i) {
        cout << "Gerbong " << kereta[i].id << " (" << kereta[i].kelas << "):" << endl;
        if (kereta[i].jumlahPenumpang == 0) cout << "Kosong" << endl;
        else for (int j = 0; j < kereta[i].jumlahPenumpang; ++j)
            cout << j + 1 << ". " << kereta[i].penumpang[j].nama << endl;
    }
    system("pause");
}

void lepasGerbong() {
    if (gerbongDilepas == true)
        return;
    else if (jumlah > 1) {
    char pilihan_gerbong;
    cout << "Masukkan nama gerbong yang ingin dilepas: ";
    cin >> pilihan_gerbong;

    int nomor_gerbong = pilihan_gerbong - 'A';
    while (nomor_gerbong < 1 || nomor_gerbong >= jumlah) {
        cout << "Tidak bisa melepas gerbong A yang berisi mesin!" << endl
             << "Masukkan nama gerbong yang ingin dilepas: ";
        cin >> pilihan_gerbong;
        nomor_gerbong = pilihan_gerbong - 'A';
    }
    gerbong_dilepas = pilihan_gerbong;
    isLepas = true;
    jumlah_gerbong_dilepas = 0;
    for (int i = nomor_gerbong; i <= jumlah; ++i)
        gerbong_dilepas_array[jumlah_gerbong_dilepas++] = kereta[i];
    jumlah = nomor_gerbong - 1;
    gerbongDilepas = true;
    }
    else
        cout << "Tidak ada gerbong yang bisa dilepas." << endl;
    system("pause");
}

int main() {
    int pilihan;
    header();
    cout << "Masukkan jumlah gerbong kereta penumpang: ";
    cin >> jumlah;
    inisialisasiGerbong(jumlah);

    while (true) {
        menu();
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahPenumpang();
                break;
            case 2:
                hapusPenumpang();
                break;
            case 3:
                infoGerbong();
                break;
            case 4:
                lepasGerbong();
                break;
            default:
                break;
        }
    }

    return 0;
}