#include <iostream>

using namespace std;

int main()
{
    string pilihan;
    char tambahan;

    cout << "Mau teh atau kopi?" << endl;
    cout << "Jawab : ";
    cin >> pilihan;

    if (pilihan == "teh")
    {
        int gula = 0;
        do
        {
            gula++;
            cout << "Memasukkan gula batu..." << endl;
            cout << "Jumlah gula batu yang sudah dimasukkan: " << gula << endl;
            cout << "Apakah mau gula lagi? (Y/N): ";
            cin >> tambahan;
        } while (tambahan == 'Y');
        cout << "Jadi minuman yang dipilih indi adalah " << pilihan << endl;
        cout << pilihan << " yang dipilih indi memiliki " << gula << " buah gula batu" << endl;
    }
    else if (pilihan == "kopi")
    {
        int krimer = 1;
        do
        {
            cout << "Memasukkan krimer..." << endl;
            cout << "Jumlah krimer yang sudah dimasukkan: " << krimer << endl;
            krimer = krimer + 2;

            cout << "Apakah mau lagi? (Y/N): ";
            cin >> tambahan;
        } while (tambahan == 'Y');
        cout << "Jadi minuman yang dipilih indi adalah " << pilihan << endl;
        cout << pilihan << " yang dipilih indi memiliki " << krimer - 2 << " sendok krimer" << endl;
    }

    system("pause");
    return 0;
}