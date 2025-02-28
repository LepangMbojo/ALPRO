#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int rad;
    cout << "--------------------------------" << endl;
    cout << "|     PROGRAM ANIMASI BULAN    |" << endl;
    cout << "--------------------------------" << endl;

    cout << "Masukkan Radius Bulan: ";
    cin >> rad;

    while (rad < 1)
    {

        cout << " Input Tidak Valid";
        cin >> rad;
    }

    do
    {
        for (int x = -(rad * 2); x <= rad * 2; x++)
        {
            for (int y = -rad; y < rad; y++)
            {
                for (int z = -(rad); z < (rad); z++)
                {

                    int bulat1 = z * z + y * y <= (rad * rad) - rad;
                    int bulat2 = (x + z) * (x + z) + y * y >= (rad - 1) * (rad - 1);

                    if (bulat1 && bulat2)
                    {
                        cout << setw(2) << "*";
                    }
                    else
                    {
                        cout << setw(2) << " ";
                    }
                }
                cout << endl;
            }
            system("cls");
        }
    } while (true);
    return 0;
}