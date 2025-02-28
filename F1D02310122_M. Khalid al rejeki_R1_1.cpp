#include <iostream>
using namespace std;

int main()
{

    float jml;
    char input;
    int uangindi;
    int uangfia;
    int tmp;
    int tmpp;

    // cout harga menu disini
    cout << "Indi pergi ke jalan majapahit bersama fia untuk berburu takjil. Indi berniat untuk mntraktir fia." << endl;
    cout << "Ternyata, di situ khalid dan yusri sedang berjualan takjil bersama teman-temannya yang lain." << endl;
    cout << "Mereka menjual: " << endl;
    cout << "(A). Es buah Rp.5000" << endl;
    cout << "(B). Sosis bakar Rp.10000" << endl;
    cout << "(C).  Nasi goreng Rp.15000" << endl;

    cout << "Takjil dipilih dengan A,B dan C" << endl;
    cout << "Indi dan fia ingin membeli barang yang sama, mereka memilih [A/B/C] dengan jumlah [berapa] : ";
    cin >> input;
    cin >> jml;
    cout << "Indi kemudian mengambil dompetnya dan melihat jumlah yang dimilikinya adalah [berapa] : ";
    cin >> uangindi;

    cout << "Summary" << endl;
    cout << "Takjil yang dibeli oleh indi dan fia adalah takjil nomer " << (int)input - 64 << " Sebanyak " << jml << " dengan total Rp." << jml * ((int)input - 64) * 5000 << endl;
    cout << "Uang yang dibawa indi adalah : " << uangindi << endl;  
    cout << "Setelah membayar , uang indi sisa  Rp. " << uangindi - (jml * ((int)input - 64) * 5000) << endl;

    cout << "saat ingin pulang , fia ingin membelikan sesuatu juga untuk indi , jadi  ia mengeluarkan dompetnya dan melihat jumlah uang yang dimilikinya adalah  ";
    cin >> uangfia;
    cout << "Ia pun membeli cilok seharga Rp. 5000 sehingga uang fia sisa Rp. " << uangfia - 5000 << endl;

    cout << "Ternyata dompet indi dan fia warna dan bentuknya persis sama  " << endl;
    cout << "saat ingin pulang , mereka berdua bertemu dengan rafi , afif , rama , dan yurian , sehingga mereka mengobrol terlebih dahulu " << endl;
    cout << "Indi menitipkan dompetnya ke fia untuk sementara. kemudian mereka pun pulang dan ternyata dompet indi dan fia tertukar" << endl;

    tmp = uangfia - 5000;
    tmpp = uangindi - (jml * ((int)input - 64) * 5000);
    uangindi = tmp;
    uangfia = tmpp;

    
    cout << "jadi saat ini dompet yang dibawa indi berisi Rp." << uangfia << endl;
    cout << "dan dompet yang dibawa fia berisi Rp." << uangindi << endl;

    system("pause");
    return 0;
}