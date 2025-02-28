#include <iostream>

using namespace std;

int main()
{
    char blok;
    int angka;
    cout << "Masukan  alamat rumah dari Fia : ";
    cin >> blok;
    cin >> angka;

    if (blok > 69 || blok < 65)
    {
        cout << "Alamat rumah yang kamu masukan tidak ada ! , masukan lagi !" << endl;
        return main();
    }
    if (blok == 68 && angka % 2 == 0)
    {
        cout << "Alamat rumah yang kamu masukan tidak ada ! , masukan lagi !" << endl;
        return main();
    }

    for (int j = 1; j <= 5; j++)
    {
        char huruf = 'A';
        huruf = huruf + (j - 1);
        for (int i = 1; huruf != (int)blok ? i <= 10 : i <= angka - 1; i % 2 == 1 && (int)huruf == 68 ? i += 2 : i++)
        {
            cout << "Melewati rumah " << huruf;
            cout << i << endl;
        }
        if ((int)blok == huruf)
        {
            cout << "Rumah Fia Yaitu " << blok << angka << " Sudah ketemu!" << endl;
            system("pause");
            return 0;
        }
    }

    system("pause");
    return 0;
}
