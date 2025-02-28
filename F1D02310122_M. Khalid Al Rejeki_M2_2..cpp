#include <iostream>
#include <conio.h> // Untuk _getch() pada Windows

using namespace std;

int main()
{
    int pilihan = 1;
    bool selesai = false;
    // string ungu = "\033[1;35m";
    string ungu = "\033[35m";
    string putih = "\033[0m";

    // Hapus pesan sebelumnya

    while (!selesai)
    {
        system("cls");

        // Tampilkan pilihan motif dengan opsi yang dipilih diberi penyorotan warna hijau
        cout << putih << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << putih << "|       MOTIF BAJU        |" << endl;
        cout << putih << "|          HOLIL          |" << endl;
        cout << putih << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << (pilihan == 1 ? ungu : putih) << "|~~~~~~~~~~~~~~~~~~~~~~~~~|" << putih << endl;
        cout << (pilihan == 1 ? ungu : putih) << "|       BANGUN DATAR      |" << putih << endl;
        cout << (pilihan == 1 ? ungu : putih) << "|~~~~~~~~~~~~~~~~~~~~~~~~~|" << putih << endl;
        cout << (pilihan == 2 ? ungu : putih) << "|~~~~~~~~~~~~~~~~~~~~~~~~~|" << putih << endl;
        cout << (pilihan == 2 ? ungu : putih) << "|       POHON CEMARA      |" << putih << endl;
        cout << (pilihan == 2 ? ungu : putih) << "|~~~~~~~~~~~~~~~~~~~~~~~~~|" << putih << endl;
        cout << (pilihan == 3 ? ungu : putih) << "|~~~~~~~~~~~~~~~~~~~~~~~~~|" << putih << endl;
        cout << (pilihan == 3 ? ungu : putih) << "|       POLA BILANGAN     |" << putih << endl;
        cout << (pilihan == 3 ? ungu : putih) << "|~~~~~~~~~~~~~~~~~~~~~~~~~|" << putih << endl;
        cout << (pilihan == 4 ? ungu : putih) << "|~~~~~~~~~~~~~~~~~~~~~~~~~|" << putih << endl;
        cout << (pilihan == 4 ? ungu : putih) << "|          KELUAR         |" << putih << endl;
        cout << (pilihan == 4 ? ungu : putih) << "|~~~~~~~~~~~~~~~~~~~~~~~~~|" << putih << endl;

        // Ambil input tombol tanpa menunggu tombol Enter
        char tombol;
        tombol = _getch();

        switch (tombol)
        {
        case 'w':
        case 'W':
        case 72: // Panah atas
            pilihan = (pilihan == 1) ? 4 : pilihan - 1;
            break;
        case 's':
        case 'S':
        case 80: // Panah bawah
            pilihan = (pilihan == 4) ? 1 : pilihan + 1;
            break;
        case 13: // Tombol Enter untuk memilih
            selesai = true;
            switch (pilihan)
            {
            case 1:
                    
                int ukuran, mulai;
                char huruf;
                mulai = 1;
                cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
                cout << "|          MOTIF          |" << endl;
                cout << "|      BANGUN DATAR       |" << endl;
                cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
                cout << "        POLA PERSEGI :)          " << endl;
                cout << "    MASUKAN JUMLAH BARIS : ";
                cin >> ukuran;

                while (ukuran < 1)
                {

                    cout << "Input Tidak Valid!\nPola Persegi :)\nMasukkan Jumlah Baris: ";
                    cin >> ukuran;
                }

                for (int i = 1; i <= ukuran; ++i)
                {

                    for (int j = 1; j <= ukuran; ++j)
                    {
                        cout << (char)('A' + min(i - 1, j - 1));
                        cout << " ";
                    }
                    cout << endl;
                }
                cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
                cout << "        POLA SEGITIGA :|            " << endl;
                cout << "     MASUKAN JUMLAH BARIS : ";
                cin >> ukuran;
                while (ukuran < 1)
                {

                    cout << " Input Tidak Valid!\nPola segitiga :|\nMasukkan Jumlah Baris: ";
                    cin >> ukuran;
                }
                if (ukuran % 2 == 0)
                {
                    huruf = 'A';
                }
                else
                {
                    huruf = 'B';
                }
                for (int i = 1; i <= ukuran; ++i)
                {

                    for (int o = ukuran; o > i; o--)
                    {
                        cout << " ";
                    }
                    for (int j = 1; j <= i; ++j)
                    {
                        if (i % 2 == 1)
                        {
                            cout << huruf << " ";
                        }
                        else if (huruf % 2 == 1)
                        {
                            cout << i - 1 << " ";
                        }
                        else
                        {
                            cout << i << " ";
                        }
                    }
                    if (i % 2 == 1)
                    {
                        huruf++;
                    }
                    cout << endl;
                }

                cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
                cout << "     POLA PERSEGI LAGI :(   " << endl;
                cout << "   MASUKAN JUMLAH BARIS : ";
                cin >> ukuran;
                while (ukuran < 1)
                {
                    cout << " Input Tidak Valid!\nPola Persegi lagi :(\nMasukkan Jumlah Baris: ";
                    cin >> ukuran;
                }

                for (int i = 0; i < ukuran; i++)
                {

                    if (i % 2 == 0)
                    {
                        for (int j = 0; j < ukuran; j++)
                        {
                            if (mulai < 10)
                            {
                                cout << "0";
                            }
                            cout << mulai++ << " ";
                        }
                    }
                    else
                    {
                        int c = mulai + ukuran - 1;
                        for (int j = 0; j < ukuran; j++)
                        {
                            if (c < 10)
                            {
                                cout << "0";
                            }
                            // cout<< "0";
                            cout << c-- << " ";
                        }
                        mulai += ukuran;
                    }
                    cout << endl;
                }
                cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
                break;
            case 2:
                system("cls");
                int tinggi, lebar, tambah;
                tambah = 1;
                system("cls");
                cout << "Masukkan Angka Yang Valid !" << endl;
                cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
                cout << "|          MOTIF          |" << endl;
                cout << "|       POHON CEMARA      |" << endl;
                cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
                cout << "       MASUKAN TINGGI : ";
                cin >> tinggi;

                while (tinggi < 1)
                {

                    cout << " Input Tidak Valid!\n  \nMasukkan Jumlah tinggi: ";
                    cin >> tinggi;
                }
                cout << "       MASUKAN LEBAR  : ";
                cin >> lebar;
                while (lebar < 1)
                {
                    cout << " Input Tidak Valid!\n \nMasukkan Jumlah lebar: ";
                    cin >> lebar;
                }
                system("cls");
                // untuk segitiga nya
                for (int m = 1; m <= tinggi; m++)
                {
                    for (int i = tambah; i <= lebar; i++)
                    {
                        for (int j = tinggi * 5; j >= i; j--)
                        {
                            cout << " ";
                        }
                        for (int k = 1; k <= i; k++)
                        {
                            cout << "* ";
                        }
                        cout << "\n";
                    }
                    tambah = tambah + 2;
                    lebar = lebar + 2;
                }
                // Untuk Pohon nya
                for (int i = 1; i <= 4; ++i)
                {
                    // spasi
                    for (int j = (tinggi * 5) - 3; j >= 1; --j)
                    {
                        cout << " ";
                    }
                    for (int k = 1; k <= 4; ++k)
                    {
                        cout << "* ";
                    }
                    cout << endl;
                }
                cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
                break;
            case 3:
                system("cls");
                int angka, bil;
                cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
                cout << "|          MOTIF          |" << endl;
                cout << "|      POLA BILANGAN      |" << endl;
                cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
                bil = 1;
                cout << "Masukkan Angka / Nilai : ";
                cin >> angka;
                // Jika Angka yang dimasukkan bukan angka positif / 0
                while (angka < 1)
                {
                    cout << " Input Tidak Valid!\n \nMasukkan Jumlah angka: ";
                    cin >> angka;
                }

                // cek jika angka yang dimasukkan adalah genap / ganjil
                // ganjil
                if (angka % 2 != 0)
                {
                    for (int i = 1; i <= angka; i++)
                    {
                        cout << bil;
                        cout << (i != angka ? " , " : " ");
                        bil *= 11;
                    }
                }
                else if (angka % 2 == 0 && angka <= 50)
                {
                    for (int i = 1; i <= angka; ++i)
                    {
                        int count = 0;
                        for (int j = 2; j * j <= i; ++j)
                        {
                            if (i % j == 0)
                            {
                                count++;
                                break;
                            }
                        }
                        if (count == 0)
                        {
                            if ((i % 10 == 3 || (i >= 30 && i <= 39)))
                            {
                                cout << "(" << i << "*n = " << (i * angka) << ") ";
                            }
                            else
                            {
                                cout << "<" << i << "> ";
                            }
                        }
                    }
                }
                else
                {
                    for (int i = 1; i <= angka; ++i)
                    {
                        int count = 0;
                        for (int j = 2; j * j <= i; ++j)
                        {
                            if (i % j == 0)
                            {
                                count++;
                                break;
                            }
                        }
                        if (count == 0)
                            cout << "<" << i << "> ";
                    }
                }

                break;
            case 4:
                char konfirmasi;
                cout << "Anda Memilih Untuk Keluar , Apakah Anda Yakin (Y/N) : ";
                cin >> konfirmasi;
                if (konfirmasi == 'Y' || konfirmasi == 'y')
                {
                    system("cls");
                    return 0;
                }
                else
                {
                    return main();
                }
                break;
            }

            break;
        }
    }
    system("pause");
    return 0;
}
