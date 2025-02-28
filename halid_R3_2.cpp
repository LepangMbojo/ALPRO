#include <iostream>
using namespace std;

int main()
{
    string menu[] = {"crepes", "jagung", "cilok", "jus"};
    int harga[] = {12, 12, 5, 7};
    double total_harga = 0;
    bool cek = false;

    string pilihan[5];
    cout << " masukan 5 menu sekaligus ( diseperate dengan spasi) : ";
    for (int i = 0; i < 5; ++i)
    {
        cin >> pilihan[i];

        int j;  
        for (j = 0; j < 4; ++j)
        {
            if (pilihan[i] == menu[j])
            {
                total_harga += harga[j];
            } else {cek = true;
            
            }
        }
        if (cek){
            total_harga += harga[3];
        }
    }
        cout << " harga sebelum tax : " << total_harga << endl;

    total_harga = total_harga + (total_harga * 0.07);
    cout << " harga setelah tax : " << total_harga << endl;
    system("pause");
    return 0;
}