#include <iostream>
using namespace std;

int main()
{
    cout << "========BERMAIN DENGAN MATRIKS========" << endl;
    int baris, kolom;
    cout << "Masukkan JUMLAH BARIS MATRIKS: ";
    cin >> baris;
    cout << "Masukkan JUMLAH KOLOM MATRIKS: ";
    cin >> kolom;

    int matriks[baris][kolom];
    cout << "Masukkan elemen matriks: " << endl;
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            cin >> matriks[i][j];
        }
    }

    cout << "Hasil rotasi 90 derajat searah jarum jam: " << endl;
    for (int j = 0; j < baris; j++)
    {
    for (int i = kolom - 1; i >= 0; i--)
        {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }



    cout << "Hasil pencerminan terhadap sumbu X: " << endl;
    for (int i = baris - 1; i >= 0; i--)
    {
        for (int j = kolom - 1; j >= 0; j--)
        {
            cout << matriks[j][i] << " ";
        }
        cout << endl;
    }

    system("pause");
    return 0;
}
