#include <iostream>
using namespace std;

int main()
{
    string nama, nim;
    char opsi;
    int pilihan, waktu, detik, thr;

    cout << "------------------------------------------" << endl;
    cout << "|     THR DARI HOLIL UNTUK SEMUA ^_^     |" << endl;
    cout << "------------------------------------------" << endl;
    cout << "Masukkan Nama\t: ";
    cin >> ws;
    getline(cin, nama);
    cout << "Masukkan NIM\t: ";
    cin >> nim;

cout << "------------------------------------------" << endl;
cout << "Yoo!!! " << nama << ", Kamu Tipe Mahasiswa Seperti Apa?" << endl;
cout << "1. Mahasiswa Kupu-kupu" << endl;
cout << "2. Mahasiswa Kura-kura" << endl;
cout << "3. Mahasiswa Kuda-kuda" << endl;
cout << "Masukkan pilihan kamu!: ";
cin >> pilihan;

while (pilihan < 1 || pilihan > 3)
{
cout << "Input Tidak Valid!" << endl;
cout << "Yoo!!! " << nama << ", Kamu Tipe Mahasiswa Seperti Apa?" << endl;
cout << "1. Mahasiswa Kupu-Kupu" << endl;
cout << "2. Mahasiswa Kura-Kura" << endl;
cout << "3. Mahasiswa Kuda-kuda" << endl;
cout << "Masukkan pilihan kamu!: ";
cin >> pilihan;
}

switch (pilihan)
{
case 1:
system("cls");

cout << "------------------------------------------" << endl;
cout << "Selamat datang " << nama << " - Mahasiswa Kuliah-Pulang" << endl;
cout << "Santai banget ya kamu :) " << endl;
thr = 500000;
break;
    case 2:
        system("cls");

        cout << "------------------------------------------" << endl;
        cout << "Selamat datang " << nama << " - Mahasiswa Kuliah-Rapat" << endl;
        cout << "Kasian banget ya kamu :)" << endl;
        thr = 850000;
        break;
    case 3:
        system("cls");

        cout << "------------------------------------------" << endl;
        cout << "Selamat datang " << nama << " - Mahasiswa Kuliah-Dagang" << endl;
        cout << "Semangat ya buat kamu :)" << endl;
        thr = 1000000;
        break;
    }

    cout << "------------------------------------------" << endl;
    cout << "Berapa Jam Waktu Kuliahmu Ramadhan Ini? ";
    cin >> waktu;

    while (waktu < 0)
    {
        cout << "Input Tidak Valid!" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Berapa Jam Waktu Kuliah Ramadhan Ini? ";
        cin >> waktu;
    }

    cout << "------------------------------------------" << endl;
    cout << "THR buat kamu sebesar   \t:Rp." << thr << endl;
    cout << "Durasi Kuliah Minggu ini\t:" << (waktu * 3600) << " Detik" << endl;
    cout << "------------------------------------------" << endl;

    cout << "Apakah Kamu Pernah Kuliah Sampai Malam? (Y/N): ";
    cin >> opsi;

    while (opsi != 'Y' && opsi != 'N')
    {
        cout << "Input Tidak Valid!" << endl;
        cout << "Apakah Kamu Pernah Kuliah Sampai Malam? (Y/N): ";
        cin >> opsi;
    }

    if (opsi == 'Y')
    {
        system("cls");

        cout << "Kamu Memang Rajin !!!\nHolil Ingin Memberimu Lebih Banyak THR\nMasukkan Total Waktu Kuliah Malam Kamu (Detik): ";
        cin >> detik;

        while (detik < 0)
        {
            cout << "Input Tidak Valid!" << endl;
            cout << "Masukkan Total Waktu Kuliah Malam Kamu (Detik): ";
            cin >> detik;
        }

        if (detik >= 3600 && detik <= 7200)
            thr += 200000;
        else if (detik > 7200 && detik <= 10800)
            thr += 500000;
        else if (detik > 10800)
            thr *= 2;

        cout << "------------------------------------------" << endl;
        cout << "Total THR " << nama << " Ramadhan ini \t: Rp." << thr << endl;
        cout << "Durasi Kuliah Ramadhan ini\t: " << (waktu + (detik / 3600)) << " Jam, " << ((detik % 3600) / 60) << " Menit, " << detik % 60 << " Detik " << endl;
        cout << "------------------------------------------" << endl;
    }
    else if (opsi == 'N')
    {
        cout << "------------------------------------------" << endl;
        cout << "Total THR " << nama << " Ramadhan ini \t: Rp." << thr << endl;
        cout << "Durasi Kuliah Ramadhan ini\t: " << waktu << " Jam, " << ((waktu % 1) * 60) << " Menit, " << (((waktu % 1) * 60) * 60) << " Detik " << endl;
        cout << "------------------------------------------" << endl;
    }
    system("pause");
    return 0;
}
