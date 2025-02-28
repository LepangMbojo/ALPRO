#include <iostream>
using namespace std;

int main()
{
    double Celcius, Farenheit, Kelvin, Farenheit_CEL25, Celcius25, Farenheit25, Kelvin25, FarenheitCEL65, Celcius65, Farenheit65, Kelvin65, suhukamar, suhukamar3, suhukamarnow, perbandingan1, perbandingan2, perbandingan3, perbandingan4;

    // level 1

    cout << "Masukkan Suhu Awal : ";
    cin >> Celcius;

     Farenheit = Celcius * 9.0 / 5.0 + 32;
    Kelvin = Celcius + 273.15;

    cout << "Suhu Awal Kamar Kholil: " << endl;
    cout << "1. " << Celcius << " Celcius" << endl;
    cout << "2. " << Farenheit << " Fahrenheit" << endl;
    cout << "3. " << Kelvin << " Kelvin" << endl;

    cout << endl;

    // level 2

    Celcius25 = Celcius * 25 / 100;
    Farenheit_CEL25 = Celcius - Celcius25;
    Farenheit25 = Farenheit_CEL25 * 9 / 5 + 32;
    Kelvin25 = Celcius25 + 273.15;

    Celcius65 = Celcius * 65 / 100;
    FarenheitCEL65 = Celcius - Celcius65;
    Farenheit65 = Celcius65 * 9 / 5 + 32;
    Kelvin65 = FarenheitCEL65 + 273.15;


    cout << "setelah 15 menit : "<<endl;
    cout << "suhu kamar kholil berkurang menjadi " << Farenheit25 << " F dengan pengurangan sebesar " << Kelvin25 << "K" << endl;
    cout << "setelah 45 menit : "<<endl;
    cout << "suhu kamar kholil berkurang menjadi " << Kelvin65 << " K dengan pengurangan sebesar " << Celcius65 << "C" << endl;

    cout << endl;

    cout << "suhu kamar kholil sebelumnya " << Celcius << endl;
    cout << "suhu kamar kholil saat ini " << FarenheitCEL65 << endl;

    cout << endl;

    // level 3

    suhukamar3 = FarenheitCEL65 * 35 / 100;
    suhukamarnow = FarenheitCEL65 + suhukamar3;

    perbandingan1 = Celcius / Celcius;
    perbandingan2 = Celcius / suhukamarnow;
    perbandingan3 = Celcius / FarenheitCEL65;
    perbandingan4 = Celcius / Farenheit_CEL25;

    cout << "kholil mematikan pendingin " << endl;
    cout << endl;
    cout << "suhu kamar kholil naik menjadi " << suhukamarnow << "C" << endl;
    cout << "kholil membandingkan seluruh suhu" << endl;
    cout << endl;
    cout << "hasil perbandingan" << endl;
    cout << perbandingan1 << ":" << perbandingan2 << " untuk suhu saat ini " << endl;
    cout << perbandingan1 << ":" << perbandingan3 << " untuk suhu terdingin " << endl;
    cout << perbandingan1 << ":" << perbandingan4 << " untuk suhu 15 menit setelah pendinginan" << endl;

    system("pause");
    return 0;
}