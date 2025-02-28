#include <iostream>

using namespace std;

int main()
{
    // level 2

    float sisiAtas;
    float sisiBawah;
    float tinggi;
    cout << "Program penghitung Luas Trapesium " << endl;
    cout << "Masukkan sisi atas (cm) : ";
    cin >> sisiAtas;
    cout << "Masukkan sisi bawah (cm) : ";
    cin >> sisiBawah;
    cout << "Masukkan tinggi (cm) : ";
    cin >> tinggi;
    cout << "Luas Trapesium : " << (0.5 * (sisiAtas + sisiBawah) * tinggi) << " cm" << endl;

        return 0;
}