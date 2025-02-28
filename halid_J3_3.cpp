#include <iostream>
using namespace std;

int main()
{
    int jumlah_kembang_api, akan_meledak[26], tambah = 0, sebaran_ledakan[26];
    char abjad[26], kembang_api_abjad;
    bool meledak[26] = {false}, kembang_api_tersisa = false;

    cout << "Masukkan jumlah kembang api : ";
    cin >> jumlah_kembang_api;

    for (int j = 0; j < jumlah_kembang_api; j++)
    {
        cout << " ? ";
    }
    cout << endl;
    for (int i = 0; i < jumlah_kembang_api; i++)
    {
        abjad[i] = 'A' + i;
        cout << "[" << abjad[i] << "]";
    }
    cout << endl;

    //  luas sebaran ledakan untuk setiap kembang api
    for (int i = 0; i < jumlah_kembang_api; i++)
    {
        cin >> sebaran_ledakan[i];
    }

    cout << "Kembang api yang akan diledakkan (nama kembang api): ";
    cin >> kembang_api_abjad;

    if (kembang_api_abjad >= 'a' && kembang_api_abjad <= 'z')
    {
        kembang_api_abjad -= 32;
    }
    // inputan salah
    int posisi_ledakan = kembang_api_abjad - 'A';
    if (posisi_ledakan < 0 || posisi_ledakan >= jumlah_kembang_api)
    {
        cout << "Abjad tidak valid." << endl;
        system("cls");
        return main();
    }
    // posisi ledakan pertama kali
    akan_meledak[tambah++] = posisi_ledakan;
    for (int i = 0; i < tambah; i++)
    {
        int posisi = akan_meledak[i];
        if (meledak[posisi])
        {
            continue;
        }
        meledak[posisi] = true;
        int luas = sebaran_ledakan[posisi];
        // ledakan ke kiri
        for (int i = 1; i <= luas; i++)
        {
            int kiri = posisi - i;
            if (kiri >= 0 && !meledak[kiri])
            {
                akan_meledak[tambah++] = kiri;
            }
        }
        // ledakan ke kanan
        for (int i = 1; i <= luas; i++)
        {
            int kanan = posisi + i;
            if (kanan < jumlah_kembang_api && !meledak[kanan])
            {
                akan_meledak[tambah++] = kanan;
            }
        }
    }
    // setelah abjad dipilih ygy
    cout << "Kembang  api yang tersisa:" << endl;
    for (int i = 0; i < jumlah_kembang_api; i++)
    {
        if (!meledak[i])
        {
            cout << abjad[i] << ": " << sebaran_ledakan[i] << endl;
            kembang_api_tersisa = true;
        }
    }
    // kondisi kalo kembang apinya udah kebakar semua
    if (!kembang_api_tersisa)
    {
        cout << endl;
        cout << "tidak ada kembang api tersisa" << endl;
    }
    system("pause");
    return 0;
}
