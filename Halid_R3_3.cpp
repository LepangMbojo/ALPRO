#include <iostream>
using namespace std;

int main()
{
    string palindom;
    string rama;
    int cetak;
    cout << "berapa kata yang mau di cetak : ";
    cin >> cetak;

    for (int i = 1; i <= cetak; ++i)
    {
        cout << " masukan kata ke- " << i << " : ";
        cin >> rama;

        int panjang = rama.length();

        for (int i = 0; i < panjang; i++)
    {
        if (rama[i] >= 65 && rama[i] <= 90)
        {
            rama[i] += 32;
        }
    }

    string kalimat2;
    for (int i = panjang - 1; i >= 0; i--)
    {
        kalimat2 += rama[i];
    }
    if (kalimat2 == rama)
    {
        palindom = palindom + "\n" + kalimat2;
    }
    }

    cout << endl;
    cout << palindom << endl;

    system("pause");
    return 0;
}